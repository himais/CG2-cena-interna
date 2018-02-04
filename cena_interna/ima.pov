

    #include "colors.inc"

    #include "shapes.inc"

    #include "textures.inc"

    #include "Woods.inc"

    #include "stones.inc"

    #include "glass.inc"

    #include "metals.inc"


  
#declare ima = 
  difference {
    box {
      <-3.5, -1, 0.1>, <3, 0.5, 0.2>
      pigment { Black }
    }
    text {
      ttf "crystal.ttf" "{ifsp-tads}" 0.15, 0
      texture {T_Stone40}  //texture {pigment { Red_Marble} }
      finish { reflection .25 specular 1 }
      translate -3*x 
      translate -0.55*y
    }
    
  }   
   
   #declare ima2 = 
    text {
      ttf "crystal.ttf" "M" 0.4, 0
      pigment { Black }
      finish { reflection .25 specular 1 }
      translate -3*x 
      translate -0.55*y
    }


     
   



  