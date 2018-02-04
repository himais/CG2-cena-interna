// PoVRay 3.6/3.7 Include File "Table_s00.inc"
// author: Friedrich A. Lohmueller, Dec-2005, May-2014
// homepage: http://www.f-lohmueller.de  
// email: Friedrich.Lohmueller_AT_t-online.de

#ifndef( Table_s00_Inc_Temp)
#declare Table_s00_Inc_Temp = version;
#version 3.6;

#ifndef(  Shapes_Inc_Temp)
#include "shapes.inc"                                             
#end

//--------------------------------------------------------------------
#macro Table_s00 ( Table__Height, 
                   Table__Half_Width_X, 
                   Table__Half_Width_Z, 
                   Table__Feet_Radius, 
                 ) //-------------------------------------------------

#local CR = Table__Feet_Radius; 
#local CX = Table__Half_Width_X - CR; 
#local CZ = Table__Half_Width_Z - CR; 
#local SH = Table__Height - CR; 

#local SX = Table__Half_Width_X ; 
#local SZ = Table__Half_Width_Z ; 
#local ST = 2*CR ; 

union{ // total union
union{
// seat
box { <-CX, 0.00, -CZ>,< CX, 0, CZ>  translate<0,SH,0> }  
// feet
cylinder { <0,0,0>,<0,SH,0>, CR translate< CX,0,-CZ> } 
cylinder { <0,0,0>,<0,SH,0>, CR translate<-CX,0,-CZ> }
cylinder { <0,0,0>,<0,SH,0>, CR translate< CX,0, CZ> }
cylinder { <0,0,0>,<0,SH,0>, CR translate<-CX,0, CZ> }
// frontside horizontal seat level
cylinder { <-CX,0,  0>,< CX,0, 0>, CR  translate<0,SH, CZ> }
cylinder { <-CX,0,  0>,< CX,0, 0>, CR  translate<0,SH,-CZ> }
cylinder { <  0,0,-CZ>,<  0,0,CZ>, CR  translate< CX,SH,0> }
cylinder { <  0,0,-CZ>,<  0,0,CZ>, CR  translate<-CX,SH,0> }
// frontside horizontal seat level
sphere{ < CX,SH,-CZ>, CR  } 
sphere{ <-CX,SH,-CZ>, CR  } 
// backside horizontal seat level
sphere{ < CX,SH, CZ>, CR } 
sphere{ <-CX,SH, CZ>, CR } 

}// end of union

// seat
object { // Round_Box(A, B, WireRadius, UseMerge)
         Round_Box(<-SX,0,-SZ>,<SX,2*CR,CZ>, CR , 0)  
         scale<1,1,1>  rotate<0, 0,0> translate<0,SH,0>
       } // ---------------------------------------------------------




}// end of total union
#end  
//------------------------------------- end of #macro Chair_s10 (...) 


#version Table_s00_Inc_Temp;
#end
//------------------------------------- end of include file

// PoVRay 3.7 Scene File "Chair_s10demo.pov"
// author: Friedrich A. Lohmueller, May-2006/Aug-2009/Jan-2011
// email: Friedrich.Lohmueller_at_t-online.de
// homepage: http://www.f-lohmueller.de
//--------------------------------------------------------------------------
#version 3.6; // 3.7;
global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }} 
//--------------------------------------------------------------------------
#include "colors.inc"
#include "textures.inc"
#include "glass.inc"
#include "metals.inc"
#include "golds.inc"
#include "stones.inc"
#include "woods.inc"
#include "shapes.inc"
#include "shapes2.inc"
#include "functions.inc"
#include "math.inc"
#include "transforms.inc"
// camera ------------------------------------------------------------------
#declare Camera_0 = camera {/*ultra_wide_angle*/ angle 65          // front view
                            location  <0.0 , 1.5 ,-3.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.3 , 0.0>}
#declare Camera_1 = camera {/*ultra_wide_angle*/ angle 22       // diagonal view
                            location <-2.00, 2.00,-3.00>
                            right     x*image_width/image_height
                            look_at   < 0.00, 0.90, -1.00>}
#declare Camera_2 = camera {/*ultra_wide_angle*/ angle 90     // right side view
                            location  <2.90 , 1.0 , 0.0>
                            right     x*image_width/image_height
                            look_at   <0.0 , 1.0 , 0.0>}
#declare Camera_3 = camera { ultra_wide_angle  angle 210            // top view
                            location  <0.50 , 2.40 , 0.500>
                            right     x*image_width/image_height
                            look_at   <0.50 , 1.0  , 0.501>}
camera{Camera_2}

// sun -------------------------------------------------------------------------
light_source{<1500,2500, 2500> color White*0.7}

// sky ---------------------------------------------------------------

plane {
  y, 0   
  pigment { 
        checker Black White 
        }
}


//--------------------------------------------------------------------------
//---------------------------- objects in scene ----------------------------
//--------------------------------------------------------------------------



//----------------------------------------------------------------------------
//----------------------------------------------------------------- textures
#declare Table_Texture = 
       texture{ pigment{ color rgb< 0.75, 0.6, 0.45>*0.55 }  
                finish { phong 1 } 
              } // end of texture  

//----------------------------------------------------------------------------
//#include "Table_s00.inc"

#declare mesa = 
union{
             

object{ Table_s00 ( 0.60, // Table__Height, 
                    0.40, // Table__Half_Width_X, 
                    0.60, // Table__Half_Width_Z, 
                    0.02  // Table__Feet_Radius, 
                  ) //------------------------------------------
        //texture {Table_Texture}
        scale <1,1,1> rotate<0,0,0> translate< 0.00,0.00,0.00> 
        scale <1,1,1> rotate<0,90,0> translate< 1.000,0.00,0.00>
        scale x* 0.6}
        
        
}  




//----------------------------------------------------------------------------
//----------------------------------------------------------------------------