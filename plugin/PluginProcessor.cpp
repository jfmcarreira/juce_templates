#include "PluginProcessor.h"

#include <juce_audio_utils/juce_audio_utils.h>

class WhiteNoise
{
public:
    WhiteNoise()
    {
        samples.resize(kReservedNumSamples);
        for (auto& sample : samples) sample = getNextSample() * kGain;
    }

    void process(juce::AudioBuffer<float>& buffer) noexcept
    {
        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            auto nextSample = samples[(size_t)sample_pos_++];

            if (sample_pos_ >= (int)samples.size()) sample_pos_ = 0;

            for (int channel = 0; channel < buffer.getNumChannels(); ++channel)
                buffer.setSample(channel, sample, nextSample);
        }
    }
    auto getNextSample() -> float
    {
        auto f = rand.nextFloat();
        return juce::jmap(f, -1.f, 1.f);
    }

private:
    static constexpr float kGain{0.5};
    static constexpr size_t kReservedNumSamples{400000};

private:  // NOLINT
    int sample_pos_{0};

    juce::Random rand;
    std::vector<float> samples;
};

PluginProcessor::PluginProcessor() :
    juce::AudioProcessor(getDefaultProperties()), noise_generator_{std::make_unique<WhiteNoise>()}
{}

const juce::String PluginProcessor::getName() const
{
    return JucePlugin_Name;
}

//==============================================================================
void PluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void PluginProcessor::releaseResources()
{}

auto PluginProcessor::getDefaultProperties() -> juce::AudioProcessor::BusesProperties
{
    return BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
        .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
        ;
}

auto PluginProcessor::createEditor() -> juce::AudioProcessorEditor*
{
    return new juce::GenericAudioProcessorEditor(*this);  // NOLINT
}

auto PluginProcessor::isBusesLayoutSupported(const juce::AudioProcessor::BusesLayout& layouts) const -> bool
{
    if (isMidiEffect()) return true;

    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
        layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo()) {
        return false;
    }
    return true;
}
void PluginProcessor::getStateInformation(juce::MemoryBlock& destData)
{
    // TODO
}

void PluginProcessor::setStateInformation(const void* data, int sizeInBytes)
{
    // TODO
}

void PluginProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ignoreUnused(midiMessages);
    buffer.clear();
}

juce::AudioProcessor::BusesProperties PluginProcessor::getBuses()
{
    juce::AudioProcessor::BusesProperties properties;
    auto stereo = juce::AudioChannelSet::stereo();
    properties = properties.withOutput("Output", stereo);
    properties = properties.withOutput("Extra", stereo);

    return properties;
}

auto JUCE_CALLTYPE createPluginFilter() -> juce::AudioProcessor*
{
    return new PluginProcessor();  // NOLINT
}
