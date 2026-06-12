#include "PauseMenuUi.h"

PauseMenuUi::PauseMenuUi(std::function<void()> on_resume, std::function<void()> on_exit)
    : m_on_resume(std::move(on_resume)), m_on_exit(std::move(on_exit))
{
}

void PauseMenuUi::update()
{
}

void PauseMenuUi::render()
{
    ImVec2 window_size = ImVec2(EngiApp->window()->size().x, EngiApp->window()->size().y);
    ImVec2 window_pos = ImVec2(0, 0);

    ImGui::Begin("PauseBackground", nullptr,
        ImGuiWindowFlags_NoTitleBar |
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoScrollbar |
        ImGuiWindowFlags_NoScrollWithMouse |
        ImGuiWindowFlags_NoBringToFrontOnFocus |
        ImGuiWindowFlags_NoBackground);

    ImVec2 panel_size(360, 240);
    int x = window_pos.x + (window_size.x - panel_size.x) * 0.5f;
    int y = window_pos.y + (window_size.y - panel_size.y) * 0.5f;

    ImGui::SetNextWindowPos(ImVec2(x, y));
    ImGui::SetNextWindowSize(panel_size);

    ImGui::Begin(Localization::tr("ui.pause.menu.name").c_str(), nullptr,
        ImGuiWindowFlags_NoResize |
        ImGuiWindowFlags_NoMove |
        ImGuiWindowFlags_NoCollapse);

    constexpr float button_width = 200.0f;
    constexpr float button_height = 40.0f;
    constexpr float panel_width = 360.0f;

    ImGui::SetCursorPosX((panel_width - ImGui::CalcTextSize(Localization::tr("ui.pause.menu.title").c_str()).x) * 0.5f);
    ImGui::TextColored(ImVec4(1.0f, 0.8f, 0.0f, 1.0f), Localization::tr("ui.pause.menu.title").c_str());

    ImGui::Spacing();
    ImGui::Separator();
    ImGui::Spacing();
    ImGui::TextWrapped(Localization::tr("ui.pause.menu.description").c_str());
    ImGui::Spacing();
    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_width - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.pause.menu.resume").c_str(), ImVec2(button_width, button_height)) && m_on_resume)
    {
        m_on_resume();
    }

    ImGui::Spacing();

    ImGui::SetCursorPosX((panel_width - button_width) * 0.5f);
    if (ImGui::Button(Localization::tr("ui.pause.menu.exit_to_menu").c_str(), ImVec2(button_width, button_height)) && m_on_exit)
    {
        m_on_exit();
    }

    ImGui::End();
    ImGui::End();
}