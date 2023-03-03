#include "Vec2.hpp"
#include <cmath>
#include <iostream>
#include <utility>

int_fast32_t Vec2Kernel::setX(int_fast32_t x)
{
    std::swap(x, x_);
    return x;
}

int_fast32_t Vec2Kernel::setY(int_fast32_t y)
{
    std::swap(y, y_);
    return y;
}

std::ostream &operator<<(std::ostream &os, const Vec2 &vec)
{
    os << "x = " << vec.getX() << ", y = " << vec.getY() << std::endl;

    return os;
}

bool Vec2::operator==(const Vec2 &vec) const
{
    return getX() == vec.getX() && getY() == vec.getY();
}
