//////////////////////////////////////////////////////////////////////////
// HardwareTextures.inc  1.0 KEA Copyright(c) 2005, K.E. Ayers Designs  //
//////////////////////////////////////////////////////////////////////////
// Textures for cabinets, and plumbing and lighting fixtures.           //
//////////////////////////////////////////////////////////////////////////

// This file should only be included once!
#ifndef (_HardwareTextures_Inc_)
#declare _HardwareTextures_Inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "HardwareTextures.inc\n"
#end

#include "Textures.inc"


#declare BrushedNickelTexture =
texture {
    pigment { color rgb < 0.8, 0.8, 0.85 > }
    finish {
        ambient     AMBIENT
        diffuse     DIFFUSE
        specular    0.8
        roughness   0.05
        metallic
        brilliance  3.0
    }
}


#declare ToiletBowlTexture =
    texture { pigment { White } finish { GlossyFinish } }

#declare ToiletSeatTexture =
    texture { pigment { White } finish { SatinFinish } }

#declare BathtubTexture = texture { ToiletBowlTexture }

        
#end    // #ifndef (_HardwareTextures_Inc_)
