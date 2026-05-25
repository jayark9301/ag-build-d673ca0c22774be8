#include "PluginEditor.h"
VelvetAudioProcessorEditor::VelvetAudioProcessorEditor(VelvetAudioProcessor& p)
    : AudioProcessorEditor(&p), processorRef(p),
      att_DELAY_DELAY_MS_90YB(processorRef.apvts,"DELAY_DELAY_MS_90YB",knob_DELAY_DELAY_MS_90YB),
      att_DELAY_FEEDBACK_90YB(processorRef.apvts,"DELAY_FEEDBACK_90YB",knob_DELAY_FEEDBACK_90YB),
      att_DELAY_MIX_90YB(processorRef.apvts,"DELAY_MIX_90YB",knob_DELAY_MIX_90YB),
      att_GAIN_GAIN_DB_N0FJ(processorRef.apvts,"GAIN_GAIN_DB_N0FJ",knob_GAIN_GAIN_DB_N0FJ),
      att_COMPRESSOR_THRESHOLD_U85H(processorRef.apvts,"COMPRESSOR_THRESHOLD_U85H",knob_COMPRESSOR_THRESHOLD_U85H),
      att_COMPRESSOR_RATIO_U85H(processorRef.apvts,"COMPRESSOR_RATIO_U85H",knob_COMPRESSOR_RATIO_U85H),
      att_COMPRESSOR_ATTACK_U85H(processorRef.apvts,"COMPRESSOR_ATTACK_U85H",knob_COMPRESSOR_ATTACK_U85H),
      att_COMPRESSOR_RELEASE_U85H(processorRef.apvts,"COMPRESSOR_RELEASE_U85H",knob_COMPRESSOR_RELEASE_U85H),
      att_COMPRESSOR_MAKEUP_U85H(processorRef.apvts,"COMPRESSOR_MAKEUP_U85H",knob_COMPRESSOR_MAKEUP_U85H)
{
    setLookAndFeel(&lnf); setSize(380,440);
    knob_DELAY_DELAY_MS_90YB.setSliderStyle(juce::Slider::Rotary); knob_DELAY_DELAY_MS_90YB.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_DELAY_DELAY_MS_90YB.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_DELAY_MS_90YB); lbl_DELAY_DELAY_MS_90YB.setText("Delay Time",juce::dontSendNotification); lbl_DELAY_DELAY_MS_90YB.setJustificationType(juce::Justification::centred); lbl_DELAY_DELAY_MS_90YB.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_DELAY_MS_90YB);
    knob_DELAY_FEEDBACK_90YB.setSliderStyle(juce::Slider::Rotary); knob_DELAY_FEEDBACK_90YB.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_DELAY_FEEDBACK_90YB.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_FEEDBACK_90YB); lbl_DELAY_FEEDBACK_90YB.setText("Delay Feedback",juce::dontSendNotification); lbl_DELAY_FEEDBACK_90YB.setJustificationType(juce::Justification::centred); lbl_DELAY_FEEDBACK_90YB.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_FEEDBACK_90YB);
    knob_DELAY_MIX_90YB.setSliderStyle(juce::Slider::Rotary); knob_DELAY_MIX_90YB.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_DELAY_MIX_90YB.setLookAndFeel(&lnf); addAndMakeVisible(knob_DELAY_MIX_90YB); lbl_DELAY_MIX_90YB.setText("Delay Mix",juce::dontSendNotification); lbl_DELAY_MIX_90YB.setJustificationType(juce::Justification::centred); lbl_DELAY_MIX_90YB.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_DELAY_MIX_90YB);
    knob_GAIN_GAIN_DB_N0FJ.setSliderStyle(juce::Slider::Rotary); knob_GAIN_GAIN_DB_N0FJ.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_GAIN_GAIN_DB_N0FJ.setLookAndFeel(&lnf); addAndMakeVisible(knob_GAIN_GAIN_DB_N0FJ); lbl_GAIN_GAIN_DB_N0FJ.setText("Gain Gain",juce::dontSendNotification); lbl_GAIN_GAIN_DB_N0FJ.setJustificationType(juce::Justification::centred); lbl_GAIN_GAIN_DB_N0FJ.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_GAIN_GAIN_DB_N0FJ);
    knob_COMPRESSOR_THRESHOLD_U85H.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_THRESHOLD_U85H.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_COMPRESSOR_THRESHOLD_U85H.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_THRESHOLD_U85H); lbl_COMPRESSOR_THRESHOLD_U85H.setText("Compressor Threshold",juce::dontSendNotification); lbl_COMPRESSOR_THRESHOLD_U85H.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_THRESHOLD_U85H.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_THRESHOLD_U85H);
    knob_COMPRESSOR_RATIO_U85H.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RATIO_U85H.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_COMPRESSOR_RATIO_U85H.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_RATIO_U85H); lbl_COMPRESSOR_RATIO_U85H.setText("Compressor Ratio",juce::dontSendNotification); lbl_COMPRESSOR_RATIO_U85H.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RATIO_U85H.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RATIO_U85H);
    knob_COMPRESSOR_ATTACK_U85H.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_ATTACK_U85H.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_COMPRESSOR_ATTACK_U85H.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_ATTACK_U85H); lbl_COMPRESSOR_ATTACK_U85H.setText("Compressor Attack",juce::dontSendNotification); lbl_COMPRESSOR_ATTACK_U85H.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_ATTACK_U85H.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_ATTACK_U85H);
    knob_COMPRESSOR_RELEASE_U85H.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_RELEASE_U85H.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_COMPRESSOR_RELEASE_U85H.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_RELEASE_U85H); lbl_COMPRESSOR_RELEASE_U85H.setText("Compressor Release",juce::dontSendNotification); lbl_COMPRESSOR_RELEASE_U85H.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_RELEASE_U85H.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_RELEASE_U85H);
    knob_COMPRESSOR_MAKEUP_U85H.setSliderStyle(juce::Slider::Rotary); knob_COMPRESSOR_MAKEUP_U85H.setTextBoxStyle(juce::Slider::TextBoxBelow,false,78,14); knob_COMPRESSOR_MAKEUP_U85H.setLookAndFeel(&lnf); addAndMakeVisible(knob_COMPRESSOR_MAKEUP_U85H); lbl_COMPRESSOR_MAKEUP_U85H.setText("Compressor Makeup",juce::dontSendNotification); lbl_COMPRESSOR_MAKEUP_U85H.setJustificationType(juce::Justification::centred); lbl_COMPRESSOR_MAKEUP_U85H.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); addAndMakeVisible(lbl_COMPRESSOR_MAKEUP_U85H);
}
VelvetAudioProcessorEditor::~VelvetAudioProcessorEditor() { setLookAndFeel(nullptr); }
void VelvetAudioProcessorEditor::paint(juce::Graphics& g) {
    g.fillAll(juce::Colour(0xff0d1117));
    g.setColour(juce::Colour(0xff161b22)); g.fillRect(0,0,getWidth(),44);
    g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.5f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.5f,juce::Font::bold));
    g.drawText("ARCHERGATE",16,4,getWidth()-32,14,juce::Justification::left);
    g.setColour(juce::Colour(0xff4d8bff)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),14.f,juce::Font::bold));
    g.drawText("VELVET",16,18,getWidth()-32,20,juce::Justification::centred);
    g.setColour(juce::Colour(0xff161b22)); g.fillRect(0,44,getWidth(),20); g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.55f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); g.drawText("DELAY",20,44,getWidth()-40,20,juce::Justification::centredLeft,false);
    g.setColour(juce::Colour(0xff161b22)); g.fillRect(0,148,getWidth(),20); g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.55f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); g.drawText("GAIN",20,148,getWidth()-40,20,juce::Justification::centredLeft,false);
    g.setColour(juce::Colour(0xff161b22)); g.fillRect(0,252,getWidth(),20); g.setColour(juce::Colour(0xffe8eaf0).withAlpha(0.55f)); g.setFont(juce::Font(juce::Font::getDefaultSansSerifFontName(),9.0f,juce::Font::bold)); g.drawText("COMPRESSOR",20,252,getWidth()-40,20,juce::Justification::centredLeft,false);
}
void VelvetAudioProcessorEditor::resized() {
    knob_DELAY_DELAY_MS_90YB.setBounds(20,64,82,58); lbl_DELAY_DELAY_MS_90YB.setBounds(20,122,82,14);
    knob_DELAY_FEEDBACK_90YB.setBounds(102,64,82,58); lbl_DELAY_FEEDBACK_90YB.setBounds(102,122,82,14);
    knob_DELAY_MIX_90YB.setBounds(184,64,82,58); lbl_DELAY_MIX_90YB.setBounds(184,122,82,14);
    knob_GAIN_GAIN_DB_N0FJ.setBounds(20,168,82,58); lbl_GAIN_GAIN_DB_N0FJ.setBounds(20,226,82,14);
    knob_COMPRESSOR_THRESHOLD_U85H.setBounds(20,272,82,58); lbl_COMPRESSOR_THRESHOLD_U85H.setBounds(20,330,82,14);
    knob_COMPRESSOR_RATIO_U85H.setBounds(102,272,82,58); lbl_COMPRESSOR_RATIO_U85H.setBounds(102,330,82,14);
    knob_COMPRESSOR_ATTACK_U85H.setBounds(184,272,82,58); lbl_COMPRESSOR_ATTACK_U85H.setBounds(184,330,82,14);
    knob_COMPRESSOR_RELEASE_U85H.setBounds(266,272,82,58); lbl_COMPRESSOR_RELEASE_U85H.setBounds(266,330,82,14);
    knob_COMPRESSOR_MAKEUP_U85H.setBounds(20,348,82,58); lbl_COMPRESSOR_MAKEUP_U85H.setBounds(20,406,82,14);
}
