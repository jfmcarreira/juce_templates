#ifndef HELPERS_H
#define HELPERS_H

#include <juce_audio_processors/juce_audio_processors.h>

namespace PluginHelpers {

// A little helper to get the parameter ID
inline auto getParamID(juce::AudioProcessorParameter* param) -> juce::String
{
    if (auto* paramWithID = dynamic_cast<juce::AudioProcessorParameterWithID*>(param)) return paramWithID->paramID;

    return param->getName(50);
}
}  // namespace PluginHelpers

#endif
