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
void sunpos::spRunCalculations(void)
{
	double	tempJC = jdnGetJdnJulianCentury();
	jdnSetJdnJulianCentury(jdnGetJdnJulianCenturyNoon());

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

	jdnSetJdnJulianCentury(tempJC);

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



}
