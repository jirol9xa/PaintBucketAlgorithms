#include "vec2.h"
#include <cmath>
#include <iostream>
#include <utility>

size_t Vec2Kernel::setX(size_t x)
{
    std::swap(x, x_);
    return x;
}

size_t Vec2Kernel::setY(size_t y)
{
    std::swap(y, y_);
    return y;
}

std::ostream &operator<<(std::ostream &os, Vec2 &vec)
{
    os << "x = " << vec.getX() << ", y = " << vec.getY() << std::endl;

    return os;
}

bool Vec2::operator==(const Vec2 &vec) const
{
    return getX() == vec.getX() && getY() == vec.getY();
}
