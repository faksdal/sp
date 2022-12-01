/*
 * spCalcEqOfTime.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"
//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcEqOfTime(void)
{
	spEqOfTime	= 4. * DEGREES(spVarY * sin(2. * RADIANS(spGeomMeanLongSun)) -
		          2. * spEccentEarthOrbit *
		          sin(RADIANS(spGeomMeanAnomSun)) +
		          4. * spEccentEarthOrbit * spVarY *
		          sin(RADIANS(spGeomMeanAnomSun)) *
		          cos(2. * RADIANS(spGeomMeanLongSun)) -
		          0.5 * spVarY * spVarY *
		          sin(4 * RADIANS(spGeomMeanLongSun)) -
		          1.25 * spEccentEarthOrbit * spEccentEarthOrbit *
		          sin(2. * RADIANS(spGeomMeanAnomSun)));


}
