/*
 * spCalcSunRtAscen.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcSunRtAscen(void)
{
	spSunRtAscen	= DEGREES(atan2(cos(RADIANS(spObliqCorr)) * sin(RADIANS(spSunAppLong)),
				              cos(RADIANS(spSunAppLong))));

}
