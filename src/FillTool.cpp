#include "FillToop.hpp"
#include <cassert>
#include <iostream>
#include <stack>

int FillTool::use(u_int32_t *pixels, const Vec2 &size)
{
    assert(pixels != nullptr);

    std::cout << "here\n";

    int_fast32_t     width = size.getX(), height = size.getY();
    std::stack<Vec2> pix_stack;

    auto is_edge = [&](int_fast32_t x, int_fast32_t y)
    {
        if (x > width || y > height)
            return true;

        return pixels[x + y * width] == COLORS::EDGE_COLOR;
    };

    int_fast32_t x = 300, y = 300;
    pix_stack.push({x, y});

    for (;;)
    {
        // Try to pop new pixel for filling
        if (pix_stack.empty())
            break;

        Vec2 pix = pix_stack.top();
        x = pix.getX(), y = pix.getY();
        pix_stack.pop();

        if (pixels[x + y * width] == COLORS::FILL_COLOR)
            continue;

        // Fill the pixel
        pixels[x + y * width] = COLORS::FILL_COLOR;

        // Add neighbors to the stack of pixels
        if (!is_edge(x + 1, y))
            pix_stack.push({x + 1, y});
        if (!is_edge(x - 1, y))
            pix_stack.push({x - 1, y});
        if (!is_edge(x, y + 1))
            pix_stack.push({x, y + 1});
        if (!is_edge(x, y - 1))
            pix_stack.push({x, y - 1});

        requireDraw();
    }

    std::cout << "Filling done\n";

    is_active_ = false;
    return 0;
}
