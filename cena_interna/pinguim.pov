#declare pinguim = 
union {
        //Tronco
        #declare corpo = 
        union{ 
                sor{
                        7
                        < 0.00, 0.00>  
                        < 0.16, 0.05>,
                        < 0.22, 0.20>,
                        < 0.18, 0.35>,
                        < 0.17, 0.48>,
                        < 0.12, 0.56>,
                        < 0.12, 0.56> 
                        pigment{Black}
                        scale 3.5
                } 
        sphere {
                <0, 1, 0>, 0.6
                pigment{Black}
                translate y*0.53
                }
                   
               scale y*0.95 
        } 
               
        
        #declare corpobranco=       
        union{ 
                sor{
                        7
                        < 0.00, 0.00>  
                        < 0.16, 0.05>,
                        < 0.22, 0.20>,
                        < 0.18, 0.35>,
                        < 0.17, 0.48>,
                        < 0.12, 0.56>,
                        < 0.12, 0.56> 
                        pigment{White}
                        scale 3.5
                }     
                                  
                
                
                
                sphere {
                        <0, 1, 0>, 0.6
                        pigment{White}
                        translate y*0.53
                 }
                 
                scale y*0.95   finish { specular 0.7 roughness 0.03 }  }
        
        //Parte superior do corpo
        #declare sup = 
        union{
           object {corpo}
            
           object {corpobranco scale 0.7 pigment{White} translate <0,0.35,-0.4>}  
           
         
        
        #declare cabeca = 
        union{   
                sphere {
                          <0, 1, 0>, 0.6
                          pigment{Black}
                          translate y*1.65
                }
                
                sphere {
                           <0, 1, 0>, 0.075
                           pigment{White}            
                           translate <0.15, 1.70, -0.545> 
                }   
         
                sphere {
                           <0, 1, 0>, 0.06
                           pigment{Black}            
                           translate <0.15, 1.70, -0.57> 
                }
                 
                sphere {
                           <0, 1, 0>, 0.03
                           pigment{White}            
                           translate <0.15, 1.71, -0.64> 
                }
                
                sphere {
                           <0, 1, 0>, 0.075
                           pigment{White}            
                           translate <-0.156, 1.70, -0.545> 
                }    
                 
                 
                sphere {
                           <0, 1, 0>, 0.06
                           pigment{Black}            
                           translate <-0.156, 1.70, -0.57> 
                }
                 
                sphere {
                          <0, 1, 0>, 0.03
                          pigment{White}            
                          translate <-0.156, 1.71, -0.64> 
                }    
                 
                cone {
                        <0, 1, 0>, 0.05    // Center and radius of one end
                        <0, 2, 3>, 1.0    // Center and radius of other end
                        pigment { Orange }
                        scale 0.1   
                        scale y* 0.6 
                        translate <-0.01, 2.45, -0.45>
                        rotate x*-10 
                } 
                
                finish { specular 0.7 roughness 0.03 }
                 
        }
            
                object {cabeca translate y*-0.4}      
            
            
            sphere {
                   <0, 1, 0>, 0.6
                   pigment{Black}  
                   scale x*0.2 
                   rotate z*-40
                   translate <-1.4, 0.55, 0.2>
                } 
                
            sphere {
                   <0, 1, 0>, 0.6
                   pigment{Black}  
                   scale x*0.2 
                   rotate z*40
                   translate <1.4, 0.55, 0.2>
             }  
                
             translate y*0.2
             finish { specular 0.7 roughness 0.03 }
                
        }    
        
        //Parte inferior do corpo
        #declare inf =
        union{         
                cone {
                    <0, 1, 0>, 0.5    // Center and radius of one end
                    <0, 2, 3>, 1.0    // Center and radius of other end
                    pigment { Black }
                    scale 0.2  
                    rotate x*270    
                    scale y*0.5
                    scale x* 1.3
                    translate <-0.25,0.1, 0.15>
                    //rotate x*-14 
                  } 
                  
                cone {
                    <0, 1, 0>, 0.5    // Center and radius of one end
                    <0, 2, 3>, 1.0    // Center and radius of other end
                    pigment { Black }
                    scale 0.2  
                    rotate x*270    
                    scale y*0.5
                    scale x* 1.3
                    translate <0.25,0.1, 0.1>
                    //rotate x*-14 
                  } 
                  
                  
          
             sphere {
                   <0, 1, 0>, 0.2
                   pigment{Orange}
                   translate y*-1
                   scale y*0.4
                   translate<-0.3,0.01,-0.1>
         }    
         
              sphere {
                   <0, 1, 0>, 0.2
                   pigment{Orange}
                   translate y*-1
                   scale y*0.4
                   translate<0.27,0.01,-0.1>
                }              
          
        }  
          
        //Cachecol    
        #declare cachecol = 
        union{    
                 sphere {
                           <0, 1, 0>, 0.6
                           pigment{MediumTurquoise} 
                           translate y*3.2  
                           translate z*-0.095
                           scale y* 0.47
                 }   
         
                  sphere {
                           <0, 1, 0>, 0.6
                           pigment{MediumTurquoise} 
                           scale y* 0.3 
                           scale z* 0.3   
                           rotate z*55 
                           
                           translate y*1.5  
                           translate z*-0.6
                 } 
         
         }
           
        //Gorro
        #declare gorro =  
        union{
                difference{ 
                          sphere {
                                   <0, 1, 0>, 0.6
                                   pigment{MediumTurquoise} 
                                   translate y*-0.4
                                }    
                 
                           box {
                            <-1, 0,   -1>,  // Near lower left corner
                            < 1, 0.5,  3>   // Far upper right corner  
                          }
                  
                }
                   
               
               sphere {
                        <0, 1, 0>, 0.15 
                        pigment{White}
                        translate y*0.3        
               }  
                        
                cylinder {
                        <0, 1, 0>,     // Center of one end
                        <0, 1.25, 0>,     // Center of other end
                        0.62            // Radius
                        open 
                        translate y*-0.5          // Remove end caps
                        pigment{White}
                }
           
           }  
             
               
        
        object{sup}
          
        object{inf} 
        
        object {cachecol}  
        
        object{gorro translate <0,2.06, -0.33> rotate x*8} 
        
       

}

