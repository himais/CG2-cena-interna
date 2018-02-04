//////////////////////////////////////////////////////////////////////////
// Textures.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs       	//
//////////////////////////////////////////////////////////////////////////
// Defines common colors and textures. 									//
//////////////////////////////////////////////////////////////////////////

#ifndef (_Textures_inc_)
#declare _Textures_inc_ = true;

#ifdef (_TRACE_INCLUDES_)
    #debug "Textures.inc\n"
#end

#declare AMBIENT            = 0.3;
#declare DIFFUSE            = 0.7;

#declare Clear              = color rgbf < 1.0, 1.0, 1.0, 1.0 >;

#declare Black				= color rgb < 0.0, 0.0, 0.0 >;
#declare Red  				= color rgb < 1.0, 0.0, 0.0 >;
#declare Green				= color rgb < 0.0, 1.0, 0.0 >;
#declare Blue				= color rgb < 0.0, 0.0, 1.0 >;
#declare White				= color rgb < 1.0, 1.0, 1.0 >;

#declare VeryLightGrey      = color rgb < 0.95,  0.95,  0.95  >;
#declare LightGrey          = color rgb < 0.875, 0.875, 0.875 >;
#declare MediumGrey         = color rgb < 0.7,   0.7,   0.7   >;
#declare DarkGrey           = color rgb < 0.5,   0.5,   0.5   >;

#declare Putty              = color rgb < 0.7,   0.6,   0.5   >;

#declare PinkishTan         = color rgb < 0.95,  0.9,   0.85  >;

#declare VeryLightTan       = color rgb < 1.0,   0.985, 0.875 >;
#declare LightTan           = color rgb < 1.0,   0.975, 0.75  >;
#declare MediumTan          = color rgb < 0.95,  0.875, 0.7   >;
#declare DarkTan            = color rgb < 0.9,   0.85,  0.65  >;

#declare Chocolate          = color rgb < 0.3,   0.15,  0.05  >;
#declare DarkRed            = color rgb < 0.4,   0.0,   0.025 >;

#declare VeryLightHoney     = color rgb < 1.0,   0.9,   0.7   >;
#declare LightHoney         = color rgb < 0.80,  0.775, 0.45  >;
#declare MediumHoney        = color rgb < 0.70,  0.55,  0.4   >;
#declare DarkHoney          = color rgb < 0.60,  0.55,  0.3   >;

#declare VeryLightCherry    = color rgb < 0.9,   0.8,   0.5   >;
#declare LightCherry 		= color rgb < 0.7,   0.3,   0.2   >;
#declare MediumCherry		= color rgb < 0.6,   0.25,  0.2   >;
#declare MediumDarkCherry   = color rgb < 0.5,   0.2,   0.15  >;
#declare DarkCherry			= color rgb < 0.4,   0.2,   0.1   >;
#declare VeryDarkCherry	    = color rgb < 0.3,   0.1,   0.0   >;

#declare VeryLightOak	    = color rgb < 1.0,   0.875, 0.65  >;
#declare LightOak			= color rgb < 0.8,   0.75,  0.4   >;
#declare DarkOak			= color rgb < 0.5,   0.4,   0.2   >;


#declare CherryPigment =
pigment {
    wood turbulence 0.175
    color_map {
        [ 0.0   LightCherry ]
        [ 0.3   MediumCherry ]
        [ 0.5   LightCherry ]
        [ 0.8   LightCherry ]
        [ 0.9   MediumDarkCherry ]
    }
    scale < 1, 1, 8.0 >
    rotate 90 * y
}

#declare OakPigment =
pigment {
    wood turbulence 0.1
    color_map {
        [ 0.0   VeryLightOak ]
        [ 0.5   LightOak ]
        [ 0.6   VeryLightOak ]
        [ 0.7   DarkOak ]
        [ 0.8   VeryLightOak ]
    }
    rotate 90 * y
    scale 0.5
}

#declare FloorTilePigment =
pigment {
    granite turbulence 0.5
    color_map {
        [ 0.0   VeryLightGrey ]
        [ 0.1   LightGrey ]
        [ 0.2   MediumTan ]
        [ 0.25  LightGrey ]
        [ 0.45  LightTan ]
        [ 0.5   MediumTan ]
        [ 0.55  VeryLightGrey ]
    }
    scale 3.5
}     

#declare BacksplashTilePigment =
pigment {
    granite turbulence 0.5
    color_map {
        [ 0.0   PinkishTan ]
        [ 0.1   PinkishTan ]
        [ 0.2   MediumTan ]
        [ 0.25  PinkishTan ]
        [ 0.45  PinkishTan ]
        [ 0.5   DarkTan ]
        [ 0.55  PinkishTan ]
    }
    scale 0.75
}     

#declare VerticalGroutPigment =
pigment {
    gradient x
    color_map {
        [ 0.0   Putty ]
        [ 0.01  Putty ]
        [ 0.02  Clear ]
        [ 0.98  Clear ]
        [ 0.99  Putty ]
        [ 1.01  Putty ]
    }
    scale 12
}

#declare HorizontalGroutPigment =
pigment {
    gradient z
    color_map {
        [ 0.0   Putty ]
        [ 0.01  Putty ]
        [ 0.02  Clear ]
        [ 0.98  Clear ]
        [ 0.99  Putty ]
        [ 1.01  Putty ]
    }
    scale 12
}

#declare VerticalGroovePigment =
pigment {
    gradient x
    color_map {
        [ 0.0   Black ]
        [ 0.005 Black ]
        [ 0.01  Clear ]
        [ 0.99  Clear ]
        [ 0.995 Black ]
        [ 1.01  Black ]
    }
    scale 3.0
}

#declare HorizontalGroovePigment =
pigment {
    gradient z
    color_map {
        [ 0.0   Black ]
        [ 0.01  Black ]
        [ 0.011 Clear ]
        [ 0.989 Clear ]
        [ 0.99  Black ]
        [ 1.01  Black ]
    }
    scale 3.0
}

#declare WhiteTanSwirlPigment =
pigment {
    bozo turbulence 0.2
    color_map {
        [ 0.0   White ]
        [ 0.4   White ]
        [ 0.5   LightTan ]
        [ 0.6   White ]
    }
    scale 1.5
}


#declare Glowing =
finish { ambient 1 diffuse 0 }

#declare FlatFinish =
finish { ambient AMBIENT diffuse DIFFUSE }

#declare SatinFinish =
finish {
    ambient     AMBIENT
    diffuse     DIFFUSE
    specular    0.6
    roughness   0.1
}

#declare GlossyFinish =
finish {
    ambient     AMBIENT
    diffuse     DIFFUSE
    specular    0.8
    roughness   0.01
    reflection  0.15
}

#declare SemiGlossFinish =
finish {
    ambient     AMBIENT
    diffuse     DIFFUSE
    specular    0.6
    roughness   0.05
    reflection  0.015
}

#declare PolishedFinish =
finish {
    ambient     AMBIENT
    diffuse     DIFFUSE
    specular    1.0
    roughness   0.001
    reflection  0.5
}


#declare TrimTexture =
texture {
    pigment { VeryLightTan }
    finish { FlatFinish }
}

#declare LightTanWallTexture =
texture {
    pigment { LightTan }
    finish { FlatFinish }
}

#declare MediumTanWallTexture =
texture {
    pigment { MediumTan }
    finish { FlatFinish }
}

#declare DarkTanWallTexture =
texture {
    pigment { DarkTan }
    finish { FlatFinish }
}

#declare CeilingTexture =
texture {
    pigment {
        crackle
        color_map {
            [ 0.0   White ]
            [ 0.45  White ]
            [ 0.5   VeryLightGrey ]
            [ 0.55  White ]
        }
        scale 2
    }
    finish { ambient 0.6 diffuse 0.4 }
}

#declare StuccoTexture =
texture {
    pigment {
        wrinkles turbulence 0.2
        color_map {
            [ 0.0   VeryLightTan ]
            [ 0.15  VeryLightTan ]
            [ 0.2   MediumTan ]
            [ 0.25  VeryLightTan ]
            [ 0.45  VeryLightTan ]
            [ 0.5   DarkTan ]
            [ 0.55  VeryLightTan ]
        }
        scale 0.125
    }
    finish { FlatFinish }
}

#declare CarpetTexture =
texture {
    pigment {
        crackle turbulence 0.5
        color_map {
            [ 0.0   VeryLightHoney ]
            [ 0.2   VeryLightHoney ]
            [ 0.25  LightHoney ]
            [ 0.3   VeryLightHoney ]
            [ 0.45  VeryLightHoney ]
            [ 0.5   MediumHoney ]
            [ 0.55  VeryLightHoney ]
            [ 0.7   VeryLightHoney ]
            [ 0.75  DarkHoney ]
            [ 0.8   VeryLightHoney ]
            [ 1.01  VeryLightHoney ]
        }
        scale 0.125
    }
    finish { FlatFinish }
}
/*
texture {
    pigment {
        granite turbulence 1.0
        color_map {
            [ 0.0   Clear ]
            [ 0.25  Clear ]
            [ 0.5   LightHoney ]
            [ 0.75  Clear ]
            [ 1.01  Clear ]
        }
        scale 12
    }
    finish { FlatFinish }
}
*/

#declare VenetianGoldGraniteTexture =
texture {
    pigment {
        granite turbulence 0.3
        color_map {
            [ 0.0   LightHoney ]
            [ 0.175 LightHoney ]
            [ 0.2   VeryLightTan ]
            [ 0.225 LightHoney ]
            [ 0.35  LightHoney ]
            [ 0.4   MediumHoney ]
            [ 0.45  LightHoney ]
            [ 0.6   LightHoney ]
            [ 0.7   DarkHoney ]
            [ 0.8   LightHoney ]
            [ 0.825 DarkRed ]
            [ 0.85  Chocolate ]
            [ 0.875 Black ]
            [ 0.9   MediumHoney ]
        }
    }
    finish { GlossyFinish }
}

#declare CabinetTexture =
texture {
    pigment { CherryPigment }
    finish { SatinFinish }
}

#declare DoorTexture = texture { CabinetTexture rotate -90 * z }

#declare OakFloorTexture =
texture { pigment { OakPigment } finish { SatinFinish } }
texture { pigment { HorizontalGroovePigment } finish { SatinFinish } }

#declare TiledFloorTexture =
texture { pigment { FloorTilePigment }          finish { FlatFinish } }
texture { pigment { HorizontalGroutPigment }    finish { FlatFinish } }
texture { pigment { VerticalGroutPigment }      finish { FlatFinish } }

#declare OakTexture =
texture { pigment { OakPigment } finish { SatinFinish } }

#declare BacksplashTileTexture =
texture { pigment { BacksplashTilePigment }          finish { FlatFinish } }
texture {
    pigment { HorizontalGroutPigment scale 0.25 rotate 45 * y }
    finish { FlatFinish }
}
texture {
    pigment { VerticalGroutPigment scale 0.25 rotate 45 * y }
    finish { FlatFinish }
}


#declare VanityTopTexture =
texture {
    pigment { WhiteTanSwirlPigment }
    finish { GlossyFinish }
}

#declare MirrorTexture =
texture {
    pigment { White }
    finish {
        ambient 0.1
        diffuse 0.3
        reflection 1
    }
}

#declare GlassTexture =
texture {
    pigment { color rgbf < 0.95, 1.0, 0.95, 1.0 > }
    finish {
        ambient 0
        diffuse 0
        reflection 0.2
    }
}

#declare WindowTexture =
texture {
    pigment { color rgb < 0.975, 0.95, 0.8 > }
    finish {
        ambient     AMBIENT
        diffuse     DIFFUSE
        specular    1.0
        roughness   0.01
    }
}

#declare WndowShadeFrameTexture =
texture {
    pigment { White }
    finish { FlatFinish }
}

#declare WindowShadeTexture =
texture {
    pigment {
        gradient y
        color_map {
            [ 0.0   VeryLightTan filter 0.1 ]
            [ 0.2   VeryLightTan filter 0.1 ]
            [ 0.4   LightTan filter 0.1 ]
            [ 0.45  LightTan filter 0.1 ]
            [ 0.5   color rgb < 0.4, 0.4,  0.0 > filter 0.1 ]
            [ 0.55  LightTan filter 0.1 ]
            [ 0.6   LightTan filter 0.1 ]
            [ 0.8   VeryLightTan filter 0.1 ]
        }
        scale < 1, 1, 1 >
    }
    finish { FlatFinish }
}

#declare FlatBlackTexture =
texture { pigment { Black } finish { FlatFinish } }

#declare GlossyBlackTexture =
texture { pigment { Black } finish { GlossyFinish } }


#declare VanityCabinetTexture   = texture { TrimTexture }

#declare OfficeTexture          = texture { LightTanWallTexture }
#declare HallwayTexture         = texture { LightTanWallTexture }
#declare KitchenTexture         = texture { LightTanWallTexture }
#declare GreatRoomTexture       = texture { LightTanWallTexture }
#declare LaundryRoomTexture     = texture { LightTanWallTexture }
#declare GarageTexture          = texture { LightTanWallTexture }
#declare SunroomTexture         = texture { LightTanWallTexture }
#declare BedroomTexture         = texture { MediumTanWallTexture }
#declare BathroomTexture        = texture { DarkTanWallTexture }

#end	// #ifndef (_Textures_inc_)
