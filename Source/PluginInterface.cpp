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
PluginInterface::PluginInterface (TremuluxAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    addAndMakeVisible (modRateDial1 = new Slider ("new slider"));
    modRateDial1->setRange (0, 1, 0);
    modRateDial1->setSliderStyle (Slider::Rotary);
    modRateDial1->setTextBoxStyle (Slider::NoTextBox, true, 80, 20);
    modRateDial1->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modRateDial1->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modRateDial1->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Rate")));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepth1 = new Slider ("new slider"));
    modDepth1->setRange (0, 1, 0);
    modDepth1->setSliderStyle (Slider::Rotary);
    modDepth1->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modDepth1->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modDepth1->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modDepth1->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Depth")));
    label2->setFont (Font (15.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (mix = new Slider ("new slider"));
    mix->setRange (0, 10, 0);
    mix->setSliderStyle (Slider::Rotary);
    mix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mix->setColour (Slider::trackColourId, Colours::bisque);
    mix->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    mix->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    mix->addListener (this);

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Mix")));
    label5->setFont (Font (15.00f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modRateDial2 = new Slider ("new slider"));
    modRateDial2->setRange (0, 100, 0);
    modRateDial2->setSliderStyle (Slider::Rotary);
    modRateDial2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    modRateDial2->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modRateDial2->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modRateDial2->addListener (this);

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Rate")));
    label6->setFont (Font (15.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepth2 = new Slider ("new slider"));
    modDepth2->setRange (0, 1, 0);
    modDepth2->setSliderStyle (Slider::Rotary);
    modDepth2->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    modDepth2->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modDepth2->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modDepth2->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Depth")));
    label7->setFont (Font (15.00f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modSyncButton1 = new ToggleButton ("new toggle button"));
    modSyncButton1->setButtonText (TRANS("Sync"));
    modSyncButton1->addListener (this);
    modSyncButton1->setToggleState (true, dontSendNotification);

    addAndMakeVisible (modSyncButton2 = new ToggleButton ("new toggle button"));
    modSyncButton2->setButtonText (TRANS("Sync"));
    modSyncButton2->addListener (this);
    modSyncButton2->setToggleState (true, dontSendNotification);

    addAndMakeVisible (modFreqLabel1 = new Label ("new label",
                                                  TRANS("Hello World")));
    modFreqLabel1->setFont (Font (10.00f, Font::plain));
    modFreqLabel1->setJustificationType (Justification::centred);
    modFreqLabel1->setEditable (false, false, false);
    modFreqLabel1->setColour (Label::backgroundColourId, Colours::white);
    modFreqLabel1->setColour (Label::outlineColourId, Colours::grey);
    modFreqLabel1->setColour (TextEditor::textColourId, Colours::black);
    modFreqLabel1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modFreqLabel2 = new Label ("new label",
                                                  TRANS("Hello World")));
    modFreqLabel2->setFont (Font (10.00f, Font::plain));
    modFreqLabel2->setJustificationType (Justification::centred);
    modFreqLabel2->setEditable (false, false, false);
    modFreqLabel2->setColour (Label::backgroundColourId, Colours::white);
    modFreqLabel2->setColour (Label::outlineColourId, Colours::grey);
    modFreqLabel2->setColour (TextEditor::textColourId, Colours::black);
    modFreqLabel2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (128, 300);


    //[Constructor] You can add your own custom stuff here..
    setRateDialRanges(processor.freqDialRange);
    /*typedef enum {
     OFF = 0,

     TWO_BARS,
     ONE_BAR,
     HALF,
     DOTTED_QUARTER,
     QUARTER,
     TRIPLET_QUARTER,
     DOTTED_EIGHTH,
     EIGHTH,
     TRIPLET_EIGHTH,
     DOTTED_SIXTEENTH,
     SIXTEENTH,
     TRIPLET_SIXTEENTH,

     NUM_SYNC_OPTIONS
     } SYNC_OPTIONS;*/
    syncModeLabels.add("NULL");
    syncModeLabels.add("Two Bars");
    syncModeLabels.add("One Bar");
    syncModeLabels.add("1/2");
    syncModeLabels.add("Dotted 1/4");
    syncModeLabels.add("1/4");
    syncModeLabels.add("1/4 Triplet");
    syncModeLabels.add("Dotted 1/8");
    syncModeLabels.add("1/8");
    syncModeLabels.add("1/8 Triplet");
    syncModeLabels.add("Dotted 1/16");
    syncModeLabels.add("1/16");
    syncModeLabels.add("1/16 Triplet");

    //[/Constructor]
}

PluginInterface::~PluginInterface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    modRateDial1 = nullptr;
    label = nullptr;
    modDepth1 = nullptr;
    label2 = nullptr;
    mix = nullptr;
    label5 = nullptr;
    modRateDial2 = nullptr;
    label6 = nullptr;
    modDepth2 = nullptr;
    label7 = nullptr;
    modSyncButton1 = nullptr;
    modSyncButton2 = nullptr;
    modFreqLabel1 = nullptr;
    modFreqLabel2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginInterface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::beige);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginInterface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    modRateDial1->setBounds (8, 0, 49, 64);
    label->setBounds (8 + 0, 72, roundFloatToInt (49 * 1.0000f), 24);
    modDepth1->setBounds (8 + 0, 93, roundFloatToInt (49 * 1.0000f), 64);
    label2->setBounds ((8 + 0) + 0, 157, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    mix->setBounds (40, 224, 48, 64);
    label5->setBounds (40 + 0, 224 + 48, roundFloatToInt (48 * 1.0000f), 24);
    modRateDial2->setBounds (72, 0, 49, 64);
    label6->setBounds (72 + 0, 72, roundFloatToInt (49 * 1.0000f), 24);
    modDepth2->setBounds (72 + 0, 93, roundFloatToInt (49 * 1.0000f), 64);
    label7->setBounds ((72 + 0) + 0, 157, roundFloatToInt ((roundFloatToInt (49 * 1.0000f)) * 1.0000f), 24);
    modSyncButton1->setBounds (8 + 0, 192, roundFloatToInt (49 * 1.0000f), 24);
    modSyncButton2->setBounds (72 + 0, 192, roundFloatToInt (49 * 1.0000f), 24);
    modFreqLabel1->setBounds (8 + 0, 56, roundFloatToInt (49 * 1.0000f), 20);
    modFreqLabel2->setBounds (72 + 0, 56, roundFloatToInt (49 * 1.0000f), 20);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void PluginInterface::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    String displayText;
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == modRateDial1)
    {
        //[UserSliderCode_modRateDial1] -- add your slider handling code here..
        int mode = 0, currentlySynced = modSyncButton1->getToggleState();
        if(currentlySynced){
            //sync activated, quantize value
            mode = (int)(sliderThatWasMoved->getValue() * 10) + 1;
            sliderThatWasMoved->setValue(mode * 0.1);
        }
        float freqDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC1, mode);
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_RATE_DIAL1,
                                            freqDialValue);
        displayText = (currentlySynced)?syncModeLabels.getReference(mode):
        String(processor.minFreeRate + (freqDialValue * processor.oneOverFreqDialRange) * (processor.maxFreeRate - processor.minFreeRate), 2) + " Hz";
        modFreqLabel1->setText(displayText, juce::NotificationType::sendNotification);
        //[/UserSliderCode_modRateDial1]
    }
    else if (sliderThatWasMoved == modDepth1)
    {
        //[UserSliderCode_modDepth1] -- add your slider handling code here..
        processor.setParameter(TremuluxAudioProcessor::MOD_DEPTH1,
                               sliderThatWasMoved->getValue());
        //[/UserSliderCode_modDepth1]
    }
    else if (sliderThatWasMoved == mix)
    {
        //[UserSliderCode_mix] -- add your slider handling code here..
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MIX,
                                            sliderThatWasMoved->getValue());
        //[/UserSliderCode_mix]
    }
    else if (sliderThatWasMoved == modRateDial2)
    {
        //[UserSliderCode_modRateDial2] -- add your slider handling code here..
        int mode = 0, currentlySynced = modSyncButton2->getToggleState();
        if(modSyncButton2->getToggleState()){
            //sync activated, quantize value
            mode = (int)(sliderThatWasMoved->getValue() * 10);
            sliderThatWasMoved->setValue(mode * 0.1);
        }
        float freqDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC2, mode);
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_RATE_DIAL2,
                                            freqDialValue);
        displayText = (currentlySynced)?syncModeLabels.getReference(mode):
        String(processor.minFreeRate + (freqDialValue * processor.oneOverFreqDialRange) * (processor.maxFreeRate - processor.minFreeRate), 2) + " Hz";
        modFreqLabel2->setText(displayText, juce::NotificationType::sendNotification);

        //[/UserSliderCode_modRateDial2]
    }
    else if (sliderThatWasMoved == modDepth2)
    {
        //[UserSliderCode_modDepth2] -- add your slider handling code here..
        processor.setParameter(TremuluxAudioProcessor::MOD_DEPTH2,
                               sliderThatWasMoved->getValue());
        //[/UserSliderCode_modDepth2]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void PluginInterface::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    const int currentlySynced = buttonThatWasClicked->getToggleState();
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == modSyncButton1)
    {
        //[UserButtonCode_modSyncButton1] -- add your button handler code here..
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC_BUTTON1,
                                            currentlySynced);
        if(currentlySynced){
            lastUnsyncedFreqs[0] = modRateDial1->getValue();
        }
        else{
            modRateDial1->setValue(lastUnsyncedFreqs[0]);
        }
        sliderValueChanged(modRateDial1);
        //[/UserButtonCode_modSyncButton1]
    }
    else if (buttonThatWasClicked == modSyncButton2)
    {
        //[UserButtonCode_modSyncButton2] -- add your button handler code here..
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC_BUTTON2,
                                            currentlySynced);
        if(currentlySynced){
            lastUnsyncedFreqs[0] = modRateDial1->getValue();
        }
        else{
            modRateDial1->setValue(lastUnsyncedFreqs[0]);
        }
        sliderValueChanged(modRateDial2);
        //[/UserButtonCode_modSyncButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginInterface::setRateDialRanges(const float max){
    modRateDial1->setRange (0.1, max, 0);
    modRateDial2->setRange (0.1, max, 0);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginInterface" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="TremuluxAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="128" initialHeight="300">
  <BACKGROUND backgroundColour="fff5f5dc"/>
  <SLIDER name="new slider" id="6f801a8b6732fcf6" memberName="modRateDial1"
          virtualName="" explicitFocusOrder="0" pos="8 0 49 64" rotarysliderfill="ff401010"
          rotaryslideroutline="ff401010" min="0" max="1" int="0" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="55db614b1ede7601" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="ef41dbafc2b42ab0" memberName="modDepth1"
          virtualName="" explicitFocusOrder="0" pos="0 93 100% 64" posRelativeX="6f801a8b6732fcf6"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          rotarysliderfill="ff401010" rotaryslideroutline="ff401010" min="0"
          max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="d9460c7a1c6e8f0b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 157 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="eb5c080c6c96c98c" memberName="mix" virtualName=""
          explicitFocusOrder="0" pos="40 224 48 64" trackcol="ffffe4c4"
          rotarysliderfill="ff401010" rotaryslideroutline="ff401010" min="0"
          max="10" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4424775d4d900f55" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 48 100% 24" posRelativeX="eb5c080c6c96c98c"
         posRelativeY="eb5c080c6c96c98c" posRelativeW="eb5c080c6c96c98c"
         edTextCol="ff000000" edBkgCol="0" labelText="Mix" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="ec1ad9429a64df37" memberName="modRateDial2"
          virtualName="" explicitFocusOrder="0" pos="72 0 49 64" rotarysliderfill="ff401010"
          rotaryslideroutline="ff401010" min="0" max="100" int="0" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="75705ee4a87a546f" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="ec1ad9429a64df37"
         posRelativeW="6f801a8b6732fcf6" edTextCol="ff000000" edBkgCol="0"
         labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="f1fb1887848bb254" memberName="modDepth2"
          virtualName="" explicitFocusOrder="0" pos="0 93 100% 64" posRelativeX="ec1ad9429a64df37"
          posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
          rotarysliderfill="ff401010" rotaryslideroutline="ff401010" min="0"
          max="1" int="0" style="Rotary" textBoxPos="TextBoxBelow" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="fe72734cb4e58011" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="0 157 100% 24" posRelativeX="f1fb1887848bb254"
         posRelativeW="ef41dbafc2b42ab0" edTextCol="ff000000" edBkgCol="0"
         labelText="Depth" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="918a6ddd08824de" memberName="modSyncButton1"
                virtualName="" explicitFocusOrder="0" pos="0 192 100% 24" posRelativeX="6f801a8b6732fcf6"
                posRelativeW="6f801a8b6732fcf6" posRelativeH="6f801a8b6732fcf6"
                buttonText="Sync" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <TOGGLEBUTTON name="new toggle button" id="b200103104a767ac" memberName="modSyncButton2"
                virtualName="" explicitFocusOrder="0" pos="0 192 100% 24" posRelativeX="ec1ad9429a64df37"
                posRelativeW="ec1ad9429a64df37" posRelativeH="ec1ad9429a64df37"
                buttonText="Sync" connectedEdges="0" needsCallback="1" radioGroupId="0"
                state="1"/>
  <LABEL name="new label" id="a734cb7cd6d90437" memberName="modFreqLabel1"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="6f801a8b6732fcf6"
         posRelativeW="6f801a8b6732fcf6" bkgCol="ffffffff" outlineCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="ee16f8f0ca36b4a1" memberName="modFreqLabel2"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="ec1ad9429a64df37"
         posRelativeW="ec1ad9429a64df37" bkgCol="ffffffff" outlineCol="ff808080"
         edTextCol="ff000000" edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
