#pragma once
#ifndef SYSTEMS_FLOATINGORIGINSYSTEM_H_
#define SYSTEMS_FLOATINGORIGINSYSTEM_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/interfaces/ISystem.h>

#include <enginecore/core/ecs/entities/Camera.h>

#include "base/ecs/components/FloatingOrigin.h"
#include "base/ecs/components/RenderTransform.h"
#include "base/ecs/components/SpaceTransform.h"
#include "base/ecs/components/WorldSpaceCache.h"

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
