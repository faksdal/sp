/*
 * sunpos.h
 *
 *  Created on: 20 Jun 2024
 *      Author: jole
 */

#ifndef INC_SUNPOS_H_
#define INC_SUNPOS_H_

/*
 *
 */
#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif

#include <math.h>
#include <iostream>

#include "julianday.h"
#include "meananomaly.h"
#include "equationofcentre.h"
#include "eclipticlongitude.h"
#include "obliquityofequator.h"
#include "siderealtime.h"
#include "equatorialcoefficients.h"



class sunpos : public julianday, public meananomaly, public equationofcentre, public eclipticlongitude, public obliquityofequator, public siderealtime, public equatorialcoefficients
{
	std::string	planet;

	double		lat, lon;

	double		M_deg;
	double		C_deg;
	double		ecliptic_longitude_Π_deg;
	double		obliquity_of_equator_ε_deg;
	double		mean_longitude_L_deg;
	double		ecliptical_longitude_λ_deg;
	double		right_ascension_α_deg;
	double		declination_δ_deg;
	double		siderealtime_Θ_deg;
	double		altitude_h_deg;
	double		azimuth_A_deg;
	double		hour_angle_H_deg;


	//***********************************************************************************
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	double	RADIANS(double _degrees) { return (_degrees * M_PI / 180.); }
	double	DEGREES(double _radians) { return (_radians * 180. / M_PI); }
	//***********************************************************************************

public:
	sunpos(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose, std::string _planet, double _lat, double _lon);
	virtual ~sunpos();

	void	sp_printToScreen(void);
};

#endif /* INC_SUNPOS_H_ */
