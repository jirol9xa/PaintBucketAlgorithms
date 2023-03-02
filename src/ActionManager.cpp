#include "ActionManager.hpp"
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
            tool->use(pixel_arr);

    for (auto &&widget : wid_arr_)
        widget->draw(pixel_arr);

    return 0;
}
