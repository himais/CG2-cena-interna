//////////////////////////////////////////////////////////////////////////
// Cabinets.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs        //
//////////////////////////////////////////////////////////////////////////
// Provides macros for creating cabinets and counter tops.              //
//////////////////////////////////////////////////////////////////////////

// This file should only be included once!
#ifndef (_Cabinets_Inc_)
#declare _Cabinets_Inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Cabinets.inc\n"
#end

#include "Units.inc"
#include "HardwareTextures.inc"
#include "Fixtures.inc"


//////////////////////////////////////////////////////////////////////////
// By default, cabinets are oriented as follows:                        //
//                                                                      //
//  Top View                                                            //
//  ========                                                            //
//            +Z                                                        //
//             ^                                                        //
//             :                                                        //
//      +------:------+                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      +------:------+ ....>+X                                         //
//                                                                      //
//  Front View                                                          //
//  ==========                                                          //
//            +Y                                                        //
//             ^                                                        //
//             :                                                        //
//      +------:------+                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      +------:------+ ....>+X                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

// Global values                                                        //

#declare CABINET_BASE_UNIT      = true;
#declare CABINET_WALL_UNIT      = false;

#declare DOUBLE_DOOR_CABINET    = true;
#declare SINGLE_DOOR_CABINET    = false;

#declare HINGES_ON_RIGHT        =  1;
#declare NO_HINGES              =  0;
#declare HINGES_ON_LEFT         = -1;
#declare HINGES_ON_BOTH_SIDES   =  2;

#declare KNOB_ON_RIGHT          =  1;
#declare KNOB_ON_TOP            =  1;
#declare NO_KNOB                =  0;
#declare KNOB_ON_BOTTOM         = -1;
#declare KNOB_ON_LEFT           = -1;

#ifndef (CABINET_DOOR_THICKNESS)
    #declare CABINET_DOOR_THICKNESS = 3/4 * INCH;
#end

#ifndef (CABINET_DOOR_PANEL_DEPTH)
    #declare CABINET_DOOR_PANEL_DEPTH = CABINET_DOOR_THICKNESS / 3;
#end

#ifndef (CABINET_DOOR_FRAME_WIDTH)
    #declare CABINET_DOOR_FRAME_WIDTH = 1.5 * INCH;
#end

#ifndef (CABINET_DOOR_INSET)
    #declare CABINET_DOOR_INSET = 1.5 * INCH;
#end

#ifndef (CABINET_DRAWER_HEIGHT)
    #declare CABINET_DRAWER_HEIGHT = 6 * INCH;
#end

#ifndef (CABINET_KICK_SPACE_HEIGHT)
    #declare CABINET_KICK_SPACE_HEIGHT = 3.5 * INCH;
#end

#ifndef (CABINET_KICK_SPACE_DEPTH)
    #declare CABINET_KICK_SPACE_DEPTH = 3.5 * INCH;
#end


#ifndef (CABINET_HARDWARE_TEXTURE)
    #declare CABINET_HARDWARE_TEXTURE = texture { BrushedNickelTexture }
#end

#declare CABINET_KNOB_ROUND =
union {
    cylinder { < 0, 0, -3/4 * INCH >, < 0, 0, 0 >, 1/4 * INCH }
    sphere {
        < 0, 0, 0 >, 1/2 * INCH
        scale < 1, 1, 0.5 >
        translate -3/4 * INCH * z
    }
    texture { CABINET_HARDWARE_TEXTURE }
}

#declare CABINET_KNOB_HANDLE =
union {
    cylinder {
        < -3/16 * INCH, 1.5 * INCH, -5/8 * INCH >,
        <  3/16 * INCH, 1.5 * INCH, -5/8 * INCH >,
        5/8 * INCH
    }
    cylinder {
        < -3/16 * INCH, -1.5 * INCH, -5/8 * INCH >,
        <  3/16 * INCH, -1.5 * INCH, -5/8 * INCH >,
        5/8 * INCH
    }
    box {
        < -3/16 * INCH, -1.5 * INCH, -(1+1/4) * INCH >,
        <  3/16 * INCH,  1.5 * INCH, -1 * INCH >
    }
    texture { CABINET_HARDWARE_TEXTURE }
}

#ifndef (CABINET_KNOB)
    #declare CABINET_KNOB = object { CABINET_KNOB_ROUND }
#end

#ifndef (CABINET_HINGE_HEIGHT)
    #declare CABINET_HINGE_HEIGHT = 1.5 * INCH;
#end

#ifndef (CABINET_HINGE_BARREL_DIAMETER)
    #declare CABINET_HINGE_BARREL_DIAMETER = 3/8 * INCH;
#end


#ifndef (CABINET_HINGE)
    #local numHingeSect = 3;
    #local numSectGaps  = numHingeSect - 1;
    #local hingeSectGap = 1/16 * INCH;
    #local hingeSectHgt = (CABINET_HINGE_HEIGHT
                                - (numSectGaps * hingeSectGap))
                                        / numHingeSect;

    #local hingeSection =
        cylinder {
            < 0, 0, 0 >,
            < 0, hingeSectHgt, 0 >,
            CABINET_HINGE_BARREL_DIAMETER / 2
        }
        
    #declare CABINET_HINGE =
    union {
        #local hSectOfs = -CABINET_HINGE_HEIGHT / 2;
        #local sectNum  = 0;
        
        #while (sectNum < numHingeSect)
            object { hingeSection translate hSectOfs * y }
            #local hSectOfs = hSectOfs + hingeSectHgt + hingeSectGap;
            #local sectNum  = sectNum + 1;
        #end

        texture { CABINET_HARDWARE_TEXTURE }
    }
#end


#ifndef (BOARD_THICKNESS)
    #declare BOARD_THICKNESS = INCHES(3/4);
#end


//////////////////////////////////////////////////////////////////////////
// A macro to generate a "slab" with its edges scooped out - used for
// cabinet doors and drawer fronts. The slab's back face will be
// aligned with the X-Y pane (Z=0); the front face will lie the
// specified thickness in the negative Z direction.

#macro DecoratedSlab(
            slabLeft,
            slabRight,
            slabBottom,
            slabTop,
            slabThickness,
            bevelDepth)
            
    #local sFrt = -slabThickness;
    #local sBak =  0;
    
    #local hEdgePunch =
    cylinder {
        < slabLeft - 1, 0, 0 >,
        < slabRight + 1, 0, 0 >,
        bevelDepth
    }

    #local vEdgePunch =
    cylinder {
        < 0, slabBottom - 1, 0 >,
        < 0, slabTop + 1, 0 >,
        bevelDepth
    }
    
    difference {
        // The basic slab.
        box {
            < slabLeft,  slabBottom, sFrt >,
            < slabRight, slabTop,    sBak >
        }
        // Subtract the edge bevel.
        object {
            hEdgePunch
            translate < 0, slabTop, -slabThickness >
        }
        object {
            hEdgePunch
            translate < 0, slabBottom, -slabThickness >
        }
        object {
            vEdgePunch
            translate < slabLeft, 0, -slabThickness >
        }
        object {
            vEdgePunch
            translate < slabRight, 0, -slabThickness >
        }
    }

#end    // #macro DecoratedSlab


//////////////////////////////////////////////////////////////////////////
// A macro to generate a basic cabinet enclosure.

#macro CabinetEnclosure(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            cabinetTexture,     // If wood, vertical grain
            isBaseUnit)

    // Just a textured box ... for now!
    #if (isBaseUnit)
        difference {
            box {
                < -cabinetWidth / 2, 0, 0 >,
                <  cabinetWidth / 2, cabinetHeight, cabinetDepth >
            }
            box {
                < -cabinetWidth, -1, -1 >,
                <  cabinetWidth,
                   CABINET_KICK_SPACE_HEIGHT,
                   CABINET_KICK_SPACE_DEPTH >
            }
            texture { cabinetTexture }
        }
    #else
        box {
            < -cabinetWidth / 2, 0, 0 >,
            <  cabinetWidth / 2, cabinetHeight, cabinetDepth >
            texture { cabinetTexture }
        }
    #end

#end    // #macro CabinetEnclosure

//////////////////////////////////////////////////////////////////////////
// A macro to generate the door for a cabinet.

#macro CabinetDoor(
            doorLeft,
            doorRight,
            doorBottom,
            doorTop,
            doorTexture,        // If wood, vertical grain
            hingePosition,
            knobPosition)       // Vector: x=left/right, y=top/bottom

    union {
        #if ((doorRight - doorLeft) < (5 * CABINET_DOOR_FRAME_WIDTH))
            // Not wide enough to have a reasonable center panel!
            object {
                DecoratedSlab(
                    doorLeft,
                    doorRight,
                    doorBottom,
                    doorTop,
                    CABINET_DOOR_THICKNESS,
                    CABINET_DOOR_PANEL_DEPTH)
                texture { doorTexture }
            }
        #else
            #local panelPunchZScale =
                         CABINET_DOOR_PANEL_DEPTH * 2 / CABINET_DOOR_FRAME_WIDTH;

            #local hPanelPunch =
            intersection {
                cylinder {
                    < doorLeft, 0, 0 >,
                    < doorRight, 0, 0 >,
                    CABINET_DOOR_FRAME_WIDTH / 2
                    scale < 1, 1, panelPunchZScale >
                }
                plane {
                    -x, 0
                    rotate 45 * z
                    translate (doorLeft + CABINET_DOOR_FRAME_WIDTH * 1.5) * x
                }
                plane {
                    x, 0
                    rotate -45 * z
                    translate (doorRight - CABINET_DOOR_FRAME_WIDTH * 1.5) * x
                }
            }

            #local vPanelPunch =
            intersection {
                cylinder {
                    < 0, doorBottom, 0 >,
                    < 0, doorTop, 0 >,
                    CABINET_DOOR_FRAME_WIDTH / 2
                    scale < 1, 1, panelPunchZScale >
                }
                plane {
                    -y, 0
                    rotate 45 * z
                    translate (doorBottom + CABINET_DOOR_FRAME_WIDTH * 1.5) * y
                }
                plane {
                    y, 0
                    rotate -45 * z
                    translate (doorTop - CABINET_DOOR_FRAME_WIDTH  * 1.5) * y
                }
            }

            difference {
                // The basic door slab
                object {
                    DecoratedSlab(
                        doorLeft,
                        doorRight,
                        doorBottom,
                        doorTop,
                        CABINET_DOOR_THICKNESS,
                        CABINET_DOOR_PANEL_DEPTH)
                }

                // Scoop out for the center panel.
                object {
                    hPanelPunch
                    translate < 0, doorTop - CABINET_DOOR_FRAME_WIDTH * 1.5,
                                        -CABINET_DOOR_THICKNESS >
                }
                object {
                    hPanelPunch
                    scale < 1, -1, 1 >
                    translate < 0, doorBottom + CABINET_DOOR_FRAME_WIDTH * 1.5,
                                        -CABINET_DOOR_THICKNESS >
                }
                object {
                    vPanelPunch
                    translate < doorLeft + CABINET_DOOR_FRAME_WIDTH * 1.5, 0,
                                        -CABINET_DOOR_THICKNESS >
                }
                object {
                    vPanelPunch
                    scale < -1, 1, 1 >
                    translate < doorRight - CABINET_DOOR_FRAME_WIDTH * 1.5, 0,
                                        -CABINET_DOOR_THICKNESS >
                }
                texture { doorTexture }
            }
        #end

        #if (hingePosition != NO_HINGES)
            #local hingeXOfs = ((hingePosition = HINGES_ON_RIGHT)
                                    ? doorRight : doorLeft);
            #local hingeYOfs = CABINET_DOOR_FRAME_WIDTH * 2
                                    + CABINET_HINGE_HEIGHT / 2;

            object {
                CABINET_HINGE
                translate <  hingeXOfs, doorBottom + hingeYOfs, 0 >
            }
            object {
                CABINET_HINGE
                translate <  hingeXOfs, doorTop - hingeYOfs, 0 >
            }
        #end

        #switch (hingePosition)
            #case (HINGES_ON_RIGHT)
                #local knobXOfs = doorLeft + CABINET_DOOR_FRAME_WIDTH / 2;
            #break;
            #case (HINGES_ON_LEFT)
                #local knobXOfs = doorRight - CABINET_DOOR_FRAME_WIDTH / 2;
            #break;
            #else
                #switch (knobPosition.x)
                    #case (KNOB_ON_LEFT)
                        #local knobXOfs = doorLeft + CABINET_DOOR_FRAME_WIDTH / 2;
                    #break
                    #case (KNOB_ON_RIGHT)
                        #local knobXOfs = doorRight - CABINET_DOOR_FRAME_WIDTH / 2;
                    #break
                    #else
                        #local knobXOfs = (doorLeft + doorRight) / 2;
                #end
        #end

        #switch (knobPosition.y)
            #case (KNOB_ON_TOP)
                #local knobYOfs = doorTop - CABINET_DOOR_FRAME_WIDTH * 1.5;
            #break;
            #case (KNOB_ON_BOTTOM)
                #local knobYOfs = doorBottom + CABINET_DOOR_FRAME_WIDTH * 1.5;
            #break;
            #else
                #local knobYOfs = (doorBottom + doorTop) / 2;
        #end
        
        object {
            CABINET_KNOB
            translate < knobXOfs, knobYOfs, -CABINET_DOOR_THICKNESS >
        }

        translate -1/8 * INCH * z
        
    } // union
        
#end    // #macro CabinetDoor


//////////////////////////////////////////////////////////////////////////
// A macro to generate a drawer front for a cabinet.

#macro CabinetDrawerFront(
            drawerLeft,
            drawerRight,
            drawerBottom,
            drawerTop,
            drawerTexture)      // If wood, horizontal grain

    union {
        // The drawer front itself
        object {
            DecoratedSlab(
                drawerLeft,
                drawerRight,
                drawerBottom,
                drawerTop,
                CABINET_DOOR_THICKNESS,
                CABINET_DOOR_PANEL_DEPTH)
            texture { drawerTexture }
        }
        
        object {
            CABINET_KNOB
            rotate 90 * z
            translate < (drawerLeft + drawerRight) / 2,
                        (drawerBottom + drawerTop) / 2,
                        -CABINET_DOOR_THICKNESS >
        }

        translate -1/8 * INCH * z
        
    }   // union
    
#end    // #macro CabinetDrawerFront


//////////////////////////////////////////////////////////////////////////
// A macro to generate a cabinet spacer panel, oriented as follows:     //
//                                                                      //
//  Top View                                                            //
//  ========                                                            //
//            +Z                                                        //
//             ^                                                        //
//             :                                                        //
//      +------:------+                                                 //
//      +------:------+ ....>+X                                         //
//                                                                      //
//  Front View                                                          //
//  ==========                                                          //
//            +Y                                                        //
//             ^                                                        //
//             :                                                        //
//      +------:------+                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      |      :      |                                                 //
//      +------:------+ ....>+X                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#macro CabinetSpacerPanel(
            cabinetWidth,
            cabinetHeight,
            cabinetTexture, // If wood, vertical grain
            isBaseUnit)

    #local pLeft    = -cabinetWidth / 2;
    #local pRight   =  cabinetWidth / 2;
    #local pBottom  =  0;
    #local pTop     =  cabinetHeight;
    #local pFront   =  0;
    #local pBack    =  3/4 * INCH;
    
    #if (isBaseUnit)
        #local pBottom  = pBottom + CABINET_KICK_SPACE_HEIGHT;
        
        union {
            box {
                < pLeft, pBottom, pFront >, < pRight, pTop, pBack >
            }
            box {
                < pLeft, pBottom, pBack >,
                < pRight, pBottom + 3/4 * INCH, CABINET_KICK_SPACE_DEPTH >
            }
            box {
                < pLeft, 0, CABINET_KICK_SPACE_DEPTH >,
                < pRight,
                  CABINET_KICK_SPACE_HEIGHT + 3/4 * INCH,
                  CABINET_KICK_SPACE_DEPTH + 3/4 * INCH >
            }
            texture { cabinetTexture }
        }
    #else
        box {
            < pLeft, pBottom, pFront >, <pRight, pTop, pBack >
            texture { cabinetTexture }
        }
    #end

#end    // #macro CabinetSpacerPanel


//////////////////////////////////////////////////////////////////////////
// A macro to generate a cabinet unit with one or two doors.            //

#macro CabinetWithDoors(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            cabinetTexture,     // If wood, vertical grain
            doorTexture,        // If wood, vertical grain
            isBaseUnit,
            doubleDoors,
            hingePosition,
            knobPosition)       // Vector: x=left/right, y=top/bottom

    #local doorLeft   = -cabinetWidth / 2 + CABINET_DOOR_INSET;
    #local doorRight  =  cabinetWidth / 2 - CABINET_DOOR_INSET;
    #local doorTop    =  cabinetHeight - CABINET_DOOR_INSET;
    #local doorBottom =  CABINET_DOOR_INSET;
    
    #if (isBaseUnit)
        #local doorBottom = doorBottom + CABINET_KICK_SPACE_HEIGHT;
    #end
    
    union {
        // The basic cabinet enclosure
        object {
            CabinetEnclosure(
                cabinetWidth,
                cabinetHeight,
                cabinetDepth,
                cabinetTexture,
                isBaseUnit)
        }

        #if (doubleDoors)
            object {
                CabinetDoor(
                    doorLeft,
                    -CABINET_DOOR_INSET / 2,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_LEFT,
                    < KNOB_ON_RIGHT, knobPosition.y, 0 > )
            }
            object {
                CabinetDoor(
                    CABINET_DOOR_INSET / 2,
                    doorRight,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_RIGHT,
                    < KNOB_ON_LEFT, knobPosition.y, 0 > )
            }
        #else        
            object {
                CabinetDoor(
                    doorLeft,
                    doorRight,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    hingePosition,
                    knobPosition)
            }
        #end
        
    }   // union

#end    // #macro CabinetWithDoors


//////////////////////////////////////////////////////////////////////////
// A macro to generate a cabinet unit with one or more drawerrs.        //

#macro CabinetWithDrawers(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            numberOfDrawers,
            cabinetTexture,     // If wood, vertical grain
            drawerTexture,      // If wood, horizontal grain
            isBaseUnit)

    #local drawerLeft   = -cabinetWidth / 2 + CABINET_DOOR_INSET;
    #local drawerRight  =  cabinetWidth / 2 - CABINET_DOOR_INSET;
    #local drawerBottom =  CABINET_DOOR_INSET;
    
    #if (isBaseUnit)
        #local drawerBottom = drawerBottom + CABINET_KICK_SPACE_HEIGHT;
    #end

    #local drawerSpacing = CABINET_DOOR_INSET / 2;
    #local drawerHeight  = (cabinetHeight
                                - drawerBottom
                                - CABINET_DOOR_INSET
                                - (numberOfDrawers - 1)
                                     * drawerSpacing)
                                            / numberOfDrawers;
    
    union {
        // The basic cabinet enclosure
        object {
            CabinetEnclosure(
                cabinetWidth,
                cabinetHeight,
                cabinetDepth,
                cabinetTexture,
                isBaseUnit)
        }
        
        #local nDrw = 0;
        
        #while (nDrw < numberOfDrawers)
            #local drawerTop = drawerBottom + drawerHeight;
            object {
                CabinetDrawerFront(
                    drawerLeft,
                    drawerRight,
                    drawerBottom,
                    drawerTop,
                    drawerTexture)
            }
            
            #local drawerBottom = drawerBottom
                                    + drawerHeight
                                    + drawerSpacing;
            #local nDrw = nDrw + 1;
        #end
        
    }   // union

#end    // #macro CabinetWithDoors


//////////////////////////////////////////////////////////////////////////
// A macro to generate a cabinet unit with one drawer and one or two    //
// doors below the drawer.                                              //

#macro CabinetWithTopDrawerAndDoors(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            cabinetTexture,     // If wood, vertical grain
            doorTexture,        // If wood, vertical grain
            drawerTexture,      // If wood, horizontal grain
            isBaseUnit,
            doubleDoors,
            hingePosition,
            knobPosition)

    #local drawerTop    =  cabinetHeight - CABINET_DOOR_INSET;
    #local drawerBottom =  drawerTop - CABINET_DRAWER_HEIGHT;
    #local doorLeft     = -cabinetWidth / 2 + CABINET_DOOR_INSET;
    #local doorRight    =  cabinetWidth / 2 - CABINET_DOOR_INSET;
    #local doorTop      =  drawerBottom - CABINET_DOOR_INSET;
    #local doorBottom   =  CABINET_DOOR_INSET;
    
    #if (isBaseUnit)
        #local doorBottom = doorBottom + CABINET_KICK_SPACE_HEIGHT;
    #end
    
    union {
        // The basic cabinet enclosure
        object {
            CabinetEnclosure(
                cabinetWidth,
                cabinetHeight,
                cabinetDepth,
                cabinetTexture,
                isBaseUnit)
        }

        object {
            CabinetDrawerFront(
                doorLeft,
                doorRight,
                drawerBottom,
                drawerTop,
                drawerTexture)
        }
        
        #if (doubleDoors)
            object {
                CabinetDoor(
                    doorLeft,
                    -CABINET_DOOR_INSET / 2,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_LEFT,
                    < KNOB_ON_RIGHT, knobPosition.y, 0 > )
            }
            object {
                CabinetDoor(
                    CABINET_DOOR_INSET / 2,
                    doorRight,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_RIGHT,
                    < KNOB_ON_LEFT, knobPosition.y, 0 > )
            }
        #else        
            object {
                CabinetDoor(
                    doorLeft,
                    doorRight,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    hingePosition,
                    knobPosition)
            }
        #end
        
    }   // union

#end    // #macro CabinetWithDoors


//////////////////////////////////////////////////////////////////////////
// A macro to generate a corner cabinet unit with one or two doors.     //
//                                                                      //
// The cabinet will be oriented as follows:                             //
//                                                                      //
//  Top View                                                            //
//  ========                                                            //
//                                                                      //
//         +Z                                                           //
//          |                                                           //
//          |                                                           //
//          |<-- width -->|                                             //
//      --- +-------------+ ---                                         //
//       :  |             |  :                                          //
//    depth |             |  :                                          //
//       :  |             |  :                                          //
//      --- \             | width                                       //
//            \           |  :                                          //
//        doors \         |  :                                          //
//                \       |  :                                          //
//    -X ---o--     \-----+ ----- +X                                    //
//          |                                                           //
//          |                                                           //
//         -Z                                                           //
//                                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#macro CornerCabinetWithDoors(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            cabinetTexture,     // If wood, vertical grain
            doorTexture,        // If wood, vertical grain
            isBaseUnit,
            doubleDoors,
            hingePosition,
            knobPosition)

    #local faceDepth = cabinetWidth - cabinetDepth;
    #local faceWidth = sqrt(faceDepth * faceDepth + faceDepth * faceDepth);

    #local doorLeft   = CABINET_DOOR_INSET;
    #local doorRight  = faceWidth - CABINET_DOOR_INSET;
    #local doorTop    = cabinetHeight - CABINET_DOOR_INSET;
    #local doorBottom = CABINET_DOOR_INSET;
    
    #if (isBaseUnit)
        #local doorBottom = doorBottom + CABINET_KICK_SPACE_HEIGHT;
        #local cabBox =
        difference {
            intersection {
                box {
                    < 0, 0, 0 >,
                    < cabinetWidth, cabinetHeight, cabinetWidth >
                }
                plane { -z, 0 rotate 45 * y translate faceDepth * z }
            }
            box {
                < -cabinetWidth, -1, -1 >,
                <  cabinetWidth * 2,
                   CABINET_KICK_SPACE_HEIGHT,
                   CABINET_KICK_SPACE_DEPTH >
                rotate 45 * y
                translate faceDepth * z
            }
        }
    #else
        #local cabBox =
        intersection {
            box {
                < 0, 0, 0 >,
                < cabinetWidth, cabinetHeight, cabinetWidth >
            }
            plane { -z, 0 rotate 45 * y translate faceDepth * z }
        }
    #end

    #if (doubleDoors)
        #local cabDoors =
        union {
            object {
                CabinetDoor(
                    doorLeft,
                    (faceWidth - CABINET_DOOR_INSET) / 2,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_LEFT,
                    knobPosition)
            }
            object {
                CabinetDoor(
                    (faceWidth + CABINET_DOOR_INSET) / 2,
                    doorRight,
                    doorBottom,
                    doorTop,
                    doorTexture,
                    HINGES_ON_RIGHT,
                    knobPosition)
            }
        }
    #else
        #local cabDoors =
        object {
            CabinetDoor(
                doorLeft,
                doorRight,
                doorBottom,
                doorTop,
                doorTexture,
                hingePosition,
                knobPosition)
        }
    #end
    
    union {
        object { cabBox texture { cabinetTexture } }
        object {
            cabDoors
            rotate 45 * y
            translate faceDepth * z
        }
    }
                   
#end    // #macro CornerCabinetWithDoors


//////////////////////////////////////////////////////////////////////////
// A macro to generate a corner cabinet unit as a lazy suzan, with      //
// two doors.                                                           //
//                                                                      //
// The cabinet will be oriented as follows:                             //
//                                                                      //
//  Top View                                                            //
//  ========                                                            //
//                                                                      //
//         +Z                                                           //
//          |                                                           //
//          |                                                           //
//          |<-- width -->|                                             //
//      --- +-------------+ ---                                         //
//       :  |             |  :                                          //
//    depth |             |  :                                          //
//       :  |             |  :                                          //
//      --- +------+      | width                                       //
//            door |      |  :                                          //
//                 |      |  :                                          //
//            door |      |  :                                          //
//    -X ---o--    +------+ ----- +X                                    //
//          |                                                           //
//          |                                                           //
//         -Z                                                           //
//                                                                      //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#macro CornerCabinetLazySusan(
            cabinetWidth,
            cabinetHeight,
            cabinetDepth,
            cabinetTexture,     // If wood, vertical grain
            doorTexture,        // If wood, vertical grain
            isBaseUnit,
            knobPosition)       // Vector: x=left/right, y=top/bottom

    #local faceWidth = cabinetWidth - cabinetDepth;

    #local doorTop    = cabinetHeight - CABINET_DOOR_INSET;
    #local doorBottom = CABINET_DOOR_INSET;
    
    #if (isBaseUnit)
        #local doorBottom = doorBottom + CABINET_KICK_SPACE_HEIGHT;
    #end
    
    union {
        difference {
            box {
                < 0, 0, 0 >,
                < cabinetWidth, cabinetHeight, cabinetWidth >
            }
            box {
                < -1, -1, -1 >,
                < faceWidth, cabinetHeight + 1, faceWidth >
            }
            box {
                < CABINET_DOOR_INSET - 1/8 * INCH,
                  doorBottom - 1/8 * INCH,
                  CABINET_DOOR_INSET - 1/8 * INCH >,
                < cabinetWidth - 1/4 * INCH,
                  doorTop + 1/8 * INCH,
                  cabinetWidth - 1/4 * INCH >
            }
            
            #if (isBaseUnit)
                box {
                    < -2, -2, -2 >,
                    <  faceWidth + CABINET_KICK_SPACE_DEPTH,
                       CABINET_KICK_SPACE_HEIGHT,
                       faceWidth + CABINET_KICK_SPACE_DEPTH >
                }
            #end
            
            texture { cabinetTexture }
        }
        object {
            CabinetDoor(
                CABINET_DOOR_INSET + 1/8 * INCH,
                faceWidth,
                doorBottom + 1/8 * INCH,
                doorTop - 1/8 * INCH,
                doorTexture,
                NO_HINGES,
                < KNOB_ON_LEFT, knobPosition.y, 0 > )
            translate faceWidth * z
        }
        object {
            CabinetDoor(
                0,
                faceWidth - CABINET_DOOR_INSET - 1/8 * INCH,
                doorBottom + 1/8 * INCH,
                doorTop - 1/8 * INCH,
                doorTexture,
                NO_HINGES,
                < KNOB_ON_RIGHT, knobPosition.y, 0 > )
            rotate 90 * y
            
            translate < faceWidth, 0, faceWidth >
        }
    }

#end // #macro CornerCabinetLazySusan


//////////////////////////////////////////////////////////////////////////
// Calculates the spacing for shelves in a bookshelf unit.              //

#macro ShelfSpacing(unitHeight, baseHeight, numShelves)
    ((unitHeight-BOARD_THICKNESS-baseHeight)/(numShelves+1))
#end

//////////////////////////////////////////////////////////////////////////
// A macro to generate an open bookshelf unit.                          //

#macro BookshelfUnit(
            unitWidth,
            unitHeight,
            unitDepth,
            baseHeight,
            numShelves,
            unitTexture)    // If wood, horizontal grain

    #local uLft = -unitWidth / 2;
    #local uRgt =  uLft + unitWidth;
    #local uBot =  0;
    #local uTop =  unitHeight;
    
    #local bdThick = BOARD_THICKNESS;
    
    #local shelfSpacing = ShelfSpacing(unitHeight,
                                       baseHeight,
                                       numShelves);
                                       
    #local shelfWid = unitWidth - 2 * bdThick;
                                
    #local unitShelf =
    box {
        < -shelfWid / 2, -bdThick / 2, 0 >,
        <  shelfWid / 2,  bdThick / 2, unitDepth - bdThick >
        texture { unitTexture }
    }
        
    #local unitSide =
    intersection {
        box { < 0, 0, 0 >, < bdThick, unitHeight, unitDepth > }
        plane { y, 0 rotate -45 * z translate unitHeight * y }
        texture { unitTexture rotate 90 * z }
    }

    #local unitTop =
    intersection {
        box { < uLft, -bdThick, 0 >, < uRgt, 0, unitDepth > }
        plane { -x, 0 rotate  45 * z translate uLft * x }
        plane {  x, 0 rotate -45 * z translate uRgt * x }
        texture { unitTexture }
    }

    #if (baseHeight > 0)
        #if (baseHeight > bdThick)
            #local unitBase =
            union {
                object {
                    unitShelf
                    translate (baseHeight - bdThick /2 ) * y
                }
                box {
                    < -shelfWid / 2, 0, 0 >,
                    <  shelfWid / 2,  baseHeight - bdThick, bdThick >
                    texture { unitTexture }
                    translate 1/4 * INCH * z
                }
            }
        #else
            #local unitBase = object { unitShelf }
        #end
    #end

    #local unitBack =
    box {
        < -shelfWid / 2, 0, -bdThick >,
        <  shelfWid / 2, unitHeight - bdThick, 0 >
        texture { unitTexture rotate 90 * z }
    }
    
    union {
        object { unitSide translate uLft * x }
        object { unitSide scale < -1, 1, 1 > translate uRgt * x }
        object { unitTop translate uTop * y }
        object { unitBack translate unitDepth * z }

        #if (baseHeight > 0)
            object { unitBase }
        #end
        
        #local nS   = 0;
        #local sOfs = baseHeight + shelfSpacing;
        
        #while (nS < numShelves)
            object { unitShelf translate sOfs * y }
            #local sOfs = sOfs + shelfSpacing;
            #local nS   = nS + 1;
        #end
    }
    
#end    // #macro BookshelfUnit


//////////////////////////////////////////////////////////////////////////
// A macro to create a plain shelf. The front edge is at Z=0, the shelf //
// bottom is at Y=0, and the length is centered on the X-axis. The      //
// shelf has an edge which extends below the bottom and in front of the //
// shelf's front edge.                                                  //

#macro ShelfWithEdge(
            shelfLength,
            shelfDepth,
            shelfThickness,
            edgeWidth,
            shelfTexture)   // If wood, horizontal grain.

    #local theShelf = 
    box {
        < -shelfLength / 2, 0, 0 >,
        <  shelfLength / 2, shelfThickness, shelfDepth >
    }
    
    #if (edgeWidth > 0)
        union {
            object { theShelf }
            box {
                < -shelfLength / 2, -edgeWidth, -shelfThickness >,
                <  shelfLength / 2,  1/8 * INCH, 0 >
            }
            texture { shelfTexture }
        }
    #else
        // No edge!
        object { theShelf texture { shelfTexture } }
    #end
    
#end    // #macro ShelfWithEdge


//////////////////////////////////////////////////////////////////////////
// A macro to create a punch for cutting out the opening for a bowl.    //

#macro VanityBowlPunch(bLength, bWidth, bDepth)
    cylinder {
        < 0, -bDepth * 2, 0 >,
        < 0,  bDepth * 2, 0 >,
        0.5
        scale < bLength, 1, bWidth >
    }
#end


//////////////////////////////////////////////////////////////////////////
// A macro to create a bowl shape for a bathroom vanity top.            //

#macro VanityBowlShape(bLength, bWidth, bDepth)
    #local bowlShape =
    intersection {
        sphere {
            < 0, 0, 0 >, 0.5
            scale < bLength, bDepth * 2, bWidth  >
        }
        plane { y, 0 }
    }
    
    difference {
        object { bowlShape }
        object { bowlShape translate 1/32 * INCH * y}
    }
#end


//////////////////////////////////////////////////////////////////////////
// A macro to create a single-bowl bathroom vanity top.                 //

#macro SingleBowlVanityTop(
            vtLeft,
            vtRight,
            vtFront,
            vtBack,
            vtThickness,
            bLength,
            bWidth,
            bDepth,
            leftBacksplashWidth,
            rightBacksplashWidth,
            backBacksplashWidth,
            vtTexture)

    union {
        difference {
            box { < vtLeft, 0, vtFront >, < vtRight, vtThickness, vtBack > }
            object { 
                VanityBowlPunch(bLength, bWidth, bDepth)
                translate  < (vtLeft + vtRight) / 2,
                             vtThickness + 1/32 * INCH,
                             (vtFront + vtBack) * 0.4 >
            }
            cylinder {
                < 0, 0, vtThickness * 0.75 >,
                < 0, 0, vtThickness * 1.25 >,
                0.5
                scale < bLength + 1.5 * INCH, 1, bWidth + 1.5 * INCH >
                translate  < (vtLeft + vtRight) / 2,
                             0,
                             (vtFront + vtBack) * 0.4 >
            }
        }

        object { 
            VanityBowlShape(bLength, bWidth, bDepth)
            translate  < (vtLeft + vtRight) / 2,
                         vtThickness + 1/32 * INCH,
                         (vtFront + vtBack) * 0.4 >
        }

        #if (leftBacksplashWidth > 0)
            box {
                < vtLeft, 0, vtFront >,
                < vtLeft + vtThickness, leftBacksplashWidth, vtBack >
                translate vtThickness * y
            }
        #end
        
        #if (rightBacksplashWidth > 0)
            box {
                < vtRight - vtThickness, 0, vtFront >,
                < vtRight, rightBacksplashWidth, vtBack >
                translate vtThickness * y
            }
        #end

        #if (backBacksplashWidth > 0)
            box {
                < vtLeft, 0, vtBack - vtThickness >,
                < vtRight, backBacksplashWidth, vtBack >
                translate vtThickness * y
            }
        #end
        
        texture { vtTexture }
    }

#end // #macro SingleBowlVanityTop
        
//////////////////////////////////////////////////////////////////////////
// A macro to generate a bathroom vanity cabinet, with a top-drawer,    //
// two doors, and a single-bowl vanity top.                             //

#macro SingleBowlBathroomVanity(
            cabWidth,
            cabHeight,
            cabDepth,
            bowlDiameter,
            cabTexture,
            topTexture,
            leftOverhang,
            rightOverhang,
            frontOverhang,
            backOverhang,
            leftBacksplashWidth,
            rightBacksplashWidth,
            backBacksplashWidth)

    #local vtLeft       = -cabWidth / 2 - leftOverhang;
    #local vtRight      = cabWidth / 2 + rightOverhang;
    #local vtFront      = -frontOverhang;
    #local vtBack       = cabDepth + backOverhang;
    #local vtThickness  = 3/4 * INCH;
    #local bWidth       = (vtBack - vtFront) * 1/2;
    #local bDepth       =  5 * INCH;

    union {
        difference {
            object {
                CabinetWithTopDrawerAndDoors(
                    cabWidth,
                    cabHeight,
                    cabDepth,
                    cabTexture,
                    cabTexture,
                    cabTexture,
                    CABINET_BASE_UNIT,
                    DOUBLE_DOOR_CABINET,
                    HINGES_ON_BOTH_SIDES,
                    < 0, KNOB_ON_TOP, 0 >)
            }
            object { 
                VanityBowlPunch(bowlDiameter, bWidth, bDepth)
                translate  < (vtLeft + vtRight) / 2,
                             cabHeight,
                             (vtFront + vtBack) * 0.4 >
            }
        }
        object {
            SingleBowlVanityTop(
                vtLeft,
                vtRight,
                vtFront,
                vtBack,
                vtThickness,
                bowlDiameter,
                bWidth,
                bDepth,
                leftBacksplashWidth,
                rightBacksplashWidth,
                backBacksplashWidth,
                topTexture)
            translate cabHeight * y
        }

        sphere {
            < 0, 0, 0 >, 1.25 * INCH
            texture { BrushedNickelTexture }
            scale < 1, 0.25, 1 >
            translate < (vtLeft + vtRight) / 2,
                        cabHeight + vtThickness - bDepth,
                        (vtFront + vtBack) * 0.4 >
        }
        
        object {
            FaucetSet(
                0,
                6 * INCH, 8 * INCH, 1 * INCH, 8 * INCH,
                CABINET_HARDWARE_TEXTURE)
            translate < (vtLeft + vtRight) / 2,
                        cabHeight + vtThickness,
                        (vtFront + vtBack) * 0.4
                            + bWidth / 2 + 2 * INCH >
        }
    }

#end    // #macro SingleBowlBathroomVanity
    
#end    // _Cabinets_Inc_

