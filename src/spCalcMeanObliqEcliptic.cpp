/*
 * spCalcMeanObliqEcliptic.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */

#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//




void sunpos::spCalcMeanObliqEcliptic(void)
{
	double T = jdnGetJdnJulianCentury();

	spMeanObliqEcliptic	= 23. + (26. + ((21.448 - T * (46.815 + T * (0.00059 - T * 0.001813)))) / 60.) / 60.;
}
