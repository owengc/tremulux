/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "tremuluxGUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
const theme::Theme TREMULUX_THEME = theme::Theme::DARK_YELLOW;



CustomSlider::CustomSliderLabel::CustomSliderLabel(CustomSlider* slider) :
Label()
{
    slider->addListener(this);
}
CustomSlider::CustomSliderLabel::~CustomSliderLabel()
{}

void CustomSlider::CustomSliderLabel::sliderValueChanged(Slider* slider)
{
    this->setText(slider->getTextFromValue(slider->getValue()), dontSendNotification);
}

CustomSlider::CustomSlider() : CustomSlider(LinearHorizontal)
{}

CustomSlider::CustomSlider(Slider::SliderStyle sliderStyle,
                           std::function<String (float)> valueToText,
                           std::function<float (const String&)> textToValue) :
                            Slider(sliderStyle, Slider::TextEntryBoxPosition::NoTextBox),
                            textBox(new CustomSliderLabel(this)),
                            valueToTextFunction(valueToText),
                            textToValueFunction(textToValue),
                            valueChangedViaTextbox(false)
{
    textBox->addListener(this);
    textBox->setEditable(true);
}

CustomSlider::~CustomSlider()
{}

Label* CustomSlider::getTextBox()
{
    return textBox;
}

void CustomSlider::setValueToTextFunction(std::function<String (float)> valueToText)
{
    valueToTextFunction = valueToText;
}
void CustomSlider::setTextToValueFunction(std::function<float (const String&)> textToValue)
{
    textToValueFunction = textToValue;
}

double CustomSlider::getValueFromText(const String& text)
{
    return textToValueFunction(text);
}

String CustomSlider::getTextFromValue(double value)
{
    return valueToTextFunction(value);
}

void CustomSlider::labelTextChanged(Label* textBox)
{
    if(valueChangedViaTextbox.load())
    {
        this->setValue(textToValueFunction(textBox->getText()));
    }
}

void CustomSlider::editorShown(Label* label, TextEditor& editor)
{
    valueChangedViaTextbox.store(false);
}

void CustomSlider::editorHidden(Label* label, TextEditor& editor)
{
    valueChangedViaTextbox.store(true);
}

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
rateDials{{new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox),
    new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox)}},
rateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
                                                                        TremuluxCore::rateParamID[0], *rateDials[0]),
    new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
                                                       TremuluxCore::rateParamID[1], *rateDials[1])}},
rateLabels{{new Label("rateLabel1", TRANS("rate")), new Label("rateLabel2", TRANS("rate"))}},
syncToggleButtons{{new DrawableButton("syncFreeButton1", DrawableButton::ButtonStyle::ImageStretched),
    new DrawableButton("syncFreeButton2", DrawableButton::ButtonStyle::ImageStretched)}},
syncToggleButtonAttachments{{new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(),
                                                                                TremuluxCore::syncToggleParamID[0], *syncToggleButtons[0]),
    new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(),
                                                       TremuluxCore::syncToggleParamID[1], *syncToggleButtons[1])}},
depthDials{{new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, utilities::percentValueToTextFunction, utilities::percentTextToValueFunction),
    new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)}},
depthDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
                                                                         TremuluxCore::depthParamID[0], *depthDials[0]), new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(),
                                                                                                                                                                            TremuluxCore::depthParamID[1], *depthDials[1])}},
depthLabels{{new Label("depth", TRANS("depth")), new Label("depth", TRANS("depth"))}},
mixDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),
mixDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(), TremuluxCore::mixParamID, *mixDial)),
mixLabel(new Label("mix", TRANS("mix"))),
bypassButton(new DrawableButton("bypassButton", DrawableButton::ButtonStyle::ImageStretched)),
bypassButtonAttachment(new AudioProcessorValueTreeState::ButtonAttachment(core->getParameterManager(), TremuluxCore::bypassParamID, *bypassButton)),
gainDial(new CustomSlider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, utilities::percentValueToTextFunction, utilities::percentTextToValueFunction)),
gainDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core->getParameterManager(), TremuluxCore::gainParamID, *gainDial)),
gainLabel(new Label("gain", TRANS("gain")))
{
    //[Constructor_pre] You can add your own custom stuff here..
    LookAndFeel::setDefaultLookAndFeel(&lookAndFeel);
    //[/Constructor_pre]


    //[UserPreSize]
    //[/UserPreSize]

    setSize (456, 384);


    //[Constructor] You can add your own custom stuff here..

//    setRateDialRanges(core->RATE_DIAL_RANGE);
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



    unsigned int oscillatorID;
    Label* label;

    // Oscillator I Controls
    oscillatorID = 0;
    addAndMakeVisible(rateDials[oscillatorID]);
    rateDials[oscillatorID]->setBounds(RATE_X, OSCILLATOR1_Y, RATE_D, RATE_D + LABEL_H);
    rateDials[oscillatorID]->setTextBoxStyle(Slider::TextBoxBelow, false, RATELABEL_W, LABEL_H);
    addAndMakeVisible(rateLabels[oscillatorID]);
    rateLabels[oscillatorID]->setBounds(RATELABEL_X, OSCILLATORLABEL1_Y, RATE_D, LABEL_H);
    rateLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
    rateLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    rateLabels[oscillatorID]->setEditable(false);

    addAndPositionButton("Tempo Sync", syncToggleButtons[oscillatorID], true,
                         Resources::icon_tempo_normal_svg, Resources::icon_tempo_normal_svgSize,
                         Resources::icon_tempo_over_svg, Resources::icon_tempo_over_svgSize,
                         Resources::icon_tempo_down_svg, Resources::icon_tempo_down_svgSize,
                         SYNC_X, SYNC1_Y, M_SIZE, M_SIZE,
                         this, this);

    addAndMakeVisible(depthDials[oscillatorID]);
    depthDials[oscillatorID]->setBounds(DEPTH_X, OSCILLATOR1_Y, DEPTH_D, DEPTH_D + LABEL_H);
    label = depthDials[oscillatorID]->getTextBox();
    addAndMakeVisible(label);
    label->setBounds(DEPTH_X, OSCILLATOR1_Y + DEPTH_D, DEPTH_D, LABEL_H);
    label->setJustificationType(juce::Justification::centred);
    label->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    addAndMakeVisible(depthLabels[oscillatorID]);
    depthLabels[oscillatorID]->setBounds(DEPTHLABEL_X, OSCILLATORLABEL1_Y, DEPTH_D, LABEL_H);
    depthLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
    depthLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    depthLabels[oscillatorID]->setEditable(false);

    // Oscillator II Controls
    oscillatorID = 1;
    addAndMakeVisible(rateDials[oscillatorID]);
    rateDials[oscillatorID]->setBounds(RATE_X, OSCILLATOR2_Y, GAIN_D, GAIN_D + LABEL_H);
    rateDials[oscillatorID]->setTextBoxStyle(Slider::TextBoxBelow, false, RATELABEL_W, LABEL_H);
    addAndMakeVisible(rateLabels[oscillatorID]);
    rateLabels[oscillatorID]->setBounds(RATELABEL_X, OSCILLATORLABEL2_Y, RATE_D, LABEL_H);
    rateLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
    rateLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    rateLabels[oscillatorID]->setEditable(false);

    addAndPositionButton("Tempo Sync", syncToggleButtons[oscillatorID], true,
                         Resources::icon_tempo_normal_svg, Resources::icon_tempo_normal_svgSize,
                         Resources::icon_tempo_over_svg, Resources::icon_tempo_over_svgSize,
                         Resources::icon_tempo_down_svg, Resources::icon_tempo_down_svgSize,
                         SYNC_X, SYNC2_Y, M_SIZE, M_SIZE,
                         this, this);

    addAndMakeVisible(depthDials[oscillatorID]);
    depthDials[oscillatorID]->setBounds(DEPTH_X, OSCILLATOR2_Y, DEPTH_D, DEPTH_D + LABEL_H);
    label = depthDials[oscillatorID]->getTextBox();
    addAndMakeVisible(label);
    label->setBounds(DEPTH_X, OSCILLATOR2_Y + DEPTH_D, DEPTH_D, LABEL_H);
    label->setJustificationType(juce::Justification::centred);
    label->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    
    addAndMakeVisible(depthLabels[oscillatorID]);
    depthLabels[oscillatorID]->setBounds(DEPTHLABEL_X, OSCILLATORLABEL2_Y, DEPTH_D, LABEL_H);
    depthLabels[oscillatorID]->setJustificationType(juce::Justification::centred);
    depthLabels[oscillatorID]->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    depthLabels[oscillatorID]->setEditable(false);

    // Master Controls
    addAndMakeVisible(mixDial);
    mixDial->setBounds(MIX_X, OSCILLATOR1_Y, MIX_D, MIX_D);
    label = mixDial->getTextBox();
    addAndMakeVisible(label);
    label->setBounds(MIX_X, OSCILLATOR1_Y + MIX_D, MIX_D, LABEL_H);
    label->setJustificationType(juce::Justification::centred);
    label->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    
    addAndMakeVisible(mixLabel);
    mixLabel->setBounds(MIXLABEL_X, OSCILLATORLABEL1_Y, MIX_D, LABEL_H);
    mixLabel->setJustificationType(juce::Justification::centred);
    mixLabel->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    mixLabel->setEditable(false);

    addAndPositionButton("On / Off", bypassButton, true,
                         Resources::icon_power_normal_svg, Resources::icon_power_normal_svgSize,
                         Resources::icon_power_over_svg, Resources::icon_power_over_svgSize,
                         Resources::icon_power_down_svg, Resources::icon_power_down_svgSize,
                         BYPASS_X, BYPASS_Y, M_SIZE, M_SIZE,
                         this, this);

    addAndMakeVisible(gainDial);
    gainDial->setBounds(GAIN_X, OSCILLATOR2_Y, GAIN_D, GAIN_D + LABEL_H);
    label = gainDial->getTextBox();
    addAndMakeVisible(label);
    label->setBounds(GAIN_X, OSCILLATOR2_Y + GAIN_D, GAIN_D, LABEL_H);
    label->setJustificationType(juce::Justification::centred);
    label->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    
    addAndMakeVisible(gainLabel);
    gainLabel->setBounds(GAINLABEL_X, OSCILLATORLABEL2_Y, GAIN_D, LABEL_H);
    gainLabel->setJustificationType(juce::Justification::centred);
    gainLabel->setFont(theme::getThemeFont().withPointHeight(LABEL_TEXT));
    gainLabel->setEditable(false);

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
    g.fillRoundedRectangle (24.0f, 48.0f, 408.0f, 312.0f, 3.000f);

    g.setColour (Colour (0x33564b44));
    g.fillRect (27, 51, 402, 306);

    g.setColour (Colour (0xffffde00));
    g.fillRect (0, 24, 338, 2);

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
                336, 8, 96, 36,
                Justification::centredRight, true);

    g.setColour (Colour (0xfff1de00));
    g.drawRoundedRectangle (48.0f, 72.0f, 252.0f, 120.0f, 3.000f, 1.000f);

    g.setColour (Colour (0xffffde00));
    g.drawRoundedRectangle (324.0f, 72.0f, 84.0f, 263.0f, 3.000f, 1.000f);

    g.setColour (Colours::grey);
    g.fillEllipse (156.0f, 120.0f, 36.0f, 36.0f);

    g.setColour (Colours::grey);
    g.fillEllipse (348.0f, 192.0f, 36.0f, 36.0f);

    g.setColour (Colour (0xff515151));
    g.setFont (Font ("Myriad Pro", 12.00f, Font::bold));
    g.drawText (TRANS("PRESETS"),
                24, 4, 48, 22,
                Justification::centredLeft, true);

    g.setColour (Colour (0xffffde00));
    g.setFont (Font ("Myriad Pro", 14.00f, Font::bold));
    g.drawText (TRANS("oscillator I"),
                48, 72, 252, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffffde00));
    g.setFont (Font ("Myriad Pro", 14.00f, Font::bold));
    g.drawText (TRANS("master"),
                324, 72, 84, 24,
                Justification::centred, true);

    g.setColour (Colour (0xffffde00));
    g.drawRoundedRectangle (48.0f, 216.0f, 252.0f, 120.0f, 3.000f, 1.000f);

    g.setColour (Colours::grey);
    g.fillEllipse (156.0f, 264.0f, 36.0f, 36.0f);

    g.setColour (Colour (0xffffde00));
    g.setFont (Font ("Myriad Pro", 14.00f, Font::bold));
    g.drawText (TRANS("oscillator II"),
                48, 216, 252, 24,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //DEBUG
//    debugOutline(g, this, Colours::chartreuse, "topLeft");
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
void TremuluxGUI::synchronizeState()
{
//    const unsigned int numRows = core->mappingMatrix.activeFeatures.size(),
//    numCols = core->mappingMatrix.activeParameters.size(),
//    numMappings = core->mappingMatrix.activeMappings.size();
//    unsigned int r, c, activeCount = 0;
//    bool once = true;
//    for(r = 0; r < numRows; ++r)
//    {
//        auto fwp = core->mappingMatrix.getRowInfo(r);
//        assert(!fwp.expired());
//        mappingMatrixGUI->insertRow(fwp, true);
//        for(c = 0; c < numCols; ++c)
//        {
//            if(once)
//            {
//                auto pwp = core->mappingMatrix.getColInfo(c);
//                assert(!pwp.expired());
//                mappingMatrixGUI->insertCol(pwp, true);
//            }
//            if(core->mappingMatrix.getMappingByRowCol(r, c).isActive())
//            {
//                activeCount++;
//                mappingMatrixGUI->setCellToggleState(r, c, true);
//            }
//        }
//        once = false;
//    }
//    jassert(activeCount == numMappings);
//    if(core->messenger->publicSession == nullptr)
//    {
//        refreshDawModel();
//    }
//    else
//    {
//        if(core->messenger->publicSession != nullptr && !core->messenger->publicSession->needsUpdate.get())
//        {
//            mappingMatrixGUI->populateParameterMenu(*core->messenger->publicSession);
//        }
//    }
//    if(!core->isEmpty())
//    {
//        audioRecorderPlayerGUI->import(true);
//    }
//    if(core->isAnalyzingStream())
//    {
//        bypassButton->setToggleState(true, dontSendNotification);
//
//    }
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
{
//    //[UsersliderValueChanged_Pre]
//    String displayText;
//    //[/UsersliderValueChanged_Pre]
//
//    if (sliderThatWasMoved == modRateDial1)
//    {
//        //[UserSliderCode_modRateDial1] -- add your slider handling code here..
//        int mode = 0, currentlySynced = modSyncButton1->getToggleState();
//        if(currentlySynced){
//            //sync activated, quantize value
//            mode = (int)sliderThatWasMoved->getValue();
//            sliderThatWasMoved->setValue(mode);
//        }
//        float freqDialValue = sliderThatWasMoved->getValue();
//        core->setParameterNotifyingHost(TremuluxCore::MOD_SYNC1, mode);
//        core->setParameterNotifyingHost(TremuluxCore::MOD_RATE_DIAL1,
//                                            freqDialValue);
//        displayText = (currentlySynced)?core->syncToggleLabels.getReference(mode):
//        String(core->MIN_FREE_RATE + (freqDialValue * core->ONE_BY_RATE_DIAL_RANGE) * (core->MAX_FREE_RATE - core->MIN_FREE_RATE), 2) + " Hz";
//        modFreqText1->setText(displayText, juce::NotificationType::sendNotification);
//
//        //[/UserSliderCode_modRateDial1]
//    }
//    else if (sliderThatWasMoved == modDepth1)
//    {
//        //[UserSliderCode_modDepth1] -- add your slider handling code here..
//        float depthDialValue = sliderThatWasMoved->getValue();
//        core->setParameterNotifyingHost(TremuluxCore::MOD_DEPTH1,
//                                            depthDialValue);
//        displayText = String(depthDialValue, 2);
//        modDepthText1->setText(displayText, juce::NotificationType::sendNotification);
//        //[/UserSliderCode_modDepth1]
//    }
//    else if (sliderThatWasMoved == mix)
//    {
//        //[UserSliderCode_mix] -- add your slider handling code here..
//        float mixDialValue = sliderThatWasMoved->getValue();
//        core->setParameterNotifyingHost(TremuluxCore::MIX,
//                                            mixDialValue);
//        displayText = String(mixDialValue, 2);
//        mixText->setText(displayText, juce::NotificationType::sendNotification);
//        //[/UserSliderCode_mix]
//    }
//    else if (sliderThatWasMoved == modRateDial2)
//    {
//        //[UserSliderCode_modRateDial2] -- add your slider handling code here..
//        int mode = 0, currentlySynced = modSyncButton2->getToggleState();
//        if(modSyncButton2->getToggleState()){
//            //sync activated, quantize value
//            mode = (int)sliderThatWasMoved->getValue();
//            sliderThatWasMoved->setValue(mode);
//        }
//        float freqDialValue = sliderThatWasMoved->getValue();
//        core->setParameterNotifyingHost(TremuluxCore::MOD_SYNC2, mode);
//        core->setParameterNotifyingHost(TremuluxCore::MOD_RATE_DIAL2,
//                                            freqDialValue);
//        displayText = (currentlySynced)?core->syncToggleLabels.getReference(mode):
//        String(core->MIN_FREE_RATE + (freqDialValue * core->ONE_BY_RATE_DIAL_RANGE) * (core->MAX_FREE_RATE - core->MIN_FREE_RATE), 2) + " Hz";
//        modFreqText2->setText(displayText, juce::NotificationType::sendNotification);
//
//        //[/UserSliderCode_modRateDial2]
//    }
//    else if (sliderThatWasMoved == modDepth2)
//    {
//        //[UserSliderCode_modDepth2] -- add your slider handling code here..
//        float depthDialValue = sliderThatWasMoved->getValue();
//        core->setParameterNotifyingHost(TremuluxCore::MOD_DEPTH2,
//                                            depthDialValue);
//        displayText = String(depthDialValue, 2);
//        modDepthText2->setText(displayText, juce::NotificationType::sendNotification);
//        //[/UserSliderCode_modDepth2]
//    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void TremuluxGUI::buttonClicked (Button* button)
{
//    const int currentlySynced = button->getToggleState();

//    if (button == syncFreeButton1)
//    {
//        core->setParameterNotifyingHost(TremuluxCore::MOD_SYNC_BUTTON1,
//                                            currentlySynced);
//        if(currentlySynced){
//            lastUnsyncedFreqs[0] = modRateDial1->getValue();
//            modRateDial1->setValue(lastSyncedFreqs[0]);
//        }
//        else{
//            lastSyncedFreqs[0] = modRateDial1->getValue();
//            modRateDial1->setValue(lastUnsyncedFreqs[0]);
//        }
//        sliderValueChanged(modRateDial1);
        //[/UserButtonCode_modSyncButton1]
//    }
//    else if (button == syncFreeButton2)
//    {
        //[UserButtonCode_modSyncButton2] -- add your button handler code here..
//        core->setParameterNotifyingHost(TremuluxCore::MOD_SYNC_BUTTON2,
//                                            currentlySynced);
//        if(currentlySynced){
//            lastUnsyncedFreqs[1] = modRateDial2->getValue();
//            modRateDial2->setValue(lastSyncedFreqs[1]);
//        }
//        else{
//            lastSyncedFreqs[1] = modRateDial2->getValue();
//            modRateDial2->setValue(lastUnsyncedFreqs[1]);
//        }
//        sliderValueChanged(modRateDial2);
        //[/UserButtonCode_modSyncButton2]
//    }
//    else if(button == bypassButton)
//    {
//        DBG("bypass");
//    }
//    else if(button == openButton)
//    {
//        //            if(audioRecorderPlayerGUI->isEmpty())
//        //            {
//        //                quickStart();
//        //            }
//        FileChooser fc("Load preset file...",
//                       File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
//                       "*.tremulux",
//                       true);
//        fc.browseForFileToOpen();
//        File presetFile = fc.getResult();
//        XmlElement * xmlPreset = XmlDocument(presetFile).getDocumentElement();
//
//        if(xmlPreset != nullptr)
//        {
////            audioRecorderPlayerGUI->stop();
////            core->clear();
////            core->mappingMatrix.clear();
////
////            core->deserialize(*xmlPreset);
//        }
//        else
//        {
//            AlertWindow("Invalid preset file", "The preset file you selected is not formatted correctly", AlertWindow::AlertIconType::NoIcon);
//        }
//
//        button->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    else if(button == saveButton)
//    {
//        FileChooser fc("Save preset as...",
//                       File::getSpecialLocation(File::SpecialLocationType::userDocumentsDirectory),
//                       "*.tremulux",
//                       true);
//        fc.browseForFileToSave(true);
//        File presetFile = fc.getResult();
//        XmlElement xmlPreset("TREMULUXNODE_PRESET");
//        core->serialize(xmlPreset);
//
//        if(presetFile.create().wasOk())
//        {
//            xmlPreset.writeToFile(presetFile, "");
//        }
//
//        button->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    lastButtonClicked = button;
//    updateButtonStates();
}

void TremuluxGUI::editorShown (Label* textBox, TextEditor& textEditor)
{
//    if(textBox == fromHighValue)
//    {
//        fromHighTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == fromLowValue)
//    {
//        fromLowTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == fromSkewValue)
//    {
//        fromSkewTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == toHighValue)
//    {
//        toHighTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == toLowValue)
//    {
//        toLowTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == toSkewValue)
//    {
//        toSkewTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
//    else if(textBox == discValue)
//    {
//        discTemp = textEditor.getText();
//        textEditor.setText("");
//        integerFilter(textEditor);
//    }
//    else if(textBox == smoothValue)
//    {
//        smoothTemp = textEditor.getText();
//        textEditor.setText("");
//        decimalFilter(textEditor);
//    }
    repaint();
}

void TremuluxGUI::editorHidden(Label* textBox, TextEditor& textEditor)
{
    if(textEditor.isEmpty())
    {
//        if(textBox == fromSkewValue)
//        {
//            disableLabeledValue(fromSkewLabel, fromSkewValue, fromSkewTemp);
//            fromSkewButton->setToggleState(false, sendNotification);
//        }
//        else if(textBox == toSkewValue)
//        {
//            disableLabeledValue(toSkewLabel, toSkewValue, toSkewTemp);
//            toSkewButton->setToggleState(false, sendNotification);
//        }
//        else if(textBox == discValue)
//        {
//            disableLabeledValue(discLabel, discValue, discTemp);
//            discButton->setToggleState(false, sendNotification);
//        }
//        else if(textBox == smoothValue)
//        {
//            disableLabeledValue(smoothLabel, smoothValue, smoothTemp);
//            smoothDial->setValue(0.0, sendNotification);
//        }
    }
    repaint();
}

void TremuluxGUI::labelTextChanged(Label* textBox)
{
//    jassert(mapping);
//    // Validate input
//    if(textBox == fromHighValue)
//    {
//        float input;
//        bool success = false;
//        if(parseDecimalInput(textBox, input) && validateRangeInput("from", input))
//        {
//            float lowValue = mapping->getRange("from").getStart();
//            if(input > lowValue)
//            {
//                mapping->setRange("from", lowValue, input);
//                // Discretized?
//                if(mapping->isDiscretized())
//                {
//                    input = mapping->getDiscretizedValue("from", input);
//                    mapping->setRange("from", lowValue, input);
//                }
//                const int precision = calculatePrecisionForRange(mapping->getRange("from").getLength());
//                textBox->setText(decimalToString(input, precision), dontSendNotification);
//                fromSlider->setMaxValue(input, dontSendNotification);
//                success = true;
//            }
//            else
//            {
//                AlertWindow::showMessageBox(AlertWindow::AlertIconType::NoIcon, "Error", "High value must be greater than low value.");
//            }
//        }
//        if(!success)
//        {
//            textBox->setText(fromHighTemp, dontSendNotification);
//        }
//    }
//    if(textBox == fromLowValue)
//    {
//        float input;
//        bool success = false;
//        if(parseDecimalInput(textBox, input) && validateRangeInput("from", input))
//        {
//            float highValue = mapping->getRange("from").getEnd();
//            if(input < highValue)
//            {
//                mapping->setRange("from", input, highValue);
//                // Discretized?
//                if(mapping->isDiscretized())
//                {
//                    input = mapping->getDiscretizedValue("from", input);
//                    mapping->setRange("from", input, highValue);
//                }
//                const int precision = calculatePrecisionForRange(mapping->getRange("from").getLength());
//                textBox->setText(decimalToString(input, precision), dontSendNotification);
//                fromSlider->setMinValue(input, dontSendNotification);
//                success = true;
//            }
//            else
//            {
//                AlertWindow::showMessageBox(AlertWindow::AlertIconType::NoIcon, "Error", "Low value must be less than high value.");
//            }
//        }
//        if(!success)
//        {
//            textBox->setText(fromLowTemp, dontSendNotification);
//        }
//    }
//    else if(textBox == fromSkewValue)
//    {
//        float input;
//        if(parseDecimalInput(textBox, input) && validateSkewInput("from", input))
//        {
//            mapping->setSkewAmount("from", true, input);
//            fromSlider->setSkewFactor(input);
//            textBox->setText(decimalToString(input), dontSendNotification);
//        }
//        else
//        {
//            mapping->setSkewAmount("from", false);
//            fromSlider->setSkewFactor(1.0);
//            disableLabeledValue(fromSkewLabel, fromSkewValue, fromSkewTemp);
//            fromSkewButton->setToggleState(false, dontSendNotification);
//        }
//    }
//    else if(textBox == toHighValue)
//    {
//        float input;
//        bool success = false;
//        if(parseDecimalInput(textBox, input) && validateRangeInput("to", input))
//        {
//            float lowValue = mapping->getRange("to").getStart();
//            if(input > lowValue)
//            {
//                mapping->setRange("to", lowValue, input);
//                // Discretized?
//                if(mapping->isDiscretized())
//                {
//                    input = mapping->getDiscretizedValue("to", input);
//                    mapping->setRange("to", lowValue, input);
//                }
//                const int precision = calculatePrecisionForRange(mapping->getRange("to").getLength());
//                textBox->setText(decimalToString(input, precision), dontSendNotification);
//                toSlider->setMaxValue(input, dontSendNotification);
//                success = true;
//            }
//            else
//            {
//                AlertWindow::showMessageBox(AlertWindow::AlertIconType::NoIcon, "Error", "High value must be greater than low value.");
//            }
//        }
//        if(!success)
//        {
//            textBox->setText(toHighTemp, dontSendNotification);
//        }
//    }
//    else if(textBox == toLowValue)
//    {
//        float input;
//        bool success = false;
//        if(parseDecimalInput(textBox, input) && validateRangeInput("to", input))
//        {
//            float highValue = mapping->getRange("to").getEnd();
//            if(input < highValue)
//            {
//                mapping->setRange("to", input, highValue);
//                // Discretized?
//                if(mapping->isDiscretized())
//                {
//                    input = mapping->getDiscretizedValue("to", input);
//                    mapping->setRange("to", input, highValue);
//                }
//                const int precision = calculatePrecisionForRange(mapping->getRange("to").getLength());
//                textBox->setText(decimalToString(input, precision), dontSendNotification);
//                toSlider->setMinValue(input, dontSendNotification);
//                success = true;
//            }
//            else
//            {
//                AlertWindow::showMessageBox(AlertWindow::AlertIconType::NoIcon, "Error", "Low value must be less than high value.");
//            }
//        }
//        if(!success)
//        {
//            textBox->setText(toLowTemp, dontSendNotification);
//        }
//    }
//    else if(textBox == toSkewValue)
//    {
//        float input;
//        if(parseDecimalInput(textBox, input) && validateSkewInput("to", input))
//        {
//            mapping->setSkewAmount("to", true, input);
//            toSlider->setSkewFactor(input);
//            textBox->setText(decimalToString(input), dontSendNotification);
//        }
//        else
//        {
//            mapping->setSkewAmount("to", false);
//            toSlider->setSkewFactor(1.0);
//            disableLabeledValue(toSkewLabel, toSkewValue, toSkewTemp);
//            toSkewButton->setToggleState(false, dontSendNotification);
//        }
//    }
//    else if(textBox == discValue)
//    {
//        int input;
//        if(parseIntegerInput(textBox, input) && validateDiscretizationInput(input))
//        {
//            mapping->setDiscretizationSteps(true, input);
//            textBox->setText((String)input, dontSendNotification);
//            textBox->setEnabled(true);
//        }
//        else
//        {
//            mapping->setDiscretizationSteps(false);
//            disableLabeledValue(discLabel, discValue, discTemp);
//            discButton->setToggleState(false, dontSendNotification);
//        }
//    }
//    else if(textBox == smoothValue)
//    {
//        float input;
//        if(parseDecimalInput(textBox, input) && validateSmoothingInput(input))
//        {
//            mapping->setSmoothing(input);
//            smoothDial->setValue(input);
//            textBox->setText(decimalToString(input), dontSendNotification);
//        }
//        else
//        {
//            mapping->setSmoothing(0);
//            disableLabeledValue(smoothLabel, smoothValue, smoothTemp);
//            smoothDial->setValue(0, dontSendNotification);
//        }
//    }
    repaint();
}

void TremuluxGUI::timerCallback()
{
    //exchange any data you want between UI elements and the plugin "ourProcessor"
//    if(core->NeedsUIUpdate()){
//        //TODO: add bypass button
//        //BypassButton->setToggleState(1.0f == core->getParameter(TremuluxCore::BYPASS), false);
//        mix->setValue(core->getParameter(TremuluxCore::MIX), juce::dontSendNotification);
//
//        modDepth1->setValue(core->getParameter(TremuluxCore::MOD_DEPTH1), juce::dontSendNotification);
//        modRateDial1->setValue(core->getParameter(TremuluxCore::MOD_RATE_DIAL1), juce::dontSendNotification);
//        modSyncButton1->setToggleState(core->getParameter(TremuluxCore::MOD_SYNC_BUTTON1),
//                                       juce::dontSendNotification);
//
//        modDepth2->setValue(core->getParameter(TremuluxCore::MOD_DEPTH2), juce::dontSendNotification);
//        modRateDial2->setValue(core->getParameter(TremuluxCore::MOD_RATE_DIAL2), juce::dontSendNotification);
//        modSyncButton2->setToggleState(core->getParameter(TremuluxCore::MOD_SYNC_BUTTON2),
//                                       juce::dontSendNotification);
//
//        core->ClearUIUpdateFlag();
//        //std::cout << "UIUpdated" << std::endl;
//    }

}

void TremuluxGUI::setRateDialRanges(const float max)
{
    for(int i = 0; i < NUM_MODS; ++i)
    {
        rateDials[i]->setRange(1.0, max, 0);
    }
}

void TremuluxGUI::visibilityChanged()
{
}

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
{
//    if(box == analysisComboBox)
//    {
//        if(shouldDisplayAnalysisData())
//        {
//            audioRecorderPlayerGUI->repaint();
//        }
//    }
}

void TremuluxGUI::updateButtonStates()
{
//    if(core->isAnalyzingStream())// Power button should be activated
    {
//        assert(bypassButton->getToggleState());

    }
}

void TremuluxGUI::clearOtherToggleStates(Button* button)
{
//    if(button != importButton)
//    {
//        importButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    if(button != commitButton)
//    {
//        commitButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    if(button != refreshButton)
//    {
//        refreshButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    if(button != recordButton)
//    {
//        recordButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    if(button != playButton)
//    {
//        playButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
//    if(button != stopButton)
//    {
//        stopButton->setToggleState(false, juce::NotificationType::dontSendNotification);
//    }
}

void TremuluxGUI::actionListenerCallback (const String& message)
{
//    if(message == "EOF")
//    {
//    }
//    else if(message == "No Audio Available")
//    {
//    }
//    else if(message == "Audio Available")
//    {
//    }
//    else if(message == "Mapping Window Closed")
//    {
//        curtain->setVisible(false);
//    }
//    else // Ignoring unrecognized messages
//    {
//        return;
//    }
//    updateButtonStates();
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
                 constructorParams="TremuluxCore* backend" variableInitialisers="core(backend),&#10;lookAndFeel(TREMULUX_THEME),&#10;curtain(new Curtain(this)),&#10;subWindow(new SubWindow(this)),&#10;waitFlag(nullptr),&#10;openButton(new DrawableButton(&quot;openButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;saveButton(new DrawableButton(&quot;saveButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;rateDials{{new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox),&#10;    new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox)}},&#10;rateDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;                                                                        TremuluxCore::rateParamID[0], *rateDials[0]),&#10;    new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;                                                       TremuluxCore::rateParamID[1], *rateDials[1])}},&#10;rateLabels{{new Label(&quot;rateLabel1&quot;, TRANS(&quot;rate&quot;)), new Label(&quot;rateLabel2&quot;, TRANS(&quot;rate&quot;))}},&#10;syncToggleButtons{{new DrawableButton(&quot;syncFreeButton1&quot;, DrawableButton::ButtonStyle::ImageStretched),&#10;    new DrawableButton(&quot;syncFreeButton2&quot;, DrawableButton::ButtonStyle::ImageStretched)}},&#10;syncToggleButtonAttachments{{new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(),&#10;                                                                                TremuluxCore::syncToggleParamID[0], *syncToggleButtons[0]),&#10;    new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(),&#10;                                                       TremuluxCore::syncToggleParamID[1], *syncToggleButtons[1])}},&#10;depthDials{{new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox),&#10;    new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox)}},&#10;depthDialAttachments{{new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;                                                                         TremuluxCore::depthParamID[0], *depthDials[0]), new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(),&#10;                                                                                                                                                                            TremuluxCore::depthParamID[1], *depthDials[1])}},&#10;depthLabels{{new Label(&quot;depth&quot;, TRANS(&quot;depth&quot;)), new Label(&quot;depth&quot;, TRANS(&quot;depth&quot;))}},&#10;mixDial(new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::TextBoxBelow)),&#10;mixDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(), TremuluxCore::mixParamID, *mixDial)),&#10;mixLabel(new Label(&quot;mix&quot;, TRANS(&quot;mix&quot;))),&#10;bypassButton(new DrawableButton(&quot;bypassButton&quot;, DrawableButton::ButtonStyle::ImageStretched)),&#10;bypassButtonAttachment(new AudioProcessorValueTreeState::ButtonAttachment(core-&gt;getParameterManager(), TremuluxCore::bypassParamID, *bypassButton)),&#10;gainDial(new Slider(Slider::SliderStyle::RotaryHorizontalVerticalDrag, Slider::TextEntryBoxPosition::NoTextBox)),&#10;gainDialAttachment(new AudioProcessorValueTreeState::SliderAttachment(core-&gt;getParameterManager(), TremuluxCore::gainParamID, *gainDial)),&#10;gainLabel(new Label(&quot;gain&quot;, TRANS(&quot;gain&quot;)))"
                 snapPixels="12" snapActive="1" snapShown="0" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="456" initialHeight="384">
  <BACKGROUND backgroundColour="ff1a1a1a">
    <ROUNDRECT pos="24 48 408 312" cornerSize="3" fill="solid: 33564b44" hasStroke="0"/>
    <RECT pos="27 51 402 306" fill="solid: 33564b44" hasStroke="0"/>
    <RECT pos="0 24 338 2" fill="solid: ffffde00" hasStroke="0"/>
    <RECT pos="0 0 144 24" fill="solid: ffffde00" hasStroke="0"/>
    <TEXT pos="24 4 48 22" fill="solid: ff84adbc" hasStroke="0" text="PRESETS"
          fontname="Myriad Pro" fontsize="12" bold="1" italic="0" justification="33"/>
    <TEXT pos="336 8 96 36" fill="solid: ffffde00" hasStroke="0" text="( TREMULUX"
          fontname="Myriad Pro" fontsize="18" bold="1" italic="0" justification="34"/>
    <ROUNDRECT pos="48 72 252 120" cornerSize="3" fill="solid: 84adbc" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: fff1de00"/>
    <ROUNDRECT pos="324 72 84 263" cornerSize="3" fill="solid: 0" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffffde00"/>
    <ELLIPSE pos="156 120 36 36" fill="solid: ff808080" hasStroke="0"/>
    <ELLIPSE pos="348 192 36 36" fill="solid: ff808080" hasStroke="0"/>
    <ELLIPSE pos="72 108 60 60" fill="solid: 515151" hasStroke="0"/>
    <ELLIPSE pos="216 108 60 60" fill="solid: 515151" hasStroke="0"/>
    <TEXT pos="24 4 48 22" fill="solid: ff515151" hasStroke="0" text="PRESETS"
          fontname="Myriad Pro" fontsize="12" bold="1" italic="0" justification="33"/>
    <TEXT pos="48 72 252 24" fill="solid: ffffde00" hasStroke="0" text="oscillator I"
          fontname="Myriad Pro" fontsize="14" bold="1" italic="0" justification="36"/>
    <TEXT pos="324 72 84 24" fill="solid: ffffde00" hasStroke="0" text="master"
          fontname="Myriad Pro" fontsize="14" bold="1" italic="0" justification="36"/>
    <ROUNDRECT pos="48 216 252 120" cornerSize="3" fill="solid: 0" hasStroke="1"
               stroke="1, mitered, butt" strokeColour="solid: ffffde00"/>
    <ELLIPSE pos="156 264 36 36" fill="solid: ff808080" hasStroke="0"/>
    <ELLIPSE pos="72 252 60 60" fill="solid: 515151" hasStroke="0"/>
    <ELLIPSE pos="216 252 60 60" fill="solid: 515151" hasStroke="0"/>
    <TEXT pos="48 216 252 24" fill="solid: ffffde00" hasStroke="0" text="oscillator II"
          fontname="Myriad Pro" fontsize="14" bold="1" italic="0" justification="36"/>
    <ELLIPSE pos="336 108 60 60" fill="solid: 515151" hasStroke="0"/>
    <ELLIPSE pos="336 252 60 60" fill="solid: 515151" hasStroke="0"/>
  </BACKGROUND>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
