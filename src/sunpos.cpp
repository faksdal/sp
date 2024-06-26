/*
 * sunpos.cpp
 *
 *  Created on: 20 Jun 2024
 *      Author: jole
 */

#include <math.h>

#include "sunpos.h"
#include "meananomaly.h"



sunpos::sunpos(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, short _dst, bool _verbose, std::string _planet, double _lat, double _lon)
       : julianday(_year, _month, _day, _hour, _minute, _second, _tz, _dst, _verbose)

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
		M_deg = ma_getM(planet);
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

		mean_longitude_L_deg		= fmod(M_deg + ecliptic_longitude_Π_deg  + 180, 360);
		ecliptical_longitude_λ_deg	= mean_longitude_L_deg + C_deg;

	//*************************************************************************



	//*************************************************************************
	// 6. The Equatorial coordinates

		// Declination δ = sin β cos ε + cos β sin ε sin λ
		// β (beta)
		// ε (epsilon)
		// λ (lamda)

		right_ascension_α_deg	= DEGREES(atan2( sin(RADIANS(ecliptical_longitude_λ_deg)) * cos(RADIANS(obliquity_of_equator_ε_deg)), cos(RADIANS(ecliptical_longitude_λ_deg))));
		declination_δ_deg		= DEGREES(asin( sin(RADIANS(ecliptical_longitude_λ_deg)) *  sin(RADIANS(obliquity_of_equator_ε_deg))));
		                          //DEGREES(asin(sin(RADIANS(aSunObliquityCorrection))     *  sin(RADIANS(aSunApparentLongitude))));

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

	//*************************************************************************



	//*************************************************************************
	// 8. Solar Transit

		double J3 = round(360 / (sr_getTheta1(planet) - ma_getM1(planet)) );
		std::cout << "J3: " << J3 << std::endl;

		double J0 = fmod(((ma_getM0(planet) + ecliptic_longitude_Π_deg + 180 - sr_getTheta0(planet)) * (J3/360)), J3);
		std::cout << "J0: " << J0 << std::endl;

		double J1 = (eoc_getC1(planet) * (J3/360));
		std::cout << "J1: " << J1 << std::endl;

		double J2 = (ec_getA2(planet) * (J3/360));
		std::cout << "J2: " << J2 << std::endl;

		double Jtransit = fmod(jd_j2000 + J0 + (lon * (J3/360.)) + J1 * (sin(RADIANS(M_deg))) + J2 * (sin(RADIANS(2 * ecliptical_longitude_λ_deg))), J3);
		std::cout << "Jtransit: " << Jtransit << std::endl;

		double nx	= ((jd_julianDayNumber - jd_j2000 - J0) / J3) - lon/360;
		double n	= round(nx);
		std::cout << "nx/n: " << nx << "/" << n << std::endl;

		double Jx	= jd_julianDayNumber + J3 * (n - nx);
		std::cout << "Jx: " << Jx << std::endl;

		std::cout << "M_deg: " << M_deg << std::endl;
		ma_init(Jx, jd_getJ2000(), _verbose);
		M_deg = ma_getM(planet);
		std::cout << "M_deg: " << M_deg << std::endl;

		std::cout << "mean_longitude_L_deg: " << mean_longitude_L_deg << std::endl;
		mean_longitude_L_deg = fmod(M_deg + ecliptic_longitude_Π_deg + 180, 360);
		std::cout << "mean_longitude_L_deg: " << mean_longitude_L_deg << std::endl;

		Jtransit = (Jx + J0 + (lon * (J3/360.)) + J1 * (sin(RADIANS(M_deg))) + J2 * (sin(RADIANS(2 * ecliptical_longitude_λ_deg)))) ;
		std::cout << "Jtransit: " << Jtransit << std::endl;

		std::cout << std::endl;

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

