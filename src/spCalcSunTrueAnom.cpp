/*
 * spCalcSunTrueAnom.cpp
 *
 *  Created on: 28 Nov 2022
 *      Author: jole
 */

#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcSunTrueAnom(void)
{
	spSunTrueAnom		= fmod((spGeomMeanAnomSun + spSunEqOfCtr), 360);
	//spSunTrueAnom		= (spGeomMeanAnomSun + spSunEqOfCtr);
}



