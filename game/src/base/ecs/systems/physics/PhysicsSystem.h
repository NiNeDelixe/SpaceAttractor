#pragma once
#ifndef SYSTEMS_PHYSICSSYSTEM_H_
#define SYSTEMS_PHYSICSSYSTEM_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/interfaces/ISystem.h>

#include <enginecore/core/Time.h>

#include <enginecore/core/ecs/components/physics/GravityComponent.h>
#include <enginecore/core/ecs/components/physics/RigidBodyComponent.h>
#include <enginecore/core/ecs/components/physics/VelocityComponent.h>
#include <enginecore/core/ecs/components/physics/SensorsComponent.h>
#include <enginecore/core/ecs/components/transform/RenderTransform.h>

#include "base/ecs/components/space_transform/FloatingOrigin.h"
//#include "base/ecs/components/RenderTransform.h"
#include "base/ecs/components/space_transform/SpaceTransform.h"
#include "base/ecs/components/space_transform/WorldSpaceCache.h"

class PhysicsSystem : public ISystem
{
public:
    PhysicsSystem();
    ~PhysicsSystem() = default;

public:
    void update(EntityRegistry<DefaultEntityIndentifier>& registry) override;

private:
    
};

#endif // SYSTEMS_PHYSICSSYSTEM_H_
