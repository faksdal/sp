/*
 * jdnParseDate.cpp
 *
 *	Created on: 20 Nov 2022
 *	Author: jole
 *
 *
 *	This function takes care of checking the user inputs a valid date, and also that we use the
 *	correct algorithm whether we're using the Julian or Gregorian calendar.
 *      
 *
 */

#include <iostream>
#include "jdnMeeus1998.h"

using namespace std;



void jdnMeeus1998::jdnParseDate(void)
{
	//
	//	We assume a valid Gregorian date, otherwise this is changed in the below switch{...}/if{...}-statements
	//
	jdnValidDate		= true;
	jdnGregorianDate	= true;

	//
	//	If we're in 1582, check for valid date. There are ten missing dates this year as we went from
	//	using the Julian to the Gregorian calendar.
	//
	if(jdnYear == 1582 && jdnMonth == 10){
		switch(jdnDay){
		case 1:
		case 2:
		case 3:
		case 4:		jdnGregorianDate = false;
					break;
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
		case 13:
		case 14:	cout << endl << "No such date!\n Exiting..." << endl;
					jdnValidDate = false;
					exit(-1);
					break;
		default:	break;
		}
	}
	else if(jdnYear == 1582 && jdnMonth < 10){
		jdnGregorianDate = false;
		//cout << endl << "Year == 1582 and month is less than 10." << endl;
	}
	else if(jdnYear < 1582){
		jdnGregorianDate = false;
		//cout << endl << "Year is less than 1582." << endl;
	}
}
