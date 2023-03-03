#pragma once

#include "Basis.hpp"
#include "Vector.hpp"
#include "VideoSettings.hpp"
#include <SFML/Graphics.hpp>
#include <cassert>
#include <functional>
#include <iostream>
#include <vector>

// Abstract class for implementing render interface
class IRender
{
  public:
    virtual void setBasis(const Basis &basis)      = 0;
    virtual void draw(Vector &vec) const           = 0;
    virtual void draw(const uint32_t *array) const = 0;
};

class Render : public IRender
{
  private:
    Basis             basis_;
    sf::RenderWindow *window_;
    uint32_t         *pixels_;

    std::vector<std::function<void(uint32_t *pixels)>> draw_cb;

  public:
    Render(Basis basis, sf::RenderWindow *window) : basis_(basis), window_(window)
    {
        try
        {
            pixels_ = new uint32_t[Settings::width * Settings::height];
        }
        catch (std::bad_alloc &except)
        {
            // Need to make my Own exception class
            std::cout << except.what() << std::endl;
            abort(); // FIXME: //throw "Render Ctor failed";
        }
    }
    Render(sf::RenderWindow *window) : window_(window)
    {
        try
        {
            pixels_ = new uint32_t[Settings::width * Settings::height];
        }
        catch (std::bad_alloc &except)
        {
            std::cout << except.what() << std::endl;
            abort(); // FIXME
        }
    }

    void setBasis(const Basis &basis) override { basis_ = basis; }

    void draw(Vector &vec) const override;
    void draw(Vector &vec, Basis &basis)
    {
        basis_ = basis;
        draw(vec);
    }
    void draw(const uint32_t *array) const override;
    void draw(const uint32_t *array, Basis &basis)
    {
        assert(array != nullptr);

        basis_ = basis;
        draw(array);
    }

    void drawAll();

    void register_callbacks(std::function<void(uint32_t *pixels)> method);

    ~Render() noexcept { delete[] pixels_; }
};
