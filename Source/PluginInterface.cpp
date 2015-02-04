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
    label->setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xff401010));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepth1 = new Slider ("new slider"));
    modDepth1->setRange (0, 1, 0);
    modDepth1->setSliderStyle (Slider::Rotary);
    modDepth1->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    modDepth1->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modDepth1->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modDepth1->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Depth")));
    label2->setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (Label::textColourId, Colour (0xff401010));
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (mix = new Slider ("new slider"));
    mix->setRange (0, 1, 0);
    mix->setSliderStyle (Slider::Rotary);
    mix->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    mix->setColour (Slider::trackColourId, Colours::bisque);
    mix->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    mix->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    mix->addListener (this);

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Mix")));
    label5->setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (Label::textColourId, Colour (0xff401010));
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
    label6->setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (Label::textColourId, Colour (0xff401010));
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepth2 = new Slider ("new slider"));
    modDepth2->setRange (0, 1, 0);
    modDepth2->setSliderStyle (Slider::Rotary);
    modDepth2->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    modDepth2->setColour (Slider::rotarySliderFillColourId, Colour (0xff401010));
    modDepth2->setColour (Slider::rotarySliderOutlineColourId, Colour (0xff401010));
    modDepth2->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("Depth")));
    label7->setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (Label::textColourId, Colour (0xff401010));
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modSyncButton1 = new ToggleButton ("new toggle button"));
    modSyncButton1->setButtonText (TRANS("Sync"));
    modSyncButton1->addListener (this);
    modSyncButton1->setColour (ToggleButton::textColourId, Colour (0xff401010));

    addAndMakeVisible (modSyncButton2 = new ToggleButton ("new toggle button"));
    modSyncButton2->setButtonText (TRANS("Sync"));
    modSyncButton2->addListener (this);
    modSyncButton2->setColour (ToggleButton::textColourId, Colour (0xff401010));

    addAndMakeVisible (modFreqText1 = new Label ("new label",
                                                 TRANS("Hello World")));
    modFreqText1->setFont (Font (10.00f, Font::bold));
    modFreqText1->setJustificationType (Justification::centred);
    modFreqText1->setEditable (false, false, false);
    modFreqText1->setColour (Label::backgroundColourId, Colours::white);
    modFreqText1->setColour (Label::textColourId, Colour (0xff401010));
    modFreqText1->setColour (Label::outlineColourId, Colour (0xff401010));
    modFreqText1->setColour (TextEditor::textColourId, Colours::black);
    modFreqText1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modFreqText2 = new Label ("new label",
                                                 TRANS("Hello World")));
    modFreqText2->setFont (Font (10.00f, Font::bold));
    modFreqText2->setJustificationType (Justification::centred);
    modFreqText2->setEditable (false, false, false);
    modFreqText2->setColour (Label::backgroundColourId, Colours::white);
    modFreqText2->setColour (Label::textColourId, Colour (0xff401010));
    modFreqText2->setColour (Label::outlineColourId, Colour (0xff401010));
    modFreqText2->setColour (TextEditor::textColourId, Colours::black);
    modFreqText2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepthText1 = new Label ("new label",
                                                  TRANS("Hello World")));
    modDepthText1->setFont (Font (10.00f, Font::bold));
    modDepthText1->setJustificationType (Justification::centred);
    modDepthText1->setEditable (false, false, false);
    modDepthText1->setColour (Label::backgroundColourId, Colours::white);
    modDepthText1->setColour (Label::textColourId, Colour (0xff401010));
    modDepthText1->setColour (Label::outlineColourId, Colour (0xff401010));
    modDepthText1->setColour (TextEditor::textColourId, Colours::black);
    modDepthText1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (modDepthText2 = new Label ("new label",
                                                  TRANS("Hello World")));
    modDepthText2->setFont (Font (10.00f, Font::bold));
    modDepthText2->setJustificationType (Justification::centred);
    modDepthText2->setEditable (false, false, false);
    modDepthText2->setColour (Label::backgroundColourId, Colours::white);
    modDepthText2->setColour (Label::textColourId, Colour (0xff401010));
    modDepthText2->setColour (Label::outlineColourId, Colour (0xff401010));
    modDepthText2->setColour (TextEditor::textColourId, Colours::black);
    modDepthText2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (mixText = new Label ("new label",
                                            TRANS("Hello World")));
    mixText->setFont (Font (10.00f, Font::bold));
    mixText->setJustificationType (Justification::centred);
    mixText->setEditable (false, false, false);
    mixText->setColour (Label::backgroundColourId, Colours::white);
    mixText->setColour (Label::textColourId, Colour (0xff401010));
    mixText->setColour (Label::outlineColourId, Colour (0xff401010));
    mixText->setColour (TextEditor::textColourId, Colours::black);
    mixText->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (336, 344);


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

    mix->setValue(0.5);
    //sliderValueChanged(mix);

    modDepth1->setValue(0.5);
    modSyncButton1->setToggleState(true, juce::NotificationType::sendNotification);
    modRateDial1->setValue(5.0);

    modDepth2->setValue(0.5);
    modSyncButton2->setToggleState(true, juce::NotificationType::sendNotification);
    modRateDial2->setValue(8.0);

    startTimer(200);
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
    modFreqText1 = nullptr;
    modFreqText2 = nullptr;
    modDepthText1 = nullptr;
    modDepthText2 = nullptr;
    mixText = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void PluginInterface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::beige);

    g.setColour (Colour (0x102a40a5));
    g.fillRoundedRectangle (8.0f, 88.0f, 216.0f, 120.0f, 4.000f);

    g.setColour (Colour (0xff401010));
    g.drawRoundedRectangle (8.0f, 88.0f, 216.0f, 120.0f, 4.000f, 0.500f);

    g.setColour (Colour (0x102a40a5));
    g.fillRoundedRectangle (9.0f, 216.0f, 216.0f, 120.0f, 4.000f);

    g.setColour (Colour (0xff401010));
    g.drawRoundedRectangle (9.0f, 216.0f, 216.0f, 120.0f, 4.000f, 0.500f);

    g.setColour (Colour (0x102a40a5));
    g.fillRoundedRectangle (232.0f, 88.0f, 96.0f, 248.0f, 4.000f);

    g.setColour (Colour (0xff401010));
    g.drawRoundedRectangle (232.0f, 88.0f, 96.0f, 248.0f, 4.000f, 0.500f);

    g.setColour (Colour (0x102a40a5));
    g.fillRoundedRectangle (10.0f, 8.0f, 317.0f, 71.0f, 4.000f);

    g.setColour (Colour (0xff401010));
    g.drawRoundedRectangle (10.0f, 8.0f, 317.0f, 71.0f, 4.000f, 0.500f);

    g.setColour (Colour (0xff401010));
    g.setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    g.drawText (TRANS("Modulator 1"),
                8, 88, 216, 24,
                Justification::centred, true);

    g.setColour (Colour (0xff401010));
    g.setFont (Font (Font::getDefaultMonospacedFontName(), 16.00f, Font::plain));
    g.drawText (TRANS("Modulator 2"),
                8, 216, 216, 24,
                Justification::centred, true);

    g.setColour (Colour (0xff401010));
    g.setFont (Font (Font::getDefaultMonospacedFontName(), 24.00f, Font::plain));
    g.drawText (TRANS("Master"),
                233, 95, 96, 24,
                Justification::centred, true);

    g.setGradientFill (ColourGradient (Colours::grey,
                                       static_cast<float> (proportionOfWidth (0.7500f)), static_cast<float> (proportionOfHeight (0.2500f)),
                                       Colours::aliceblue,
                                       static_cast<float> (proportionOfWidth (0.2500f)), static_cast<float> (proportionOfHeight (0.7500f)),
                                       false));
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginInterface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    modRateDial1->setBounds (24, 112, 56, 56);
    label->setBounds (24 + 0, 112 + 72, roundFloatToInt (56 * 1.0000f), 24);
    modDepth1->setBounds (24 + 72, 112 + 0, roundFloatToInt (56 * 1.0000f), roundFloatToInt (56 * 1.0000f));
    label2->setBounds ((24 + 72) + 0, (112 + 0) + 72, roundFloatToInt ((roundFloatToInt (56 * 1.0000f)) * 1.0000f), 24);
    mix->setBounds (248, 176, 64, 64);
    label5->setBounds (248 + 0, 176 + 80, roundFloatToInt (64 * 1.0000f), 24);
    modRateDial2->setBounds (24, 240, 56, 56);
    label6->setBounds (24 + 0, 240 + 72, roundFloatToInt (56 * 1.0000f), 24);
    modDepth2->setBounds (24 + 72, 240 + 0, roundFloatToInt (56 * 1.0000f), roundFloatToInt (56 * 1.0000f));
    label7->setBounds ((24 + 72) + 0, (240 + 0) + 72, roundFloatToInt ((roundFloatToInt (56 * 1.0000f)) * 1.0000f), 24);
    modSyncButton1->setBounds ((24 + 72) + 72, 112 + 24, roundFloatToInt (56 * 1.0000f), roundFloatToInt (56 * 0.5000f));
    modSyncButton2->setBounds ((24 + 72) + 72, 240 + 24, roundFloatToInt (56 * 1.0000f), roundFloatToInt (56 * 0.5000f));
    modFreqText1->setBounds (24 + 0, 112 + 56, roundFloatToInt (56 * 1.0000f), 20);
    modFreqText2->setBounds (24 + 0, 240 + 56, roundFloatToInt (56 * 1.0000f), 20);
    modDepthText1->setBounds ((24 + 72) + 0, (112 + 0) + 56, roundFloatToInt ((roundFloatToInt (56 * 1.0000f)) * 1.0000f), 20);
    modDepthText2->setBounds ((24 + 72) + 0, (240 + 0) + 56, roundFloatToInt ((roundFloatToInt (56 * 1.0000f)) * 1.0000f), 20);
    mixText->setBounds (248 + 0, 176 + 64, roundFloatToInt (64 * 1.0000f), 20);
    internalPath1.clear();
    internalPath1.startNewSubPath (18.0f, 26.0f);
    internalPath1.lineTo (48.0f, 26.0f);
    internalPath1.lineTo (47.0f, 31.0f);
    internalPath1.lineTo (37.0f, 31.0f);
    internalPath1.lineTo (34.0f, 58.0f);
    internalPath1.lineTo (54.0f, 58.0f);
    internalPath1.lineTo (53.0f, 62.0f);
    internalPath1.lineTo (24.0f, 62.0f);
    internalPath1.quadraticTo (25.0f, 54.0f, 26.0f, 46.0f);
    internalPath1.quadraticTo (27.0f, 39.0f, 28.0f, 31.0f);
    internalPath1.lineTo (18.0f, 31.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (56.0f, 35.0f);
    internalPath1.quadraticTo (62.0f, 35.0f, 68.0f, 35.0f);
    internalPath1.quadraticTo (75.0f, 35.0f, 81.0f, 35.0f);
    internalPath1.quadraticTo (83.0f, 35.0f, 84.0f, 36.0f);
    internalPath1.quadraticTo (85.0f, 38.0f, 85.0f, 40.0f);
    internalPath1.lineTo (84.0f, 48.0f);
    internalPath1.lineTo (74.0f, 48.0f);
    internalPath1.lineTo (75.0f, 40.0f);
    internalPath1.lineTo (66.0f, 40.0f);
    internalPath1.lineTo (63.0f, 62.0f);
    internalPath1.lineTo (53.0f, 62.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (94.0f, 35.0f);
    internalPath1.lineTo (113.0f, 35.0f);
    internalPath1.quadraticTo (115.0f, 35.0f, 116.0f, 36.0f);
    internalPath1.quadraticTo (118.0f, 38.0f, 117.0f, 40.0f);
    internalPath1.quadraticTo (117.0f, 42.0f, 117.0f, 44.0f);
    internalPath1.quadraticTo (117.0f, 46.0f, 116.0f, 49.0f);
    internalPath1.lineTo (97.0f, 49.0f);
    internalPath1.lineTo (96.0f, 58.0f);
    internalPath1.lineTo (125.0f, 58.0f);
    internalPath1.lineTo (125.0f, 62.0f);
    internalPath1.lineTo (86.0f, 62.0f);
    internalPath1.lineTo (88.0f, 40.0f);
    internalPath1.quadraticTo (88.0f, 38.0f, 90.0f, 36.0f);
    internalPath1.quadraticTo (92.0f, 35.0f, 94.0f, 35.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (108.0f, 40.0f);
    internalPath1.lineTo (98.0f, 40.0f);
    internalPath1.lineTo (97.0f, 44.0f);
    internalPath1.lineTo (107.0f, 44.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (128.0f, 35.0f);
    internalPath1.quadraticTo (139.0f, 35.0f, 149.0f, 35.0f);
    internalPath1.quadraticTo (160.0f, 35.0f, 171.0f, 35.0f);
    internalPath1.quadraticTo (173.0f, 35.0f, 175.0f, 36.0f);
    internalPath1.quadraticTo (176.0f, 38.0f, 176.0f, 40.0f);
    internalPath1.lineTo (174.0f, 58.0f);
    internalPath1.lineTo (184.0f, 58.0f);
    internalPath1.lineTo (183.0f, 62.0f);
    internalPath1.lineTo (173.0f, 62.0f);
    internalPath1.lineTo (164.0f, 62.0f);
    internalPath1.lineTo (166.0f, 40.0f);
    internalPath1.lineTo (156.0f, 40.0f);
    internalPath1.lineTo (154.0f, 62.0f);
    internalPath1.lineTo (144.0f, 62.0f);
    internalPath1.lineTo (147.0f, 40.0f);
    internalPath1.lineTo (137.0f, 40.0f);
    internalPath1.lineTo (134.0f, 62.0f);
    internalPath1.lineTo (125.0f, 62.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (186.0f, 35.0f);
    internalPath1.lineTo (196.0f, 35.0f);
    internalPath1.lineTo (193.0f, 58.0f);
    internalPath1.lineTo (203.0f, 58.0f);
    internalPath1.lineTo (205.0f, 35.0f);
    internalPath1.lineTo (215.0f, 35.0f);
    internalPath1.lineTo (213.0f, 58.0f);
    internalPath1.lineTo (223.0f, 58.0f);
    internalPath1.lineTo (222.0f, 62.0f);
    internalPath1.lineTo (193.0f, 62.0f);
    internalPath1.lineTo (188.0f, 62.0f);
    internalPath1.quadraticTo (186.0f, 62.0f, 185.0f, 61.0f);
    internalPath1.quadraticTo (183.0f, 60.0f, 184.0f, 58.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (226.0f, 26.0f);
    internalPath1.lineTo (236.0f, 26.0f);
    internalPath1.lineTo (232.0f, 58.0f);
    internalPath1.lineTo (242.0f, 58.0f);
    internalPath1.lineTo (242.0f, 62.0f);
    internalPath1.quadraticTo (237.0f, 62.0f, 232.0f, 62.0f);
    internalPath1.quadraticTo (227.0f, 62.0f, 222.0f, 62.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (244.0f, 35.0f);
    internalPath1.lineTo (254.0f, 35.0f);
    internalPath1.lineTo (252.0f, 58.0f);
    internalPath1.lineTo (262.0f, 58.0f);
    internalPath1.lineTo (264.0f, 35.0f);
    internalPath1.lineTo (274.0f, 35.0f);
    internalPath1.lineTo (271.0f, 58.0f);
    internalPath1.lineTo (281.0f, 58.0f);
    internalPath1.lineTo (280.0f, 62.0f);
    internalPath1.lineTo (251.0f, 62.0f);
    internalPath1.lineTo (246.0f, 62.0f);
    internalPath1.quadraticTo (244.0f, 62.0f, 243.0f, 61.0f);
    internalPath1.quadraticTo (242.0f, 60.0f, 242.0f, 58.0f);
    internalPath1.closeSubPath();
    internalPath1.startNewSubPath (283.0f, 35.0f);
    internalPath1.lineTo (293.0f, 35.0f);
    internalPath1.lineTo (292.0f, 44.0f);
    internalPath1.lineTo (302.0f, 44.0f);
    internalPath1.lineTo (303.0f, 35.0f);
    internalPath1.lineTo (313.0f, 35.0f);
    internalPath1.lineTo (312.0f, 42.0f);
    internalPath1.quadraticTo (312.0f, 44.0f, 310.0f, 45.0f);
    internalPath1.quadraticTo (309.0f, 46.0f, 307.0f, 46.0f);
    internalPath1.quadraticTo (309.0f, 46.0f, 310.0f, 48.0f);
    internalPath1.quadraticTo (311.0f, 49.0f, 311.0f, 51.0f);
    internalPath1.lineTo (310.0f, 58.0f);
    internalPath1.lineTo (320.0f, 58.0f);
    internalPath1.lineTo (319.0f, 62.0f);
    internalPath1.lineTo (310.0f, 62.0f);
    internalPath1.lineTo (304.0f, 62.0f);
    internalPath1.lineTo (300.0f, 62.0f);
    internalPath1.lineTo (301.0f, 49.0f);
    internalPath1.lineTo (292.0f, 49.0f);
    internalPath1.lineTo (290.0f, 62.0f);
    internalPath1.lineTo (280.0f, 62.0f);
    internalPath1.lineTo (282.0f, 51.0f);
    internalPath1.quadraticTo (282.0f, 49.0f, 283.0f, 48.0f);
    internalPath1.quadraticTo (285.0f, 46.0f, 287.0f, 46.0f);
    internalPath1.quadraticTo (285.0f, 46.0f, 284.0f, 45.0f);
    internalPath1.quadraticTo (282.0f, 44.0f, 283.0f, 42.0f);
    internalPath1.closeSubPath();

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
            mode = (int)sliderThatWasMoved->getValue();
            sliderThatWasMoved->setValue(mode);
        }
        float freqDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC1, mode);
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_RATE_DIAL1,
                                            freqDialValue);
        displayText = (currentlySynced)?processor.syncModeLabels.getReference(mode):
        String(processor.minFreeRate + (freqDialValue * processor.oneOverFreqDialRange) * (processor.maxFreeRate - processor.minFreeRate), 2) + " Hz";
        modFreqText1->setText(displayText, juce::NotificationType::sendNotification);
        //[/UserSliderCode_modRateDial1]
    }
    else if (sliderThatWasMoved == modDepth1)
    {
        //[UserSliderCode_modDepth1] -- add your slider handling code here..
        float depthDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_DEPTH1,
                               depthDialValue);
        displayText = String(depthDialValue, 2);
        modDepthText1->setText(displayText, juce::NotificationType::sendNotification);
        //[/UserSliderCode_modDepth1]
    }
    else if (sliderThatWasMoved == mix)
    {
        //[UserSliderCode_mix] -- add your slider handling code here..
        float mixDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MIX,
                                            mixDialValue);
        displayText = String(mixDialValue, 2);
        mixText->setText(displayText, juce::NotificationType::sendNotification);
        //[/UserSliderCode_mix]
    }
    else if (sliderThatWasMoved == modRateDial2)
    {
        //[UserSliderCode_modRateDial2] -- add your slider handling code here..
        int mode = 0, currentlySynced = modSyncButton2->getToggleState();
        if(modSyncButton2->getToggleState()){
            //sync activated, quantize value
            mode = (int)sliderThatWasMoved->getValue();
            sliderThatWasMoved->setValue(mode);
        }
        float freqDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_SYNC2, mode);
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_RATE_DIAL2,
                                            freqDialValue);
        displayText = (currentlySynced)?processor.syncModeLabels.getReference(mode):
        String(processor.minFreeRate + (freqDialValue * processor.oneOverFreqDialRange) * (processor.maxFreeRate - processor.minFreeRate), 2) + " Hz";
        modFreqText2->setText(displayText, juce::NotificationType::sendNotification);

        //[/UserSliderCode_modRateDial2]
    }
    else if (sliderThatWasMoved == modDepth2)
    {
        //[UserSliderCode_modDepth2] -- add your slider handling code here..
        float depthDialValue = sliderThatWasMoved->getValue();
        processor.setParameterNotifyingHost(TremuluxAudioProcessor::MOD_DEPTH2,
                               depthDialValue);
        displayText = String(depthDialValue, 2);
        modDepthText2->setText(displayText, juce::NotificationType::sendNotification);
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
            modRateDial1->setValue(lastSyncedFreqs[0]);
        }
        else{
            lastSyncedFreqs[0] = modRateDial1->getValue();
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
            lastUnsyncedFreqs[1] = modRateDial2->getValue();
            modRateDial2->setValue(lastSyncedFreqs[1]);
        }
        else{
            lastSyncedFreqs[1] = modRateDial2->getValue();
            modRateDial2->setValue(lastUnsyncedFreqs[1]);
        }
        sliderValueChanged(modRateDial2);
        //[/UserButtonCode_modSyncButton2]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void PluginInterface::timerCallback(){
    //exchange any data you want between UI elements and the plugin "ourProcessor"
    if(processor.NeedsUIUpdate()){
        //TODO: add bypass button
        //BypassButton->setToggleState(1.0f == processor.getParameter(TremuluxAudioProcessor::BYPASS), false);
        mix->setValue(processor.getParameter(TremuluxAudioProcessor::MIX), juce::dontSendNotification);

        modDepth1->setValue(processor.getParameter(TremuluxAudioProcessor::MOD_DEPTH1), juce::dontSendNotification);
        modRateDial1->setValue(processor.getParameter(TremuluxAudioProcessor::MOD_RATE_DIAL1), juce::dontSendNotification);
        modSyncButton1->setToggleState(processor.getParameter(TremuluxAudioProcessor::MOD_SYNC_BUTTON1),
                                       juce::dontSendNotification);

        modDepth2->setValue(processor.getParameter(TremuluxAudioProcessor::MOD_DEPTH2), juce::dontSendNotification);
        modRateDial2->setValue(processor.getParameter(TremuluxAudioProcessor::MOD_RATE_DIAL2), juce::dontSendNotification);
        modSyncButton2->setToggleState(processor.getParameter(TremuluxAudioProcessor::MOD_SYNC_BUTTON2),
                                       juce::dontSendNotification);

        processor.ClearUIUpdateFlag();
        //std::cout << "UIUpdated" << std::endl;
    }

}

void PluginInterface::setRateDialRanges(const float max){
    modRateDial1->setRange (1.0, max, 0);
    modRateDial2->setRange (1.0, max, 0);
}

void PluginInterface::visibilityChanged(){
    processor.RaiseUIUpdateFlag();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginInterface" componentName=""
                 parentClasses="public AudioProcessorEditor, public Timer" constructorParams="TremuluxAudioProcessor&amp; p"
                 variableInitialisers="AudioProcessorEditor (&amp;p), processor (p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="336" initialHeight="344">
  <BACKGROUND backgroundColour="fff5f5dc">
    <ROUNDRECT pos="8 88 216 120" cornerSize="4" fill="solid: 102a40a5" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff401010"/>
    <ROUNDRECT pos="9 216 216 120" cornerSize="4" fill="solid: 102a40a5" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff401010"/>
    <ROUNDRECT pos="232 88 96 248" cornerSize="4" fill="solid: 102a40a5" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff401010"/>
    <ROUNDRECT pos="10 8 317 71" cornerSize="4" fill="solid: 102a40a5" hasStroke="1"
               stroke="0.5, mitered, butt" strokeColour="solid: ff401010"/>
    <TEXT pos="8 88 216 24" fill="solid: ff401010" hasStroke="0" text="Modulator 1"
          fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="8 216 216 24" fill="solid: ff401010" hasStroke="0" text="Modulator 2"
          fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
          justification="36"/>
    <TEXT pos="233 95 96 24" fill="solid: ff401010" hasStroke="0" text="Master"
          fontname="Default monospaced font" fontsize="24" bold="0" italic="0"
          justification="36"/>
    <PATH pos="0 0 100 100" fill="linear: 75% 25%, 25% 75%, 0=ff808080, 1=fff0f8ff"
          hasStroke="0" nonZeroWinding="1">s 18.35 26.08 l 47.54 26.08 l 47.05 30.57 l 37.33 30.57 l 34.46 57.71 l 53.91 57.71 l 53.43 62.25 l 24.24 62.25 q 25.08 54.33 25.92 46.43 q 26.75 38.53 27.6 30.57 l 17.86 30.57 x s 56.3 35.15 q 62.38 35.15 68.45 35.15 q 74.53 35.15 80.63 35.15 q 82.64 35.15 83.92 36.45 q 85.2 37.75 85.01 39.64 l 84.08 47.73 l 74.34 47.73 l 75.28 39.64 l 65.57 39.64 l 63.15 62.25 l 53.43 62.25 x s 93.56 35.15 l 113.01 35.15 q 115.02 35.15 116.29 36.45 q 117.58 37.75 117.39 39.64 q 117.13 41.92 116.91 44.18 q 116.67 46.43 116.45 48.67 l 96.98 48.67 l 96.01 57.71 l 125.21 57.71 l 124.72 62.25 l 85.7 62.25 l 88.19 39.64 q 88.38 37.75 89.96 36.45 q 91.54 35.15 93.56 35.15 x s 107.66 39.64 l 97.94 39.64 l 97.46 44.18 l 107.18 44.18 x s 127.59 35.15 q 138.53 35.15 149.49 35.15 q 160.43 35.15 171.39 35.15 q 173.41 35.15 174.68 36.45 q 175.96 37.75 175.77 39.64 l 173.87 57.71 l 183.59 57.71 l 183.1 62.25 l 173.39 62.25 l 163.64 62.25 l 166.05 39.64 l 156.31 39.64 l 153.91 62.25 l 144.2 62.25 l 146.58 39.64 l 136.85 39.64 l 134.44 62.25 l 124.72 62.25 x s 186.02 35.15 l 195.76 35.15 l 193.35 57.71 l 203.08 57.71 l 205.49 35.15 l 215.22 35.15 l 212.82 57.71 l 222.55 57.71 l 222.07 62.25 l 192.88 62.25 l 188.02 62.25 q 186 62.25 184.71 60.93 q 183.42 59.59 183.63 57.71 x s 225.91 26.08 l 235.65 26.08 l 232.27 57.71 l 242 57.71 l 241.54 62.25 q 236.65 62.25 231.79 62.25 q 226.91 62.25 222.07 62.25 x s 244.45 35.15 l 254.2 35.15 l 251.79 57.71 l 261.51 57.71 l 263.92 35.15 l 273.65 35.15 l 271.25 57.71 l 280.98 57.71 l 280.5 62.25 l 251.31 62.25 l 246.44 62.25 q 244.43 62.25 243.13 60.93 q 241.85 59.59 242.06 57.71 x s 283.36 35.15 l 293.12 35.15 l 292.15 44.18 l 301.87 44.18 l 302.84 35.15 l 312.57 35.15 l 311.85 41.87 q 311.66 43.69 310.09 45.02 q 308.52 46.36 306.51 46.36 q 308.52 46.36 309.79 47.7 q 311.08 49.02 310.89 50.87 l 310.17 57.71 l 319.9 57.71 l 319.41 62.25 l 309.68 62.25 l 304.19 62.25 l 299.97 62.25 l 301.4 48.67 l 291.67 48.67 l 290.23 62.25 l 280.5 62.25 l 281.71 50.87 q 281.9 49.02 283.47 47.7 q 285.04 46.36 287.06 46.36 q 285.04 46.36 283.75 45.02 q 282.47 43.69 282.66 41.87 x</PATH>
  </BACKGROUND>
  <SLIDER name="new slider" id="6f801a8b6732fcf6" memberName="modRateDial1"
          virtualName="" explicitFocusOrder="0" pos="24 112 56 56" rotarysliderfill="ff401010"
          rotaryslideroutline="ff401010" min="0" max="1" int="0" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="55db614b1ede7601" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="6f801a8b6732fcf6"
         posRelativeY="6f801a8b6732fcf6" posRelativeW="6f801a8b6732fcf6"
         textCol="ff401010" edTextCol="ff000000" edBkgCol="0" labelText="Rate"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
         justification="36"/>
  <SLIDER name="new slider" id="ef41dbafc2b42ab0" memberName="modDepth1"
          virtualName="" explicitFocusOrder="0" pos="72 0 100% 100%" posRelativeX="6f801a8b6732fcf6"
          posRelativeY="6f801a8b6732fcf6" posRelativeW="6f801a8b6732fcf6"
          posRelativeH="6f801a8b6732fcf6" rotarysliderfill="ff401010" rotaryslideroutline="ff401010"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="d9460c7a1c6e8f0b" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="ef41dbafc2b42ab0"
         posRelativeY="ef41dbafc2b42ab0" posRelativeW="ef41dbafc2b42ab0"
         textCol="ff401010" edTextCol="ff000000" edBkgCol="0" labelText="Depth"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
         justification="36"/>
  <SLIDER name="new slider" id="eb5c080c6c96c98c" memberName="mix" virtualName=""
          explicitFocusOrder="0" pos="248 176 64 64" trackcol="ffffe4c4"
          rotarysliderfill="ff401010" rotaryslideroutline="ff401010" min="0"
          max="1" int="0" style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="4424775d4d900f55" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="0 80 100% 24" posRelativeX="eb5c080c6c96c98c"
         posRelativeY="eb5c080c6c96c98c" posRelativeW="eb5c080c6c96c98c"
         textCol="ff401010" edTextCol="ff000000" edBkgCol="0" labelText="Mix"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
         justification="36"/>
  <SLIDER name="new slider" id="ec1ad9429a64df37" memberName="modRateDial2"
          virtualName="" explicitFocusOrder="0" pos="24 240 56 56" rotarysliderfill="ff401010"
          rotaryslideroutline="ff401010" min="0" max="100" int="0" style="Rotary"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="75705ee4a87a546f" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="ec1ad9429a64df37"
         posRelativeY="ec1ad9429a64df37" posRelativeW="6f801a8b6732fcf6"
         textCol="ff401010" edTextCol="ff000000" edBkgCol="0" labelText="Rate"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
         justification="36"/>
  <SLIDER name="new slider" id="f1fb1887848bb254" memberName="modDepth2"
          virtualName="" explicitFocusOrder="0" pos="72 0 100% 100%" posRelativeX="ec1ad9429a64df37"
          posRelativeY="ec1ad9429a64df37" posRelativeW="ec1ad9429a64df37"
          posRelativeH="ec1ad9429a64df37" rotarysliderfill="ff401010" rotaryslideroutline="ff401010"
          min="0" max="1" int="0" style="Rotary" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="fe72734cb4e58011" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="0 72 100% 24" posRelativeX="f1fb1887848bb254"
         posRelativeY="f1fb1887848bb254" posRelativeW="f1fb1887848bb254"
         textCol="ff401010" edTextCol="ff000000" edBkgCol="0" labelText="Depth"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default monospaced font" fontsize="16" bold="0" italic="0"
         justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="918a6ddd08824de" memberName="modSyncButton1"
                virtualName="" explicitFocusOrder="0" pos="72 24 100% 50%" posRelativeX="ef41dbafc2b42ab0"
                posRelativeY="6f801a8b6732fcf6" posRelativeW="6f801a8b6732fcf6"
                posRelativeH="6f801a8b6732fcf6" txtcol="ff401010" buttonText="Sync"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="b200103104a767ac" memberName="modSyncButton2"
                virtualName="" explicitFocusOrder="0" pos="72 24 100% 50%" posRelativeX="f1fb1887848bb254"
                posRelativeY="ec1ad9429a64df37" posRelativeW="ec1ad9429a64df37"
                posRelativeH="ec1ad9429a64df37" txtcol="ff401010" buttonText="Sync"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="a734cb7cd6d90437" memberName="modFreqText1"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="6f801a8b6732fcf6"
         posRelativeY="6f801a8b6732fcf6" posRelativeW="6f801a8b6732fcf6"
         bkgCol="ffffffff" textCol="ff401010" outlineCol="ff401010" edTextCol="ff000000"
         edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="ee16f8f0ca36b4a1" memberName="modFreqText2"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="ec1ad9429a64df37"
         posRelativeY="ec1ad9429a64df37" posRelativeW="ec1ad9429a64df37"
         bkgCol="ffffffff" textCol="ff401010" outlineCol="ff401010" edTextCol="ff000000"
         edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="e7b93ca1af9ac83d" memberName="modDepthText1"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="ef41dbafc2b42ab0"
         posRelativeY="ef41dbafc2b42ab0" posRelativeW="ef41dbafc2b42ab0"
         bkgCol="ffffffff" textCol="ff401010" outlineCol="ff401010" edTextCol="ff000000"
         edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="433681df1094f408" memberName="modDepthText2"
         virtualName="" explicitFocusOrder="0" pos="0 56 100% 20" posRelativeX="f1fb1887848bb254"
         posRelativeY="f1fb1887848bb254" posRelativeW="f1fb1887848bb254"
         bkgCol="ffffffff" textCol="ff401010" outlineCol="ff401010" edTextCol="ff000000"
         edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
  <LABEL name="new label" id="c504412f027cb9de" memberName="mixText" virtualName=""
         explicitFocusOrder="0" pos="0 64 100% 20" posRelativeX="eb5c080c6c96c98c"
         posRelativeY="eb5c080c6c96c98c" posRelativeW="eb5c080c6c96c98c"
         bkgCol="ffffffff" textCol="ff401010" outlineCol="ff401010" edTextCol="ff000000"
         edBkgCol="0" labelText="Hello World" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="10" bold="1" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
