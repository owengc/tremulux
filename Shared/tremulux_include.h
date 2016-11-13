/*
  ==============================================================================

    tremulux_include.h
    Created: 27 Jul 2015 5:37:03pm
    Author:  Owen Campbell

  ==============================================================================
*/

#ifndef TREMULUX_INCLUDE_H_INCLUDED
#define TREMULUX_INCLUDE_H_INCLUDED

//Includes
#include <array>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
//#include <atomic>
#include <cstdlib>
#include <unistd.h>
#include <string>

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include "utilities.h"
#include "flatLookAndFeel.h"

//Globals

using namespace utilities;

namespace tremulux {
    const std::string APPDIR_PATH = File::addTrailingSeparator(File::getSpecialLocation(File::SpecialLocationType::userApplicationDataDirectory).getFullPathName()).toStdString()
    + "tremulux";
    
    constexpr double BANDPASS_CENTER_FREQUENCY = 500, BANDPASS_BANDWIDTH = BANDPASS_CENTER_FREQUENCY * 0.85;
    constexpr unsigned int NUM_MODS = 2;
//    , NUM_COEFFICIENTS = 11;
//    
//    const std::vector<double> NUMERATOR_COEFFICIENTS = {
//        
//        0.0847392328045,
//        -0.476359958368,
//        1.22600097567,
//        -1.80059132753,
//        1.40738995377,
//        0.0,
//        -1.40738995377,
//        1.80059132753,
//        -1.22600097567, 
//        0.476359958368, 
//        -0.0847392328045
//    },
//                             DENOMINATOR_COEFFICIENTS = {
//                                 1.0,
//                                 -6.58344135363,
//                                 20.8731391178,
//                                 -41.5776591469,
//                                 57.3685463177,
//                                 -57.1351584317, 
//                                 41.5460432542, 
//                                 -21.7781320748, 
//                                 7.88580685068, 
//                                 -1.78577330015, 
//                                 0.193688018545
//                             };

constexpr float MODULATION_SCALING_FACTOR = 1.0 / NUM_MODS;
    
    
// Layout
constexpr unsigned int
    // General
    WINDOW_W = 480, WINDOW_H = 372,
    
    // Main Panel
    PANEL_X = MARGIN, PANEL_Y = 2 * MARGIN,
    PANEL_W = WINDOW_W - 2 * MARGIN, PANEL_H = WINDOW_H - 3 * MARGIN,
    
    LABEL_H = UNIT_SIZE, LABEL_TEXT = 9,
    VALUE_H = UNIT_SIZE, VALUE_TEXT = 9,
    
        // Rows
        TOP_Y = PANEL_Y + 2 * MARGIN,
        TOPLABEL_Y = TOP_Y - LABEL_H + UNIT_INDENT,
        TOPVALUE_Y = TOP_Y + XL_SIZE,
    
        MIDDLE_Y = TOP_Y + XL_SIZE + MARGIN,
        MIDDLELABEL_Y = MIDDLE_Y - LABEL_H + UNIT_INDENT,
        MIDDLEVALUE_Y = MIDDLE_Y + M_SIZE,
    
        BOTTOM_Y = MIDDLE_Y + M_SIZE + MARGIN,
        BOTTOMLABEL_Y = BOTTOM_Y - LABEL_H + UNIT_INDENT,
        BOTTOMVALUE_Y = BOTTOM_Y + XL_SIZE,
    
        // Columns
        OSCILLATOR1_X = PANEL_X + 2 * MARGIN,
    
        BLEND_X = OSCILLATOR1_X + XL_SIZE + MARGIN + 2,
    
        OSCILLATOR2_X = BLEND_X - 2 + M_SIZE + MARGIN,
    
        MASTER_X = OSCILLATOR2_X + XL_SIZE + 3 * MARGIN,
    
        // Oscillator Controls
        RATE_D = XL_SIZE,
        RATE1_X = OSCILLATOR1_X,
        RATE2_X = OSCILLATOR2_X,
        RATE_Y = TOP_Y,
        RATELABEL_Y = TOPLABEL_Y,
        RATEVALUE_Y = TOPVALUE_Y,
    
        SYNC_D = M_SIZE,
        SYNC1_X = OSCILLATOR1_X + UNIT_SIZE,
        SYNC2_X = OSCILLATOR2_X + UNIT_SIZE,
        SYNC_Y = MIDDLE_Y,
    
        DEPTH_D = XL_SIZE,
        DEPTH1_X = OSCILLATOR1_X,
        DEPTH2_X = OSCILLATOR2_X,
        DEPTH_Y = BOTTOM_Y,
        DEPTHLABEL_Y = BOTTOMLABEL_Y,
        DEPTHVALUE_Y = BOTTOMVALUE_Y,
    
        // Master Controls
        // BLEND_X above...
        BLEND_Y = MIDDLE_Y,
        BLEND_D = M_SIZE,
        BLENDLABEL_Y = MIDDLELABEL_Y,
        BLENDVALUE_Y = MIDDLEVALUE_Y,
    
        MIX_X = MASTER_X,
        MIX_Y = TOP_Y,
        MIX_D = XL_SIZE,
        MIXLABEL_Y = TOPLABEL_Y,
        MIXVALUE_Y = TOPVALUE_Y,
    
        BYPASS_X = MIX_X + UNIT_SIZE,
        BYPASS_Y = MIDDLE_Y,
        BYPASS_D = M_SIZE,
    
        GAIN_X = MASTER_X,
        GAIN_Y = BOTTOM_Y,
        GAIN_D = XL_SIZE,
        GAINLABEL_Y = BOTTOMLABEL_Y,
        GAINVALUE_Y = BOTTOMVALUE_Y;
    
    
    
//
//    
//            // 'From' Elements
//            FROM_HEADER_X = UNIT_SIZE,                              FROM_HEADER_Y = UNIT_SIZE,
//    
//            FROM_HIGH_VALUE_X = M_SIZE - UNIT_SIZE/2,               FROM_HIGH_VALUE_Y = 4 * S_SIZE,
//            FROM_SLIDER_X = FROM_HIGH_VALUE_X + UNIT_SIZE,          FROM_SLIDER_Y = FROM_HIGH_VALUE_Y + MAPPING_VALUE_H,
//            FROM_LOW_VALUE_X = FROM_HIGH_VALUE_X,                   FROM_LOW_VALUE_Y = FROM_SLIDER_Y + MAPPING_SLIDER_H,
//    
//            FROM_SKEW_LABEL_X = M_SIZE,                             FROM_SKEW_LABEL_Y = FROM_LOW_VALUE_Y + M_SIZE,
//            FROM_SKEW_BUTTON_X = FROM_SKEW_LABEL_X,                 FROM_SKEW_BUTTON_Y = FROM_SKEW_LABEL_Y + MAPPING_LABEL_H,
//            FROM_SKEW_VALUE_X = FROM_SKEW_LABEL_X,                  FROM_SKEW_VALUE_Y = FROM_SKEW_BUTTON_Y + MAPPING_BUTTON_H,
//  
//            // 'To' Elements
//            TO_HEADER_X = 13 * UNIT_SIZE,                           TO_HEADER_Y = FROM_HEADER_Y,
//
//            TO_HIGH_VALUE_X = 5 * M_SIZE - UNIT_SIZE/2,                           TO_HIGH_VALUE_Y = FROM_HIGH_VALUE_Y,
//            TO_SLIDER_X = TO_HIGH_VALUE_X + UNIT_SIZE,              TO_SLIDER_Y = FROM_SLIDER_Y,
//            TO_LOW_VALUE_X = TO_HIGH_VALUE_X,                       TO_LOW_VALUE_Y = FROM_LOW_VALUE_Y,
//
//            TO_SKEW_LABEL_X = 5 * M_SIZE,                           TO_SKEW_LABEL_Y = FROM_SKEW_LABEL_Y,
//            TO_SKEW_BUTTON_X = TO_SKEW_LABEL_X,                     TO_SKEW_BUTTON_Y = FROM_SKEW_BUTTON_Y,
//            TO_SKEW_VALUE_X = TO_SKEW_LABEL_X,                      TO_SKEW_VALUE_Y = FROM_SKEW_VALUE_Y,
//    
//            // Shared UI Elements
//            POL_LABEL_X = 3 * M_SIZE,                               POL_LABEL_Y = FROM_SKEW_LABEL_Y,
//            POL_BUTTON_X = POL_LABEL_X,                             POL_BUTTON_Y = POL_LABEL_Y + MAPPING_LABEL_H,
//    
//            DISC_LABEL_X = 7 * UNIT_SIZE,                           DISC_LABEL_Y = 16 * S_SIZE,
//            DISC_BUTTON_X = DISC_LABEL_X,                           DISC_BUTTON_Y = DISC_LABEL_Y + MAPPING_LABEL_H,
//            DISC_VALUE_X = DISC_LABEL_X,                            DISC_VALUE_Y = DISC_BUTTON_Y + MAPPING_BUTTON_H,
//    
//            SMOOTH_LABEL_X = 11 * UNIT_SIZE,                        SMOOTH_LABEL_Y = DISC_LABEL_Y,
//            SMOOTH_DIAL_X = SMOOTH_LABEL_X,                         SMOOTH_DIAL_Y = SMOOTH_LABEL_Y + MAPPING_LABEL_H,
//            SMOOTH_VALUE_X = SMOOTH_LABEL_X,                        SMOOTH_VALUE_Y = SMOOTH_DIAL_Y + MAPPING_BUTTON_H;
}


#endif  // TREMULUX_INCLUDE_H_INCLUDED
