#pragma once
#ifndef BASE_GAMESCREEN_H_
#define BASE_GAMESCREEN_H_

#include <memory>

#include <enginecore/core/screens/Screen.h>

#include <enginecore/core/EngineCoreApplication.h>

#include <enginecore/core/ecs/systems/ThirdPersonSystem.h>

#include "base/ecs/systems/PlayerControllSystem.h"
#include "base/ecs/systems/FloatingOriginSystem.h"
#include "base/ecs/systems/managment/GameSystemFactory.h"
#include "base/renderer/world/WorldRenderer.h"

class GameScreen : public Screen
{
public:
	GameScreen(const std::shared_ptr<Level>& level);
	~GameScreen() = default;

	void update(const float& delta) override;
	void draw(const float& delta) override;

	void loadTestMap();

private:
	WorldRenderer render;
	std::shared_ptr<Level> m_level;
};


#endif // !BASE_GAMESCREEN_H_