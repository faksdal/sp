/*
 * spCalcVarY.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
void sunpos::spCalcVarY(void)
{
	spVarY	= tan(RADIANS(spObliqCorr/2.)) *
	              tan(RADIANS(spObliqCorr/2.));


}
