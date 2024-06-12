#include "PluginEditor.h"

PluginEditor::PluginEditor(juce::AudioProcessor& processor) : juce::AudioProcessorEditor{processor}
{
    setOpaque(true);
    setResizable(true, false);
}

void PluginEditor::paint(juce::Graphics& g)
{
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void PluginEditor::resized()
{
    setBounds(getLocalBounds());
}
