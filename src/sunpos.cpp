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

/*
 *
 *




	spMeanObliqEcliptic	= 23. + (26. + ((21.448 - jdnGetJdnJulianCentury() * (46.815 + jdnGetJdnJulianCentury() * (0.00059 - jdnGetJdnJulianCentury() * 0.001813)))) / 60.) / 60.;

	spObliqCorr			= spMeanObliqEcliptic + 0.00256 * cos(RADIANS(125.04 - 1934.136 * jdnGetJdnJulianCentury()));

	spSunRtAscen		= DEGREES(atan2(cos(RADIANS(spObliqCorr)) * sin(RADIANS(spSunAppLong)),
			                                cos(RADIANS(spSunAppLong))));

	spSunDeclin			= DEGREES(asin(sin(RADIANS(spObliqCorr)) *
	                                  sin(RADIANS(spSunAppLong))));
	spVarY				= tan(RADIANS(spObliqCorr/2.)) *
	                          tan(RADIANS(spObliqCorr/2.));

	spEqOfTime			= 4. * DEGREES(spVarY * sin(2. * RADIANS(spGeomMeanLongSun)) -
	                      2. * spEccentEarthOrbit *
	                      sin(RADIANS(spGeomMeanAnomSun)) +
	                      4. * spEccentEarthOrbit * spVarY *
	                      sin(RADIANS(spGeomMeanAnomSun)) *
	                      cos(2. * RADIANS(spGeomMeanLongSun)) -
	                      0.5 * spVarY * spVarY *
	                      sin(4 * RADIANS(spGeomMeanLongSun)) -
	                      1.25 * spEccentEarthOrbit * spEccentEarthOrbit *
	                      sin(2. * RADIANS(spGeomMeanAnomSun)));

	spHaSunrise			= DEGREES(acos(cos(RADIANS(90.833)) /
	                                      (cos(RADIANS(spLat)) *
	                                       cos(RADIANS(spSunDeclin))) -
	                                       tan(RADIANS(spLat)) *
	                                       tan(RADIANS(spSunDeclin))));

	if(isnan(spHaSunrise))
		spHaSunrise = -1.;

	spLocalSolarNoon	= (720. -
	                       4. * spLon -
						   spEqOfTime + spTz * 60.) /
	                       1440.;

	spLocalSunRise		= spLocalSolarNoon - spHaSunrise * 4. / 1440.;
	//printf("haSunrise from sp.cpp: %f\n", this->haSunrise);

	spLocalSunSet		= spLocalSolarNoon + spHaSunrise * 4. / 1440.;

	//std::cout << "geomMeanLongSun (degrees): " << this->getgeomMeanLongSun() << "\n";
	//std::cout << "geomMeanAnomSun (degrees): " << this->getgeomMeanAnomSun() << "\n";

	 */



sunpos::sunpos(int _year, short _month, short _day, short _hour, short _minute, short _second, short _tz, double _lat, double _lon, int _dst, bool _verbose) :
        jdnMeeus1998(_year, _month, _day, _hour, _minute, _second, _tz, _verbose)
{
	spTz		= _tz;
	spDst		= _dst;
	spVerbose	= _verbose;

	/*
	spLat	= _lat;
	spLon	= _lon;
	*/


	spCalcGeomMeanLongSun();
	spCalcGeomMeanAnomSun();
	spCalcEccentEarthOrbit();
	spCalcSunEqOfCtr();
	spCalcSunTrueLong();
	spCalcSunTrueAnom();
	spCalcSunRadVector();
	spCalcSunAppLong();


	spFLOATWIDTH		= 25;
	spFLOATPRECISION	= 15;

	return;
}



sunpos::~sunpos()
{
	return;
}
