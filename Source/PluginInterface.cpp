/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginInterface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginInterface::PluginInterface (PhaserWahAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (freq1 = new Slider ("new slider"));
    freq1->setRange (20, 10000, 0);
    freq1->setSliderStyle (Slider::Rotary);
    freq1->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freq1->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Freq")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (width1 = new Slider ("new slider"));
    width1->setRange (0, 1, 0);
    width1->setSliderStyle (Slider::Rotary);
    width1->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    width1->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Width")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (moddepth = new Slider ("new slider"));
    moddepth->setRange (0, 1, 0);
    moddepth->setSliderStyle (Slider::Rotary);
    moddepth->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    moddepth->addListener (this);

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Mod depth")));
    label3->setFont (Font (15.00f, Font::plain));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modfreq = new Slider ("new slider"));
    modfreq->setRange (0.01, 40, 0);
    modfreq->setSliderStyle (Slider::Rotary);
    modfreq->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modfreq->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Mod freq")));
    label4->setFont (Font (15.00f, Font::plain));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (mix = new Slider ("new slider"));
    mix->setRange (0, 10, 0);
    mix->setSliderStyle (Slider::Rotary);
    mix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mix->addListener (this);

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Mix")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (freq2 = new Slider ("new slider"));
    freq2->setRange (20, 10000, 0);
    freq2->setSliderStyle (Slider::Rotary);
    freq2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freq2->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Freq")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (width2 = new Slider ("new slider"));
    width2->setRange (0, 1, 0);
    width2->setSliderStyle (Slider::Rotary);
    width2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    width2->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Width")));
    label7->setFont (Font (15.00f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (freq3 = new Slider ("new slider"));
    freq3->setRange (20, 10000, 0);
    freq3->setSliderStyle (Slider::Rotary);
    freq3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freq3->addListener (this);

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("Freq")));
    label8->setFont (Font (15.00f, Font::plain));
    label8->setJustificationType (Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (width3 = new Slider ("new slider"));
    width3->setRange (0, 1, 0);
    width3->setSliderStyle (Slider::Rotary);
    width3->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    width3->addListener (this);

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Width")));
    label9->setFont (Font (15.00f, Font::plain));
    label9->setJustificationType (Justification::centred);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (freq4 = new Slider ("new slider"));
    freq4->setRange (20, 10000, 0);
    freq4->setSliderStyle (Slider::Rotary);
    freq4->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    freq4->addListener (this);

    addAndMakeVisible (label10 = new Label ("new label",
                                            TRANS("Freq")));
    label10->setFont (Font (15.00f, Font::plain));
    label10->setJustificationType (Justification::centred);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (width4 = new Slider ("new slider"));
    width4->setRange (0, 1, 0);
    width4->setSliderStyle (Slider::Rotary);
    width4->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    width4->addListener (this);

    addAndMakeVisible (label11 = new Label ("new label",
                                            TRANS("Width")));
    label11->setFont (Font (15.00f, Font::plain));
    label11->setJustificationType (Justification::centred);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (300, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginInterface::~PluginInterface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    freq1 = nullptr;
    label = nullptr;
    width1 = nullptr;
    label2 = nullptr;
    moddepth = nullptr;
    label3 = nullptr;
    modfreq = nullptr;
    label4 = nullptr;
    mix = nullptr;
    label5 = nullptr;
    freq2 = nullptr;
    label6 = nullptr;
    width2 = nullptr;
    label7 = nullptr;
    freq3 = nullptr;
    label8 = nullptr;
    width3 = nullptr;
    label9 = nullptr;
    freq4 = nullptr;
    label10 = nullptr;
    width4 = nullptr;
    label11 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginInterface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginInterface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    freq1->setBounds (8, 8, 49, 64);
    label->setBounds (8 + 0, 72, roundFloatToInt (49 * 1.0000f), 24);
    width1->setBounds (8 + 0, 93, roundFloatToInt (49 * 1.0000f), 64);
    label2->setBounds ((8 + 0) + 0, 157, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    moddepth->setBounds (80, 208, roundFloatToInt (49 * 1.0000f), 64);
    label3->setBounds (64, 272, 80, 24);
    modfreq->setBounds (157, 208, roundFloatToInt (49 * 1.0000f), 64);
    label4->setBounds (141, 272, 80, 24);
    mix->setBounds (216, 208, 64, 64);
    label5->setBounds (232, 264, 31, 24);
    freq2->setBounds (77, 8, 49, 64);
    label6->setBounds (8 + 69, 72, roundFloatToInt (49 * 1.0000f), 24);
    width2->setBounds (8 + 69, 93, roundFloatToInt (49 * 1.0000f), 64);
    label7->setBounds ((8 + 0) + 69, 157, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    freq3->setBounds (144, 9, 49, 64);
    label8->setBounds (8 + 136, 73, roundFloatToInt (49 * 1.0000f), 24);
    width3->setBounds (8 + 136, 94, roundFloatToInt (49 * 1.0000f), 64);
    label9->setBounds ((8 + 0) + 136, 158, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    freq4->setBounds (208, 8, 49, 64);
    label10->setBounds (8 + 200, 72, roundFloatToInt (49 * 1.0000f), 24);
    width4->setBounds (8 + 200, 96, roundFloatToInt (49 * 1.0000f), 64);
    label11->setBounds ((8 + 0) + 200, 160, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginInterface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == freq1)
    {
        //[UserSliderCode_freq1] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_FREQ1,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_freq1]
    }
    else if (sliderThatWasMoved == width1)
    {
        //[UserSliderCode_width1] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_WIDTH1,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_width1]
    }
    else if (sliderThatWasMoved == moddepth)
    {
        //[UserSliderCode_moddepth] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::MOD_DEPTH,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_moddepth]
    }
    else if (sliderThatWasMoved == modfreq)
    {
        //[UserSliderCode_modfreq] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::MOD_FREQ,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_modfreq]
    }
    else if (sliderThatWasMoved == mix)
    {
        //[UserSliderCode_mix] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::MIX,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_mix]
    }
    else if (sliderThatWasMoved == freq2)
    {
        //[UserSliderCode_freq2] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_FREQ2,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_freq2]
    }
    else if (sliderThatWasMoved == width2)
    {
        //[UserSliderCode_width2] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_WIDTH2,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_width2]
    }
    else if (sliderThatWasMoved == freq3)
    {
        //[UserSliderCode_freq3] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_FREQ3,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_freq3]
    }
    else if (sliderThatWasMoved == width3)
    {
        //[UserSliderCode_width3] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_WIDTH3,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_width3]
    }
    else if (sliderThatWasMoved == freq4)
    {
        //[UserSliderCode_freq4] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_FREQ4,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_freq4]
    }
    else if (sliderThatWasMoved == width4)
    {
        //[UserSliderCode_width4] -- add your slider handling code here..
        processor.setParameterNotifyingHost(PhaserWahAudioProcessor::BAND_WIDTH4,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_width4]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginInterface" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="PhaserWahAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="300" initialHeight="300">
  <BACKGROUND backgroundColour="ffffffff"/>
  <SLIDER name="new slider" id="6f801a8b6732fcf6" memberName="freq1" virtualName=""
          explicitFocusOrder="0" pos="8 8 49 64" min="20" max="10000" int="0"
          style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="55db614b1ede7601" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="ef41dbafc2b42ab0" memberName="width1" virtualName=""
          explicitFocusOrder="0" pos="0 93 100% 64" posRelativeX="6f801a8b6732fcf6"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          min="0" max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="d9460c7a1c6e8f0b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 157 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="2a9863d0dfb16477" memberName="moddepth"
          virtualName="" explicitFocusOrder="0" pos="80 208 100% 64" posRelativeW="6f801a8b6732fcf6"
          posRelativeH="6f801a8b6732fcf6" min="0" max="1" int="0" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="46edccb945a09ab" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="64 272 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="d7a81e361dca4a9f" memberName="modfreq"
          virtualName="" explicitFocusOrder="0" pos="157 208 100% 64" posRelativeW="6f801a8b6732fcf6"
          posRelativeH="6f801a8b6732fcf6" min="0.010000000000000000208"
          max="40" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="55f7090f429ea60d" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="141 272 80 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mod freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="eb5c080c6c96c98c" memberName="mix" virtualName=""
          explicitFocusOrder="0" pos="216 208 64 64" min="0" max="10" int="0"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4424775d4d900f55" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="232 264 31 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Mix" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="new slider" id="ec1ad9429a64df37" memberName="freq2" virtualName=""
          explicitFocusOrder="0" pos="77 8 49 64" min="20" max="10000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="75705ee4a87a546f" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="69 72 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="f1fb1887848bb254" memberName="width2" virtualName=""
          explicitFocusOrder="0" pos="69 93 100% 64" posRelativeX="6f801a8b6732fcf6"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          min="0" max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="fe72734cb4e58011" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="69 157 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="5ef844054a5b0a17" memberName="freq3" virtualName=""
          explicitFocusOrder="0" pos="144 9 49 64" min="20" max="10000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="b19b08fadd164df2" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="136 73 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b4955c3384463ae2" memberName="width3" virtualName=""
          explicitFocusOrder="0" pos="136 94 100% 64" posRelativeX="6f801a8b6732fcf6"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          min="0" max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="41176fb17352422e" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="136 158 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="76cd2831f9de41e4" memberName="freq4" virtualName=""
          explicitFocusOrder="0" pos="208 8 49 64" min="20" max="10000"
          int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="c8b2f2960dbfe000" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="200 72 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Freq" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="d42a7b1fd2ca3b67" memberName="width4" virtualName=""
          explicitFocusOrder="0" pos="200 96 100% 64" posRelativeX="6f801a8b6732fcf6"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          min="0" max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="41a70fbfad1d3e38" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="200 160 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Width" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
