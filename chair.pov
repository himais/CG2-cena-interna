#include "colors.inc"
#include "woods.inc"

#declare ColMod = 1.25;

#declare M_MyWood13A =   //This has bee adapted from woodmaps.inc
color_map { 
    [0.0, 0.1 color rgb <0.70, 0.45, 0.30>*ColMod
              color rgb <0.80, 0.45, 0.30>*ColMod]
    [0.1, 0.9 color rgb <0.80, 0.45, 0.30>*ColMod
              color rgb <0.90, 0.65, 0.45>*ColMod]
    [0.9, 1.0 color rgb <0.90, 0.65, 0.45>*ColMod
              color rgb <0.70, 0.45, 0.30>*ColMod]
}

#declare F_Chair =
   finish {
      roughness 0.4
      specular 0.2
     }

#declare T_MyWood13 = 
    texture { pigment { P_WoodGrain1A  color_map { M_MyWood13A }} finish {F_Chair} }
    
#declare T_Fabric =
   texture { pigment {rgb 1} }
           
   texture {
      pigment {gradient z scale 7.5  translate z*29
         color_map {
            [0 rgbt 1]
            [0.03 rgb 0]
            [0.04 rgb 0]
            [0.07 rgbt 1]
            [0.12 rgbt 1]
            [0.15 rgb 0]
            [0.16 rgb 0]
            [0.19 rgbt 1]
           }
        }
      finish { diffuse 0.8 }
     } //end of 2nd layer
     
    texture {
      pigment {gradient z translate z*150 scale 0.5
         color_map {
            [0.5 rgb 1]
            [0.65 rgbt 1]
            [0.85 rgbt 1]
            [1 rgb 1]
           }
         warp {repeat x*0.2 offset z*0.25}
        }
     } //end of 3rd layer
     
   texture {
      pigment {gradient x scale 7.5  translate x*34.7
         color_map {
            [0 rgbt 1]
            [0.03 rgb <0.25,0.1,0>]
            [0.04 rgb <0.25,0.1,0>]
            [0.07 rgbt 1]
            [0.12 rgbt 1]
            [0.15 rgb <0.25,0.1,0>]
            [0.16 rgb <0.25,0.1,0>]
            [0.19 rgbt 1]
           }
        }
      finish { diffuse 0.8 }
     } //end of 4rd layer
     
    texture {
      pigment {gradient x translate x*150 scale 0.5
         color_map {
            [0.5 rgb <0.9,0.65,0.5>]
            [0.75 rgbt 1]
            [0.85 rgbt 1]
            [1 rgb <0.9,0.65,0.5>]
           }
         warp {repeat z*0.2 offset x*0.25}
        }
      normal {granite scale 0.2}
     } //end of layered texture
     

#declare F_Leg =
   difference {
      prism {cubic_spline conic_sweep
         0.666,1,8,
         <3,-3>,<-3,-3>,<-3,3>,<3,3>,<3,-3>,<-3,-3>,<-3,3>,<3,3>
         sturm
         scale <1,121.621621,1>
         translate y*-81.121622
        }
      box {<-4,-0.5,-4>,<-0.5,41,4>}
      box {<-1,-0.5,0.5>,<4,41,4>}
      bounded_by { box {<-0.5,0,-4>,<4,41,4>} }
      texture {T_MyWood13 scale 5 rotate x*89}
     }

#declare R_Leg =
   union {
      prism {cubic_spline
         0,1,12,
         //outer rim
         <-25,-30>,<0,40.5>,<-25,115>,
         <-25,-30>,<0,40.5>,<-25,115>,
         //inner rim
         <-25,-29>,<-3,40.5>,<-25,114>,
         <-25,-29>,<-3,40.5>,<-25,114>
         sturm
         rotate x*-90
         scale <1,1,3>
         translate z*1.5
         clipped_by { box {<-12,0,-2>,<1,85.5,2>} }
        }
      cylinder {<-10.2,85.5,-1.5>,<-10.2,85.5,1.5>,1}
      texture {T_MyWood13 scale 5 rotate x*91}
    }
 
#declare ChairBack =
   union {
      difference {
         cylinder {0,<0,4,0>,22}
         cylinder {<0,-1,0>,<0,5,0>,21}
        }
      torus {21.5,0.5 sturm translate y*4}
      torus {21.5,0.5 sturm}
      scale <1,1,1.5>
     }

#declare K_Chair =     
   union {
      //the front legs
      object {F_Leg translate z*-14}
      object {F_Leg rotate y*-90 translate z*14}
      box {<-0.75,28.5,-16>,<0.75,30,16>
         texture {T_MyWood13 scale 5 rotate x*2}
         translate x*1.5}
   
      //the supporting rim
      prism {cubic_spline
         0,1,18,
         //outer rim
         <27,0>,<18,-15>,<-18,-15>,<-27,0>,<-18,15>,
         <18,15>,<27,0>,<18,-15>,<-18,-15>,
         //inner rim
         <25.5,0>,<17,-13.5>,<-17,-13.5>,<-25.5,0>,<-17,13.5>,
         <17,13.5>,<25.5,0>,<17,-13.5>,<-17,-13.5>
         sturm
         scale <1,2,1>
         translate y*32
         texture {T_MyWood13 scale 5 rotate x*1.5}
         clipped_by { box {<-27,32,17>,<1,33.7,-17>} }
        }
      
      //the seat
      prism {cubic_spline
         0,1,8,
         <-18,-16>,<-27,0>,<-18,16>,
         <5,16>,<5,-16>,
         <-18,-16>,<-27,0>,<-18,16>
         sturm
         scale <1,3,1>
         translate <-1,40.5,0>
         texture {T_MyWood13 scale 5 rotate x*-2}
        }
        
      //the cushion
      blob {
         threshold 0.65
         sphere {0,24,1 scale <0.75,0.2,1> translate <-19,43.5,0>}
         sphere {0,24,1 scale <0.95,0.2,0.85> translate <-5,43.5,9>}
         sphere {0,24,1 scale <0.95,0.2,0.85> translate <-5,43.5,-9>}
         cylinder {<-8,0,0>,0,10,0.05 translate <0,43.5,-20>}
         cylinder {<-8,0,0>,0,10,0.05 translate <0,43.5,20>}
         cylinder {<0,0,-5>,<0,0,5>,10,0.05 translate <10,43.5,0>}
         texture {T_Fabric}
        }
        
      //the rear legs
      object {R_Leg rotate y*30 translate <-22.5,0,12>}
      object {R_Leg rotate y*-30 translate <-22.5,0,-12>}
      
      //the Chair's Back
      union {
         object {ChairBack}
         object {ChairBack translate y*8}
         object {ChairBack translate y*16}
         rotate z*13.5
         translate <-8,67.5,0>
         texture {T_MyWood13 scale 5 rotate <1,0,13.5>}
         clipped_by { box {<-35,85,-15.3>,<-22,60,15.3>} }
        }
   
     } //end of main union