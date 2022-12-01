/*
 * spCalcSunDeclin.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcSunDeclin(void)
{
	spSunDeclin	= DEGREES(asin(sin(RADIANS(spObliqCorr)) *
	                      sin(RADIANS(spSunAppLong))));

}
