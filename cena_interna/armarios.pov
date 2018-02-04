//////////////////////////////////////////////////////////////////////////
// CabinetsTest.inc  1.0  KEA  Copyright(c) 2005, K.E. Ayers Designs    //
//////////////////////////////////////////////////////////////////////////
// A test bed for cabinets and other stuff.                             //
//////////////////////////////////////////////////////////////////////////  

#ifndef (AMBIENT)
    #declare AMBIENT = 0.3;
#end

#ifndef (DIFFUSE)
    #declare DIFFUSE = 0.7;
#end


#include "Units.inc"
#include "Cabinets.inc"


//Textura dos armários
#declare CherryTexture =
texture {
    pigment {
        wood turbulence 0.075
        color_map {
            [ 0.0   color rgb < 0.7,  0.4,  0.2  > ]
            [ 0.3   color rgb < 0.7,  0.4,  0.2  > ]
            [ 0.5   color rgb < 0.4,  0.2,  0.0  > ]
            [ 0.7   color rgb < 0.7,  0.4,  0.2  > ]
        }
        rotate 90 * y
        scale < 4, 0.25, 0.25 > 
    }
    finish {
        ambient     AMBIENT
        diffuse     DIFFUSE
        specular    0.6
        roughness   0.01
    }
}

#declare CABINET_KNOB = object { CABINET_KNOB_HANDLE }  

/*
________________________________________________________

                Armários de parede
________________________________________________________
*/

#declare armarioTopMini = 
object {
   CabinetWithDoors(
        37 * INCH, 12 * INCH, 15 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_WALL_UNIT,
        SINGLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_BOTTOM, 0 > )
}  

#declare armarioTopMini2 = 
object {
   CabinetWithDoors(
        11 * INCH, 28 * INCH, 15 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_WALL_UNIT,
        SINGLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_BOTTOM, 0 > )
} 

#declare armarioTopMini3 = 
object {
   CabinetWithDoors(
        15 * INCH, 28 * INCH, 15 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_WALL_UNIT,
        SINGLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_BOTTOM, 0 > )
}   

#declare armarioTop =
object {
    CabinetWithDoors(
        26 * INCH, 28 * INCH, 15 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_WALL_UNIT,
        DOUBLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_BOTTOM, 0 > )
    
}   

#declare armarioCantoDireitoTop = 
object {
    CornerCabinetLazySusan(
        36 * INCH, 28 * INCH, 18 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_WALL_UNIT,
        < 0, KNOB_ON_TOP, 0 > )
}

/*
________________________________________________________

                Armários de chão
________________________________________________________
*/

#declare armarioBottomMini = 
object {
    CabinetWithDoors(
        15 * INCH, 36 * INCH, 24 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_BASE_UNIT,
        SINGLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_TOP, 0 >)
}  

#declare armarioBottomGaveta = 
object {
    CabinetWithDrawers(
        30 * INCH, 36 * INCH, 24 * INCH, 4
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture },
        CABINET_BASE_UNIT)
}


#declare armarioBottomGavetaMini = 
object {
    CabinetWithDrawers(
        15 * INCH, 36 * INCH, 24 * INCH, 4
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture },
        CABINET_BASE_UNIT)
}


#declare armarioBottom = 
object {
    CabinetWithDoors(
        30 * INCH, 36 * INCH, 24 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_BASE_UNIT,
        DOUBLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_TOP, 0 >)
}

#declare armarioCantoDireito =   
  object {
    CornerCabinetWithDoors(
        36 * INCH, 36 * INCH, 19 * INCH,
        texture { CherryTexture rotate 90 * z },
        texture { CherryTexture rotate 90 * z },
        CABINET_BASE_UNIT,
        DOUBLE_DOOR_CABINET,
        HINGES_ON_BOTH_SIDES,
        < 0, KNOB_ON_TOP, 0 > )
}