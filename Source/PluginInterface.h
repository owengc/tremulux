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
                         public SliderListener
{
public:
    //==============================================================================
    PluginInterface (PhaserWahAudioProcessor& p);
    ~PluginInterface();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void sliderValueChanged (Slider* sliderThatWasMoved);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    PhaserWahAudioProcessor& processor;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<Slider> freq1;
    ScopedPointer<Label> label;
    ScopedPointer<Slider> width1;
    ScopedPointer<Label> label2;
    ScopedPointer<Slider> moddepth;
    ScopedPointer<Label> label3;
    ScopedPointer<Slider> modfreq;
    ScopedPointer<Label> label4;
    ScopedPointer<Slider> mix;
    ScopedPointer<Label> label5;
    ScopedPointer<Slider> freq2;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> width2;
    ScopedPointer<Label> label7;
    ScopedPointer<Slider> freq3;
    ScopedPointer<Label> label8;
    ScopedPointer<Slider> width3;
    ScopedPointer<Label> label9;
    ScopedPointer<Slider> freq4;
    ScopedPointer<Label> label10;
    ScopedPointer<Slider> width4;
    ScopedPointer<Label> label11;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginInterface)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_7A0AAA5230769E18__
