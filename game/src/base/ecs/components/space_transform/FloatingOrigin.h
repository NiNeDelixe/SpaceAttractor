#pragma once
#ifndef SPACE_TRANSFORM_FLOATINGORIGIN_H_
#define SPACE_TRANSFORM_FLOATINGORIGIN_H_

#include <enginecore/core/CoreDefines.h>

#include <glm/glm.hpp>

#include <enginecore/interfaces/IComponent.h>

class FloatingOrigin : public IComponent
{
public:
    glm::dvec3 origin;
};

#endif // SPACE_TRANSFORM_FLOATINGORIGIN_H_
