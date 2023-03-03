#pragma once

#include "Vec3.hpp"
#include <cstdint>
#include <iostream>

/// Class for implementing background of programm.
/// Always it is just wrapper over the uint32_t*
class Background
{
  public:
    uint32_t    *pixels_;
    int_fast32_t width_, height_;
    const Vec3   color_;

  public:
    Background(const int_fast32_t width, const int_fast32_t height, const Vec3 &color = {0, 0, 0})
        : width_(width), height_(height), color_(color)
    {
        try
        {
            pixels_ = new uint32_t[height_ * width_];
        }
        catch (std::bad_alloc &except)
        {
            std::cout << except.what() << std::endl;
            abort(); // FIXME: throw "..."
        }

        // We have color only in 24 low bits
        uint32_t color24 = color_.getAsColor();

        for (int_fast32_t i = 0; i < height_; ++i)
            for (int_fast32_t j = 0; j < width_; ++j)
                pixels_[j + i * width_] = 0xFF000000 + color24;
    }

    ~Background() noexcept { delete[] pixels_; }
};
