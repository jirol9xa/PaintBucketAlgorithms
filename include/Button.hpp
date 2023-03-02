#pragma once

#include "ActionManager.hpp"
#include "Render.hpp"
#include "Widget.hpp"
#include <iostream>

class Button : public Widget
{
  private:
    bool        is_pressed_;
    std::string name_;

  protected:
    void press() { is_pressed_ = !is_pressed_; }
    int  draw(uint32_t *PixelArr) const override;
    int  close() override{};
    int  onClick(Vec2 &pos, bool is_left) override;
    int  onKey() override { return 0; };

    uint32_t getColor() { return uint32_t(color_) * is_pressed_; }

  public:
    Button(Vec2 pos, Vec3 color) : Widget(pos, color), is_pressed_(false){};

    int move(Vec2 &delta) override
    {
        pos_ += delta;
        return STATUSES::USED;
    }
};
