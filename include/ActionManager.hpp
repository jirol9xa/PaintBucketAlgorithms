#pragma once

#include "Render.hpp"
#include "Widget.hpp"
#include <cstdint>
#include <vector>

class Tool;

class ActionManager : public Widget
{
  private:
    std::vector<Widget *> wid_arr_;
    std::vector<Tool *>   tools_arr_;

    Render   *view_   = nullptr;
    uint32_t *pixels_ = nullptr;

  public:
    ActionManager() {}
    ActionManager(uint32_t *pixels) : pixels_(pixels) {}
    ActionManager(Render *view) : view_(view) {}

    int draw(uint32_t *pixel_arr) const override;
    int close() override;
    int onClick(Vec2 &pos, bool is_left) override;
    int onKey() override;
    int move(Vec2 &delta) override;

    void draw() { draw(pixels_); }

    /// Method for adding widget to the management
    void registerWidget(Widget *wid);
    /// Method for adding tool to the managent
    void registerTool(Tool *tool);
    /// Method for adding new Render as posssible view
    void registerView(Render *view) { view_ = view; }
    /// Method for adding pixels array with stored result
    void registerPixels(uint32_t *pixels) { pixels_ = pixels; }
};
