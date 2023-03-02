#include "actionManager.hpp"
#include "vec2.h"

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
