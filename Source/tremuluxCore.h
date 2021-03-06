/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef TREMULUXCORE_H_INCLUDED
#define TREMULUXCORE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "tremulux_include.h"
#include "../../calib/include/blocks/Filter.h"
#include "../../calib/include/blocks/Oscillator.h"


using namespace tremulux;

class TremuluxGUI;

//==============================================================================
/**
*/

class TremuluxCore  : public AudioProcessor, public AudioProcessorValueTreeState::Listener
{
public:
    friend class TremuluxGUI;
    
    const float RATE_DIAL_RANGE = NUM_SYNC_OPTIONS - 1;
    const float ONE_BY_RATE_DIAL_RANGE = 1.0 / RATE_DIAL_RANGE;
    const float MIN_FREE_RATE = 0.1, MAX_FREE_RATE = 11.0;

    //==============================================================================
    TremuluxCore();
    ~TremuluxCore();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
    void numChannelsChanged() override;
    void numBusesChanged() override;
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    
    const String getName() const override;
    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    
    void parameterChanged(const String &parameterID, float newValue) override;
    
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    AudioProcessorValueTreeState& getParameterManager();

    //==============================================================================
    
    void setGUI(TremuluxGUI* frontend);
    void clear();
    
    //==============================================================================

    void serialize(XmlElement& xml);

    void deserialize(XmlElement& xml);

    //==============================================================================

protected:
    TremuluxGUI* gui;
    CriticalSection callbackLock;
    
private:
    
    bool updateTransportInfo(const bool force = false);
    inline int getSyncMode(const int modID);
    float getSyncedRate(const int modID);
    float getUnsyncedRate(const int modID);
    void updateOscillators(const int interpolationLength);
    
    //==============================================================================

    File logFile;
    FileLogger logger;
    
    float sampleRate, maxModRate;
    bool isStereoToMono, isMono;
    unsigned int numInputChannels, numOutputChannels;
    
    std::shared_ptr<Wavetable<double> > sineTable;
    std::array<Sine<double>, NUM_MODS> mods;
//    std::array<RecursiveFilter<double>, NUM_MODS> bandPasses;
    std::array<RecursiveBandPass<double>, NUM_MODS> bandPasses;
    
    //==============================================================================
    // Parameters
    
    ScopedPointer<UndoManager> undoManager;
    ScopedPointer<AudioProcessorValueTreeState> parameterManager;
    
    static String mixParamID;
    static String bypassParamID;
    static String gainParamID;
    static String blendParamID;
    static String rateParamID[NUM_MODS];
    static String depthParamID[NUM_MODS];
    static String syncToggleParamID[NUM_MODS];
    static String syncModeParamID[NUM_MODS];
    
    std::atomic<bool> bypassData;
    std::atomic<float> mixData, gainData, blendData;
    std::atomic<unsigned int> interpData;
    std::array<std::atomic<float>, NUM_MODS> rateData;
    std::array<std::atomic<bool>, NUM_MODS> rateChanged;
    std::array<std::atomic<float>, NUM_MODS> depthData;
    std::array<std::atomic<bool>, NUM_MODS> syncToggleData;
    std::array<std::atomic<int>, NUM_MODS> syncModeData;
    AudioBuffer<float> blendBuffer;

    //==============================================================================
    // Tempo Sync
    
    AudioPlayHead *transport;
    AudioPlayHead::CurrentPositionInfo transportInfo;
    std::atomic<float> lastBPM;
    std::atomic<unsigned int> lastTimeSigDenominator, lastTimeSigNumerator;
    
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremuluxCore)
};


#endif  // TREMULUXCORE_H_INCLUDED
