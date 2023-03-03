#include "Canvas.hpp"
#include <iostream>

int Canvas::onClick(Vec2 &pos, bool is_left)
{
    if (!is_hit(pos))
        return STATUSES::NON_USED;

    Vec2 canv_pos = pos - pos_;

    int_fast32_t x = canv_pos.getX(), y = canv_pos.getY();

    for (unsigned i = 0;
         i < width_ / 100 && i + x < width_ && i + y < height_ && x - i >= 0 && y - i >= 0; i++)
    {
        canvas_pixels_[x - i + y * width_]   = 0xFF000000 + !is_left * 0x00FFFFFF;
        canvas_pixels_[x + (y - i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;

        canvas_pixels_[x + i + y * width_]   = 0xFF000000 + !is_left * 0x00FFFFFF;
        canvas_pixels_[x + (y + i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;

        canvas_pixels_[x - i + (y + i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;
        canvas_pixels_[x + i + (y - i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;

        canvas_pixels_[x + i + (y + i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;
        canvas_pixels_[x - i + (y - i) * width_] = 0xFF000000 + !is_left * 0x00FFFFFF;
    }

    return STATUSES::USED;
}

int Canvas::draw(uint32_t *PixelArr) const
{
    assert(PixelArr != nullptr);

    int_fast32_t x_start = pos_.getX(), y_start = pos_.getY();

    for (int_fast32_t height = 0; height < height_; ++height)
        for (int_fast32_t width = 0; width < width_; ++width)
        {
            PixelArr[x_start + width + (y_start + height) * Settings::width] =
                0xFF000000 + uint32_t(color_);
        }

    for (int_fast32_t height = 0; height < height_; ++height)
        for (int_fast32_t width = 0; width < width_; ++width)
        {
            PixelArr[x_start + width + (y_start + height) * Settings::width] =
                canvas_pixels_[width + height * width_];
        }

    return 0;
}
