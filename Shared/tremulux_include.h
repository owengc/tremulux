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
    
constexpr unsigned int NUM_MODS = 2, LOWPASS_CUTOFF = 11000, LOWPASS_ORDER = 3;

constexpr float OUTPUT_SCALING_FACTOR = 1.0 / (NUM_MODS + 1);
    
    
// Layout
constexpr unsigned int
    // General
    WINDOW_W = 456, WINDOW_H = 384,
    
    // Main Panel
    PANEL_X = MARGIN, PANEL_Y = 2 * MARGIN,
    PANEL_W = WINDOW_W - 2 * MARGIN, PANEL_H = WINDOW_H - 3 * MARGIN,
    
    LABEL_H = UNIT_SIZE, LABEL_TEXT = 9,
    VALUE_H = UNIT_SIZE, VALUE_TEXT = 9,
    
        // Oscillator Controls
        OSCILLATOR1_Y = PANEL_Y + MARGIN + M_SIZE,
        OSCILLATORLABEL1_Y = OSCILLATOR1_Y - LABEL_H + UNIT_INDENT,
        OSCILLATORVALUE1_Y = OSCILLATOR1_Y + XL_SIZE,
    
        OSCILLATOR2_Y = OSCILLATOR1_Y + 2 * MARGIN + XL_SIZE + M_SIZE,
        OSCILLATORLABEL2_Y = OSCILLATOR2_Y - LABEL_H + UNIT_INDENT,
        OSCILLATORVALUE2_Y = OSCILLATOR2_Y + XL_SIZE,
    
        RATE_X = PANEL_X + 2 * MARGIN, RATE_D = XL_SIZE,
        RATELABEL_X = RATE_X, RATELABEL_W = RATE_D,
    
        SYNC_X = RATE_X + RATE_D + MARGIN, SYNC_D = M_SIZE,
        SYNC1_Y = OSCILLATOR1_Y + UNIT_SIZE,
        SYNC2_Y = OSCILLATOR2_Y + UNIT_SIZE,
    
        DEPTH_X = SYNC_X + SYNC_D + MARGIN, DEPTH_D = XL_SIZE,
        DEPTHLABEL_X = DEPTH_X, DEPTHLABEL_W = RATE_D,
    
        // Master Controls
        MIX_X = PANEL_X + 13 * S_SIZE, MIX_D = XL_SIZE,
        MIXLABEL_X = MIX_X, MIXLABEL_W = MIX_D,
    
        BYPASS_X = MIX_X + UNIT_SIZE, BYPASS_D = M_SIZE,
        BYPASS_Y = OSCILLATOR1_Y + MIX_D + MARGIN,
    
        GAIN_X = MIX_X, GAIN_D = XL_SIZE,
        GAINLABEL_X = GAIN_X, GAINLABEL_W = GAIN_D;
    
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
