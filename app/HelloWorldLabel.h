#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

namespace GuiApp {

class HelloWorldLabel : public juce::Label
{
public:
    HelloWorldLabel()
    {
        constexpr float kFontSize{20};

        setText("HelloWorld", juce::dontSendNotification);
        setJustificationType(juce::Justification::centred);
        setFont(juce::Font(kFontSize));
    }
};

}  // namespace GuiApp
