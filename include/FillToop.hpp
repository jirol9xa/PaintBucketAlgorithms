#pragma once

#include "Tool.hpp"
#include "Vec3.hpp"
#include <functional>

/// Class for implementing PaintBucket logic
class FillTool : public Tool
{
  private:
    Vec3 color_;

    std::function<void()> req_draw_func_ = []() { return; };

  public:
    /// Method for immediate drowing
    /// PLEASE, TRY TO DON'T USE IT
    void requireDraw() const { req_draw_func_(); }
    void setReqDrawFunc(std::function<void()> func) { req_draw_func_ = func; }

    int use(uint32_t *pixels, const Vec2 &size) override;
};
