/*
 * siderealtime.h
 *
 *  Created on: 22 Jun 2024
 *      Author: jole
 */

#ifndef INC_SIDEREALTIME_H_
#define INC_SIDEREALTIME_H_

#include <string>

#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif



class siderealtime {

	struct sidereal_table{
			std::string	planet;
			double		Θ0, Θ1, Θ;
		};

		bool	sr_verbose;

		sidereal_table	Θ01[NUMBEROFPLANETS] = {	"Mercury",	132.3282,	6.1385025,		0.,
													"Venus",	104.9067,	-1.4813688,		0.,
													"Earth",	280.1470,	360.9856235,	0.,
													"Mars",		313.3827,	350.89198226,	0.,
													"Jupiter",	145.9722,	870.5360000,	0.,
													"Saturn",	174.3508,	810.7939024,	0.,
													"Uranus",	29.6474,	-501.1600928,	0.,
													"Neptune",	52.4160,	536.31128662,	0.,
													"Pluto",	122.2370,	56.625225,		0.};
public:
	siderealtime();
	virtual ~siderealtime();

	void	sr_init(double _jd, double _j2000, bool _verbose, double _lon);

	double	sr_getTheta(std::string _planet);

};

#endif /* INC_SIDEREALTIME_H_ */
