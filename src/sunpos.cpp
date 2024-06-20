/*
 * sunpos.cpp
 *
 *  Created on: 20 Jun 2024
 *      Author: jole
 */

#include "sunpos.h"
#include "meananomaly.h"

sunpos::sunpos(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose, std::string _planet)
       : julianday(_year, _month, _day, _hour, _minute, _second, _tz,_verbose)

{
	planet = _planet;

	//*************************************************************************
	// 1. Time; Calculate jd
		jd_calculateJulianDay();
	//*************************************************************************



	//*************************************************************************
	// 2. The Mean anomaly; Calculate and retreive the mean anomaly M
		ma_init(jd_getJulianDayNumber(), jd_getJ2000(), _verbose);
		M = ma_getM(_planet);
	//*************************************************************************



	//*************************************************************************
	// 3. The equation of center
		eoc_init(M, _verbose);
		C = eoc_getC(planet);
	//*************************************************************************



	//*************************************************************************
	// 4. The Perihelion and the Obliquity of the Ecliptic
	//*************************************************************************



	//*************************************************************************
	// 5. The Ecliptical Coordinates
	//*************************************************************************



	//*************************************************************************
	// 6. The Equatorial coordinates
	//*************************************************************************



	//*************************************************************************
	// 7. The Observer
	//*************************************************************************



	//*************************************************************************
	// 8. Solar Transit
	//*************************************************************************



	//*************************************************************************
	// 9. Equation of Time
	//*************************************************************************



	//*************************************************************************
	// 10. Sunrise and Sunset
	//*************************************************************************


	return;
}



sunpos::~sunpos()
{
	return;
}
