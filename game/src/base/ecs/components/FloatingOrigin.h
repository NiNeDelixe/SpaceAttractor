#pragma once
#ifndef COMPONENTS_FLOATINGORIGIN_H_
#define COMPONENTS_FLOATINGORIGIN_H_

#include <enginecore/core/CoreDefines.h>

#include <glm/glm.hpp>

#include <enginecore/interfaces/IComponent.h>

class FloatingOrigin : public IComponent
{
public:
    glm::dvec3 origin;
};

#endif  // COMPONENTS_FLOATINGORIGIN_H_
