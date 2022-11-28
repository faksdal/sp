#include "sunpos.h"



void sunpos::spPrintOutput(void)
{
	//
	//	Fixes the floating point values on print, see: https://faculty.cs.niu.edu/~hutchins/csci241/output.htm
	//	Used in conjunction with setw() and setprecision()
	cout.setf(ios::fixed);

	//cout << endl;
	cout	<< "Date/time: " << jdnGetJdnDay() << "/" <<  jdnGetJdnMonth() << "/" << jdnGetJdnYear() << " @ " << setw(2) << setfill('0') << jdnGetJdnHour() <<":" << setw(2) << setfill('0')<< jdnGetJdnMinute() << ":" << setw(2) << setfill('0')<< jdnGetJdnSecond() << endl;
	//cout	<< "Timezone: " << jdnGetJdnTz() << endl;
	//cout	<< "Lat/Lon: " << setw(12) << setprecision(8) << spGetspLat() << "°/" << setw(12) << setprecision(8) << spGetspLon() << "°" << endl;
	//cout << endl;


	//
	// Custom grouping of large numbers, see: https://cplusplus.com/reference/locale/numpunct/grouping/
	//
	struct my_numpunct : std::numpunct<char> {
		// We want to group in numbers of three
		std::string do_grouping() const {return "\03";}
	};
	std::locale loc (std::cout.getloc(),new my_numpunct);
	std::cout.imbue(loc);
	//*************************************************************************************************


	cout	<< "      Julian Day Number (jdn): " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) << setfill(' ') << jdnGetJdnJulianDay() << endl;
	cout	<< "    Julian Day Number at noon: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  jdnGetJdnNoon() << endl;
	cout	<< "               Julian Century: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) << jdnGetJdnJulianCentury() << endl;
	cout	<< "       Julian Century at noon: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) << jdnGetJdnJulianCenturyNoon() << endl;

	cout	<< endl << "Earth/Solar coordinates:" << endl;

	cout	<< "    Suns geometric mean longitude: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spGetGeomMeanLongSun() << endl;
	cout	<< "      Suns geometric mean anomaly: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spGetGeomMeanAnomSun() << endl;
	cout	<< "               spEccentEarthOrbit: " << setw(spFLOATWIDTH) << setprecision(spFLOATPRECISION) <<  spGetEccentEarthOrbit() << endl;
	/*
	cout	<< "                 spSunEqOfCtr: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION) <<  spGetSunEqOfCtr() << endl;
	cout	<< "                spSunTrueLong: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunTrueLong() << endl;
	cout	<< "                spSunTrueAnom: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunTrueAnom() << endl;
	cout	<< "               spSunRadVector: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunRadVector() << endl;
	cout	<< "                 spSunAppLong: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunAppLong() << endl;
	cout	<< "          spMeanObliqEcliptic: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetMeanObliqEcliptic() << endl;
	cout	<< "                  spOliqCorr: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetObliqCorr() << endl;
	cout	<< "                 spSunRtAscen: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunRtAscen() << endl;
	cout	<< "                  spSunDeclin: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetSunDeclin() << endl;
	cout	<< "                       spVarY: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetVarY() << endl;
	cout	<< "                   spEqOfTime: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetEqOfTime() << endl;
	cout	<< "                  spHaSunrise: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetHaSunrise() << endl;
	cout	<< "   spLocalSolarNoon (decimal): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetLocalSolarNoon() << endl;
	cout	<< "     spLocalSolarNoon (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(spGetLocalSolarNoon()) << endl;

	if(spGetHaSunrise() != -1){
		cout	<< "                 localSunRise: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetLocalSunRise() << endl;
		cout	<< "         localSunRise (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(spGetLocalSunRise()) << endl;
		cout	<< "                  localSunSet: " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << spGetLocalSunSet() << endl;
		cout	<< "          localSunSet (h:m:s): " << setw(FLOATWIDTH) << setprecision(FLOATPRECISION)  << timeStringFromDecimal(spGetLocalSunSet()) << endl;
	}
	else{
		cout << "     Sun below horizon\n";
	}
	*/
	cout << endl;

	return;

}
