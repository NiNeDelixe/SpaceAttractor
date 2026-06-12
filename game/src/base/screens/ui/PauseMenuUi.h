#pragma once
#ifndef UI_PAUSEMENUUI_H_
#define UI_PAUSEMENUUI_H_

#include <enginecore/core/CoreDefines.h>

#include <functional>

#include <enginecore/core/graphics/ui/Ui.h>
#include <enginecore/core/EngineCoreApplication.h>
#include <enginecore/core/lang/Localization.h>

#include <enginecore/utils/ImguiIncludes.h>

class PauseMenuUi : public Ui
{
public:
    PauseMenuUi(std::function<void()> on_resume, std::function<void()> on_exit);
    ~PauseMenuUi() override = default;

public:
    void update() override;
    void render() override;

private:
    std::function<void()> m_on_resume;
    std::function<void()> m_on_exit;  
};

#endif  // UI_PAUSEMENUUI_H_
