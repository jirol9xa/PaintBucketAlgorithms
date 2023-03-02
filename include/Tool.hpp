#pragma once

#include "ActionManager.hpp"
#include <functional>

/// Abstract class for implementing tool
class Tool
{
    ActionManager *mng_ = nullptr;

    bool is_active_ = false;

  public:
    virtual int  use(uint32_t *pixels) = 0;
    virtual void setMng(ActionManager *mng) { mng_ = mng; }
    virtual void requireDraw() { mng_->draw(); };
    virtual bool is_active() { return is_active_; }
};
