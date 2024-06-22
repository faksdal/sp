/*
 * sr_init.cpp
 *
 *  Created on: 22 Jun 2024
 *      Author: jole
 */

//
// TODO - describe what we're calculating here...
//

#include <math.h>
#include <iostream>
#include <iomanip>

#include "siderealtime.h"



void siderealtime::sr_init(double _jd, double _j2000, bool _verbose, double _lon)
{
	sr_verbose = _verbose;



	if(sr_verbose){
		std::cout << "----------------- Sidereal time table -------------------" << std::endl;
		std::cout << "Element\tPlanet\t     Θ0\t\t     Θ1\t\t  Θ"<< std::endl;
		std::cout << "---------------------------------------------------------" << std::endl;
	}

	std::cout << std::fixed;
	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){
		Θ01[i].Θ = fmod( (Θ01[i].Θ0 + Θ01[i].Θ1 * (_jd - _j2000) - _lon), 360);
		//Θ01[i].Θ = Θ01[i].Θ0 + Θ01[i].Θ1 * (_jd - _j2000) - _lon;


		if(sr_verbose){
			std::cout	<< "Θ01[" << i << "]: " << Θ01[i].planet << "\t"
						<< std::setw(11) << std::setprecision(7) << Θ01[i].Θ0 << "\t"
						<< std::setw(11) << std::setprecision(7) << Θ01[i].Θ1 << "\t"
						<< std::setw(9) << std::setprecision(5) << Θ01[i].Θ
						<< std::endl;
		}
	}

	if(sr_verbose)
		std::cout << "---------------------------------------------------------" << std::endl;

}
