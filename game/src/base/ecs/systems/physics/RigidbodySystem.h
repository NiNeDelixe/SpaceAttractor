#pragma once
#ifndef PHYSICS_RIGIDBODYSYSTEM_H_
#define PHYSICS_RIGIDBODYSYSTEM_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/interfaces/ISystem.h>

#include <enginecore/core/ecs/components/physics/RigidBodyComponent.h>
#include <enginecore/core/ecs/components/transform/RenderTransform.h>

#include "base/ecs/components/space_transform/SpaceTransform.h"
#include "base/ecs/components/space_transform/WorldSpaceCache.h"
#include "base/ecs/components/space_transform/FloatingOrigin.h"

class RigidbodySystem : public ISystem
{
public:
    RigidbodySystem() = default;
    ~RigidbodySystem() = default;

public:
    void update(EntityRegistry<DefaultEntityIndentifier>& registry) override;

private:
    
};

#endif // PHYSICS_RIGIDBODYSYSTEM_H_
