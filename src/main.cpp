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
	char	*shortOptions = (char*)"vjd";
	struct option	longOptions[] = {
					{"date",	required_argument,	NULL,	1},
					{"time",	required_argument,	NULL,	2},
					{"tz",		required_argument,	NULL,	3},
					{"lat",		required_argument,	NULL,	4},
					{"lon",		required_argument,	NULL,	5},
					{"dst",		required_argument,	NULL,	6},
					{"verbose",	no_argument,		NULL, 'v'},
					//{"jdn",		no_argument,		NULL,	'j'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//	Initialize command line variables to some default values, should the user fail to provide...
	//	This is for development purpose only, not to enter production code
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
	


	/*getopt switch statement*/
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
			switch(c){
				case 1:		{
								year = atoi(optarg);
								parseOptarg(&optarg);
								month = atoi(optarg);
								parseOptarg(&optarg);
								day = atoi(optarg);
								// end of parsing optarg

								break;
							}
				case 2:		{
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
			}	//end of getopt switch statement
		}	// end of while-loop
	


	// allocate memory for a sunpos-instance
	sunpos *sp = new sunpos(year, month, day, hour, minute, second, timezone, lat, lon, dst, verbose);

	//	handle any error that might occur
	if(!sp){
		cout << "Allocation failed: " << "memory Error" << '\n';
	}



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
