/*
 * main.cpp
 *
 *  Created on: 16 Nov 2022
 *      Author: jole
 *
 *      Driver file for classes jdnMeeus1998 and sp.
 *
 */

using namespace std;

#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>

#include "sunpos.h"
#include "parseOptarg.h"
#include "jdnMeeus1998.h"



int main(int argc, char *argv[])
{
	bool	verbose = true;
	int		year, month, day, hour, minute, second, timezone, dst;
	double	lat, lon;

	
	//
	//	getopt variables
	//
	int		c, optionIndex;
	//float	input = 0L, output;

	//
	//	TODO Add proper switches as the projects goes along
	//
	char	*shortOptions = (char*)"d:t:v";
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	'd'},
					{"time",	required_argument,	NULL,	't'},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{"verbose",	no_argument,		NULL, 'v'},
					//{"jdn",		no_argument,		NULL,	'j'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//	Initialise command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code.
	year		= 2020;
	month		= 6;
	day			= 21;
	hour		= 10;
	minute		= 0;
	second		= 0;
	timezone	= 10;
	dst			= 0;
	lat			= -37.81998;
	lon			= 144.983431;
	


	//
	//	getopt() switch statement
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 'd':	{
								year = atoi(optarg);
								parseOptarg(&optarg);
								month = atoi(optarg);
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg

								break;
							}
				case 't':	{
								hour = atoi(optarg);
								parseOptarg(&optarg);
								minute = atoi(optarg);
								parseOptarg(&optarg);
								second = atoi(optarg);
								// end of parsing optarg

								break;
							}
				case 3:		{	
								timezone = atoi(optarg);
								
								break;
							}
				case 4:		{
								lat = atof(optarg);
								
								break;
				}
				case 5:		{	
								lon = atof(optarg);
								
								break;
							}
				case 6:		{
								dst = atoi(optarg);

								break;
							}
				case 'v':	{
								verbose = true;

								break;
							}
				default:	{
								printf("switch default\n");
								break;
							}
			}	//end of getopt() switch statement
		}	// end of while-loop
	


	// Try to allocate memory for an instance of class sunpos
	sunpos *sp = new sunpos(year, month, day, hour, minute, second, timezone, lat, lon, dst, verbose);

	//	handle any error that might occur
	if(!sp){
		cout << "Allocation failed: " << "memory Error" << '\n';
		exit(-1);
	}



	//
	//	Print something if the user sets the verbose switch
	//
	if(verbose){
		sp->spPrintOutput();
	}


	/*
	jdnMeeus1998	*jd = new jdnMeeus1998(year, month, day, hour, minute, second, timezone, verbose);
	if(!jd){
			cout << "Allocation failed: " << "memory Error" << '\n';
			exit(-1);
	}	// if()
	if(verbose){
			jd->jdnPrintOutput();
	}	// if()
	'/
	*/

	return 1;
}	// main
