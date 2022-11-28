/*
 * spCalcGeomMeanLongSun.cpp
 *
 *  Created on: 25 Nov 2022
 *      Author: jole
 *
 *      Calculating the geometric mean longitude of the Sun to low accuracy as described in
 *      Jean Meeus' Astronomical Algorithms second edition 1998 p.163(25.2)
 *
 *      The ecliptic and celestial equators intersects at two point; the vernal and autumnal equinoxes.
 *      We measure the Suns longitude from the vernal equinox in degrees eastward.
 *
 */

#include "sunpos.h"



void sunpos::spCalcGeomMeanLongSun(void)
{
	//spGeomMeanLongSun = 280.46646 + jdnGetJdnJulianCentury() * (36000.76983  + 0.0003032 * jdnGetJdnJulianCentury());
	spGeomMeanLongSun	= fmod(280.46646 + jdnGetJdnJulianCentury() * (36000.76983 + jdnGetJdnJulianCentury() * 0.0003032), 360.);
}
