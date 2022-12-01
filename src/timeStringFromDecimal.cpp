/*
 * timeStringFromDecimal.cpp
 *
 *  Created on: 1 Dec 2022
 *      Author: jole
 */
#include "sunpos.h"



//
// TODO - describe what we're calculating here...
//
char* sunpos::timeStringFromDecimal(double time)
{
	char* retVal	= new char[16];

	if(!retVal)
		return NULL;

	time *= 24;

	int hour		= floor(time);
	int minutes		= floor((time - hour) * 60);
	int seconds		= floor((((time - hour) * 60) - minutes) * 60);

	sprintf(retVal, "%02d:%02d:%02d", hour, minutes, seconds);

	return retVal;
}

