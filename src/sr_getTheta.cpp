/*
 * sr_getTheta.cpp
 *
 *  Created on: 22 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//


#include <iostream>

#include "siderealtime.h"



// Returns the sidereal time for a given planet.
double siderealtime::sr_getTheta(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){

		// Compare planets in list with the one asked for by _planet
		if(Θ01[i].planet == _planet){
			retval = Θ01[i].Θ;

			break;
		}
	}

	return retval;
}
