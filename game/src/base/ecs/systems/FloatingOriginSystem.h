#pragma once
#ifndef SYSTEMS_FLOATINGORIGINSYSTEM_H_
#define SYSTEMS_FLOATINGORIGINSYSTEM_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/interfaces/ISystem.h>

#include <enginecore/core/ecs/entities/Camera.h>
#include <enginecore/core/ecs/components/transform/RenderTransform.h>

#include "base/ecs/components/space_transform/FloatingOrigin.h"
//#include "base/ecs/components/space_transform/RenderTransform.h"
#include "base/ecs/components/space_transform/SpaceTransform.h"
#include "base/ecs/components/space_transform/WorldSpaceCache.h"

class FloatingOriginSystem : public ISystem
{
public:
    FloatingOriginSystem() = default;
    ~FloatingOriginSystem() = default;

public:
    void update(EntityRegistry<DefaultEntityIndentifier>& registry) override;

private:
    
};

#endif  // SYSTEMS_FLOATINGORIGINSYSTEM_H_
