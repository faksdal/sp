/*
 * spCalcLocalSolarNoon.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcLocalSolarNoon(void)
{
	spLocalSolarNoon	= (720. - 4. * spLon - spEqOfTime + spTz * 60.) / 1440.;
}
