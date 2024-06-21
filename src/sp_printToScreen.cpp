/*
 * jd_printToScreen.cpp
 *
 *  Created on: 2 Jun 2024
 *      Author: jole
 */

//
// TODO
//

#include <iomanip>
#include <iostream>


#include "sunpos.h"



void sunpos::sp_printToScreen(void)
{

	std::cout << std::fixed;

	std::cout	<< jd_getDOW() << ", " << ts_getMonthName() << " " << (short)ts_getDay() << jd_getDaySuffix() << " " << ts_getYear() << " "
				//<< " " << std::setw(2) << ts_getHour() << ":" << std::setw(2) << ts_getMinute() << ":" << std::setw(5) << std::setprecision(3) << ts_getSecond() << std::endl;
				<< std::setw(2) << std::setfill('0') << ts_getHour() << ":"
				<< std::setw(2) << std::setfill('0') << ts_getMinute() << ":"
				<< std::setw(2) << std::setprecision(7) << std::setfill('0') << ts_getSecond() << std::endl << std::endl;

	std::cout << "      Julian Day Number(UTC, whole): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDayNumber << std::endl;
	std::cout << "         Julian Date(UTC, fraction): " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_julianDate << std::endl;
	std::cout << "                            jd_2000: " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_j2000 << std::endl;
	std::cout << "                                DOY: " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << jd_doy << std::endl << std::endl;
	std::cout << std::endl;

	std::cout << "        Mean anomaly M for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << M_deg << "°" << std::endl;
	std::cout << "  Equation of centre C for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << C_deg << "°" << std::endl;
	std::cout << "  Ecliptic longitude Π for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << ecliptic_longitude_Π_deg << "°" << std::endl;
	std::cout << "Obliquity of equator ε for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << obliquity_of_equator_ε_deg << "°" << std::endl;
	std::cout << "      Mean longitude L for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << fmod(mean_longitude_L_deg, 360) << "°" << std::endl;
	std::cout << "Ecliptical longitude λ for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << fmod(ecliptical_longitude_λ_deg, 360) << "°" << std::endl;
	std::cout << "     Right ascension α for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << right_ascension_α_deg << "°" << std::endl;
	std::cout << "         Declination δ for " << planet << ": " << std::setw(jd_FLOATWIDTH) << std::setprecision(jd_FLOATPRECISION) << std::setfill(' ') << declination_δ_deg << "°" << std::endl;

	//right_ascension_α_deg;
			//declination_δ_deg;



	std::cout << std::endl;

}
