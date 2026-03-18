#include "GameScreen.h"

GameScreen::GameScreen(const std::shared_ptr<Level>& level)
	: m_level(level), render(level)
{
	EngiApp->window()->events()->lockCursor(true);
	EngiApp->getSystemManager()->emplaceSystems<GameSystemFactory>();
	// EngiApp->setEntitySystem(SystemCategory::CAMERA_BEHAVIOR, std::make_shared<ThirdPersonSystem>());
	// EngiApp->setEntitySystem(SystemCategory::OBJECT_CONTROLLING, std::make_shared<PlayerControllSystem>());
	// EngiApp->addEntitySystem(std::make_shared<FloatingOriginSystem>());
}

void GameScreen::update(const float& delta)
{
	//render.generateChunk(0, 0);
	render.render();
}

void GameScreen::draw(const float& delta)
{
	//mesh->draw();
}

void GameScreen::loadTestMap()
{
	
}
