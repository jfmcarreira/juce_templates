#ifndef PLUGINEDITOR_H
#define PLUGINEDITOR_H

#include <juce_audio_processors/juce_audio_processors.h>

class PluginEditor : public juce::AudioProcessorEditor
{
public:
    explicit PluginEditor(juce::AudioProcessor& processor);

    void paint(juce::Graphics&) override;
    void resized() override;

private:
};

#endif
