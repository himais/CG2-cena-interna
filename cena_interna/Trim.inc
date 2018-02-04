//////////////////////////////////////////////////////////////////////////
// Trim.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs            //
//////////////////////////////////////////////////////////////////////////
// Defines a set of macros, which can generate sections of trim shapes  //
// for baseboards, door openings, and window and picture frames.        //
//////////////////////////////////////////////////////////////////////////

// This file should only be included once!
#ifndef (_Trim_Inc_)
#declare _Trim_Inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Trim.inc\n"
#end

#include "Units.inc"

#declare INSIDE_CORNER_BEVEL    = -1;
#declare NO_CORNER_BEVEL        =  0;
#declare OUTSIDE_CORNER_BEVEL   =  1;

#declare TRIM_STYLE_FLAT        =  0;
#declare TRIM_STYLE_CURVED      =  1;
#declare TRIM_STYLE_FANCY       =  2;


#ifndef (VENEER_THICKNESS)
    #declare VENEER_THICKNESS = 1/32 * INCH;
#end


//////////////////////////////////////////////////////////////////////////
// A macro to generate a length of decorated ("fancy") trim. The macro  //
// assumes the trim section will be attached to the "inside" of a wall  //
// that is oriented in the "standard way".                              //

#macro FancyTrimSection(
            trimLeft,
            trimRight,
            trimWidth,
            trimThickness)

    #local tCutDepth            = trimThickness / 3;
    #local tBorderWidth         = trimThickness;
    #local tNarrowCutWidth      = tCutDepth * 2;
    #local tBorderWidth         = trimThickness;
    #local tWideCutWidth        = trimWidth / 2
                                    - tBorderWidth
                                    - tNarrowCutWidth;
    #local tWideCutDepthScale   = tCutDepth * 2 / tWideCutWidth;

    #local halfTrimSection =
    intersection {
        difference {
            box {
                < trimLeft, 0, -trimThickness >,
                < trimRight, trimWidth / 2, 0 >
            }
            cylinder {
                < trimLeft  - 1, 0, 0 >,
                < trimRight + 1, 0, 0 >,
                tNarrowCutWidth / 2
                translate < 0, tWideCutWidth + tNarrowCutWidth / 2,
                                -trimThickness >
            }
            cylinder {
                < trimLeft  - 1, 0, 0 >,
                < trimRight + 1, 0, 0 >,
                tWideCutWidth * 0.49
                scale < 1, 1, tWideCutDepthScale >
                translate < 0, tWideCutWidth / 2, -trimThickness >
            }
        }
        plane {
            y, 0
            rotate -45 * x
            translate < 0, (trimWidth - tCutDepth) / 2,
                            -trimThickness + tCutDepth >
        }
    }
    
    union {
        object { halfTrimSection }
        object { halfTrimSection scale < 1, -1, 1 > }
        translate trimWidth / 2 * y
    }
    
#end // #macro FancyTrimSection


//////////////////////////////////////////////////////////////////////////
// A macro to generate a length of baseboard trim. The macro assumes    //
// the trim section will be attached to the "inside" of a wall that is  //
// oriented in the "standard way".                                      //
//                                                                      //
// The left and right bevel parameters determine how the ends of the    //
// trim section are beveled.                                            //
//                                                                      //
//  INSIDE_CORNER_BEVEL     The end of the trim section will align with //
//                          the end of the wall section. A 45-degree    //
//                          bevel will be applied to the end.           //
//                                                                      //
//  OUTSIDE_CORNER_BEVEL    The end of the trim section will extend     //
//                          beyond the wall's edge by the trim's        //
//                          thickness. A 45-degree bevel will then be   //
//                          cut from the inside facing edge to the      //
//                          wall's inside face.                         //
//                                                                      //
//  NO_CORNER_BEVEL         The end of the trim section will align with //
//                          the end of the wall section. No bevel will  //
//                          be applied.                                 //
//////////////////////////////////////////////////////////////////////////

#macro BaseboardTrim(
            wallLength,
            trimWidth,
            trimThickness,
            trimStyle,
            leftBevel,
            rightBevel,
            trimTexture)

    #local leftEndPos   = ((leftBevel = OUTSIDE_CORNER_BEVEL)
                                ? -trimThickness : 0);
    #local rightEndPos  = ((rightBevel = OUTSIDE_CORNER_BEVEL)
                                ? (wallLength + trimThickness)
                                : wallLength);

    #local trimSection =
        #switch (trimStyle)
            #case (TRIM_STYLE_CURVED)
                intersection {
                    cylinder {
                        < leftEndPos,  0, 0 >,
                        < rightEndPos, 0, 0 >,
                        trimWidth
                        scale < 1, 1, trimThickness / trimWidth >
                    }
                    plane { -y, 0 }
                    plane {  z, 0 }
                }
            #break
            
            #case (TRIM_STYLE_FANCY)
                object {
                    FancyTrimSection(
                        leftEndPos,
                        rightEndPos,
                        trimWidth,
                        trimThickness)
                }
            #break;

            #else
                box {
                    < leftEndPos, 0, -trimThickness >,
                    < rightEndPos, trimWidth, 0 >
                }
        #end    // #switch (trimStyle)

    #if ((leftBevel = NO_CORNER_BEVEL) & (rightBevel = NO_CORNER_BEVEL))
        object { trimSection texture { trimTexture } }
    #else
        intersection {
            object { trimSection }
            plane { -x, 0 rotate leftBevel * 45 * y }
            plane {
                x, 0
                rotate -rightBevel * 45 * y
                translate wallLength * x
            }
            texture { trimTexture }
        }
    #end
    
#end    // #macro BaseboardTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a length of crown molding trim. The macro        //
// assumes  the trim section will be attached to the "inside" of a wall //
// that is oriented in the "standard way".                              //
//                                                                      //
// The left and right bevel parameters determine how the ends of the    //
// trim section are beveled.                                            //
//                                                                      //
//  INSIDE_CORNER_BEVEL     The end of the trim section will align with //
//                          the end of the wall section. A 45-degree    //
//                          bevel will be applied to the end.           //
//                                                                      //
//  OUTSIDE_CORNER_BEVEL    The end of the trim section will extend     //
//                          beyond the wall's edge by the trim's        //
//                          thickness. A 45-degree bevel will then be   //
//                          cut from the inside facing edge to the      //
//                          wall's inside face.                         //
//                                                                      //
//  NO_CORNER_BEVEL         The end of the trim section will align with //
//                          the end of the wall section. No bevel will  //
//                          be applied.                                 //
//////////////////////////////////////////////////////////////////////////

#macro CrownMoldingTrim(
            wallLength,
            trimWidth,
            trimThickness,
            trimStyle,
            leftBevel,
            rightBevel,
            trimTexture)

    #local leftEndPos   = ((leftBevel = OUTSIDE_CORNER_BEVEL)
                                ? -trimWidth : 0);
    #local rightEndPos  = ((rightBevel = OUTSIDE_CORNER_BEVEL)
                                ? (wallLength + trimWidth)
                                : wallLength);

    #local trimSection =
        #switch (trimStyle)
            #case (TRIM_STYLE_CURVED)
                intersection {
                    cylinder {
                        < leftEndPos,  0, 0 >,
                        < rightEndPos, 0, 0 >,
                        trimWidth
                        scale < 1, 1, trimThickness / trimWidth >
                    }
                    plane { -y, 0 }
                    plane {  z, 0 }
                }
            #break
            
            #case (TRIM_STYLE_FANCY)
                object {
                    FancyTrimSection(
                        leftEndPos,
                        rightEndPos,
                        trimWidth,
                        trimThickness)
                }
            #break;

            #else
                box {
                    < leftEndPos, 0, -trimThickness >,
                    < rightEndPos, trimWidth, 0 >
                }
        #end    // #switch (trimStyle)

    #if ((leftBevel = NO_CORNER_BEVEL) & (rightBevel = NO_CORNER_BEVEL))
        object { trimSection texture { trimTexture } rotate -45 * x }
    #else
        intersection {
            object { trimSection rotate -45 * x }
            plane { -x, 0 rotate leftBevel * 45 * y }
            plane {
                x, 0
                rotate -rightBevel * 45 * y
                translate wallLength * x
            }
            texture { trimTexture }
        }
    #end
    
#end    // #macro BaseboardTrim


//////////////////////////////////////////////////////////////////////////
// A macro to calculate the vertical offset required to place a section //
// of crown molding trim at the ceiling height.                         //

#macro CrownMoldingCeilingOffset(ceilingHeight, trimWidth)
    (ceilingHeight - sqrt((trimWidth * trimWidth) / 2))
#end


//////////////////////////////////////////////////////////////////////////
// A macro to generate a vertical section of trim, which can be used to //
// frame an opening, such as a door or window. The right edge of the	//
// trim section will be aligned with the Y-axis, and the back will be	//
// aligned on the X/Y plane.											//

#macro VertFrameTrim(
			openingBottom,
			openingTop,
			tWidth,
			tThickness,
			bevelTop,		// true/false
			bevelBottom,	// true/false
			tStyle,
			tTexture)

	#local tBottom = ((bevelBottom)
						? (openingBottom - tWidth)
						: openingBottom);
	#local tTop = ((bevelTop)
						? (openingTop + tWidth)
						: openingTop);

	#switch (tStyle)
		#case (TRIM_STYLE_CURVED)
			#local tSect =
			intersection {
				#local rMajor = tWidth - tThickness;
				#local rMinor = tThickness;					
				union {
					intersection {
						cylinder {
							< -rMajor, tBottom, 0 >,
							< -rMajor, tTop, 0 >,
							rMajor
						}
						plane { -x, 0 translate -rMajor * x }
						scale < 1, 1, tThickness / rMajor > 
					}
					intersection {
						cylinder {
							< -rMajor, tBottom, 0 >,
							< -rMajor, tTop, 0 >,
							rMinor
						}
						plane { x, 0 translate -rMajor * x }
					}
				}
				plane { z, 0 }
			}
		#break

        #case (TRIM_STYLE_FANCY)
            #local tLeft  = openingTop - tTop;
            #local tRight = tLeft + (tTop - tBottom);
            
			#local tSect =
            object {
                FancyTrimSection(
                    tLeft,
                    tRight,
			        tWidth,
			        tThickness)
                rotate -90 * z
                translate < -tWidth, openingTop, 0 >
            }
        #break
			
		#else
			// Must be flat trim.
			#local tSect =
			box {
				< -tWidth, tBottom, -tThickness >,
				< 0, tTop, 0 >
			}
	#end	// #switch (tStyle)
		
	#if (bevelTop | bevelBottom)
		intersection {
			object { tSect }
			#if (bevelTop)
				plane {
					y, 0
					rotate -45 * z
					translate (openingTop - (1/64*INCH)) * y
				}
			#end
			#if (bevelBottom)
				plane {
					-y, 0
					rotate 45 * z
					translate (openingBottom + (1/64*INCH)) * y
				}
			#end
			texture { tTexture rotate 90 * z }
		}
	#else
		object { tSect texture { tTexture rotate 90 * z} }
	#end

#end	// #macro VertFrameTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a horizontal section of trim, which can be used	//
// to frame an opening, such as a door or window. The top edge of the	//
// trim section will be aligned with the X-axis, and the back will be	//
// aligned on the X/Y plane.											//

#macro HorizFrameTrim(
			openingLeft,
			openingRight,
			tWidth,
			tThickness,
			bevelLeft,		// true/false
			bevelRight,		// true/false
			tStyle,
			tTexture)

	#local tLeft = ((bevelLeft)
						? (openingLeft - tWidth)
						: openingLeft);
	#local tRight = ((bevelRight)
						? (openingRight + tWidth)
						: openingRight);

	#switch (tStyle)
		#case (TRIM_STYLE_CURVED)
			#local tSect =
			intersection {
				#local rMajor = tWidth - tThickness;
				#local rMinor = tThickness;					
				union {
					intersection {
						cylinder {
							< tLeft, -rMajor, 0 >,
							< tRight, -rMajor, 0 >,
							rMajor
						}
						plane { -y, 0 translate -rMajor * y }
						scale < 1, 1, tThickness / rMajor > 
					}
					intersection {
						cylinder {
							< tLeft, -rMajor, 0 >,
							< tRight, -rMajor, 0 >,
							rMinor
						}
						plane { y, 0 translate -rMajor * y }
					}
				}
				plane { z, 0 }
			}
		#break
        
        #case (TRIM_STYLE_FANCY)
			#local tSect =
            object {
                FancyTrimSection(
			        tLeft,
                    tRight,
                    tWidth,
			        tThickness)
                translate -tWidth * y
            }
        #break
        
		#else
			// Must be flat trim.
			#local tSect =
			box {
				< tLeft, -tWidth, -tThickness >,
				< tRight, 0, 0 >
			}
	#end	// #switch (tStyle)
		
	#if (bevelLeft | bevelRight)
		intersection {
			object { tSect }
			#if (bevelLeft)
				plane {
					-x, 0
					rotate -45 * z
					translate (openingLeft + (1/64*INCH)) * x
				}
			#end
			#if (bevelRight)
				plane {
					x, 0
					rotate 45 * z
					translate (openingRight - (1/64*INCH)) * x
				}
			#end
			texture { tTexture }
		}
	#else
		object { tSect texture { tTexture } }
	#end

#end	// #macro HorizFrameTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a trim frame around a window opening. The macro  //
// assumes the wall, in which the window opening has been punched, is   //
// oriented in the "standard way".                                      //

#macro WindowTrim(
            wallThickness,
            winWidth,
            winHeight,
            winCenter,
            winBottom,
            trimWidth,
            trimThickness,
            trimStyle,
            trimTexture,
            trimInside,
            trimOutside)

    #local winLeft  = winCenter - (winWidth / 2);
    #local winRight = winLeft   + winWidth;
    #local winTop   = winBottom + winHeight;

	// Vertical section of trim lining the interior of the window opening.
    #local intVT =
    box {
        < 0, winBottom, 0 >,
        < trimThickness, winTop, wallThickness >
        texture { trimTexture rotate 90 * z }
    }
    
	// Horizontal section of trim lining the interior of the window opening.
    #local intHT =
    box {
        < winLeft, 0, 0 >,
        < winRight, trimThickness, wallThickness >
        texture { trimTexture }
    }

    #local frameTrim =        
    union {
        object {
        	VertFrameTrim(
				winBottom,
				winTop,
				trimWidth,
				trimThickness,
				true,
				true,
				trimStyle,
				trimTexture)
			translate winLeft * x
		}
        object {
        	VertFrameTrim(
				winBottom,
				winTop,
				trimWidth,
				trimThickness,
				true,
				true,
				trimStyle,
				trimTexture)
			scale < -1, 1, 1 >
			translate winRight * x
		}
		object {
			HorizFrameTrim(
				winLeft,
				winRight,
				trimWidth,
				trimThickness,
				true,
				true,
				trimStyle,
				trimTexture)
			translate winBottom * y
		}
		object {
			HorizFrameTrim(
				winLeft,
				winRight,
				trimWidth,
				trimThickness,
				true,
				true,
				trimStyle,
				trimTexture)
			scale < 1, -1, 1 >
			translate winTop * y
		}
    }
    
    union {
        object { intVT translate winLeft * x }
        object { intVT scale < -1, 1, 1 > translate winRight * x }
        object { intHT translate winBottom * y }
        object { intHT scale < 1, -1, 1 > translate winTop * y }
        
        #if (trimInside)
            object { frameTrim }
        #end
        
        #if (trimOutside)
            object {
                frameTrim
                scale < 1, 1, -1 >
                translate wallThickness * z
            }
        #end
    }

#end    // #macro WindowTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a wall frame around an otherwise untrimmed       //
// window opening. The macro assumes the wall, in which the window      //
// opening has been punched, is oriented in the "standard way".         //

#macro WindowOpeningTrim(
            wallThickness,
            winWidth,
            winHeight,
            winCenter,
            winBottom,
            wallTexture)

    #local winLeft  = winCenter - (winWidth / 2);
    #local winRight = winLeft   + winWidth;
    #local winTop   = winBottom + winHeight;

	// Vertical section of veneer lining the interior of the window opening.
    #local intVT =
    box {
        < 0, winBottom, 0 >,
        < VENEER_THICKNESS, winTop, wallThickness >
        texture { wallTexture }
    }
    
	// Horizontal section of veneer lining the interior of the window opening.
    #local intHT =
    box {
        < winLeft, 0, 0 >,
        < winRight, VENEER_THICKNESS, wallThickness >
        texture { wallTexture }
    }
        
    union {
        object { intVT translate winLeft * x }
        object { intVT scale < -1, 1, 1 > translate winRight * x }
        object { intHT translate winBottom * y }
        object { intHT scale < 1, -1, 1 > translate winTop * y }
    }

#end    // #macro WindowOpeningTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a trim frame around a door opening. The macro  	//
// assumes the wall, in which the door opening has been punched, is     //
// oriented in the "standard way".                                      //

#macro DoorTrim(
            wallThickness,
            doorWidth,
            doorHeight,
            doorCenter,
            trimWidth,
            trimThickness,
            trimStyle,
            trimTexture,
            trimInside,
            trimOutside)

    #local doorLeft   = doorCenter - (doorWidth / 2);
    #local doorRight  = doorLeft   + doorWidth;
    #local doorTop    = doorHeight;
    #local doorBottom = 0;

	// Vertical section of trim lining the interior of the door opening.
    #local intVT =
    box {
        < 0, doorBottom, 0 >,
        < trimThickness, doorTop, wallThickness >
        texture { trimTexture rotate 90 * z }
    }
    
	// Horizontal section of trim lining the interior of the door opening.
    #local intHT =
    box {
        < doorLeft, 0, 0 >,
        < doorRight, trimThickness, wallThickness >
        texture { trimTexture }
    }
    
    #local frameTrim =
    union {
        object {
        	VertFrameTrim(
				doorBottom,
				doorTop,
				trimWidth,
				trimThickness,
				true,
				false,
				trimStyle,
				trimTexture)
			translate doorLeft * x
		}
        object {
        	VertFrameTrim(
				doorBottom,
				doorTop,
				trimWidth,
				trimThickness,
				true,
				false,
				trimStyle,
				trimTexture)
			scale < -1, 1, 1 >
			translate doorRight * x
		}
		object {
			HorizFrameTrim(
				doorLeft,
				doorRight,
				trimWidth,
				trimThickness,
				true,
				true,
				trimStyle,
				trimTexture)
			scale < 1, -1, 1 >
			translate doorTop * y
		}
    }
        
    union {
        object { intVT translate doorLeft * x }
        object { intVT scale < -1, 1, 1 > translate doorRight * x }
        object { intHT scale < 1, -1, 1 > translate doorTop * y }
        
        #if (trimInside)
            object { frameTrim }
        #end
        
        #if (trimOutside)
            object {
                frameTrim
                scale < 1, 1, -1 >
                translate wallThickness * z
            }
        #end
    }

#end    // #macro DoorTrim


//////////////////////////////////////////////////////////////////////////
// A macro to generate a wall frame around an otherwise untrimmed door  //
// opening. The macro assumes the wall, in which the door opening has   //
// been punched, is oriented in the "standard way".                     //

#macro DoorOpeningTrim(
            wallThickness,
            doorWidth,
            doorHeight,
            doorCenter,
            wallTexture)

    #local doorLeft   = doorCenter - (doorWidth / 2);
    #local doorRight  = doorLeft   + doorWidth;
    #local doorTop    = doorHeight;
    #local doorBottom = 0;

	// Vertical section of trim lining the interior of the door opening.
    #local intVT =
    box {
        < 0, doorBottom, 0 >,
        < VENEER_THICKNESS, doorTop, wallThickness >
        texture { wallTexture }
    }
    
	// Horizontal section of trim lining the interior of the door opening.
    #local intHT =
    box {
        < doorLeft, 0, 0 >,
        < doorRight, VENEER_THICKNESS, wallThickness >
        texture { wallTexture }
    }
        
    union {
        object { intVT translate doorLeft * x }
        object { intVT scale < -1, 1, 1 > translate doorRight * x }
        object { intHT scale < 1, -1, 1 > translate doorTop * y }
    }

#end    // #macro DoorOpeningTrim

#end    // _Trim_Inc_
