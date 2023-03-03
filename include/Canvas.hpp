#pragma once

#include "ActionManager.hpp"
#include "VideoSettings.hpp"
#include "Widget.hpp"
#include <iostream>
#include <utility>

/// @brief Widget for canvas, where we can draw
class Canvas : public Widget
{
  private:
    int draw(uint32_t *Pixels) const override;
    int close() override { return 0; };
    int onClick(Vec2 &pos, bool is_left) override;
    int move(Vec2 &delta) override { return 0; };
    int onKey() override { return 0; };

    uint32_t *canvas_pixels_;

  public:
    Canvas(Vec2 pos, Vec3 color, size_t width = 200, size_t height = 200) : Widget(pos, color)
    {
        width_  = width;
        height_ = height;

        try
        {
            canvas_pixels_ = new uint32_t[width_ * height_];
            for (int i = 0; i < width_ * height_; ++i)
                canvas_pixels_[i] = 0xFF000000 + uint32_t(color_);
        }
        catch (std::bad_alloc except)
        {
            // Need make my own Exception Class
            std::cout << except.what() << std::endl;
            // FIXME: Make my own exception class
            abort(); // throw "Canvas Ctor error";
        }
    }

    /// Return Vec2 {width, heigth}
    inline Vec2 getSize() const { return Vec2(width_, height_); }
    /// Return pixels array in canvas
    uint32_t *getPixels() const { return canvas_pixels_; }

    ~Canvas() noexcept { delete[] canvas_pixels_; }
};
