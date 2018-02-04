//  Material Include file.
//
//  This file was generated for POV-Ray V3.5 by
//  NOTE: Do *NOT* remove the comment lines containing '$MRY$'.
//        To make Moray not re-export the material, change
//        the '$MRY$' to '$MRX$'.
//


//
// ********  MATERIALS  *******
//



//  $MRY$: 'Bowl Material'


#declare Bowl_Material = 
   material  // Bowl Material
   {   
      texture
      {      
         pigment
         {
            spiral1 1
            color_map
            {
               [ 0.0     rgbft <0.501961, 0.501961, 1.0, 0.0, 0.0> ]
               [ 0.33452  rgbft <1.0, 1.0, 1.0, 0.0, 0.0> ]
               [ 0.558719  rgbft <0.501961, 0.501961, 1.0, 0.0, 0.0> ]
               [ 0.846975  rgbft <1.0, 1.0, 1.0, 0.0, 0.0> ]
               [ 1.0     rgbft <1.0, 1.0, 1.0, 0.0, 0.0> ]
            }
         }      
         finish
         {
            ambient 0.1
            phong 0.7122
            phong_size 57.613333
            specular 0.503567
            roughness 0.1203
            reflection
            {
               0.03 , 0.03
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Bowl Outside'


#declare Bowl_Outside = 
   material  // Bowl Outside
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 1.0>
         }      
         finish
         {
            ambient 0.1
            phong 0.769767
            specular 0.4892
            reflection
            {
               0.05 , 0.05
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'BowlRim'


#declare BowlRim = 
   material  // BowlRim
   {   
      texture
      {      
         pigment
         {
            color rgb <0.0, 0.25098, 0.501961>
         }      
         finish
         {
            ambient 0.1
            phong 0.7122
            specular 0.517967
            reflection
            {
               0.0935 , 0.0935
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Frosty Material'


#declare Frosty_Material = 
   material  // Frosty Material
   {   
      texture
      {      
         pigment
         {
            spotted
            color_map
            {
               [ 0.0     rgbft <0.958333, 0.791667, 0.517823, 0.0, 0.0> ]
               [ 0.871886  rgbft <0.958333, 0.791667, 0.517823, 0.0, 0.0> ]
               [ 1.0     rgbft <1.0, 1.0, 1.0, 0.0, 0.0> ]
            }
            scale  <1.0, 1.0, 0.1>
         }      
         normal
         {
            agate , 5.0
            agate_turb 1.0

            /* no entries with a valid normal defined.
            normal_map
            {
               /* no normal type given.
               [0.0   

               ]
               */
               /* no normal type given.
               [1.0   

               ]
               */
            }
            */
            scale  <2.0, 2.0, 1.0>
         }      
         finish
         {
            ambient 0.410067
            phong 0.8417
            specular 0.705033
         }
      }
   }


//  $MRY$: 'Milk'


#declare Milk = 
   material  // Milk
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 1.0, 0.8958>
         }      
         normal
         {
            ripples , 0.15
         }      
         finish
         {
            ambient 0.525167
            phong 0.640267
            reflection
            {
               0.05 , 0.05
               fresnel  off
               falloff  1.0
               exponent 1.0
               metallic 0.0
            }
         }
      }
   }


//  $MRY$: 'Floor'


#declare Floor = 
   material  // Floor
   {   
      texture
      {      
         pigment
         {
            color rgb <1.0, 0.501961, 0.25098>
         }
      }
   }
