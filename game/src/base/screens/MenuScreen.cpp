#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
    menu_ui_it = EngiApp->getUis().emplace(EngiApp->getUis().end(), std::make_shared<MainMenuUi>());
}

MenuScreen::~MenuScreen()
{
    EngiApp->getUis().erase(menu_ui_it);
}

void MenuScreen::update(const float& delta)
{
    
}

void MenuScreen::draw(const float& delta)
{
}
