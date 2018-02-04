
#declare gas =  
union{
union{
        sphere {
           <0, 3, 0>, 3     
           
           scale y* 0.4 
           translate y*2.7
        }
        
         cylinder {
           <0, 0, 0>, <0, 4, 0>, 3
        }
         
        
        sphere {
           <0, 3, 0>, 3 
           
           
           scale -1
           scale y* 0.4 
           translate y*1.2    
           
        }
        
        sphere {
           <0, 1, 0>, 3.1 
           
           scale y* 0.1 
           translate y*2    
           
        }  
        
        cylinder {
                   <0, 2, 0>, <0, 4.5, 0>, 2.5
                   
                   translate y*-3  
                   
                }  
                
                }         

difference{
        difference{
                cylinder {
                   <0, 2, 0>, <0, 4.5, 0>, 1.5
                   
                   translate y*6  
                   
                }  
                
                
                cylinder {
                   <0, 2, 0>, <0, 6, 0>, 1.25
                   
                   translate y*5  
                   
                }     
                
                rotate x*90
        }
        
        
        cylinder {
           <0, 2, 0>, <0, 6, 0>, 1    
           
           translate y*4.5 
           scale x*0.4 
           translate <-1.5,2,0>  
           
           rotate x*90
           
        }  
        
        
        cylinder {
           <0, 2, 0>, <0, 6, 0>, 1
           
           translate y*4.5 
           scale x*0.4 
           translate <1.5,2,0>
           rotate x*90
           
        }  
          
          

      
        
      
     

  cylinder {
           <0, 2, 0>, <0, 6, 0>, 1
           
           translate y*4.5 
           scale x*0.3 
           translate <1.5,2,1.5>  
           rotate x*90 
           rotate z*90 
           
           translate <-1.5,-0.2,0.5>
           
        }    
        
        
          cylinder {
           <0, 2, 0>, <0, 6, 0>, 1
           
           translate y*4.5 
           scale x*0.3 
           translate <1.5,2,1.5>  
           rotate x*90 
           rotate z*90 
           
           translate <-1.5,-2.5,0.5>
           
        } 
           
           rotate x*90 
           rotate y*110 
           translate y*14.3
        
         }    
           
           
         
         } 
         
         