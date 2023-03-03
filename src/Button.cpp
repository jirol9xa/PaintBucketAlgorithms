#include "Button.hpp"
#include "VideoSettings.hpp"
#include <cstdio>

int Button::draw(uint32_t *PixelArr) const
{
    assert(PixelArr != nullptr);

    size_t x_start = pos_.getX(), y_start = pos_.getY();

    for (int height = 0; height < height_; ++height)
        for (int width = 0; width < width_; ++width)
            PixelArr[x_start + width + (y_start + height) * Settings::width] =
                0xFF000000 + uint32_t(color_);

    return 0;
};

int Button::onClick(Vec2 &pos, bool is_left)
{
    if (!is_hit(pos))
        return STATUSES::NON_USED; // FIXME: make norm err_code

    if (is_left)
        press();

    return STATUSES::USED;
}
