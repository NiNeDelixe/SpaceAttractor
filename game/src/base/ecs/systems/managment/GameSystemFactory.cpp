#include "GameSystemFactory.h"

SystemsContainer GameSystemFactory::createSystems()
{
    SystemsContainer systems = EngineSystemFactory::createSystems();

    systems.add(std::make_shared<FloatingOriginSystem>());
    systems.add(std::make_shared<PhysicsSystem>());
    systems.add(std::make_shared<PlayerControllSystem>());

    return systems;
}
