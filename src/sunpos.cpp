/*
 * sunpos.cpp
 *
 *  Created on: 20 Jun 2024
 *      Author: jole
 */

#include <math.h>

#include "sunpos.h"
#include "meananomaly.h"

sunpos::sunpos(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose, std::string _planet, double _lat, double _lon)
       : julianday(_year, _month, _day, _hour, _minute, _second, _tz,_verbose)

{
	planet	= _planet;
	lon		= _lon;
	lat		= _lat;

	//*************************************************************************
	// 1. Time; Calculate jd
		jd_calculateJulianDay();
	//*************************************************************************



	//*************************************************************************
	// 2. The Mean anomaly; Calculate and retreive the mean anomaly M
		ma_init(jd_getJulianDayNumber(), jd_getJ2000(), _verbose);
		M_deg = ma_getM(_planet);
	//*************************************************************************



	//*************************************************************************
	// 3. The equation of center

		eoc_init(M_deg, _verbose);
		C_deg = eoc_getC(planet);

	//*************************************************************************



	//*************************************************************************
	// 4. The Perihelion and the Obliquity of the Ecliptic

		ecliptic_longitude_Π_deg	= el_getPI(planet);
		obliquity_of_equator_ε_deg	= ooe_getEpsilon(planet);

	//*************************************************************************



	//*************************************************************************
	// 5. The Ecliptical Coordinates

		mean_longitude_L_deg		= M_deg + ecliptic_longitude_Π_deg  + 180;
		ecliptical_longitude_λ_deg	= mean_longitude_L_deg + C_deg;

	//*************************************************************************



	//*************************************************************************
	// 6. The Equatorial coordinates

		right_ascension_α_deg	= DEGREES(atan2( sin(RADIANS(ecliptical_longitude_λ_deg)) * cos(RADIANS(obliquity_of_equator_ε_deg)), cos(RADIANS(ecliptical_longitude_λ_deg))));
		declination_δ_deg		= DEGREES(asin( sin(RADIANS(ecliptical_longitude_λ_deg)) *  sin(RADIANS(obliquity_of_equator_ε_deg))));

	//*************************************************************************



	//*************************************************************************
	// 7. The Observer

		sr_init(jd_getJulianDayNumber(), jd_getJ2000(), _verbose, lon);
		siderealtime_Θ_deg = sr_getTheta(planet);

		altitude_h_deg		= 0.;
		azimuth_A_deg		= 0.;
		hour_angle_H_deg	= 0.;

		hour_angle_H_deg	= siderealtime_Θ_deg - right_ascension_α_deg;
		azimuth_A_deg		= DEGREES( atan2( sin(RADIANS(hour_angle_H_deg)), cos(RADIANS(hour_angle_H_deg)) * sin(RADIANS(lat)) - tan(RADIANS(declination_δ_deg)) * cos(RADIANS(lat)) ));
		altitude_h_deg		= DEGREES( asin( sin(RADIANS(lat)) * sin(RADIANS(declination_δ_deg)) + cos(RADIANS(lat)) * cos(RADIANS(declination_δ_deg)) * cos(RADIANS(hour_angle_H_deg))));

		//altitude_h_deg = asin( sin(RADIANS(φ)) * sin(δ) + cos(RADIANS(φ)) * cos(δ) * cos(RADIANS(H)) );

		//double		altitude_h_deg;
		//double		azimuth_A_deg;
		//double		hour_angle_H_deg;

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

