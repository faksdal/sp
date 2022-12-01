/*
 * spCalcLocalSunRise.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcLocalSunRise(void)
{
	spLocalSunRise		= spLocalSolarNoon - spHaSunrise * 4. / 1440.;
	//printf("haSunrise from sp.cpp: %f\n", this->haSunrise);


}
