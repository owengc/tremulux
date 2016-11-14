/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.3.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "tremuluxCore.h"
//[/Headers]

#include "tremuluxGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const theme::Theme TREMULUX_THEME = theme::Theme::DARK_YELLOW;


//int CustomSlider::mouseWheelMove (const MouseEvent& e, float wheelIncrementX, float wheelIncrementY)


//[/MiscUserDefs]

//==============================================================================
TremuluxGUI::TremuluxGUI (TremuluxCore* backend)
    : core(backend),
      lookAndFeel(TREMULUX_THEME),
      curtain(new Curtain(this)),
      subWindow(new SubWindow(this)),
      waitFlag(nullptr),
      openButton(new DrawableButton("openButton", DrawableButton::ButtonStyle::ImageStretched)),
      saveButton(new DrawableButton("saveButton", DrawableButton::ButtonStyle::ImageStretched)),
      bypassButton(new DrawableButton("bypassButton", DrawableButton::ButtonStyle::ImageStretched)),
      bypassButtonAttachment(new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(), TremuluxCore::bypassParamID, *bypassButton)),
      syncToggleButtons{{new DrawableButton("syncFreeButton1", DrawableButton::ButtonStyle::ImageStretched),
      new DrawableButton("syncFreeButton2", DrawableButton::ButtonStyle::ImageStretched)}},
      syncToggleButtonAttachments{{new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(),
      TremuluxCore::syncToggleParamID[0], *syncToggleButtons[0]),
      new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(),
      TremuluxCore::syncToggleParamID[1], *syncToggleButtons[1])}},
      hzRateDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(RATE1_X, RATE_Y, RATE_D, RATE_D),
      Rectangle<int>(RATE1_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,
      utilities::hzRateValueToTextFunction, utilities::hzRateTextToValueFunction),
      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(RATE2_X, RATE_Y, RATE_D, RATE_D),
      Rectangle<int>(RATE2_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,
      utilities::hzRateValueToTextFunction, utilities::hzRateTextToValueFunction)}},
      hzRateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::rateParamID[0], *hzRateDials[0]),
      new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::rateParamID[1], *hzRateDials[1])}},
      syncedRateDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(RATE1_X, RATE_Y, RATE_D, RATE_D),
      Rectangle<int>(RATE1_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,
      utilities::syncedRateValueToTextFunction, utilities::syncedRateTextToValueFunction),
      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(RATE2_X, RATE_Y, RATE_D, RATE_D),
      Rectangle<int>(RATE2_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,
      utilities::syncedRateValueToTextFunction, utilities::syncedRateTextToValueFunction)}},
      syncedRateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::syncModeParamID[0], *syncedRateDials[0]),
      new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::syncModeParamID[1], *syncedRateDials[1])}},
      rateLabels{{new Label("rate I", TRANS("rate I")), new Label("rate II", TRANS("rate II"))}},
      depthDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(DEPTH1_X, DEPTH_Y, DEPTH_D, DEPTH_D),
      Rectangle<int>(DEPTH1_X, DEPTHVALUE_Y, DEPTH_D, LABEL_H), VALUE_TEXT,
      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction),
      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(DEPTH2_X, DEPTH_Y, DEPTH_D, DEPTH_D),
      Rectangle<int>(DEPTH2_X, DEPTHVALUE_Y, DEPTH_D, LABEL_H), VALUE_TEXT,
      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)}},
      depthDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::depthParamID[0], *depthDials[0]), new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
      TremuluxCore::depthParamID[1], *depthDials[1])}},
      depthLabels{{new Label("depth I", TRANS("depth I")), new Label("depth II", TRANS("depth II"))}},
      mixDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(MIX_X, MIX_Y, MIX_D, MIX_D),
      Rectangle<int>(MIX_X, MIXVALUE_Y, MIX_D, LABEL_H),
      VALUE_TEXT,
      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),
      mixDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(), TremuluxCore::mixParamID, *mixDial)),
      mixLabel(new Label("mix", TRANS("mix"))),
      gainDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(GAIN_X, GAIN_Y, GAIN_D, GAIN_D),
      Rectangle<int>(GAIN_X, GAINVALUE_Y, GAIN_D, LABEL_H),
      VALUE_TEXT,
      utilities::dbValueToTextFunction, utilities::dbTextToValueFunction)),
      gainDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(), TremuluxCore::gainParamID, *gainDial)),
      gainLabel(new Label("gain", TRANS("gain"))),
      blendDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,
      Rectangle<int>(BLEND_X, BLEND_Y, BLEND_D, BLEND_D),
      Rectangle<int>(BLEND_X, BLENDVALUE_Y, BLEND_D, LABEL_H),
      VALUE_TEXT,
      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),
      blendDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(), TremuluxCore::blendParamID, *blendDial)),
      blendLabel(new Label("blend", TRANS("blend")))
{
    //[Constructor_pre] You can add your own custom stuff here..
    LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (480, 372);


    //[Constructor] You can add your own custom stuff here..

//    setRateDialRanges(core->RATE_DIAL_RANGE);

    //***************
    //** GUI Setup **
    //***************

    //////////////////
    // Button setup:

    // Preset Menu:
    // Open
    addAndPositionButton("Open Preset", openButton, true,
                         Resources::icon_open_normal_svg, Resources::icon_open_normal_svgSize,
                         Resources::icon_open_over_svg, Resources::icon_open_over_svgSize,
                         Resources::icon_open_down_svg, Resources::icon_open_down_svgSize,
                         OPENPRESETBUTTON_X, PRESETMENU_Y, M_SIZE, M_SIZE,
                         this, this);
    // Save
    addAndPositionButton("Save Preset", saveButton, true,
                         Resources::icon_save_normal_svg, Resources::icon_save_normal_svgSize,
                         Resources::icon_save_over_svg, Resources::icon_save_over_svgSize,
                         Resources::icon_save_down_svg, Resources::icon_save_down_svgSize,
                         SAVEPRESETBUTTON_X, PRESETMENU_Y, M_SIZE, M_SIZE,
                         this, this);



//    Label* label;

    // Oscillator Controls
    for(int oscillatorID = 0; oscillatorID < NUM_MODS; ++oscillatorID)
    {
        const int labelX = (oscillatorID == 0)? OSCILLATOR1_X : OSCILLATOR2_X,
                 syncX = (oscillatorID == 0)? SYNC1_X : SYNC2_X;

        syncToggleButtons[oscillatorID]->setToggleState(core->syncToggleData[oscillatorID].load(), dontSendNotification);

        // Hz rate dial
        addAndMakeVisible(hzRateDials[oscillatorID]);
        addAndMakeVisible(hzRateDials[oscillatorID]->getTextBox());

        // Synced rate dial
        addAndMakeVisible(syncedRateDials[oscillatorID]);
        addAndMakeVisible(syncedRateDials[oscillatorID]->getTextBox());
        syncedRateDials[oscillatorID]->getTextBox()->setEditable(false);
        syncedRateDials[oscillatorID]->setMouseDragSensitivity(LOW_DRAG_SENSITIVITY);
        syncedRateDials[oscillatorID]->setVelocityModeParameters(LOW_VELOCITY_SENSITIVITY);
        syncedRateDials[oscillatorID]->setScrollWheelEnabled(false);

        // Rate label
        addAndMakeVisible(rateLabels[oscillatorID]);
        rateLabels[oscillatorID]->setBounds(labelX, RATELABEL_Y, RATE_D, LABEL_H);
        rateLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
        rateLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
        rateLabels[oscillatorID]->setEditable(false);

        displayRateDial(oscillatorID, syncToggleButtons[oscillatorID]->getToggleState());

        // Tempo sync button
        addAndPositionButton("Tempo Sync", syncToggleButtons[oscillatorID], true,
                             Resources::icon_tempo_normal_svg, Resources::icon_tempo_normal_svgSize,
                             Resources::icon_tempo_over_svg, Resources::icon_tempo_over_svgSize,
                             Resources::icon_tempo_down_svg, Resources::icon_tempo_down_svgSize,
                             syncX, SYNC_Y, SYNC_D, SYNC_D,
                             this, this);

        // Depth dial
        addAndMakeVisible(depthDials[oscillatorID]);
        addAndMakeVisible(depthDials[oscillatorID]->getTextBox());

        // Depth label
        addAndMakeVisible(depthLabels[oscillatorID]);
        depthLabels[oscillatorID]->setBounds(labelX, DEPTHLABEL_Y, DEPTH_D, LABEL_H);
        depthLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
        depthLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
        depthLabels[oscillatorID]->setEditable(false);


    }



    //////////////////
    // Master Controls

    // Mix dial
    addAndMakeVisible(mixDial);
//    mixDial->setBounds(MIX_X, OSCILLATOR1_Y, MIX_D, MIX_D);
//    label = mixDial->getTextBox();
    addAndMakeVisible(mixDial->getTextBox());
//    label->setBounds(MIX_X, OSCILLATOR1_Y + MIX_D, MIX_D, LABEL_H);

//    label->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
//    label->setText(mixDial->getTextFromValue(mixDial->getValue()), dontSendNotification);

    addAndMakeVisible(mixLabel);
    mixLabel->setBounds(MIX_X, MIXLABEL_Y, MIX_D, LABEL_H);
    mixLabel->setJustificationType(juce::Justification::centred);
    mixLabel->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    mixLabel->setEditable(false);

    // Bypass button
    addAndPositionButton("On / Off", bypassButton, true,
                         Resources::icon_power_normal_svg, Resources::icon_power_normal_svgSize,
                         Resources::icon_power_over_svg, Resources::icon_power_over_svgSize,
                         Resources::icon_power_down_svg, Resources::icon_power_down_svgSize,
                         BYPASS_X, BYPASS_Y, BYPASS_D, BYPASS_D,
                         this, this, true);
    bypassButton->setToggleState(core->bypassData.load(), dontSendNotification);

    // Gain dial
    addAndMakeVisible(gainDial);
    gainDial->getTextBox()->setText(dbValueToTextFunction(gainDial->getValue()), dontSendNotification);
    addAndMakeVisible(gainDial->getTextBox());

    addAndMakeVisible(gainLabel);
    gainLabel->setBounds(GAIN_X, GAINLABEL_Y, GAIN_D, LABEL_H);
    gainLabel->setJustificationType(juce::Justification::centred);
    gainLabel->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    gainLabel->setEditable(false);
    
    
    // Blend dial
    addAndMakeVisible(blendDial);
    blendDial->getTextBox()->setText(percentValueToTextFunction(blendDial->getValue()), dontSendNotification);
    addAndMakeVisible(blendDial->getTextBox());

    addAndMakeVisible(blendLabel);
    blendLabel->setBounds(BLEND_X, BLENDLABEL_Y, BLEND_D, LABEL_H);
    blendLabel->setJustificationType(juce::Justification::centred);
    blendLabel->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    blendLabel->setEditable(false);
    
    ////////////////////////////////////////////
    // Curtain (appears while editing ...)
//    addAndMakeVisible(curtain);
//    curtain->setBounds(Rectangle<int>(Point<int>(WAVEFORM_X, WAVEFORM_Y), Point<int>(MATRIX_X + MATRIX_W, MATRIX_Y + MATRIX_H)));
//    curtain->setAlwaysOnTop(true);
//    curtain->setVisible(false);

    ////////////////////////////////////////////
    // Curtain (appears while editing mapping)
//    addAndMakeVisible(subWindow);
//    setOpaque(true);
    synchronizeState();


    startTimer(30);
    //[/Constructor]
}

TremuluxGUI::~TremuluxGUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    hideComponent();

    lastButtonClicked = nullptr;

    openButton->removeListener(this);
    saveButton->removeListener(this);

//    core->removeActionListener(this);
//    core->setGUI(nullptr);
    //[/Destructor]
}

//==============================================================================
void TremuluxGUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff1a1a1a));

    g.setColour (Colour (0x33564b44));
    g.fillRoundedRectangle (24.0f, 48.0f, 432.0f, 303.0f, 3.000f);

    g.setColour (Colour (0x33564b44));
    g.fillRect (27, 51, 426, 297);

    g.setColour (Colour (0xffffde00));
    g.drawRoundedRectangle (48.0f, 72.0f, 252.0f, 252.0f, 3.000f, 1.000f);

    g.setColour (Colour (0xffffde00));
    g.fillRect (0, 24, 362, 2);

    g.setColour (Colour (0xffffde00));
    g.fillRect (0, 0, 144, 24);

    g.setColour (Colour (0xff84adbc));
    g.setFont (Font ("Myriad Pro", 12.00f, Font::bold));
    g.drawText (TRANS("PRESETS"),
                24, 4, 48, 22,
                Justification::centredLeft, true);

    g.setColour (Colour (0xffffde00));
    g.setFont (Font ("Myriad Pro", 18.00f, Font::bold));
    g.drawText (TRANS("( TREMULUX"),
                360, 8, 96, 36,
                Justification::centredRight, true);

    g.setColour (Colour (0xffffde00));
    g.drawRoundedRectangle (324.0f, 72.0f, 108.0f, 252.0f, 3.000f, 1.000f);

    g.setColour (Colours::grey);
    g.fillEllipse (84.0f, 180.0f, 36.0f, 36.0f);

    g.setColour (Colours::grey);
    g.fillEllipse (360.0f, 180.0f, 36.0f, 36.0f);

    g.setColour (Colour (0xff515151));
    g.setFont (Font ("Myriad Pro", 12.00f, Font::bold));
    g.drawText (TRANS("PRESETS"),
                24, 4, 48, 22,
                Justification::centredLeft, true);

    g.setColour (Colours::grey);
    g.fillEllipse (228.0f, 180.0f, 36.0f, 36.0f);

    //[UserPaint] Add your own custom painting code here..
    //DEBUG
//    debugOutline(g, blendDial, Colours::chartreuse, "topLeft");
    //[/UserPaint]
}

void TremuluxGUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TremuluxGUI::displayRateDial(const unsigned int oscillatorID, const bool synced)
{
    Label* label;
    if(synced)
    {
        // Hide hz dial & label
        label = hzRateDials[oscillatorID]->getTextBox();
        hzRateDials[oscillatorID]->setVisible(false);
        label->setVisible(false);

        // Show synced dial & label
        label = syncedRateDials[oscillatorID]->getTextBox();
        syncedRateDials[oscillatorID]->setVisible(true);
        label->setVisible(true);
    }
    else
    {
        // Hide synced dial & label
        label = syncedRateDials[oscillatorID]->getTextBox();
        syncedRateDials[oscillatorID]->setVisible(false);
        label->setVisible(false);

        // Show hz dial & label
        label = hzRateDials[oscillatorID]->getTextBox();
        hzRateDials[oscillatorID]->setVisible(true);
        label->setVisible(true);
    }
}


void TremuluxGUI::synchronizeState()
{

    updateButtonStates();
}

void TremuluxGUI::showComponent(Component *componentToDisplay)
{
//    if(curtain->getParentComponent())
    {
        curtain->setVisible(true);
        curtain->addAndMakeVisible(componentToDisplay);
        componentToDisplay->centreWithSize(componentToDisplay->getWidth(), componentToDisplay->getHeight());
    }
}

void TremuluxGUI::hideComponent()
{
//    if(curtain->getParentComponent())
    {
        curtain->setVisible(false);
        curtain->deleteAllChildren();
    }
}

void TremuluxGUI::sliderValueChanged (Slider* sliderThatWasMoved)
{}

void TremuluxGUI::buttonClicked (Button* button)
{
    if(button == bypassButton)
    {
        if(bypassButton->getToggleState())
        {
            // disable UI elements
//            mixDial->setEnabled(false);
//            gainDial->setEnabled(false);
//            blendDial->setEnabled(false);
//            
//            for(int i = 0; i < NUM_MODS; ++i)
//            {
//                hzRateDials[i]->setEnabled(false);
//                syncedRateDials[i]->setEnabled(false);
//                syncToggleButtons[i]->setEnabled(false);
//                depthDials[i]->setEnabled(false);
//            }
        }
        else
        {
//            mixDial->setEnabled(true);
//            gainDial->setEnabled(true);
//            blendDial->setEnabled(true);
//            
//            for(int i = 0; i < NUM_MODS; ++i)
//            {
//                hzRateDials[i]->setEnabled(true);
//                syncedRateDials[i]->setEnabled(true);
//                syncToggleButtons[i]->setEnabled(true);
//                depthDials[i]->setEnabled(true);
//            }
        }
    }
    else if(button == openButton)
    {
        FileChooser fc("Load preset file...",
                       File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
                       "*.tremulux",
                       true);
        fc.browseForFileToOpen();
        File presetFile = fc.getResult();
        XmlElement * xmlPreset = XmlDocument(presetFile).getDocumentElement();
        
        if(xmlPreset != nullptr)
        {
            core->deserialize(*xmlPreset);
        }
        else
        {
            AlertWindow("Invalid preset file", "The preset file you selected is not formatted correctly", AlertWindow::AlertIconType::NoIcon);
        }
        
        button->setToggleState(false, juce::NotificationType::dontSendNotification);
    }
    else if(button == saveButton)
    {
        FileChooser fc("Save preset as...",
                       File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
                       "*.tremulux",
                       true);
        fc.browseForFileToSave(true);
        File presetFile = fc.getResult();
        XmlElement xmlPreset("Tremulux");
        core->serialize(xmlPreset);
        
        if(presetFile.create().wasOk())
        {
            xmlPreset.writeToFile(presetFile, "");
        }
        
        button->setToggleState(false, juce::NotificationType::dontSendNotification);
    }
    else
    {
        for(int i =0; i < NUM_MODS; ++i)
        {
            if(button == syncToggleButtons[i])
            {
                displayRateDial(i, syncToggleButtons[i]->getToggleState());
            }
        }
    }
}

void TremuluxGUI::editorShown (Label* textBox, TextEditor& textEditor)
{}

void TremuluxGUI::editorHidden(Label* textBox, TextEditor& textEditor)
{}

void TremuluxGUI::labelTextChanged(Label* textBox)
{}

void TremuluxGUI::timerCallback()
{}

void TremuluxGUI::setRateDialRanges(const float max)
{
//    for(int i = 0; i < NUM_MODS; ++i)
//    {
//        hzRateDials[i]->setRange(1.0, max, 0);
//    }
}

void TremuluxGUI::visibilityChanged()
{}

//==============================================================================
// Private Classes and Methods
//==============================================================================
TremuluxGUI::SubWindow::SubWindow(TremuluxGUI* parent) : owner(parent)
{}

TremuluxGUI::SubWindow::~SubWindow()
{
    deleteAllChildren();
}

void TremuluxGUI::SubWindow::paint(Graphics& g)
{
    g.fillAll(theme::Palette::black);
}

TremuluxGUI::Curtain::Curtain(TremuluxGUI* parent) : owner(parent)
{}

TremuluxGUI::Curtain::~Curtain()
{
    deleteAllChildren();
}

void TremuluxGUI::Curtain::paint(Graphics& g)
{
    g.fillAll(theme::Palette::brown.withAlpha(0.667f));
}

void TremuluxGUI::Curtain::mouseUp(const MouseEvent& e)
{
    setVisible(false);
    owner->repaint();
}

TremuluxGUI::ModalWaitAnimation::ModalWaitAnimation (TremuluxGUI* parent, const Rectangle<int>& sizeAndPosition,
                    Atomic<int32>* &terminateFlag,
                    void (TremuluxGUI::*callback)(void),
                       const int cancellingTimeOutMs,
                    const String& waitingText, const String& completeText)
:
Thread("ModalWaitIcon"),

owner(parent),
progress(-1),
message(""),
waitingMessage(waitingText),
completeMessage(completeText),
condition(terminateFlag),
onFinish(callback),
timeOutMsWhenCancelling(cancellingTimeOutMs),
progressBar(new ProgressBar(progress))
{
    owner->addAndMakeVisible(progressBar);
    progressBar->setBounds(sizeAndPosition);
    setStatusMessage(message);
}

TremuluxGUI::ModalWaitAnimation::~ModalWaitAnimation()
{
    progressBar = nullptr;
    condition = nullptr;
    stopThread(timeOutMsWhenCancelling);
}

#if JUCE_MODAL_LOOPS_PERMITTED
/** Starts the thread and waits for it to finish.

 This will start the thread, make the dialog box appear, and wait until either
 the thread finishes normally, or until the cancel button is pressed.

 Before returning, the dialog box will be hidden.

 @param priority   the priority to use when starting the thread - see
 Thread::startThread() for values
 @returns true if the thread finished normally; false if the user pressed cancel
 */
bool TremuluxGUI::ModalWaitAnimation::runThread (int priority)
{
    launchThread(priority);

    while (isTimerRunning())
        MessageManager::getInstance()->runDispatchLoopUntil(5);
}
#endif

void TremuluxGUI::ModalWaitAnimation::launchThread (int priority)
{
    jassert (MessageManager::getInstance()->isThisTheMessageThread());

    startThread(priority);
    startTimer(100);

    {
        const ScopedLock sl(messageLock);
        progressBar->setTextToDisplay(message);
    }

    owner->enterModalState();
}

void TremuluxGUI::ModalWaitAnimation::run()
{
    while(condition->get())
    {
        wait(500);
    }
    if(completeMessage != "")
    {
        setStatusMessage(completeMessage);
        wait(2000);
    }
}

void TremuluxGUI::ModalWaitAnimation::timerCallback()
{
    bool threadStillRunning = isThreadRunning();

    if (! (threadStillRunning && owner->isCurrentlyModal()))
    {
        stopTimer();
        stopThread (timeOutMsWhenCancelling);
        owner->exitModalState (1);
        //            alertWindow->setVisible (false);

        wasCancelledByUser = threadStillRunning;
        threadComplete (threadStillRunning);
        return; // (this may be deleted now)
    }

    const ScopedLock sl (messageLock);
    progressBar->setTextToDisplay(message);
}

// This method gets called on the message thread once our thread has finished..
void TremuluxGUI::ModalWaitAnimation::threadComplete (bool userPressedCancel)
{
    if (userPressedCancel)
    {
        AlertWindow::showMessageBoxAsync (AlertWindow::WarningIcon,
                                          "Progress window",
                                          "You pressed cancel!");
    }
    else
    {
        ((owner)->*(onFinish))();
    }
    // ..and clean up by deleting our thread object..
    delete this;
}

void TremuluxGUI::ModalWaitAnimation::setStatusMessage (const String& newStatusMessage)
{
    const ScopedLock sl (messageLock);
    message = newStatusMessage;
}

void TremuluxGUI::ModalWaitAnimation::setCondition(Atomic<int32>& terminateFlag)
{
    condition = &terminateFlag;
}

void TremuluxGUI::buttonStateChanged(Button* button)
{

}

void TremuluxGUI::comboBoxChanged (ComboBox* box)
{}

void TremuluxGUI::updateButtonStates()
{

}

void TremuluxGUI::clearOtherToggleStates(Button* button)
{
}

void TremuluxGUI::actionListenerCallback (const String& message)
{
}

void TremuluxGUI::alertCallback(int modalResult, String context)
{
    if(context == "Unsaved Data")
    {
        if(modalResult == 1)
        {
            //TODO add save routine here
        }
    }
}

void TremuluxGUI::userTriedToCloseWindow()
{

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TremuluxGUI" componentName=""
                 parentClasses="public Component, public Timer, public ModalComponentManager, public ActionListener, private DrawableButton::Listener, private Slider::Listener, private ComboBox::Listener, public LabelListener"
                 constructorParams="TremuluxCore* backend" variableInitialisers="core(backend),&#10;      lookAndFeel(TREMULUX_THEME),&#10;      curtain(new Curtain(this)),&#10;      subWindow(new SubWindow(this)),&#10;      waitFlag(nullptr),&#10;      openButton(new DrawableButton(&quot;openButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;      saveButton(new DrawableButton(&quot;saveButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;      bypassButton(new DrawableButton(&quot;bypassButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;      bypassButtonAttachment(new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(), TremuluxCore::bypassParamID, *bypassButton)),&#10;      syncToggleButtons{{new DrawableButton(&quot;syncFreeButton1&quot;, DrawableButton::ButtonStyle::ImageStretched),&#10;      new DrawableButton(&quot;syncFreeButton2&quot;, DrawableButton::ButtonStyle::ImageStretched)}},&#10;      syncToggleButtonAttachments{{new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::syncToggleParamID[0], *syncToggleButtons[0]),&#10;      new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::syncToggleParamID[1], *syncToggleButtons[1])}},&#10;      hzRateDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(RATE1_X, RATE_Y, RATE_D, RATE_D),&#10;      Rectangle&lt;int&gt;(RATE1_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,&#10;      utilities::hzRateValueToTextFunction, utilities::hzRateTextToValueFunction),&#10;      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(RATE2_X, RATE_Y, RATE_D, RATE_D),&#10;      Rectangle&lt;int&gt;(RATE2_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,&#10;      utilities::hzRateValueToTextFunction, utilities::hzRateTextToValueFunction)}},&#10;      hzRateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::rateParamID[0], *hzRateDials[0]),&#10;      new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::rateParamID[1], *hzRateDials[1])}},&#10;      syncedRateDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(RATE1_X, RATE_Y, RATE_D, RATE_D),&#10;      Rectangle&lt;int&gt;(RATE1_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,&#10;      utilities::syncedRateValueToTextFunction, utilities::syncedRateTextToValueFunction),&#10;      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(RATE2_X, RATE_Y, RATE_D, RATE_D),&#10;      Rectangle&lt;int&gt;(RATE2_X, RATEVALUE_Y, RATE_D, LABEL_H), VALUE_TEXT,&#10;      utilities::syncedRateValueToTextFunction, utilities::syncedRateTextToValueFunction)}},&#10;      syncedRateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::syncModeParamID[0], *syncedRateDials[0]),&#10;      new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::syncModeParamID[1], *syncedRateDials[1])}},&#10;rateLabels{{new Label(&quot;rate I&quot;, TRANS(&quot;rate I&quot;)), new Label(&quot;rate II&quot;, TRANS(&quot;rate II&quot;))}},&#10;      depthDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(DEPTH1_X, DEPTH_Y, DEPTH_D, DEPTH_D),&#10;      Rectangle&lt;int&gt;(DEPTH1_X, DEPTHVALUE_Y, DEPTH_D, LABEL_H), VALUE_TEXT,&#10;      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction),&#10;      new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(DEPTH2_X, DEPTH_Y, DEPTH_D, DEPTH_D),&#10;      Rectangle&lt;int&gt;(DEPTH2_X, DEPTHVALUE_Y, DEPTH_D, LABEL_H), VALUE_TEXT,&#10;      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)}},&#10;      depthDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::depthParamID[0], *depthDials[0]), new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;      TremuluxCore::depthParamID[1], *depthDials[1])}},&#10;depthLabels{{new Label(&quot;depth I&quot;, TRANS(&quot;depth I&quot;)), new Label(&quot;depth II&quot;, TRANS(&quot;depth II&quot;))}},&#10;      mixDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(MIX_X, MIX_Y, MIX_D, MIX_D),&#10;      Rectangle&lt;int&gt;(MIX_X, MIXVALUE_Y, MIX_D, LABEL_H),&#10;      VALUE_TEXT,&#10;      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),&#10;      mixDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(), TremuluxCore::mixParamID, *mixDial)),&#10;      mixLabel(new Label(&quot;mix&quot;, TRANS(&quot;mix&quot;))),&#10;      gainDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(GAIN_X, GAIN_Y, GAIN_D, GAIN_D),&#10;      Rectangle&lt;int&gt;(GAIN_X, GAINVALUE_Y, GAIN_D, LABEL_H),&#10;      VALUE_TEXT,&#10;      utilities::dbValueToTextFunction, utilities::dbTextToValueFunction)),&#10;      gainDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(), TremuluxCore::gainParamID, *gainDial)),&#10;      gainLabel(new Label(&quot;gain&quot;, TRANS(&quot;gain&quot;))),&#10;      blendDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag,&#10;      Rectangle&lt;int&gt;(BLEND_X, BLEND_Y, BLEND_D, BLEND_D),&#10;      Rectangle&lt;int&gt;(BLEND_X, BLENDVALUE_Y, BLEND_D, LABEL_H),&#10;      VALUE_TEXT,&#10;      utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),&#10;      blendDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(), TremuluxCore::blendParamID, *blendDial)),&#10;      blendLabel(new Label(&quot;blend&quot;, TRANS(&quot;blend&quot;)))"
                 snapPixels="12" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="480" initialHeight="372">
  <BACKGROUND backgroundColour="ff1a1a1a">
    <ROUNDRECT pos="24 48 432 303" cornerSize="3" fill="solid: 33564b44" hasStroke="0"/>
    <RECT pos="27 51 426 297" fill="solid: 33564b44" hasStroke="0"/>
    <ROUNDRECT pos="48 72 252 252" cornerSize="3" fill="solid: 0" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffffde00"/>
    <RECT pos="0 24 362 2" fill="solid: ffffde00" hasStroke="0"/>
    <RECT pos="0 0 144 24" fill="solid: ffffde00" hasStroke="0"/>
    <TEXT pos="24 4 48 22" fill="solid: ff84adbc" hasStroke="0" text="PRESETS"
          fontname="Myriad Pro" fontsize="12" bold="1" italic="0" justification="33"/>
    <TEXT pos="360 8 96 36" fill="solid: ffffde00" hasStroke="0" text="( TREMULUX"
          fontname="Myriad Pro" fontsize="18" bold="1" italic="0" justification="34"/>
    <ROUNDRECT pos="324 72 108 252" cornerSize="3" fill="solid: 0" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffffde00"/>
    <ELLIPSE pos="84 180 36 36" fill="solid: ff808080" hasStroke="0"/>
    <ELLIPSE pos="360 180 36 36" fill="solid: ff808080" hasStroke="0"/>
    <TEXT pos="24 4 48 22" fill="solid: ff515151" hasStroke="0" text="PRESETS"
          fontname="Myriad Pro" fontsize="12" bold="1" italic="0" justification="33"/>
    <ELLIPSE pos="228 180 36 36" fill="solid: ff808080" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
