#include "ActionManager.hpp"
#include "Button.hpp"
#include "Canvas.hpp"
#include "Tool.hpp"
#include "Vec2.hpp"
#include <functional>

int ActionManager::close()
{
    int status = STATUSES::NON_USED;
    for (auto &widget : wid_arr_)
    {
        status = widget->close();
        if (status != -1)
            return status;
    }

    return status;
}

int ActionManager::onClick(Vec2 &pos, bool is_left)
{
    int status = STATUSES::NON_USED;
    for (auto &widget : wid_arr_)
    {
        status = widget->onClick(pos, is_left);
        if (status != STATUSES::NON_USED)
            return status;
    }

    return status;
}

int ActionManager::onKey()
{
    int status = STATUSES::NON_USED;
    for (auto &widget : wid_arr_)
    {
        status = widget->onKey();
        if (status != STATUSES::NON_USED)
            return status;
    }

    return status;
}

int ActionManager::move(Vec2 &delta)
{
    int status = STATUSES::NON_USED;
    for (auto &widget : wid_arr_)
    {
        status = widget->move(delta);
        if (status != STATUSES::NON_USED)
            return status;
    }

    return status;
}

void ActionManager::registerTool(Tool *tool)
{
    assert(tool != nullptr);

    tools_arr_.push_back(tool);
    tool->setMng(this);
}

void ActionManager::registerWidget(Widget *wid)
{
    assert(wid != nullptr);

    wid_arr_.push_back(wid);
    wid->setMng(this);
}

int ActionManager::draw(uint32_t *pixel_arr) const
{
    assert(pixel_arr != nullptr);

    for (auto &&tool : tools_arr_)
        if (tool->is_active())
        {
            for (auto &&widget : wid_arr_)
                if (Canvas *canv = dynamic_cast<Canvas *>(widget))
                    tool->use(canv->getPixels(), canv->getSize());
        }

    for (auto &&widget : wid_arr_)
        widget->draw(pixel_arr);

    return 0;
}

int ActionManager::drawWithoutTools() const
{
    assert(back_gr_ != nullptr);
    assert(back_gr_->pixels_ != nullptr);

    for (auto &&widget : wid_arr_)
        widget->draw(back_gr_->pixels_);

    return 0;
}

void ActionManager::registerView(Render *view)
{
    assert(view != nullptr);

    view_ = view;
}

void ActionManager::registerBackground(Background *back_gr)
{
    assert(back_gr != nullptr);

    back_gr_ = back_gr;
}
