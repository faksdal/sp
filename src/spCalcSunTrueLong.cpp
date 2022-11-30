/*
 * spCalcSunTrueLong.cpp
 *
 *  Created on: 28 Nov 2022
 *      Author: jole
 */

#include "sunpos.h"



//
//	The Sun's true longitude is equal to the geometric mean longitude of the Sun (L0) + the Sun's equation of center (C).
//
void sunpos::spCalcSunTrueLong(void)
{
	//spSunTrueLong	=	spGetGeomMeanLongSun() + spGetSunEqOfCtr();
	spSunTrueLong		= spGeomMeanLongSun + spSunEqOfCtr;
}



