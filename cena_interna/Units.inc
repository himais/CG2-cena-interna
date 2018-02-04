//////////////////////////////////////////////////////////////////////////
// Walls.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs           //
//////////////////////////////////////////////////////////////////////////
// Defines a set of macros for converting between inches and feet.      //
// The basic unit of measurement is assumed to be INCHES.               //
//                                                                      //
// A global SCALE factor can be declared externally. If not defined, it //
// will be defined here as 1.0.                                         //
//////////////////////////////////////////////////////////////////////////

// This file should only be included once!
#ifndef (_Units_Inc_)
#declare _Units_Inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Units.inc\n"
#end

//////////////////////////////////////////////////////////////////////////
// Define the global scale factor, if not already defined.              //

#ifndef (SCALE)
    #declare SCALE = 1.0;
#end


//////////////////////////////////////////////////////////////////////////
// Basic unit scale factors.                                            //

#declare INCH   = 1.0;          // The "basic unit" is an inch.
#declare FOOT   = INCH * 12;
#declare YARD   = INCH * 36;


//////////////////////////////////////////////////////////////////////////
// Length conversion macros                                             //

#macro INCHES(Inches) (Inches * INCH) #end

#macro FEET_INCHES(Feet, Inches) INCHES(Feet * FOOT + Inches) #end

#macro AS_INCHES(Feet, Inches) ((Feet * FOOT) + Inches) #end

#macro AS_FEET(Inches) (Inches / FOOT) #end

#macro AS_YARDS(Inches) (Inches / YARD) #end


//////////////////////////////////////////////////////////////////////////
// Area calculation macros                                              //

#macro SQ_IN(widInInches, depthInInches)
    (widInInches * depthInInches)
#end

#macro SQ_FT(widInInches, widInInches)
    (AS_FEET(widInInches) * AS_FEET(widInInches))
#end

#macro SQ_YD(widInInches, widInInches)
    (AS_YARDS(widInInches) * AS_YARDS(widInInches))
#end


#end    // #ifndef (_Units_Inc_)
