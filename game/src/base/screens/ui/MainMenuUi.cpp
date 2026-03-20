#include "MainMenuUi.h"

#include "base/world/World.h"

void MainMenuUi::update()
{
}

void MainMenuUi::render()
{
    ImVec2 window_size = ImVec2(EngiApp->window()->size().x, EngiApp->window()->size().y);
    ImVec2 window_pos = ImVec2(0, 0);

    ImGui::Begin("Background", nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoBackground);

    ImVec2 panel_size(420, 320);

    int x = window_pos.x + (window_size.x - panel_size.x) * 0.5f;
    int y = window_pos.y + (window_size.y - panel_size.y) * 0.5f;

    ImGui::SetNextWindowPos(ImVec2(x, y));
    ImGui::SetNextWindowSize(panel_size);

    ImGui::Begin(Localization::tr("ui.main.menu.name").c_str(), nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar);

    switch (m_mode)
    {
    case WorldMenuMode::Main:
        renderMainMenu();
        break;
    case WorldMenuMode::CreateWorld:
        renderCreateWorldMenu();
        break;
    }

    ImGui::End(); // Main Menu
    ImGui::End(); // Background
}

void MainMenuUi::renderMainMenu()
{
    constexpr float button_width = 220.0f;
    constexpr float button_height = 40.0f;
    constexpr float panel_width = 420.0f;

    ImGui::SetCursorPosX((panel_width - ImGui::CalcTextSize(Localization::tr("ui.main.menu.game_name").c_str()).x) * 0.5f);
    ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.0f, 1.0f), Localization::tr("ui.main.menu.game_name").c_str());

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_width - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.main.menu.world.select").c_str(), ImVec2(button_width, button_height)))
    {
        m_mode = WorldMenuMode::CreateWorld;
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_width - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.main.menu.settings").c_str(), ImVec2(button_width, button_height)))
    {
        LOG(INFO) << "Settings do nothing";
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_width - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.main.menu.quit").c_str(), ImVec2(button_width, button_height)))
    {
        EngiApp->quit(0);
    }
}

void MainMenuUi::renderCreateWorldMenu()
{
    constexpr float panel_width = 420.0f;
    constexpr float button_width = 170.0f;
    constexpr float button_height = 40.0f;

    const std::string create_world_title = Localization::tr("ui.main.menu.world.create_title");
    const std::string selected_game_type = selectedGameTypeLabel();

    ImGui::SetCursorPosX((panel_width - ImGui::CalcTextSize(create_world_title.c_str()).x) * 0.5f);
    ImGui::TextColored(ImVec4(0.6f, 0.9f, 1.0f, 1.0f), create_world_title.c_str());

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();

    ImGui::TextUnformatted(Localization::tr("ui.main.menu.world.create_hint").c_str());
    ImGui::Spacing();
    ImGui::TextUnformatted(Localization::tr("ui.main.menu.world.game_type").c_str());
    if (ImGui::BeginCombo("##game_type", selected_game_type.c_str()))
    {
        const bool is_test_selected = m_selected_game_type == WorldGameType::Test;
        if (ImGui::Selectable(Localization::tr("ui.main.menu.world.test_type").c_str(), is_test_selected))
        {
            m_selected_game_type = WorldGameType::Test;
        }

        if (is_test_selected)
        {
            ImGui::SetItemDefaultFocus();
        }

        ImGui::EndCombo();
    }

    ImGui::Spacing();
    ImGui::TextWrapped(Localization::tr("ui.main.menu.world.test_description").c_str());

    ImGui::Dummy(ImVec2(0.0f, 24.0f));

    if (ImGui::Button(Localization::tr("ui.main.menu.world.back").c_str(), ImVec2(button_width, button_height)))
    {
        m_mode = WorldMenuMode::Main;
    }

    ImGui::SameLine();

    if (ImGui::Button(Localization::tr("ui.main.menu.world.create").c_str(), ImVec2(button_width, button_height)))
    {
        if (auto world = createWorld())
        {
            EngiApp->setScreen(std::make_shared<GameScreen>(world));
        }
    }
}

std::shared_ptr<World> MainMenuUi::createWorld() const
{
    auto world = std::make_shared<World>();

    switch (m_selected_game_type)
    {
    case WorldGameType::Test:
    default:
        world->setLevel(std::make_shared<TestLevel>());
        break;
    }

    return world;
}

std::string MainMenuUi::selectedGameTypeLabel() const
{
    switch (m_selected_game_type)
    {
    case WorldGameType::Test:
    default:
        return Localization::tr("ui.main.menu.world.test_type");
    }
}