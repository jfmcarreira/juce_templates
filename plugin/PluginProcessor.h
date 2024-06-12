#ifndef PLUGINPROCESSOR_H
#define PLUGINPROCESSOR_H

#include <juce_audio_processors/juce_audio_processors.h>
#include <juce_audio_utils/juce_audio_utils.h>

class WhiteNoise;

class PluginProcessor : public juce::AudioProcessor
{
public:
    PluginProcessor();
    explicit PluginProcessor(const BusesProperties& ioLayouts);

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

    auto isBusesLayoutSupported(const BusesLayout& layouts) const -> bool override;

    using AudioProcessor::processBlock;

    void getStateInformation(juce::MemoryBlock& destData) override;
    void setStateInformation(const void* data, int sizeInBytes) override;

    auto createEditor() -> juce::AudioProcessorEditor* override;
    auto hasEditor() const -> bool override { return true; }

    auto getName() const -> const juce::String override;

    auto acceptsMidi() const -> bool override { return true; }
    auto producesMidi() const -> bool override { return false; }
    auto isMidiEffect() const -> bool override { return false; }
    auto getTailLengthSeconds() const -> double override { return 0.0; }

    auto getNumPrograms() -> int override
    {
        // NB: some hosts don't cope very well if you tell them there are 0 programs,
        // so this should be at least 1, even if you're not really implementing programs.
        return 1;
    }
    auto getCurrentProgram() -> int override { return 0; }
    void setCurrentProgram([[maybe_unused]] int index) override {}
    auto getProgramName([[maybe_unused]] int index) -> const juce::String override { return {}; }
    void changeProgramName([[maybe_unused]] int index, [[maybe_unused]] const juce::String& newName) override {}

    static auto getDefaultProperties() -> BusesProperties;

private:
    void processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages) override;

    static BusesProperties getBuses();

private:  // NOLINT
    std::unique_ptr<WhiteNoise> noise_generator_;
};

#endif
