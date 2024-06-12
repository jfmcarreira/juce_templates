#include "MainWindow.h"

namespace GuiApp {
class JuceApplication : public juce::JUCEApplication
{
public:
    auto getApplicationName() -> const juce::String override { return JUCE_APPLICATION_NAME_STRING; }
    auto getApplicationVersion() -> const juce::String override { return JUCE_APPLICATION_VERSION_STRING; }
    auto moreThanOneInstanceAllowed() -> bool override { return true; }

    void initialise(const juce::String& commandLine) override
    {
        if (!commandLine.contains("console")) mainWindow = std::make_unique<MainWindow>(getApplicationName());
    }

    void shutdown() override { mainWindow.reset(); }

    void systemRequestedQuit() override { quit(); }

    void anotherInstanceStarted(const juce::String& /*commandLine*/) override {}

private:
    std::unique_ptr<MainWindow> mainWindow;
};

// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(JuceApplication)

}  // namespace GuiApp
