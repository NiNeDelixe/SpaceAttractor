#pragma once
#ifndef UI_MAINMENUUI_H_
#define UI_MAINMENUUI_H_

#include <array>

#include <enginecore/core/graphics/ui/Ui.h>

#include <enginecore/core/EngineCoreApplication.h>

#include <enginecore/utils/ImguiIncludes.h>

#include <enginecore/core/lang/Localization.h>

#include "base/screens/GameScreen.h"
#include "base/world/TestLevel.h"

class MainMenuUi : public Ui
{
private:
    enum class WorldMenuMode
    {
        Main,
        CreateWorld,
    };

    enum class WorldGameType
    {
        Test,
    };

public:
    MainMenuUi() = default;
    ~MainMenuUi() override = default;

public:
    virtual void update() override;
    virtual void render() override;

private:
    void renderMainMenu();
    void renderCreateWorldMenu();
    std::shared_ptr<World> createWorld() const;
    std::string selectedGameTypeLabel() const;

private:
    WorldMenuMode m_mode = WorldMenuMode::Main;
    WorldGameType m_selected_game_type = WorldGameType::Test;
};

#endif  // UI_MAINMENUUI_H_
