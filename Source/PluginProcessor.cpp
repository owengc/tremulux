/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginInterface.h"


//==============================================================================
TremuluxAudioProcessor::TremuluxAudioProcessor()
{
    sineTable.setWaveform(Wavetable<float>::WAVEFORM::SINE, true);
    
    for(int i = 0; i < NUM_SYNC_OPTIONS; i++){
        SYNC_OPTIONS option = (SYNC_OPTIONS)i;
        switch(option){
            case OFF:
                syncModeLabels.add("NULL");
                syncFactors[OFF] = 0.0;
                break;
            case TWO_BARS:
                syncModeLabels.add("Two Bars");
                syncFactors[TWO_BARS] = 0.0;
                break;
            case ONE_BAR:
                syncModeLabels.add("One Bar");
                syncFactors[ONE_BAR] = 0.0;
                break;
            case HALF:
                syncModeLabels.add("1/2");
                syncFactors[HALF] = 1.0 / 120;
                break;
            case DOTTED_QUARTER:
                syncModeLabels.add("Dotted 1/4");
                syncFactors[DOTTED_QUARTER] = 1.0 / 90;
                break;
            case QUARTER:
                syncModeLabels.add("1/4");
                syncFactors[QUARTER] = 1.0 / 60.0;
                break;
            case TRIPLET_QUARTER:
                syncModeLabels.add("1/4 Triplet");
                syncFactors[TRIPLET_QUARTER] = 1.0 / 40.0;
                break;
            case DOTTED_EIGHTH:
                syncModeLabels.add("Dotted 1/8");
                syncFactors[DOTTED_EIGHTH] = 1.0 / 45.0;
                break;
            case EIGHTH:
                syncModeLabels.add("1/8");
                syncFactors[EIGHTH] = 1.0 / 30.0;
                break;
            case TRIPLET_EIGHTH:
                syncModeLabels.add("1/8 Triplet");
                syncFactors[TRIPLET_EIGHTH] = 1.0 / 20.0;
                break;
            case DOTTED_SIXTEENTH:
                syncModeLabels.add("Dotted 1/16");
                syncFactors[DOTTED_SIXTEENTH] = 1.0 / 22.5;
                break;
            case SIXTEENTH:
                syncModeLabels.add("1/16");
                syncFactors[SIXTEENTH] = 1.0 / 15.0;
                break;
            case TRIPLET_SIXTEENTH:
                syncModeLabels.add("1/16 Triplet");
                syncFactors[TRIPLET_SIXTEENTH] = 1.0 / 10.0;
                break;
            case NUM_SYNC_OPTIONS:
                //just here to avoid warning
                break;
        }
    }
    
    //Not sure if these defaults will screw things up...
    lastBPM = 120;
    lastTimeSigDenominator = 4;
    lastTimeSigNumerator = 4;
    modInterp = 1024;
    
    setParameter(MIX, 0.5);
    
    setParameter(MOD_DEPTH1, 0.5);
    setParameter(MOD_SYNC_BUTTON1, 1);
    setParameter(MOD_SYNC1, QUARTER);
    setParameter(MOD_RATE_DIAL1, 5.0);

    
    setParameter(MOD_DEPTH2, 0.5);
    setParameter(MOD_SYNC_BUTTON2, 1);
    setParameter(MOD_SYNC2, EIGHTH);
    setParameter(MOD_RATE_DIAL2, 8.0);
    
    UIUpdateFlag = true;
}

TremuluxAudioProcessor::~TremuluxAudioProcessor()
{
}

//==============================================================================
const String TremuluxAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int TremuluxAudioProcessor::getNumParameters()
{
    return NUM_PARAMS;
}

float TremuluxAudioProcessor::getParameter (int index)
{
    PARAMS p = (PARAMS) index;
    switch(p){
        case MOD_DEPTH1:
            return modDepthTargets[0];
        case MOD_RATE_DIAL1:
            return modRateDials[0];
        case MOD_RATE1:
            return modRateTargets[0];
        case MOD_SYNC1:
            return modSyncs[0];
        case MOD_SYNC_BUTTON1:
            return modSyncButtons[0];
        case MOD_DEPTH2:
            return modDepthTargets[1];
        case MOD_RATE_DIAL2:
            return modRateDials[1];
        case MOD_RATE2:
            return modRateTargets[1];
        case MOD_SYNC2:
            return modSyncs[1];
        case MOD_SYNC_BUTTON2:
            return modSyncButtons[1];
        case MIX:
            return mix;
        default:
            return 0.0f;
    }
}

void TremuluxAudioProcessor::setParameter (int index, float newValue)
{
    PARAMS p = (PARAMS) index;
    switch(p){
        case MOD_DEPTH1:// [0.0, 1.0]
            modDepthTargets[0] = newValue;
            mods[0].updateAmp(newValue, modInterp);
            break;
        case MOD_RATE_DIAL1:// [0.1, 1.2]
            modRateDials[0] = newValue;
            setParameter(TremuluxAudioProcessor::MOD_RATE1, calcRate(newValue, 0));
            break;
        case MOD_RATE1:
            // Only called when MOD_RATE_DIAL1 changes, should receive Hz value
            modRateTargets[0] = newValue;
            mods[0].updateFreq(newValue, modInterp);
            break;
        case MOD_SYNC_BUTTON1:// 0.0 or 1.0
            modSyncButtons[0] = (int)newValue;
            break;
        case MOD_SYNC1:// SYNC_OPTIONS
            // Only called when MOD_SYNC_BUTTON1 or MOD_RATE_DIAL1 changes
            modSyncs[0] = (SYNC_OPTIONS)newValue;
            break;
        case MOD_DEPTH2:// [0.0, 1.0]
            modDepthTargets[1] = newValue;
            mods[1].updateAmp(newValue, modInterp);
            break;
        case MOD_RATE_DIAL2:// [0.1, 1.2]
            modRateDials[1] = newValue;
            setParameter(TremuluxAudioProcessor::MOD_RATE2, calcRate(newValue, 1));
            break;
        case MOD_RATE2:
            // Only called when MOD_RATE_DIAL1 changes, should receive Hz value
            modRateTargets[1] = newValue;
            mods[1].updateFreq(newValue, modInterp);
            break;
        case MOD_SYNC_BUTTON2:// 0.0 or 1.0
            modSyncButtons[1] = (int)newValue;
            break;
        case MOD_SYNC2:// SYNC_OPTIONS
            // Only called when MOD_SYNC_BUTTON2 or MOD_RATE_DIAL2 changes
            modSyncs[1] = (SYNC_OPTIONS)newValue;
            break;
        case MIX:// [0.0, 1.0]
            mix = newValue;
            break;
        case NUM_PARAMS:
            // Just here to avoid warnings
            break;
    }
    return;
}

const String TremuluxAudioProcessor::getParameterName (int index)
{
    PARAMS p = (PARAMS) index;
    switch(p){
        case MOD_DEPTH1:
            return "Modulator 1 Depth";
        case MOD_RATE_DIAL1:
            return "modratedial1";
        case MOD_RATE1:
            return "Modulator 1 Rate";
        case MOD_SYNC1:
            return "Modulator 1 Sync Mode";
        case MOD_DEPTH2:
            return "Modulator 2 Depth";
        case MOD_RATE_DIAL2:
            return "modratedial2";
        case MOD_RATE2:
            return "Modulator 2 Rate";
        case MOD_SYNC2:
            return "Modulator 2 Sync Mode";
        case MIX:
            return "Master Mix";
        default:
            return "";
    }
}

const String TremuluxAudioProcessor::getParameterText (int index)
{
    PARAMS p = (PARAMS) index;
    switch(p){
        case MOD_DEPTH1:
            return String(modDepthTargets[0], 2);
        case MOD_RATE_DIAL1:
            return "modratedial1 value";
        case MOD_RATE1:
            if(modSyncButtons[0]){
                return syncModeLabels[modSyncs[0]];
            }
            else{
                return String(modRateTargets[0], 2);
            }
        case MOD_SYNC1:
            return "modsync1 value";
        case MOD_DEPTH2:
            return String(modDepthTargets[1], 2);
        case MOD_RATE_DIAL2:
            return "modratedial2 value";
        case MOD_RATE2:
            if(modSyncButtons[0]){
                return syncModeLabels[modSyncs[1]];
            }
            else{
                return String(modRateTargets[1], 2);
            }
        case MOD_SYNC2:
            return "modsync2 value";
        case MIX:
            return String(mix, 2);
        default:
            return "";
    }
}

const String TremuluxAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String TremuluxAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool TremuluxAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool TremuluxAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool TremuluxAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TremuluxAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TremuluxAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double TremuluxAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TremuluxAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TremuluxAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TremuluxAudioProcessor::setCurrentProgram (int index)
{
}

const String TremuluxAudioProcessor::getProgramName (int index)
{
    return String();
}

void TremuluxAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TremuluxAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
 
    for(int m = 0; m < numMods; m++){
        mods[m].init(&sineTable, sampleRate);
        mods[m].start(modDepthTargets[m], modRateTargets[m], 0.0);
    }
}

void TremuluxAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void TremuluxAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    int numSamples = buffer.getNumSamples();
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, numSamples);

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    if(modSyncButtons[0] || modSyncButtons[1]){
        // at least one mod is in sync mode, check for changes in transport
        updateSyncedRates();
    }
    for (int channel = 0; channel < getNumInputChannels(); ++channel)
    {
        const float* inData = buffer.getReadPointer(channel);
        float* outData = buffer.getWritePointer(channel);
        for(int i = 0; i < numSamples; i++){
            float in = *inData++;
            float out = in;
            for(int m = 0; m < numMods; m++){//testing
                out *= (1 + mods[m].next() * 0.5);
                
                // This is here to keep updateRates informed
                modRates[m] = mods[m].getFrequency();
            }
            *outData++ = mix * out + (1.0 - mix) * in;
        }
    }
}

//==============================================================================
bool TremuluxAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TremuluxAudioProcessor::createEditor()
{
    return new PluginInterface (*this);
}

//==============================================================================
void TremuluxAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    XmlElement root("Root");
    XmlElement *el;
    el = root.createNewChildElement("Mix");
    el->addTextElement(String(mix));
    el = root.createNewChildElement("ModRate1");
    el->addTextElement(String(modRateTargets[0]));
    el = root.createNewChildElement("ModRateDial1");
    el->addTextElement(String(modRateDials[0]));
    el = root.createNewChildElement("ModDepth1");
    el->addTextElement(String(modDepthTargets[0]));
    el = root.createNewChildElement("ModSyncButton1");
    el->addTextElement(String(modSyncButtons[0]));
    el = root.createNewChildElement("ModSync1");
    el->addTextElement(String(modSyncs[0]));
    
    
    el = root.createNewChildElement("ModRate2");
    el->addTextElement(String(modRateTargets[1]));
    el = root.createNewChildElement("ModRateDial2");
    el->addTextElement(String(modRateDials[1]));
    el = root.createNewChildElement("ModDepth2");
    el->addTextElement(String(modDepthTargets[1]));
    el = root.createNewChildElement("ModSyncButton2");
    el->addTextElement(String(modSyncButtons[1]));
    el = root.createNewChildElement("ModSync2");
    el->addTextElement(String(modSyncs[1]));
    
    copyXmlToBinary(root, destData);
}

void TremuluxAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    XmlElement *pRoot = getXmlFromBinary(data, sizeInBytes);
    if(pRoot != NULL){
        forEachXmlChildElement((*pRoot), pChild){
            if(pChild->hasTagName("Mix")){
                String text = pChild->getAllSubText();
                setParameter(MIX, text.getFloatValue());
            }
            
            if(pChild->hasTagName("ModRate1")){
                String text = pChild->getAllSubText();
                setParameter(MOD_RATE1, text.getFloatValue());
            }
            if(pChild->hasTagName("ModRateDial1")){
                String text = pChild->getAllSubText();
                setParameter(MOD_RATE_DIAL1, text.getFloatValue());
            }
            if(pChild->hasTagName("ModDepth1")){
                String text = pChild->getAllSubText();
                setParameter(MOD_DEPTH1, text.getFloatValue());
            }
            if(pChild->hasTagName("ModSyncButton1")){
                String text = pChild->getAllSubText();
                setParameter(MOD_SYNC_BUTTON1, text.getFloatValue());
            }
            if(pChild->hasTagName("ModSync1")){
                String text = pChild->getAllSubText();
                setParameter(MOD_SYNC1, text.getFloatValue());
            }
            
            
            if(pChild->hasTagName("ModRate2")){
                String text = pChild->getAllSubText();
                setParameter(MOD_RATE2, text.getFloatValue());
            }
            if(pChild->hasTagName("ModRateDial2")){
                String text = pChild->getAllSubText();
                setParameter(MOD_RATE_DIAL2, text.getFloatValue());
            }
            if(pChild->hasTagName("ModDepth2")){
                String text = pChild->getAllSubText();
                setParameter(MOD_DEPTH2, text.getFloatValue());
            }
            if(pChild->hasTagName("ModSyncButton2")){
                String text = pChild->getAllSubText();
                setParameter(MOD_SYNC_BUTTON2, text.getFloatValue());
            }
            if(pChild->hasTagName("ModSync2")){
                String text = pChild->getAllSubText();
                setParameter(MOD_SYNC2, text.getFloatValue());
            }
        }
        delete pRoot;
    }
    UIUpdateFlag = true; //Request UI update
}

float TremuluxAudioProcessor::calcSyncedRate(const int mode, const int modID){
    float rate;
    if(mode == TWO_BARS || mode == ONE_BAR){
        float beat;
        switch(lastTimeSigDenominator){
            case 2:
                beat = syncFactors[HALF];
                break;
            case 4:
                beat = syncFactors[QUARTER];
                break;
            case 8:
                beat = syncFactors[SIXTEENTH];
                break;
            default:
                //just to be safe?
                beat = syncFactors[QUARTER];
                break;
        }
        rate = beat * lastBPM / lastTimeSigNumerator;
        if(mode == TWO_BARS){
            rate *= 0.5;
        }
    }
    else{
        rate = syncFactors[mode] * lastBPM;
    }
    return rate;
}

float TremuluxAudioProcessor::calcRate(const float freqDialValue, const int modID){
    float rate;
    if(modSyncButtons[modID]){
        //sync activated
        int mode = modSyncs[modID];
        rate = calcSyncedRate(mode, modID);
    }
    else{
        rate = minFreeRate + (freqDialValue * oneOverFreqDialRange) * (maxFreeRate - minFreeRate);
    }
    return rate;
}

void TremuluxAudioProcessor::updateSyncedRates(const bool force)
{
    // Called at beginning of processBlock iff a mod is in sync mode
    // sets new modFreqTargets to reflect changes in tempo or time signature,
    // if there have been any such changes
    
    transport = getPlayHead();
    transport->getCurrentPosition(transportInfo);
    float bpm = transportInfo.bpm;
    int timeSigDenominator = transportInfo.timeSigDenominator,
    timeSigNumerator = transportInfo.timeSigNumerator;
    if(force || bpm != lastBPM ||
       timeSigDenominator != lastTimeSigDenominator ||
       timeSigNumerator != lastTimeSigNumerator){
        lastBPM = bpm;
        lastTimeSigDenominator = timeSigDenominator;
        lastTimeSigNumerator = timeSigNumerator;
        for(int m = 0; m < numMods; m++){
            int mode = modSyncs[m];
            assert(mode > 0);
            modRateTargets[m] = calcSyncedRate(mode, m);
            if(modRateTargets[m] != modRates[m]){
                mods[m].updateFreq(modRateTargets[m], modInterp);
            }
        }
    }
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TremuluxAudioProcessor();
}
