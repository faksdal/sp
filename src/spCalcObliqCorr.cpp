/*
 * spCalcObliqCorr.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcObliqCorr(void)
{
	double T = jdnGetJdnJulianCentury();
	spObliqCorr	= spMeanObliqEcliptic + 0.00256 * cos(RADIANS(125.04 - 1934.136 * T));

}



