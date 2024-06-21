/*
 * ooe_getEpsilon.cpp
 *
 *  Created on: 21 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "obliquityofequator.h"



double obliquityofequator::ooe_getEpsilon(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){
		// Compare planets in list with the one asked for by _planet
		if(ε[i].planet == _planet){
			retval = ε[i].obliquity_of_equator_ε_deg;
			break;
		}
	}
	return retval;
}
