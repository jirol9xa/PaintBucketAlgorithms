#include "button.hpp"
#include "videoSettings.hpp"
#include <cstdio>

int Button::draw(uint32_t *PixelArr) const
{
    size_t x_start = pos_.getX(), y_start = pos_.getY();

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::Width] =
                0xFF000000 + uint32_t(color_);

    return 0;
};

int Button::onClick(Vec2 &pos, bool is_left)
{
    if (!is_hit(pos))
        return -1; // FIXME: make norm err_code

    is_pressed = is_left;
}
