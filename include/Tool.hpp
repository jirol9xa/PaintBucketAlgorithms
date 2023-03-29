#pragma once

#include "ActionManager.hpp"
#include <functional>
#include <iostream>
#include <unistd.h>

/// Abstract class for implementing tool
class Tool
{
  protected:
    ActionManager *mng_ = nullptr;

    bool is_active_ = false;

  public:
    virtual int  use(uint32_t *pixels, const Vec2 &size) = 0;
    virtual void setMng(ActionManager *mng) { mng_ = mng; }

    virtual bool is_active() const { return is_active_; }

    bool toggle()
    {
        sleep(1);
        return is_active_ = !is_active_;
    }
};
