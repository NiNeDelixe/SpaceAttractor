#pragma once
#ifndef MANAGMENT_GAMESYSTEMFACTORY_H_
#define MANAGMENT_GAMESYSTEMFACTORY_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/core/ecs/systems/managment/EngineSystemFactory.h>

#include "base/ecs/systems/FloatingOriginSystem.h"
#include "base/ecs/systems/physics/PhysicsSystem.h"
#include "base/ecs/systems/physics/RigidbodySystem.h"
#include "base/ecs/systems/PlayerControllSystem.h"

class GameSystemFactory : public EngineSystemFactory
{
public:
    GameSystemFactory() = default;
    ~GameSystemFactory() = default;

public:
    virtual SystemsContainer createSystems() override;

private:
    
};

#endif // MANAGMENT_GAMESYSTEMFACTORY_H_
