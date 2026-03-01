#pragma once
#ifndef SPACE_TRANSFORM_SPACETRANSFORM_H_
#define SPACE_TRANSFORM_SPACETRANSFORM_H_

#include <enginecore/core/CoreDefines.h>

#include <glm/glm.hpp>

#include <enginecore/interfaces/IComponent.h>
#include <enginecore/core/LibrariesDefines.h>

class SpaceTransform : public IComponent
{
public:
    entt::entity parent;
    glm::dvec3 local_position;
    glm::dquat local_rotation;
};

#endif // SPACE_TRANSFORM_SPACETRANSFORM_H_
