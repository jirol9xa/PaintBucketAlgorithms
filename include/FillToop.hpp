#pragma once

#include "Tool.hpp"
#include "Vec3.hpp"
#include <functional>

/// Config list for filling and detecting colors in FillTool
enum FILL_TOOL_COLORS
{
    EDGE_COLOR = 0xFF000000,
};

/// Class for implementing PaintBucket logic
class FillTool : public Tool
{
  private:
    Vec3 color_;

    std::function<void()> req_draw_func_        = []() { return; };
    std::function<Vec2()> req_mouse_click_func_ = []() -> Vec2 { return {0, 0}; };

  public:
    FillTool(const Vec3 &color) : color_(color) {}

    /// Method for immediate drowing
    /// PLEASE, TRY TO DON'T USE IT
    void requireDraw() const { req_draw_func_(); }
    void setReqDrawFunc(std::function<void()> func) { req_draw_func_ = func; }

    /// Method for immediate drowing
    /// PLEASE, TRY TO DON'T USE IT
    Vec2 requireMouseClick() const { return req_mouse_click_func_(); }
    void setReqMouseClickFunc(std::function<Vec2()> func) { req_mouse_click_func_ = func; }

    int use(uint32_t *pixels, const Vec2 &size) override;

    void setColor(const Vec3 &color) { color_ = color; }
};
