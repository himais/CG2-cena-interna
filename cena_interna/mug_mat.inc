#include "colors.inc"
#include "textures.inc"

#declare mug_mat = union
{
        cylinder
        {
                <0,0.05,0>, <0,0.3,0>, 5
        }
        torus
        {
                4.8, 0.2
                translate <0, 0.3, 0>
        }
        cone
	{
		<0, 0, 0>, 4.95
		<0, 0.05, 0>, 5
	}
        texture
	{
		//Cork
	}
        normal
	{
		crackle 0.25
		scale 0.25
	}
}
