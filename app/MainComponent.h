#pragma once

#include "HelloWorldLabel.h"

namespace GuiApp {

class MainComponent : public juce::Component
{
public:
    MainComponent();

    void paint(juce::Graphics& graphics) override;
    void resized() override;

private:
    HelloWorldLabel helloWorld;
};

}  // namespace GuiApp
