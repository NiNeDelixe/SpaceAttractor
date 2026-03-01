#pragma once
#ifndef COMPONENTS_WORLDSPACECACHE_H_
#define COMPONENTS_WORLDSPACECACHE_H_

#include <enginecore/core/CoreDefines.h>

#include <glm/glm.hpp>

#include <enginecore/interfaces/IComponent.h>

class WorldSpaceCache : public IComponent
{
public:
    glm::dvec3 world_position;
    glm::dquat world_rotation;
    bool dirty;
};

#endif  // COMPONENTS_WORLDSPACECACHE_H_
