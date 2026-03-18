#pragma once
#ifndef WORLD_LEVEL_H_
#define WORLD_LEVEL_H_

#include "enginecore/core/CoreDefines.h"

#include <vector>

#include "enginecore/utils/types/GameObjectsAllocator.h"
#include "enginecore/utils/types/GameObject.h"

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

private:
	GameObjectContainer m_objects;
};


#endif // !WORLD_LEVEL_H_