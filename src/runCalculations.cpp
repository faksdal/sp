/*
 * runCalculations.cpp
 *
 *  Created on: 3 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
//	Run all calculations
//
void sunpos::runCalculations(void)
{
		spCalcGeomMeanLongSun();
		spCalcGeomMeanAnomSun();
		spCalcEccentEarthOrbit();
		spCalcSunEqOfCtr();
		spCalcSunTrueLong();
		spCalcSunTrueAnom();
		spCalcSunRadVector();
		spCalcSunAppLong();
		spCalcMeanObliqEcliptic();
		spCalcObliqCorr();
		spCalcSunRtAscen();
		spCalcSunDeclin();
		spCalcVarY();
		spCalcEqOfTime();
		spCalcHaSunrise();
		spCalcLocalSolarNoon();
		spCalcLocalSunRise();
		spCalcLocalSunSet();
}
