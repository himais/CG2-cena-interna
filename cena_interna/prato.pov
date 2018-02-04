// Persistence of Vision Ray Tracer Scene Description File
// File: crystallo.pov
// Vers: 3.1
// Desc: a oval crytall glass plate
// Date: 12/08/1999
// Auth: ReVerSi (reinhard.rettelbach.KH@t.online.de)
//

#version 3.1;

#include "colors.inc"
#include "textures.inc"	// Standard Texture definitions
#include "skies.inc" 
#include "math.inc"


 

#declare sinx = function{sin(2.5*(x/3)^2)-z}


#declare Wrinklong = function{pigment{wrinkles color_map{
                [0 rgb 0]
                [1 rgb 1]}    }
}

plane { y, -4.5 pigment {function{sinx(x, y, z)}
                         color_map{
                                [0, rgb <1, 0.65, 0.65>]
                                [1, rgb <0.85, 0.4, 0.05>]
                                }
                         scale 2 }
                finish{ ambient 0.6}
                                }
                                

//crystal glass plate  
isosurface{
        function{sqrt((x/3)^2+(16*y*exp(-(x^2+z^2)/10)+0.3*Wrinklong(x, 1, z))^4+(z/3)^2-3.5)}
                threshold 0.15
                max_gradient 10000                    //In order to speed up rendering time, you might try to choose lower settings in this 
                accuracy 0.001                        //and higher ones in this line, but be cautious: some strange effects could occur. ;-)
                bounded_by{box{-6, 6}}     hollow  
                pigment{ rgbf <1, 0.95, 0.95, 0.95>}
                finish{specular 0.15 reflection 0.2} 
                interior{ior 1.35
                        media {absorption 1 rgb  <0.1, 0.1, 0>}
                } 
                scale <1.2, 0.8, 1>
                rotate <-20, 0, 10>   }