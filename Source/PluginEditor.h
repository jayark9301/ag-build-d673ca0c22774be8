#pragma once
#include "PluginProcessor.h"
#include "CustomLookAndFeel.h"
class VelvetAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
    VelvetAudioProcessorEditor(VelvetAudioProcessor&);
    ~VelvetAudioProcessorEditor() override;
    void paint(juce::Graphics&) override;
    void resized() override;
private:
    VelvetAudioProcessor& processorRef;
    VelvetLookAndFeel lnf;
    juce::Slider knob_DELAY_DELAY_MS_90YB;
    juce::Label lbl_DELAY_DELAY_MS_90YB;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_DELAY_MS_90YB;
    juce::Slider knob_DELAY_FEEDBACK_90YB;
    juce::Label lbl_DELAY_FEEDBACK_90YB;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_FEEDBACK_90YB;
    juce::Slider knob_DELAY_MIX_90YB;
    juce::Label lbl_DELAY_MIX_90YB;
    juce::AudioProcessorValueTreeState::SliderAttachment att_DELAY_MIX_90YB;
    juce::Slider knob_GAIN_GAIN_DB_N0FJ;
    juce::Label lbl_GAIN_GAIN_DB_N0FJ;
    juce::AudioProcessorValueTreeState::SliderAttachment att_GAIN_GAIN_DB_N0FJ;
    juce::Slider knob_COMPRESSOR_THRESHOLD_U85H;
    juce::Label lbl_COMPRESSOR_THRESHOLD_U85H;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_THRESHOLD_U85H;
    juce::Slider knob_COMPRESSOR_RATIO_U85H;
    juce::Label lbl_COMPRESSOR_RATIO_U85H;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RATIO_U85H;
    juce::Slider knob_COMPRESSOR_ATTACK_U85H;
    juce::Label lbl_COMPRESSOR_ATTACK_U85H;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_ATTACK_U85H;
    juce::Slider knob_COMPRESSOR_RELEASE_U85H;
    juce::Label lbl_COMPRESSOR_RELEASE_U85H;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_RELEASE_U85H;
    juce::Slider knob_COMPRESSOR_MAKEUP_U85H;
    juce::Label lbl_COMPRESSOR_MAKEUP_U85H;
    juce::AudioProcessorValueTreeState::SliderAttachment att_COMPRESSOR_MAKEUP_U85H;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VelvetAudioProcessorEditor)
};
