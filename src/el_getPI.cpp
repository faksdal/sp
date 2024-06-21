/*
 * el_getPI.cpp
 *
 *  Created on: 21 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "eclipticlongitude.h"



double eclipticlongitude::el_getPI(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){
		// Compare planets in list with the one asked for by _planet
		if(Π[i].planet == _planet){
			retval = Π[i].ecliptic_longitude_Π_deg;
			break;
		}
	}
	return retval;
}
