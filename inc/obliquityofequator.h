/*
 * obliquityofequator.h
 *
 *  Created on: 21 Jun 2024
 *      Author: jole
 */

#ifndef INC_OBLIQUITYOFEQUATOR_H_
#define INC_OBLIQUITYOFEQUATOR_H_

#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif

#include <iostream>



class obliquityofequator {

protected:

	struct ε_table{
		std::string	planet;
		double		obliquity_of_equator_ε_deg;
	};

	ε_table	ε[NUMBEROFPLANETS] = {	"Mercury",	0.0351,
									"Venus",	2.6376,
									"Earth",	23.4393,
									"Mars",		25.1918,
									"Jupiter",	3.1189,
									"Saturn",	26.7285,
									"Uranus",	82.2298,
									"Neptune",	27.8477,
									"Pluto",	119.6075 };

public:
	obliquityofequator();
	virtual ~obliquityofequator();

	double ooe_getEpsilon(std::string _planet);
};

#endif /* INC_OBLIQUITYOFEQUATOR_H_ */
