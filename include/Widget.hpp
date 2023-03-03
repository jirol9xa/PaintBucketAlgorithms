#pragma once

#include "Vec2.hpp"
#include "Vec3.hpp"
#include <cmath>

class ActionManager;

class Widget
{
  protected:
    Vec2         pos_;
    Vec3         color_;
    int_fast32_t width_;
    int_fast32_t height_;

    bool is_hit(Vec2 &pos) const
    {
        int_fast32_t x_cent = pos_.getX(), y_cent = pos_.getY(), x = pos.getX(), y = pos.getY();
        int_fast32_t delta_x = x - x_cent, delta_y = y - y_cent;

        return labs(delta_x) < width_ && labs(delta_y) < height_;
    }

    enum STATUSES
    {
        NON_USED = -1,
        USED     = 0,
    };

    // This field for widgets, that need make callbacks to managers
    // Mb should move initiallisation of this field to constructor, but I am
    // not sure
    ActionManager *mng_ = nullptr;

  public:
    Widget(Vec2 pos = {0, 0}, Vec3 color = {255, 255, 255}, int_fast32_t width = 30,
           int_fast32_t height = 30)
        : pos_(pos), color_(color), width_(width), height_(height)
    {
    }

    void setWidth(size_t new_width) { width_ = new_width; }
    void setHeight(size_t new_height) { height_ = new_height; }
    void setMng(ActionManager *mng) { mng_ = mng; }

    virtual int draw(uint32_t *PixelArr) const   = 0;
    virtual int close()                          = 0;
    virtual int onClick(Vec2 &pos, bool is_left) = 0;
    virtual int onKey()                          = 0;
    virtual int move(Vec2 &delta)                = 0;

    // Need to
    // virtual void register_callbacks(ActionManager *mng, Render *rnd) = 0;

    virtual ~Widget() noexcept {};
};
