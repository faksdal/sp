/*
 * spCalcEccentEarthOrbit.cpp
 *
 *  Created on: 27 Nov 2022
 *      Author: jole
 *
 *      Calculating the eccentricity of the Earth's orbit to low accuracy as described in
 *      Jean Meeus' Astronomical Algorithms second edition 1998 p.163(25.4)
 *
 *      See: https://en.wikipedia.org/wiki/Orbital_eccentricity
 */


#include "sunpos.h"



void sunpos::spCalcEccentEarthOrbit(void)
{
	spEccentEarthOrbit	= 0.016708634 - (jdnGetJdnJulianCentury() * 0.000042037) - (0.0000001267 * jdnGetJdnJulianCentury() * jdnGetJdnJulianCentury());
}
