//a very low detailed microwave
//it might be useful as a backdrop object
//luisvaloyes, Bogota, Colombia
//www.luisvaloyes.uni.cc

//scale : 1 POV unit = 10 cm
//dimensions: 50 cm x 27 cm x 25 cm

#include "Textures.inc"


#declare microwave = union {
cone { <0,0,0>,  0.05, <0,0.2,0>, 0.1 translate <2.3,0,1.05> texture{ BrushedNickelTexture }}
cone { <0,0,0>,  0.05, <0,0.2,0>, 0.1 translate <-2.3,0,1.05> texture{ BrushedNickelTexture }}
cone { <0,0,0>,  0.05, <0,0.2,0>, 0.1 translate <2.3,0,-1.05> texture{ BrushedNickelTexture }}
cone { <0,0,0>,  0.05, <0,0.2,0>, 0.1 translate <-2.3,0,-1.05> texture{ BrushedNickelTexture }}
sphere { <0,0,0>,1.0 scale 0.1 translate <2.4,0.3,1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <2.4,0.3,-1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <-2.4,0.3,1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <-2.4,0.3,-1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <2.4,2.6,1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <2.4,2.6,-1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <-2.4,2.6,1.15> }
sphere { <0,0,0>,1.0 scale 0.1 translate <-2.4,2.6,-1.15> }
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,4.8,0.1> rotate <0,0,90> translate <0,0.3,1.15>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,4.8,0.1> rotate <0,0,90> translate <0,0.3,-1.15>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,4.8,0.1> rotate <0,0,90> translate <0,2.6,1.15>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,4.8,0.1> rotate <0,0,90> translate <0,2.6,-1.15>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,2.3,0.1> rotate <90,0,0> translate <2.4,0.3,0>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,2.3,0.1> rotate <90,0,0> translate <-2.4,0.3,0>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,2.3,0.1> rotate <90,0,0> translate <2.4,2.6,0>}
cylinder {<0,-0.5,0>,<0,0.5,0>,1 scale <0.1,2.3,0.1> rotate <90,0,0> translate <-2.4,2.6,0>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,2.3,0.1> translate <2.4,0.3,1.15>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,2.3,0.1> translate <2.4,0.3,-1.15>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,2.3,0.1> translate <-2.4,0.3,-1.15>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,2.3,0.1> translate <-2.4,0.3,1.15>}
box {<-0.5,-0.5,-0.5><0.5,0.5,0.5> scale <4.8,0.2,2.3> translate <0,0.3,0>}
box {<-0.5,-0.5,-0.5><0.5,0.5,0.5> scale <4.8,0.2,2.3> translate <0,2.6,0>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <4.8,2.3,0.2> translate <0,0.3,-1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.2,2.3,2.3> translate <2.4,0.3,0>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.2,2.3,2.3> translate <-2.4,0.3,0>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.2,2.3,0.2> translate <-2.3,0.3,1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.1,2.3,0.2> translate <-1.55,0.3,1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.6,0.2,0.2> translate <-1.9,2.4,1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.6,0.1,0.2> translate <-1.9,1.8,1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.6,0.2,0.2> translate <-1.9,0.3,1.15>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.1,2.3,0.2> translate <-1.45,0.3,1.1>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.2,2.3,0.2> translate <-1.3,0.3,1.175>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.2,2.3,0.2> translate <2.3,0.3,1.175>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <3.8,0.2,0.2> translate <0.5,2.4,1.175>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <3.8,0.2,0.2> translate <0.5,0.3,1.175>}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <3.8,2.2,0.02> translate <0.5,0.4,1.165> 
texture{ GlossyBlackTexture}}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.6,0.5,0.1> translate <-1.9,1.9,1.14>
texture{ GlossyBlackTexture}}
box {<-0.5,0,-0.5><0.5,1,0.5> scale <0.6,1.3,0.1> translate <-1.9,0.5,1.14>
pigment {Black} }
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,0.35,0.075> rotate <90,0,0> translate <-1.05,2.5,1.15>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,0.35,0.075> rotate <90,0,0> translate <-1.05,0.4,1.15>}
sphere { <0,0,0>,1.0 scale <0.1,0.075,0.075> translate <-1.05,2.5,1.5>}
sphere { <0,0,0>,1.0 scale <0.1,0.075,0.075> translate <-1.05,0.4,1.5>}
cylinder {<0,0,0>,<0,1,0>,1 scale <0.1,2.1,0.075> translate <-1.05,0.4,1.5>}
texture{ BrushedNickelTexture } }
