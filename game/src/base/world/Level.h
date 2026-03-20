#pragma once
#ifndef WORLD_LEVEL_H_
#define WORLD_LEVEL_H_

#include "enginecore/core/CoreDefines.h"

#include <vector>

#include "enginecore/utils/types/GameObjectsAllocator.h"
#include "enginecore/utils/types/GameObject.h"

class World;

using GameObjectContainer = std::vector<std::shared_ptr<CRNMSP::GameObject>, 
	UTLSNMSP::memory::GameObjectAllocator<std::shared_ptr<CRNMSP::GameObject>>>;

/// @brief Level contains data about objects
/// World contains data about save
class Level
{
public:
	Level() = default;
	virtual ~Level() = default;

public:
	bool addGameObject(const std::shared_ptr<CRNMSP::GameObject>& object) { return false; }
	[[nodiscard]] std::shared_ptr<World> world() const { return m_world.lock(); }

private:
	friend class World;
    void setWorld(const std::shared_ptr<World>& world) { m_world = world; }

private:
    GameObjectContainer m_objects;
    std::weak_ptr<World> m_world;
};


#endif // !WORLD_LEVEL_H_