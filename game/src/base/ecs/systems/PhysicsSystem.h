#pragma once
#ifndef SYSTEMS_PHYSICSSYSTEM_H_
#define SYSTEMS_PHYSICSSYSTEM_H_

#include <enginecore/core/CoreDefines.h>

#include <enginecore/interfaces/ISystem.h>

class PhysicsSystem : public ISystem
{
public:
    PhysicsSystem() = default;
    ~PhysicsSystem() = default;

public:
    void update(EntityRegistry<DefaultEntityIndentifier>& registry) override;

private:
    
};

#endif  // SYSTEMS_PHYSICSSYSTEM_H_
