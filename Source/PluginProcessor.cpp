#include "PluginProcessor.h"
#include "PluginEditor.h"
VelvetAudioProcessor::VelvetAudioProcessor()
    : AudioProcessor(BusesProperties().withInput("Input",juce::AudioChannelSet::stereo()).withOutput("Output",juce::AudioChannelSet::stereo())),
      apvts(*this,nullptr,"Parameters",createParameterLayout()) {}
VelvetAudioProcessor::~VelvetAudioProcessor() {}
juce::AudioProcessorValueTreeState::ParameterLayout VelvetAudioProcessor::createParameterLayout() {
    juce::AudioProcessorValueTreeState::ParameterLayout layout;
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_DELAY_MS_90YB","Delay Time",juce::NormalisableRange<float>(1.0f,2000.0f,0.01f),250.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_FEEDBACK_90YB","Delay Feedback",juce::NormalisableRange<float>(0.0f,95.0f,0.01f),40.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("DELAY_MIX_90YB","Delay Mix",juce::NormalisableRange<float>(0.0f,100.0f,0.01f),30.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("GAIN_GAIN_DB_N0FJ","Gain Gain",juce::NormalisableRange<float>(-24.0f,24.0f,0.01f),0.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_THRESHOLD_U85H","Compressor Threshold",juce::NormalisableRange<float>(-60.0f,0.0f,0.01f),-18.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RATIO_U85H","Compressor Ratio",juce::NormalisableRange<float>(1.0f,20.0f,0.1f),4.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_ATTACK_U85H","Compressor Attack",juce::NormalisableRange<float>(0.1f,200.0f,0.01f),10.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_RELEASE_U85H","Compressor Release",juce::NormalisableRange<float>(10.0f,2000.0f,0.01f),150.0f));
    layout.add(std::make_unique<juce::AudioParameterFloat>("COMPRESSOR_MAKEUP_U85H","Compressor Makeup",juce::NormalisableRange<float>(0.0f,24.0f,0.01f),0.0f));
    return layout;
}
void VelvetAudioProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    currentSampleRate = sampleRate;
    juce::dsp::ProcessSpec spec;
    spec.sampleRate=(uint32_t)sampleRate; spec.maximumBlockSize=(uint32_t)samplesPerBlock; spec.numChannels=(uint32_t)getTotalNumOutputChannels();
    delay_90YB.prepare(spec); delay_90YB.setMaximumDelayInSamples((int)(spec.sampleRate*2.0)); delayMix_90YB.prepare(spec); delayMix_90YB.setWetMixProportion(0.3f);
    gain_N0FJ.prepare(spec); gain_N0FJ.setGainDecibels(0.0f);
    comp_U85H.prepare(spec); comp_U85H.setThreshold(-18.0f); comp_U85H.setRatio(4.0f); comp_U85H.setAttack(10.0f); comp_U85H.setRelease(150.0f); compMakeup_U85H.prepare(spec); compMakeup_U85H.setGainDecibels(0.0f);
}
void VelvetAudioProcessor::releaseResources() {}
bool VelvetAudioProcessor::isBusesLayoutSupported(const BusesLayout& l) const {
    return l.getMainOutputChannelSet()==juce::AudioChannelSet::stereo()&&l.getMainInputChannelSet()==juce::AudioChannelSet::stereo();
}
void VelvetAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&) {
    juce::ScopedNoDenormals noDenormals;
    juce::dsp::AudioBlock<float> block(buffer);
    juce::dsp::ProcessContextReplacing<float> context(block);
    { delay_90YB.setDelay((float)(*apvts.getRawParameterValue("DELAY_DELAY_MS_90YB")*currentSampleRate/1000.0)); delayMix_90YB.setWetMixProportion(*apvts.getRawParameterValue("DELAY_MIX_90YB")/100.0f); delayMix_90YB.pushDrySamples(block); delay_90YB.process(context); delayMix_90YB.mixWetSamples(block); }
    gain_N0FJ.setGainDecibels(*apvts.getRawParameterValue("GAIN_GAIN_DB_N0FJ")); gain_N0FJ.process(context);
    comp_U85H.setThreshold(*apvts.getRawParameterValue("COMPRESSOR_THRESHOLD_U85H")); comp_U85H.setRatio(*apvts.getRawParameterValue("COMPRESSOR_RATIO_U85H")); comp_U85H.setAttack(*apvts.getRawParameterValue("COMPRESSOR_ATTACK_U85H")); comp_U85H.setRelease(*apvts.getRawParameterValue("COMPRESSOR_RELEASE_U85H")); compMakeup_U85H.setGainDecibels(*apvts.getRawParameterValue("COMPRESSOR_MAKEUP_U85H")); comp_U85H.process(context); compMakeup_U85H.process(context);
}
void VelvetAudioProcessor::getStateInformation(juce::MemoryBlock& d) {
    auto s=apvts.copyState(); std::unique_ptr<juce::XmlElement> xml(s.createXml()); copyXmlToBinary(*xml,d);
}
void VelvetAudioProcessor::setStateInformation(const void* d,int sz) {
    std::unique_ptr<juce::XmlElement> xml(getXmlFromBinary(d,sz));
    if(xml&&xml->hasTagName(apvts.state.getType())) apvts.replaceState(juce::ValueTree::fromXml(*xml));
}
juce::AudioProcessorEditor* VelvetAudioProcessor::createEditor() { return new VelvetAudioProcessorEditor(*this); }
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter() { return new VelvetAudioProcessor(); }
