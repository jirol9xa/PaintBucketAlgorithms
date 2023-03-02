#pragma once

#include <cstdio>
#include <iostream>

class Vec3Kernel
{
  private:
    size_t x_, y_, z_;

  public:
    Vec3Kernel(size_t x = 0, size_t y = 0, size_t z = 0) : x_(x), y_(y), z_(z) {}

    size_t getX() const { return x_; }
    size_t getY() const { return y_; }
    size_t getZ() const { return z_; }

    size_t setX(size_t x);
    size_t setY(size_t y);
    size_t setZ(size_t z);

    const Vec3Kernel &operator=(const Vec3Kernel &ker);

    const Vec3Kernel &operator+=(const Vec3Kernel &arg);
    const Vec3Kernel &operator-=(const Vec3Kernel &arg);
    const Vec3Kernel &operator*=(size_t coef);
};

class Vec3
{
  private:
    Vec3Kernel Kernel;

  public:
    Vec3(size_t x = 0, size_t y = 0, size_t z = 0) : Kernel(x, y, z) {}

    Vec3(const Vec3 &&vec) { Kernel = vec.Kernel; }
    Vec3(const Vec3 &vec) { Kernel = vec.Kernel; }

    size_t getX() const { return Kernel.getX(); }
    size_t getY() const { return Kernel.getY(); }
    size_t getZ() const { return Kernel.getZ(); }

    uint32_t getAsColor() const { return (getZ() << 16) + (getY() << 8) + getX(); }

    explicit operator uint32_t() const { return getAsColor(); }

    size_t setX(size_t x) { return Kernel.setX(x); }
    size_t setY(size_t y) { return Kernel.setY(y); }
    size_t setZ(size_t z) { return Kernel.setZ(z); }

    friend Vec3          operator*(double coef, const Vec3 &vec);
    friend std::ostream &operator<<(std::ostream &os, Vec3 &vec);

    const Vec3 &operator=(const Vec3 &&vec);
    const Vec3 &operator=(const Vec3 &vec);
    Vec3        operator+(const Vec3 &vec) const;
    Vec3        operator-(const Vec3 &vec) const;
    Vec3        operator%(const Vec3 &vec) const;
    Vec3        operator*(size_t coef) const;
    Vec3        operator/(size_t coef) const { return this->operator*(1 / coef); }
    Vec3        operator-() const { return (-1) * (*this); }

    bool operator==(const Vec3 &vec) const;
    bool operator!=(const Vec3 &vec) const { return !(*this == vec); }

    double operator*(const Vec3 &arg) const;

    void operator+=(const Vec3 &arg) { Kernel += arg.Kernel; }
    void operator-=(const Vec3 &arg) { Kernel -= arg.Kernel; }
    void operator*=(size_t coef) { Kernel *= coef; }
};

inline const Vec3Kernel &Vec3Kernel::operator=(const Vec3Kernel &ker)
{
    x_ = ker.x_;
    y_ = ker.y_;
    z_ = ker.z_;

    return *this;
}

inline const Vec3Kernel &Vec3Kernel::operator+=(const Vec3Kernel &ker)
{
    x_ += ker.x_;
    y_ += ker.y_;
    z_ += ker.z_;

    return *this;
}

inline const Vec3Kernel &Vec3Kernel::operator-=(const Vec3Kernel &ker)
{
    x_ -= ker.x_;
    y_ -= ker.y_;
    z_ -= ker.z_;

    return *this;
}

inline const Vec3Kernel &Vec3Kernel::operator*=(size_t coef)
{
    x_ *= coef;
    y_ *= coef;
    z_ *= coef;

    return *this;
}

inline const Vec3 &Vec3::operator=(const Vec3 &&vec)
{
    Kernel = vec.Kernel;
    return *this;
}

inline const Vec3 &Vec3::operator=(const Vec3 &vec)
{
    Kernel = vec.Kernel;
    return *this;
}

inline Vec3 Vec3::operator*(size_t coef) const
{
    return Vec3(Kernel.getX() * coef, Kernel.getY() * coef, Kernel.getZ() * coef);
}

inline double Vec3::operator*(const Vec3 &vec) const
{
    return (Kernel.getX() * vec.Kernel.getX() + Kernel.getY() * vec.Kernel.getY() +
            Kernel.getZ() * vec.Kernel.getZ());
}

inline Vec3 operator*(double coef, const Vec3 &vec)
{
    return Vec3(vec.Kernel.getX() * coef, vec.Kernel.getY() * coef, vec.Kernel.getZ() * coef);
}

inline Vec3 Vec3::operator+(const Vec3 &arg) const
{
    return Vec3(Kernel.getX() + arg.Kernel.getX(), Kernel.getY() + arg.Kernel.getY(),
                Kernel.getZ() + arg.Kernel.getZ());
}

inline Vec3 Vec3::operator-(const Vec3 &arg) const
{
    return Vec3(Kernel.getX() - arg.Kernel.getX(), Kernel.getY() - arg.Kernel.getY(),
                Kernel.getZ() - arg.Kernel.getZ());
}

// Component multiplication
inline Vec3 Vec3::operator%(const Vec3 &vec) const
{
    return Vec3(Kernel.getX() * vec.Kernel.getX(), Kernel.getY() * vec.Kernel.getY(),
                Kernel.getZ() * vec.Kernel.getZ());
}
