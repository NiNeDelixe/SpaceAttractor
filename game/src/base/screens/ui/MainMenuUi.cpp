#include "MainMenuUi.h"

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

    ImVec2 panel_size(400, 300);

    int x = panel_size.x;
    int y = panel_size.y;

    x = window_pos.x + (window_size.x - panel_size.x) * 0.5f;
    y = window_pos.y + (window_size.y - panel_size.y) * 0.5f;

    ImVec2 panel_pos(x, y);

    ImGui::SetNextWindowPos(panel_pos);
    ImGui::SetNextWindowSize(panel_size);

    ImGui::Begin(Localization::tr("ui.main.menu.name").c_str(), nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar);

    ImGui::SetCursorPosX((panel_size.x - ImGui::CalcTextSize(Localization::tr("ui.main.menu.game_name").c_str()).x) * 0.5f);
    ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.0f, 1.0f), Localization::tr("ui.main.menu.game_name").c_str());

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::Spacing();

    float button_width = 200.0f;
    float button_height = 40.0f;

    ImGui::SetCursorPosX((panel_size.x - button_width) * 0.5f);

    if (ImGui::Button(Localization::tr("ui.main.menu.play").c_str(), ImVec2(button_width, button_height))) {
        EngiApp->setScreen(std::make_shared<GameScreen>(std::make_shared<TestLevel>()));
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_size.x - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.main.menu.settings").c_str(), ImVec2(button_width, button_height))) {
        LOG(INFO) << "Settings do nothing";
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_size.x - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.main.menu.quit").c_str(), ImVec2(button_width, button_height))) {
        EngiApp->quit(0);
    }

    ImGui::End(); // Main Menu
    ImGui::End(); // Background
}
