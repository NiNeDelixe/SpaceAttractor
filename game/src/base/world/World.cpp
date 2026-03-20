#include "World.h"

bool World::setLevel(const std::shared_ptr<Level>& level)
{
    if (!level)
    {
        return false;
    }

    m_level = level;
    m_level->setWorld(shared_from_this());
    return true;
}