

#include "Units.inc"            // Common units of measure
#include "Measurements.inc"     // Common measurement constants
#include "Textures.inc"         // Common color and texture definitions
#include "HardwareTextures.inc"
#include "Cabinets.inc"
#include "Appliances.inc"
#include "Fixtures.inc"


#declare CABINET_KNOB = object { CABINET_KNOB_HANDLE }


// The basic shape for the kitchen sink.
#local sinkLength       = 18 * INCH;
#local sinkWidth        = 15 * INCH;
#local sinkDepth        = 12 * INCH;
#local sinkXOfs         = 24 * INCH;    // From the cabinet west side
#local sinkZOfs         = 18 * INCH;    // From the cabinet soutth side

#local sinkShape =
intersection {
    superellipsoid { <0.3, 0.3> }
    plane { y, 0 }
    scale < sinkLength / 2, sinkDepth, sinkWidth / 2 >
    rotate -45 * y
}

#local sinkPunch =
object { sinkShape scale < 1, 3, 1 > translate sinkDepth * 1.5 * y }

#local kitchenSink =
difference {
    object { sinkShape }
    object {
        sinkShape
        scale < (sinkLength - 1/8 * INCH) / sinkLength,
                1,
                (sinkWidth - 1/8 * INCH) / sinkWidth >
        translate 1/8 * INCH * y
    }
    texture { BrushedNickelTexture }
}

// The cabinetry.
#local baseCabHgt       = 35 * INCH;
#local baseCabDepth     = 24 * INCH;

#local ctrThick         = 1.25 * INCH;
#local ctrOverhang      = 1 * INCH;
#local ctrDepth         = baseCabDepth + ctrOverhang;


#local wallCabHgt       = 30 * INCH;    // Not all!
#local wallCabDepth     = 12 * INCH;
#local wallCabBot       = 18 * INCH + baseCabHgt;

#local stoveWid         = 30 * INCH;
#local stoveHgt         = baseCabHgt + 1 * INCH;
#local stoveDepth       = ctrDepth;
#local distToStove      = 36 * INCH;

#local microwaveWid     = stoveWid;
#local microwaveHgt     = 12 * INCH;
#local microwaveDepth   = wallCabDepth;

#local dishWasherWid    = 24 * INCH;
#local dishWasherHgt    = baseCabHgt;
#local dishWasherDepth  = baseCabDepth - 1 * INCH;
#local distToDishWasher = distToStove + 9 * INCH;

#local refrigWid        = 36 * INCH;
#local refrigHgt        = 69 * INCH;
#local refrigDepth      = 30 * INCH;

// The base cabinets
#local cabXOfs          = 0;
#local cabZOfs          = 0;

#local vertCabTexture   = texture { CabinetTexture rotate 90 * z }
#local horizCabTexture  = texture { CabinetTexture }

declare pia = 
// The kitchen sink.
union {
    object { kitchenSink }
    object {
        FaucetSet(
            0,
            10 * INCH,
            8 * INCH,
            1 * INCH,
            10 * INCH,
            BrushedNickelTexture)
        translate < 0, ctrThick, sinkDepth / 2 + 3 * INCH >
        rotate -45 * y
    }
    translate < sinkXOfs,
                baseCabHgt,
                OFFICE_INSIDE_DEPTH
                    + WALL_THICKNESS
                    + KITCHEN_W_CAB_LENGTH
                    - 42 * INCH
                    + sinkZOfs >
}
 
 
 
