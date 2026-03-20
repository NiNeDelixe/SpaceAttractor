#include "GameScreen.h"

GameScreen::GameScreen(const std::shared_ptr<World>& world)
	: m_world(world), render(world)
{
	EngiApp->window()->events()->lockCursor(true);
    EngiApp->getSystemManager()->emplaceSystems<GameSystemFactory>();
}

void GameScreen::update(const float& delta)
{
	render.render();
}

void GameScreen::draw(const float& delta)
{
}

void GameScreen::loadTestMap()
{
	
}
