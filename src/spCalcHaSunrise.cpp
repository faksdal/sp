/*
 * spCalcHaSunrise.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcHaSunrise(void)
{
	spHaSunrise			= DEGREES(acos(cos(RADIANS(90.833)) /
                                      (cos(RADIANS(spLat)) *
                                       cos(RADIANS(spSunDeclin))) -
                                       tan(RADIANS(spLat)) *
                                       tan(RADIANS(spSunDeclin))));

	if(isnan(spHaSunrise))
		spHaSunrise = -1.;
}
