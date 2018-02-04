//////////////////////////////////////////////////////////////////////////
// Fixtures.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs       	//
//////////////////////////////////////////////////////////////////////////
// Defines common bathroom and kitchen fixtures. 						//
//////////////////////////////////////////////////////////////////////////

#ifndef (_Fixtures_inc_)
#declare _Fixtures_inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Fixtures.inc\n"
#end

#include "Units.inc"
#include "Textures.inc"
#include "HardwareTextures.inc"
#include "Trim.inc"


//////////////////////////////////////////////////////////////////////////
// A basic toilet.                                                      //
//////////////////////////////////////////////////////////////////////////

#local TOILET_TANK_WIDTH            = 16 * INCH;
#local TOILET_TANK_HEIGHT           = 15 * INCH;
#local TOILET_TANK_DEPTH            = 8 * INCH;
#local TOILET_TANK_LID_HEIGHT       = 1.5 * INCH;

#local TOILET_BOWL_WIDTH            = 15 * INCH;
#local TOILET_BOWL_HEIGHT           = 8 * INCH;
#local TOILET_BOWL_DEPTH            = TOILET_BOWL_WIDTH * 1.5;

#local TOILET_BASE_WIDTH            = 8 * INCH;
#local TOILET_BASE_HEIGHT           = 6 * INCH;
#local TOILET_BASE_DEPTH            = TOILET_BOWL_DEPTH - 8 * INCH;

#local TOILET_SHELF_WIDTH           = TOILET_BOWL_WIDTH / 3;
#local TOILET_SHELF_HEIGHT          = TOILET_BOWL_HEIGHT + TOILET_BASE_HEIGHT;
#local TOILET_SHELF_DEPTH           = TOILET_TANK_DEPTH + 1 * INCH;
#local TOILET_SHELF_BOX_DEPTH       = TOILET_SHELF_DEPTH + TOILET_BOWL_DEPTH / 2;

#local TOILET_SEAT_HEIGHT           = 5/8 * INCH;
#local TOILET_LID_HEIGHT            = 1/2 * INCH;


// Export the overall width, height, and depth.
#declare TOILET_WIDTH               = TOILET_TANK_WIDTH;
#declare TOILET_HEIGHT              = TOILET_BASE_HEIGHT
                                        + TOILET_BOWL_HEIGHT
                                        + TOILET_TANK_HEIGHT;
#declare TOILET_DEPTH               = TOILET_SHELF_DEPTH + TOILET_BOWL_DEPTH;


#local ToiletTankShape =
superellipsoid {
    <0.05, 0.05>
    translate 1 * y
    scale < TOILET_TANK_WIDTH / 2,
            TOILET_TANK_HEIGHT / 2,
            TOILET_TANK_DEPTH / 2 >
}

#local ToiletTankLid =
intersection {
    object { ToiletTankShape }
    plane { -y, 0 translate (TOILET_TANK_HEIGHT - 2 * INCH) * y }
    scale < (TOILET_TANK_WIDTH + 1) / TOILET_TANK_WIDTH,
            1,
            (TOILET_TANK_DEPTH + 1) / TOILET_TANK_DEPTH >
    translate 1/2 * INCH * y
}

#local ToiletTank =
union {
    object { ToiletTankShape texture { ToiletBowlTexture } }
    object { ToiletTankLid texture { ToiletBowlTexture } }
    intersection {
        sphere {
            < 0, 0, 0 >, 1/2 * INCH
            scale < 1, 0.5, 3 >
        }
        plane { x, 0 translate 1/8 * INCH * x }
        texture { BrushedNickelTexture }
        translate < -(TOILET_TANK_WIDTH / 2 + 1/8 * INCH),
                    TOILET_TANK_HEIGHT - 3 * INCH,
                    -(TOILET_TANK_DEPTH / 2 - 2 * INCH) >
    }
}

#local ToiletBowlShape =
intersection {
    sphere { < 0, 0, 0 >, 1/2 * INCH }
    plane { y, 0 }
    scale < TOILET_BOWL_WIDTH, TOILET_BOWL_HEIGHT * 2, TOILET_BOWL_DEPTH >
}

#local ToiletBowl =
union {
    object { ToiletBowlShape }
    intersection {
        object { ToiletBowlShape }
        plane { -y, 0 translate -1.5 * INCH * y }
        scale < (TOILET_BOWL_WIDTH + 1/2 * INCH) / TOILET_BOWL_WIDTH,
                1,
                (TOILET_BOWL_DEPTH + 1/2 * INCH) / TOILET_BOWL_DEPTH >
        translate 1/8 * INCH * y
    }
    texture { ToiletBowlTexture }
}

#local ToiletBase =
superellipsoid {
    <0.2, 0.2>
    translate 1 * y
    scale < TOILET_BASE_WIDTH / 2,
            TOILET_BASE_HEIGHT / 2,
            TOILET_BASE_DEPTH / 2 >
    texture { ToiletBowlTexture }
}

#local ToiletTankShelf =
intersection {
    object { ToiletBowlShape }
    plane { -x, 0 translate -TOILET_SHELF_WIDTH / 2 * x }
    plane {  x, 0 translate  TOILET_SHELF_WIDTH / 2 * x }
    plane { -z, 0 }
    scale < 1,
            (TOILET_BOWL_HEIGHT + TOILET_BASE_HEIGHT) / TOILET_BOWL_HEIGHT,
            (TOILET_BOWL_DEPTH + TOILET_SHELF_DEPTH) / TOILET_BOWL_DEPTH >
    texture { ToiletBowlTexture }
}

#local ToiletSeat =
intersection {
    object { ToiletBowlShape scale < 1, -0.25, 1 > }
    plane { -y, 0 }
    plane {  y, TOILET_SEAT_HEIGHT }
    scale < (TOILET_BOWL_WIDTH + 3/4 * INCH) / TOILET_BOWL_WIDTH,
            1,
            (TOILET_BOWL_DEPTH + 3/4 * INCH) / TOILET_BOWL_DEPTH >
    texture { ToiletSeatTexture }
}

#local ToiletLid =
intersection {
    object { ToiletBowlShape scale < 1, -0.25, 1 > }
    plane { -y, 0 }
    plane { y, TOILET_LID_HEIGHT }
    scale < (TOILET_BOWL_WIDTH - 3/4 * INCH) / TOILET_BOWL_WIDTH,
            1,
            (TOILET_BOWL_DEPTH - 3/4 * INCH) / TOILET_BOWL_DEPTH >
    texture { ToiletSeatTexture }
}


#declare Toilet =
union {
    union {
       object { ToiletBowl }
       object { ToiletTankShelf }
       object { ToiletSeat translate 1/4 * INCH * y }
       object { ToiletLid translate (TOILET_SEAT_HEIGHT + 1/2 * INCH) * y }
       translate < 0,
                   TOILET_BOWL_HEIGHT + TOILET_BASE_HEIGHT,
                   -(TOILET_BOWL_DEPTH / 2 + TOILET_SHELF_DEPTH) >
       }
    object {
        ToiletTank
        translate < 0,
                    TOILET_BOWL_HEIGHT + TOILET_BASE_HEIGHT,
                    -TOILET_TANK_DEPTH / 2 >
    }
    object {
        ToiletBase
        translate < 0, 0, -(TOILET_BOWL_DEPTH / 2 + TOILET_SHELF_DEPTH) >
    }
}


//////////////////////////////////////////////////////////////////////////
// A macro to create a basic bathtub.                                   //
//                                                                      //
// The bathtub will be oriented as follows:                             //
//                                                                      //
//                                                                      //
//      +Z                                                              //
//      |                                                               //
//      +-----------------------------+ -- +X                           //
//      |                             |                                 //
//      |                             |                                 //
//      |                             |                                 //
//      |                             |                                 //
//      |                             |                                 //
//      +-----------------------------+                                 //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#ifndef (BATHTUB_LENGTH)
    #declare BATHTUB_LENGTH = AS_INCHES(5, 5.5);
#end

#ifndef (BATHTUB_HEIGHT)
    #declare BATHTUB_HEIGHT = 12 * INCH;
#end

#ifndef (BATHTUB_DEPTH)
    #declare BATHTUB_DEPTH = 30 * INCH;
#end

#macro Bathtub(
            btWidth,
            btHeight,
            btDepth,
            btTexture)

    #local bathtubShape =
    superellipsoid {
        <0.05, 0.05>
        translate y
        scale < btWidth / 2, btHeight / 2, btDepth / 2 >
    }

    difference {
        object { bathtubShape }
        object {
            #local sFX = (btWidth - 6 * INCH) / btWidth;
            #local sFZ = (btDepth - 6 * INCH) / btDepth;
            bathtubShape
            scale < sFX, 1, sFZ >
            translate 2 * INCH * y
        }
        texture { btTexture }
        translate < btWidth / 2, 0, -btDepth / 2 >
    }

#end // #macro Bathtub


//////////////////////////////////////////////////////////////////////////
// A macro to create a framed mirror.                                   //

#macro FramedMirror(
            mirrorWidth,
            mirrorHeight,
            frameWidth,
            frameThickness,
            frameStyle,
            frameTexture)

    #local mLeft   = -mirrorWidth / 2 + frameWidth - 1/8 * INCH;
    #local mRight  =  mirrorWidth / 2 - frameWidth + 1/8 * INCH;
    #local mBottom =  frameWidth - 1/8 * INCH;
    #local mTop    =  mirrorHeight - frameWidth + 1/8 * INCH;
    
    union {
        object {
            WindowTrim(
                1/32 * INCH,
                mirrorWidth - 2 * frameWidth,
                mirrorHeight - 2 * frameWidth,
                0,
                frameWidth,
                frameWidth,
                frameThickness,
                frameStyle,
                frameTexture,
                true, false)
        }

        box {
            < mLeft, mBottom, -1/8 * INCH >,
            < mRight, mTop, 0 >
            texture { MirrorTexture }
        }
    }
    
#end    // #macro FramedMirror


//////////////////////////////////////////////////////////////////////////
// A macro to create a framed circular mirror.                                   //

#macro FramedCircularMirror(
            mirrorDiameter, // Overall size
            frameWidth,
            frameThickness,
            frameTexture)

    union {
        difference {
            cylinder {
                < 0, 0, -frameThickness >,
                < 0, 0, 0 >,
                mirrorDiameter / 2
            }
            cylinder {
                < 0, 0, -frameThickness * 2 >,
                < 0, 0,  frameThickness >,
                mirrorDiameter / 2 - frameWidth
            }
            texture { frameTexture }
        }
        cylinder {
            < 0, 0, -1/4 * INCH >,
            < 0, 0, 0 >,
            mirrorDiameter / 2 - frameWidth
            texture  { MirrorTexture }
        }
    }
        
#end // #macro FramedCircularMirror



//////////////////////////////////////////////////////////////////////////
// A macro to create a faucet and valve set. The faucet supply pipe is  //
// centered on the origin and aligned with the negative Z-axis.         //

#macro FaucetSet(
            faucetStyle,        // Not used ... for now!
            faucetHeight,
            faucetDepth,
            pipeDiameter,
            valveSpacing,
            faucetTexture)

    #local curveRad     = (faucetDepth - pipeDiameter) / 2;
    #local pipeRad      = pipeDiameter / 2;
    #local pipeStemLen  = faucetHeight - (curveRad + pipeRad);

    #if ( pipeStemLen <= 0)
        #local pipeStemLen = 1/4 * INCH;
    #end

    #local valveAssy =
    union {
        cone { < 0, 0, 0 >, 3/4 * INCH, < 0, 1 * INCH, 0 >, 1/4 * INCH }
        union {
            sphere { < 0, 0, 0 >, 1/2 * INCH }
            cone { < 0, 0, 0 >, 1/8 * INCH, < 2 * INCH, 0, 0 >, 3/16 * INCH }
            sphere {
                < 0, 0, 0 >, 5/16 * INCH
                translate 2 * INCH * x
            }
            translate 1.25 * INCH * y
        }
    }

    union {
        union {
            union {
                intersection {
                    torus {
                        curveRad, pipeRad
                        rotate -90 * z
                    }
                    plane { -y, 0 }
                }
                torus {
                    pipeRad, 1/8 * INCH
                    translate < 0, 1/8 * INCH, -curveRad >
                }
                translate < 0, pipeStemLen, -curveRad >
            }
            cylinder { < 0, 0, 0 >, < 0, pipeStemLen, 0 >, pipeRad }
        }
        cone { < 0, 0, 0 >, pipeRad * 3, < 0, pipeStemLen / 8, 0 >, pipeRad }
        object { valveAssy translate valveSpacing / 2 * x }
        object { valveAssy scale <-1,1,1> translate -valveSpacing / 2 * x }
        texture { faucetTexture }
    }
    
#end // #macro FaucetSet

    
//////////////////////////////////////////////////////////////////////////

#end    // #ifndef (_Fixtures_inc_)
