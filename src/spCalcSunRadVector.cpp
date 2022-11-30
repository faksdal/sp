/*
 * spCalcSunRadVector.cpp
 *
 *  Created on: 30 Nov 2022
 *      Author: jole
 */

#include "sunpos.h"



//
//	The Sun's radius vector is the distance between the centers of the Sun and the Earth, expressed
//	in astronomical unit (AU).
//
//	The astronomical unit was originally conceived as the average of Earth's aphelion and perihelion;
//	however, since 2012 it has been defined as exactly 149'597'870'700 m.
//	See: https://en.wikipedia.org/wiki/Astronomical_unit
//
void sunpos::spCalcSunRadVector(void)
{
	spSunRadVector		= (1.000001018 * (1. - spEccentEarthOrbit * spEccentEarthOrbit)) /
						  (1. + spEccentEarthOrbit * cos(RADIANS(spSunTrueAnom)));
}



