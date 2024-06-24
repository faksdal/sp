/*
 * ec_getA2.cpp
 *
 *  Created on: 24 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include "equatorialcoefficients.h"



double equatorialcoefficients::ec_getA2(std::string _planet)
{
	double retval = 0.;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){
		// Compare planets in list with the one asked for by _planet
		if(coeff[i].planet == _planet){
			retval = coeff[i].A2;
			break;
		}
	}

	return retval;
}
