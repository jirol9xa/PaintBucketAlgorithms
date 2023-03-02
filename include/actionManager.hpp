#pragma once

#include "widget.hpp"
#include <vector>

class ActionManager : public Widget
{
  private:
    std::vector<Widget *> wid_arr_;

  public:
    int draw(uint32_t *PixelArr) const override{};
    int close() override;
    int onClick(Vec2 &pos, bool is_left) override;
    int onKey() override;
    int move(Vec2 &delta) override;

    // Method for adding widget to the management
    void registerWidget(Widget *wid)
    {
        wid_arr_.push_back(wid);
        wid->setMng(this);
    }
};
