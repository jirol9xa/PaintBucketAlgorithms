#pragma once

#include <cstdint>
#include <cstdio>
#include <iostream>

class Vec2Kernel
{
  private:
    int_fast32_t x_, y_;

  public:
    Vec2Kernel(int_fast32_t x = 0, int_fast32_t y = 0) : x_(x), y_(y) {}

    int_fast32_t getX() const { return x_; }
    int_fast32_t getY() const { return y_; }

    int_fast32_t setX(int_fast32_t x);
    int_fast32_t setY(int_fast32_t y);

    const Vec2Kernel &operator=(const Vec2Kernel &ker);

    const Vec2Kernel &operator+=(const Vec2Kernel &arg);
    const Vec2Kernel &operator-=(const Vec2Kernel &arg);
    const Vec2Kernel &operator*=(int_fast32_t coef);
};

class Vec2
{
  private:
    Vec2Kernel Kernel;

  public:
    Vec2(int_fast32_t x = 0, int_fast32_t y = 0) : Kernel(x, y) {}

    Vec2(const Vec2 &&vec) { Kernel = vec.Kernel; }
    Vec2(const Vec2 &vec) { Kernel = vec.Kernel; }

    int_fast32_t getX() const { return Kernel.getX(); }
    int_fast32_t getY() const { return Kernel.getY(); }

    int_fast32_t setX(int_fast32_t x) { return Kernel.setX(x); }
    int_fast32_t setY(int_fast32_t y) { return Kernel.setY(y); }

    friend Vec2          operator*(double coef, const Vec2 &vec);
    friend std::ostream &operator<<(std::ostream &os, Vec2 &vec);

    const Vec2 &operator=(const Vec2 &&vec);
    const Vec2 &operator=(const Vec2 &vec);
    Vec2        operator+(const Vec2 &vec) const;
    Vec2        operator-(const Vec2 &vec) const;
    Vec2        operator%(const Vec2 &vec) const;
    Vec2        operator*(int_fast32_t coef) const;
    Vec2        operator/(int_fast32_t coef) const { return this->operator*(1 / coef); }
    Vec2        operator-() const { return (-1) * (*this); }

    bool operator==(const Vec2 &vec) const;
    bool operator!=(const Vec2 &vec) const { return !(*this == vec); }

    double operator*(const Vec2 &arg) const;

    void operator+=(const Vec2 &arg) { Kernel += arg.Kernel; }
    void operator-=(const Vec2 &arg) { Kernel -= arg.Kernel; }
    void operator*=(int_fast32_t coef) { Kernel *= coef; }
};

inline const Vec2Kernel &Vec2Kernel::operator=(const Vec2Kernel &ker)
{
    x_ = ker.x_;
    y_ = ker.y_;

    return *this;
}

inline const Vec2Kernel &Vec2Kernel::operator+=(const Vec2Kernel &ker)
{
    x_ += ker.x_;
    y_ += ker.y_;

    return *this;
}

inline const Vec2Kernel &Vec2Kernel::operator-=(const Vec2Kernel &ker)
{
    x_ -= ker.x_;
    y_ -= ker.y_;

    return *this;
}

inline const Vec2Kernel &Vec2Kernel::operator*=(int_fast32_t coef)
{
    x_ *= coef;
    y_ *= coef;

    return *this;
}

inline const Vec2 &Vec2::operator=(const Vec2 &&vec)
{
    Kernel = vec.Kernel;
    return *this;
}

inline const Vec2 &Vec2::operator=(const Vec2 &vec)
{
    Kernel = vec.Kernel;
    return *this;
}

inline Vec2 Vec2::operator*(int_fast32_t coef) const
{
    return Vec2(Kernel.getX() * coef, Kernel.getY() * coef);
}

inline double Vec2::operator*(const Vec2 &vec) const
{
    return (Kernel.getX() * vec.Kernel.getX() + Kernel.getY() * vec.Kernel.getY());
}

inline Vec2 operator*(double coef, const Vec2 &vec)
{
    return Vec2(vec.Kernel.getX() * coef, vec.Kernel.getY() * coef);
}

inline Vec2 Vec2::operator+(const Vec2 &arg) const
{
    return Vec2(Kernel.getX() + arg.Kernel.getX(), Kernel.getY() + arg.Kernel.getY());
}

inline Vec2 Vec2::operator-(const Vec2 &arg) const
{
    return Vec2(Kernel.getX() - arg.Kernel.getX(), Kernel.getY() - arg.Kernel.getY());
}

// Component multiplication
inline Vec2 Vec2::operator%(const Vec2 &vec) const
{
    return Vec2(Kernel.getX() * vec.Kernel.getX(), Kernel.getY() * vec.Kernel.getY());
}
