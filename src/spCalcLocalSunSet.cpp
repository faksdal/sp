/*
 * spCalcLocalSunSet.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcLocalSunSet(void)
{
	spLocalSunSet	= spLocalSolarNoon + spHaSunrise * 4. / 1440.;

}
