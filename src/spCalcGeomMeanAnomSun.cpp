/*
 * spCalcGeomMeanAnomSun.cpp
 *
 *  Created on: 26 Nov 2022
 *      Author: jole
 */


#include "sunpos.h"



void sunpos::spCalcGeomMeanAnomSun(void)
{
	spGeomMeanAnomSun	= 357.52911 + jdnGetJdnJulianCentury() * (35999.05029 - 0.0001537 * jdnGetJdnJulianCentury());
	//spGeomMeanAnomSun	= fmod((357.52911 + jdnGetJdnJulianCentury() * (35999.05029 - 0.0001537 * jdnGetJdnJulianCentury())), 360.);
}



