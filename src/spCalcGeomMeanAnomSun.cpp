/*
 * spCalcGeomMeanAnomSun.cpp
 *
 *  Created on: 26 Nov 2022
 *      Author: jole
 */


#include "sunpos.h"



//
//	TODO - describe what we're calculating here...
//
void sunpos::spCalcGeomMeanAnomSun(void)
{
	double T = jdnGetJdnJulianCentury();
	//spGeomMeanAnomSun	= 357.52911 + T * (35999.05029 - 0.0001537 * T);
	spGeomMeanAnomSun	= fmod((357.52911 + T * (35999.05029 - 0.0001537 * T)), 360.);
	// just some comment
}



