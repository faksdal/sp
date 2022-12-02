/*
 * sunpos.cpp
 *
 *  Created on: 29 May 2020
 *      Author: jole
 *
 *	This work is largely based on the work of Jean Meeus and his writing in the
 *	publication Astronomical Algorithms ISBN 0-943396-61-1
 *	It can be found here https://isbnsearch.org/isbn/0943396611
 *
  *	****************************************************************************************************
 *	The class is provided as-is without any warranty of any kind. Feel free to modify to your own needs!
 *	****************************************************************************************************
 */

#include "sunpos.h"



sunpos::sunpos(int _year,
		       short _month,
			   short _day,
			   short _hour,
			   short _minute,
			   short _second,
			   short _tz,
			   double _lat,
			   double _lon,
			   int _dst,
			   bool _verbose) : jdnMeeus1998(_year,
					                         _month,
											 _day,
											 _hour,
											 _minute,
											 _second,
											 _tz,
											 _verbose)
{
	spTz		= _tz;
	spDst		= _dst;
	spVerbose	= _verbose;

	spLat		= _lat;
	spLon		= _lon;

	//
	//	Run all calculations
	//
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
	//******************************************************

	spFLOATWIDTH		= 25;
	spFLOATPRECISION	= 15;

	return;
}



sunpos::~sunpos()
{
	return;
}
