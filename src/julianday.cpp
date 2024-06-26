/*
 * julianday.cpp
 *
 *  Created on: May 30, 2024
 *      Author: leijon
 */


#include <cmath>
#include <math.h>

#include "julianday.h"



julianday::julianday(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, short _dst, bool _verbose)
          : timestamp(_year, _month, _day, _hour, _minute, _second, _tz, _dst, _verbose)
{
	jd_tz		= _tz;
	jd_dst		= _dst;
	jd_verbose	= _verbose;


	//
	//	This is a fixed value used to calculate Julian century.
	//	See Meeus, Jean Astronomical Algorithms second edition p.163 (25.1)
	//
	jd_j2000	= 2451545.0;

	// Format specifiers for output
	jd_FLOATWIDTH		= 25;
	jd_FLOATPRECISION	= 11;

	//jd_calculateJulianDay();

	//jd_printToScreen();

	return;
}
