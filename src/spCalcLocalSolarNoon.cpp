/*
 * spCalcLocalSolarNoon.cpp
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
void sunpos::spCalcLocalSolarNoon(void)
{
	spLocalSolarNoon	= (720. - 4. * spLon - spEqOfTime + spTz * 60.) / 1440.;
}
