#include "vec3.h"
#include <cmath>
#include <iostream>
#include <utility>

size_t Vec3Kernel::setX(size_t x)
{
    size_t old_x = x_;
    x_           = x;

    return old_x;
}

size_t Vec3Kernel::setY(size_t y)
{
    size_t old_y = y_;
    y_           = y;

    return old_y;
}

size_t Vec3Kernel::setZ(size_t z)
{
    size_t old_z = z_;
    z_           = z;

    return old_z;
}

std::ostream &operator<<(std::ostream &os, Vec3 &vec)
{
    os << "x = " << vec.getX() << ", y = " << vec.getY() << ", z = " << vec.getZ() << std::endl;

    return os;
}

bool Vec3::operator==(const Vec3 &vec) const
{
    return getX() == vec.getX() && getY() == vec.getY() && getZ() == vec.getZ();
}