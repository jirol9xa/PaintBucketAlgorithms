#include "FillToop.hpp"
#include <cassert>
#include <iostream>
#include <stack>

namespace
{
inline bool is_black(uint32_t pixel) { return pixel == 0xFF000000; }
} // namespace

int FillTool::use(u_int32_t *pixels, const Vec2 &size)
{
    assert(pixels != nullptr);

    std::cout << "here\n";

    std::stack<Vec2> pix_stack;

    for (unsigned i = 0; i < size.getX() - 10; i += 9)
    {
        pixels[i + 30 * size.getX()] = 0xFF000000;
        pixels[i + 31 * size.getX()] = 0xFF000000;
        pixels[i + 32 * size.getX()] = 0xFF000000;
        pixels[i + 33 * size.getX()] = 0xFF000000;

        requireDraw();
    }

    is_active_ = false;
    return 0;
}
