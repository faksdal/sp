/*
 * eclipticlongitude.h
 *
 *  Created on: 21 Jun 2024
 *      Author: jole
 */

#ifndef INC_ECLIPTICLONGITUDE_H_
#define INC_ECLIPTICLONGITUDE_H_

#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif

#include <iostream>



class eclipticlongitude{

protected:
	struct Π_table{
		std::string	planet;
		double		ecliptic_longitude_Π_deg;
		//double		obliquity_of_equator_ε_deg;
	};

	Π_table	Π[NUMBEROFPLANETS] = {	"Mercury",	230.3265,
									"Venus",	73.7576,
									"Earth",	102.9373,
									"Mars",		71.0041,
									"Jupiter",	237.1015,
									"Saturn",	99.4587,
									"Uranus",	5.4634,
									"Neptune",	182.2100,
									"Pluto",	184.5484 };

public:
	eclipticlongitude();
	virtual ~eclipticlongitude();

	double el_getPI(std::string _planet);
};

#endif /* INC_ECLIPTICLONGITUDE_H_ */
