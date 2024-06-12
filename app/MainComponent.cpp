#include "MainComponent.h"

namespace GuiApp {
MainComponent::MainComponent()
{
    addAndMakeVisible(helloWorld);
    setSize(600, 400);
}

void MainComponent::paint(juce::Graphics& graphics)
{
    graphics.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void MainComponent::resized()
{
    helloWorld.setBounds(getLocalBounds());
}

}  // namespace GuiApp
