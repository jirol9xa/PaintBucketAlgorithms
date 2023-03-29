#pragma once

#include "ActionManager.hpp"
#include "Render.hpp"
#include "Widget.hpp"
#include <functional>
#include <iostream>
#include <unistd.h>

class Button : public Widget
{
  private:
    bool is_pressed_;

    std::string name_;
    // TODO: Mb should move it to ABC
    std::function<bool()> action_;

    // protected:
  public:
    void press()
    {
        sleep(1);

        is_pressed_ = !is_pressed_;
        action_();
    }
    int draw(uint32_t *PixelArr) const override;
    int close() override { return 0; };
    int onClick(Vec2 &pos, bool is_left) override;
    int onKey() override { return 0; };

    // TODO: Mb should move it to ABC
    /// Method for binding some action to button press
    /// signature of action call should be void(void)
    void connect(std::function<bool()> func) { action_ = func; }

    uint32_t getColor() { return uint32_t(color_) * is_pressed_; }

  public:
    Button(Vec2 pos, Vec3 color) : Widget(pos, color), is_pressed_(false){};

    int move(Vec2 &delta) override
    {
        pos_ += delta;
        return STATUSES::USED;
    }
};
