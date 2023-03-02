#pragma once

#include "basis.h"
#include "vector.h"
#include "videoSettings.h"
#include <SFML/Graphics.hpp>
#include <functional>
#include <iostream>
#include <vector>

class Render
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
            pixels_ = new uint32_t[Settings::Width * Settings::Heigth];
        }
        catch (std::bad_alloc except)
        {
            // Need to make my Own exception class
            std::cout << except.what() << std::endl;
            throw "Render Ctor failed";
        }
    }
    Render(sf::RenderWindow *window) : window_(window)
    {
        pixels_ = new uint32_t[Settings::Width * Settings::Heigth];
    }

    void setBasis(const Basis &basis) { basis_ = basis; }

    void draw(Vector &vec) const;
    void draw(Vector &vec, Basis &basis)
    {
        basis_ = basis;
        draw(vec);
    }
    void draw(const uint32_t *array) const;
    void draw(const uint32_t *array, Basis &basis)
    {
        basis_ = basis;
        draw(array);
    }

    void drawAll();

    void register_callbacks(std::function<void(uint32_t *pixels)> method);

    ~Render() noexcept { delete[] pixels_; }
};
