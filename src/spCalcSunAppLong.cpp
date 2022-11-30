/*
 * spCalcSunAppLong.cpp
 *
 *  Created on: 30 Nov 2022
 *      Author: jole
 */

#include "sunpos.h"



//
//	Apparent longitude is the mean longitude corrected for aberration and nutition.
//	For low accuracy this can be done as described on p.164
//
//
void sunpos::spCalcSunAppLong(void)
{
	double T = jdnGetJdnJulianCentury();

	spSunAppLong	= spSunTrueLong - 0.00569 - (0.00478 * sin(RADIANS(125.04 - 1934.136 * T)));
}
