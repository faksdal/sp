/*
 * spCalcHaSunrise.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
//	TODO -	Replace the algorithms to calculate sunrise and sunset correctly.
//	TODO	To do that, I need to calculate these values based on the Julian Day Number at noon
//	TODO	I have made a specific data member to hold that value in particular, but need to read up on my astronomy...
//
void sunpos::spCalcHaSunrise(void)
{
	spHaSunrise	= DEGREES(acos(cos(RADIANS(90.833)) / (cos(RADIANS(spLat)) * cos(RADIANS(spSunDeclin))) - tan(RADIANS(spLat)) * tan(RADIANS(spSunDeclin))));

	if(isnan(spHaSunrise))
		spHaSunrise = -1.;
}
