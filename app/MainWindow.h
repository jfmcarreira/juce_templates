#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace GuiApp {
class MainWindow : public juce::DocumentWindow
{
public:
    explicit MainWindow(const juce::String& name);

private:
    void closeButtonPressed() override;
    auto getBackgroundColour() -> juce::Colour;
};

}  // namespace GuiApp
