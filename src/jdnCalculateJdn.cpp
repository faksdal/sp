/*
 * jdnCalculateJdn.cpp
 *
 *	Created on: 16 Oct 2022
 *	Author: jole
 *
 *	void jdnMeeus1998::jdnCalculateJdn(void) is part of class jdnMeeus1998.
 *	This function calculates the julian day number (jdn) as described in
 *	Jean Meeus' Astronomical Algorithms second edition 1998 p.61 (7.1)
 */


#include "jdnMeeus1998.h"



void jdnMeeus1998::jdnCalculateJdn(void)
{
	int		/*A,*/ B, M, Y;

		M = jdnMonth;
		Y = jdnYear;

		if((M == 1) || (M == 2) ){
			//printf("calculate month and year...\n");
			M += 12;
			Y--;
		}

		//
		//	Different algorithms based on which calendar is used, Gregorian or Julian
		//
		if(!jdnGregorianDate){
			if(jdnVerbose)
				cout << "Perform Meeus calculations based on Julian date..." << endl;

			//A	=	floor(jdnYear/100);
			B	=	0;


		}
		else if(jdnGregorianDate){
				if(jdnVerbose)
					cout << "Perform Meeus calculations based on Gregorian date..." << endl;

				//
				//	The following algorithm is taken from Jean Meeus Astronomical Algorithms Second Edition published in 1998.
				//
				//A	=	floor(jdnYear/100);
				//int B	=	2 - A + floor(A/4);
				B	=	2 - (floor(jdnYear/100)) + floor((floor(jdnYear/100))/4);


		}

		//
		//	Calculate the jdn according to p.61 (7.1) in Jean Meeus Astronomical Algorithms Second Edition published in 1998.
		//	I keep a separate variable, jdnJdnNoon, for the start of the jdn. I believe it will be useful for calculating
		//	sunrise and sunsets later in the project.
		//
		jdnJulianDay = jdnJdnNoon	=		floor(365.25 * (Y + 4716))
										+	floor(30.6001 * (M + 1))
										+	jdnDay + B - 1524.5;
		jdnJdnNoon += 0.5;



		//
		// Calculate the fraction of the day
		//
		jdnJulianDay += (((jdnHour - jdnTz) + (jdnMinute / 60.) + (jdnSecond / 3600.) ) / 24.);

		//
		// Calculating Julian Century according to p.163 in Jean Meeus Astronomical Algorithms Second Edition published in 1998.
		//
		jdnJulianCentury		= ((jdnJulianDay - jdnJ2000) / 36525.);
		jdnJulianCenturyNoon	= ((jdnJdnNoon - jdnJ2000) / 36525.);


		return;
}
