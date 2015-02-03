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

#ifndef __JUCE_HEADER_7A0AAA5230769E18__
#define __JUCE_HEADER_7A0AAA5230769E18__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class PluginInterface  : public AudioProcessorEditor,
                         public SliderListener,
                         public ButtonListener
{
public:
    //==============================================================================
    PluginInterface (TremuluxAudioProcessor& p);
    ~PluginInterface();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void setRateDialRanges(const float max);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    TremuluxAudioProcessor& processor;
    float lastUnsyncedFreqs[2]{0.1};
    StringArray syncModeLabels;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> modRateDial1;
    ScopedPointer<Label> label;
    ScopedPointer<Slider> modDepth1;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> mix;
    ScopedPointer<Label> label5;
    ScopedPointer<Slider> modRateDial2;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> modDepth2;
    ScopedPointer<Label> label7;
    ScopedPointer<ToggleButton> modSyncButton1;
    ScopedPointer<ToggleButton> modSyncButton2;
    ScopedPointer<Label> modFreqLabel1;
    ScopedPointer<Label> modFreqLabel2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginInterface)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7A0AAA5230769E18__
