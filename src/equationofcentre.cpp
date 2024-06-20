/*
 * equationofcentre.cpp
 *
 *  Created on: 14 Jun 2024
 *      Author: jole
 */

#include <iostream>

#include "equationofcentre.h"



equationofcentre::equationofcentre()
{

	eoc_verbose = false;

	return;
}



equationofcentre::equationofcentre(double _M, bool _verbose)
{
	eoc_init(_M, _verbose);
}



void equationofcentre::eoc_init(double _M, bool _verbose)
{

	eoc_verbose = _verbose;

	for(int i = 0; i <= NUMBEROFPLANETS-1; i++){

		C[i].C =	C[i].C1 * sin(RADIANS(_M))
				+	C[i].C2 * sin(2 * RADIANS(_M))
				+	C[i].C3 * sin(3 * RADIANS(_M))
				+	C[i].C4 * sin(4 * RADIANS(_M))
				+	C[i].C5 * sin(5 * RADIANS(_M))
				+	C[i].C6 * sin(6 * RADIANS(_M));


		if(eoc_verbose){
			std::cout	<< "Planet: " << C[i].planet << " "
						<< C[i].C1 << " "
						<< C[i].C2 << " "
						<< C[i].C3 << " "
						<< C[i].C4 << " "
						<< C[i].C5 << " "
						<< C[i].C6 << " "
						<< C[i].EC << " "
						<< C[i].C
						<< std::endl;
		}

	}

}



equationofcentre::~equationofcentre()
{

}

