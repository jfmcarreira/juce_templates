#include "MainWindow.h"

#include "MainComponent.h"

namespace GuiApp {
constexpr auto isMobile() -> bool
{
#if JUCE_IOS || JUCE_ANDROID
    return true;
#else
    return false;
#endif
}

MainWindow::MainWindow(const juce::String& name) : DocumentWindow(name, getBackgroundColour(), allButtons)
{
    setUsingNativeTitleBar(true);
    setContentOwned(new MainComponent(), true); // NOLINT

    if (isMobile()) {
        setFullScreen(true);
    } else {
        setResizable(true, true);
        centreWithSize(getWidth(), getHeight());
    }

    setVisible(true);
}

void MainWindow::closeButtonPressed()
{
    juce::JUCEApplication::getInstance()->systemRequestedQuit();
}

auto MainWindow::getBackgroundColour() -> juce::Colour
{
    return juce::Desktop::getInstance().getDefaultLookAndFeel().findColour(ResizableWindow::backgroundColourId);
}

}  // namespace GuiApp
