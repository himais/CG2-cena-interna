// ===========================================================================
//
// plant_pot.inc
//
// (C) Ian Shumsky / OuterArm 1999
//
// ===========================================================================
//
// Include file to define a full and empty plant pot. Scale is cm.
//
// ===========================================================================

#include "colors.inc"

#declare empty_plant_pot = union
{
	cone
	{
		<0, 0, 0>, 6.5
		<0, 17, 0>, 11
		open
	}
	cone
	{
		<0, 0, 0>, 7.5
		<0, 17, 0>, 12
		open
	}
	difference
	{
		cylinder
		{
			<0, 0, 0>, <0, 1, 0>, 7.5
		}
		cylinder
		{
			<0, -1,0>, <0, 2, 0>, 1.25
		}
	}
	difference
	{
		cylinder
		{
			<0, 17, 0>, <0, 22, 0>, 13
		}
		cylinder
		{
			<0, 16, 0>, <0, 23, 0>, 12
		}
	}
	texture
	{
		pigment
		{
			colour OrangeRed
		}
		finish
		{
			specular 0.5
			roughness 0.15
		}
	}
}

#declare plant_pot_soil = height_field
{
	gif "plant_pot_soil.gif"
	water_level 0.01
	translate <-0.5, 0, -0.5>
	scale <24, 2, 24>
	translate <0, 19, 0>
	texture
	{
		pigment
		{
			colour Brown
		}
	}
}

#declare full_plant_pot = union
{
	object
	{
		empty_plant_pot
	}
	object
	{
		plant_pot_soil
	}
}
