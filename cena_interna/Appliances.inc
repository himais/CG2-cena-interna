//////////////////////////////////////////////////////////////////////////
// Appliances.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs      //
//////////////////////////////////////////////////////////////////////////
// Provides macros for creating various major appliances.               //
//////////////////////////////////////////////////////////////////////////

// This file should only be included once!
#ifndef (_Appliances_Inc_)
#declare _Appliances_Inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Appliances.inc\n"
#end

#include "Units.inc"
#include "Textures.inc"
#include "HardwareTextures.inc"


// We'll make washers and dryers look the same!
#macro WasherDryer(
            baseWidth,
            baseHeight,
            baseDepth,
            unitTexture)
            
    #local topThick = 2 * INCH;
    #local topGap   = 3/8 * INCH;
    
    union { // Just a box box with a smaller box on top ... for now!
        union {
            box {
                < -baseWidth / 2, 1 * INCH, 0 >,
                <  baseWidth / 2,
                   baseHeight - topThick - topGap,
                   baseDepth >
            }
            box {
                < -baseWidth / 2, baseHeight - topThick, 0 >,
                <  baseWidth / 2, baseHeight, baseDepth >
            }
            box {
                < -baseWidth / 2, baseHeight, baseDepth - 4 * INCH >,
                <  baseWidth / 2, baseHeight + 6 * INCH, baseDepth >
            }
            texture { unitTexture }
        }
        union {
            cylinder {
                < 0, 0, -1/4 * INCH >,
                < 0, 0, 0 >,
                2 * INCH
                texture { GlossyBlackTexture }
            }
            cylinder {
                < 0, 0, -1.25 * INCH >,
                < 0, 0, -1/2 * INCH >
                1 * INCH
                texture { BrushedNickelTexture }
            }
            translate < baseWidth * 3/16,
                        baseHeight + 3 * INCH,
                        baseDepth - 4 * INCH >
        }
    }

#end // #macro WasherDryer


// A simple side-by-side refrigerator/freezer
#macro Refrigerator(
            unitWidth,
            unitHeight,
            unitDepth,
            unitTexture,
            doorTexture,
            handleTexture)

    #local freezerWid = unitWidth / 3;
    #local fridgWid   = unitWidth - freezerWid;
    #local doorThick  = 2 * INCH;
    #local doorGap    = 1/2 * INCH;
    #local handleLen  = unitHeight * 3/8;
    #local handleDiam = 1.5 * INCH;

    #local refrigHandle =
    cylinder {
        < 0, 0, 0 >, < 0, handleLen, 0 >, handleDiam / 2
        texture { handleTexture }
        translate < 0, unitHeight * 1/2, -handleDiam / 2 >
    }
    
    union {
        union {
            union {
                box {
                    < -unitWidth / 2,
                      1 * INCH,
                      doorThick + doorGap >,
                    <  unitWidth / 2, unitHeight, unitDepth >
                }
                box {
                    < -unitWidth / 2 + doorGap,
                      1 * INCH + doorGap,
                      doorThick >,
                    < unitWidth / 2 - doorGap,
                      unitHeight - doorGap,
                      doorThick + doorGap >
                }
                box {
                    < -freezerWid * 3/8, -6 * INCH, -3/8 * INCH >,
                    <  freezerWid * 3/8, 6 * INCH, 0 >
                    translate < -(unitWidth - freezerWid) / 2,
                                (unitHeight + handleLen) / 2, 0 >
                }
                texture { unitTexture }
            }
            union {
                box {
                    < -unitWidth / 2, 0, 0 >,
                    < -unitWidth / 2 + freezerWid - doorGap,
                      unitHeight,
                      doorThick >
                }
                box {
                    < -unitWidth / 2 + freezerWid + doorGap, 0, 0 >,
                    < unitWidth / 2, unitHeight, doorThick >
                }
                texture { doorTexture }
            }
        }
        object {
            refrigHandle
            translate (-unitWidth / 2 + freezerWid - handleDiam) * x
        }
        object {
            refrigHandle
            translate (-unitWidth / 2
                            + freezerWid
                            + 1/2 * INCH
                            + handleDiam) * x
        }
    }
    
#end // #macro Refrigerator


// A simple flat-top electric stove
#macro Stove(
            baseWidth,
            baseHeight,
            baseDepth,
            ovenDoorTexture,
            topTexture,
            handleTexture)

    #local handleLen    = baseWidth * 3/4;
    #local handleDiam   = 1.5 * INCH;
    #local topThick     = 1 * INCH;

    union { // Just a box box with a smaller box on top ... for now!
        box {
            < -baseWidth / 2, 3/4 * INCH, 0 >,
            <  baseWidth / 2, baseHeight - topThick, baseDepth >
            texture { ovenDoorTexture }
        }
        union {
            box {
                < -baseWidth / 2, baseHeight - topThick, 0 >,
                <  baseWidth / 2, baseHeight, baseDepth >
            }
            box {
                < -baseWidth / 2, baseHeight, baseDepth - 4 * INCH >,
                <  baseWidth / 2, baseHeight + 5 * INCH, baseDepth >
            }
            texture { topTexture }
        }
        cylinder {
            < -handleLen / 2, 0, 0 >,
            <  handleLen / 2, 0, 0 >,
            handleDiam / 2
            texture { handleTexture }
            translate < 0,
                        baseHeight - topThick - handleDiam,
                        -handleDiam / 2 >
        }
    }

#end // #macro Stove


// A basic dishwasher stand-in
#macro Dishwasher(
            unitWidth,
            unitHeight,
            unitDepth,
            doorTexture,
            panelTexture)

    #local panelWid     = 5 * INCH;

    union {
        box {
            < -unitWidth / 2, 2 * INCH, 0 >,
            <  unitWidth / 2, unitHeight - panelWid, unitDepth >
            texture { doorTexture }
        }
        box {
            < -unitWidth / 2, unitHeight - panelWid, 0 >,
            <  unitWidth / 2, unitHeight, unitDepth >
            texture { panelTexture }
        }
    }

#end // #macro Dishwasher


// A simplified microwave oven.
#macro MicrowaveOven(
            unitWidth,
            unitHeight,
            unitDepth,
            unitTexture,
            handleTexture)

    #local panelWid     = 5 * INCH;
    #local handleLen    = unitHeight * 3/4;
    #local handleOfs    = (unitHeight - handleLen) / 2;
    
    union {
        box {
            < -unitWidth / 2, 0, 0 >,
            <  unitWidth / 2, unitHeight, unitDepth >
            texture { unitTexture }
        }
        cylinder {
            < 0, 0, 0 >, < 0, handleLen, 0 >, 1 * INCH
            texture { handleTexture }
            translate < unitWidth / 2 - panelWid - 1 * INCH,
                        handleOfs,
                        -0.5 * INCH >
        }
    }

#end // #macro MicrowaveOven
 

#end    // #ifndef (_Appliances_Inc_)
