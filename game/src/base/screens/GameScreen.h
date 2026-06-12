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
#include "base/world/World.h"

#include "base/screens/ui/PauseMenuUi.h"

class GameScreen : public Screen
{
public:
	GameScreen(const std::shared_ptr<World>& level);
	~GameScreen();

	void update(const float& delta) override;
	void draw(const float& delta) override;

private:
    void setPaused(bool paused);
    void showPauseMenu();
    void hidePauseMenu();
    void togglePause();
    void exitToMainMenu();

private:
	WorldRenderer render;
    std::shared_ptr<World> m_world;
    bool m_is_paused = false;
    bool m_has_pause_ui = false;
    std::vector<std::shared_ptr<Ui>>::iterator m_pause_ui_it;
};


#endif // !BASE_GAMESCREEN_H_