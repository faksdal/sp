/*
 * sunpos.h
 *
 *  Created on: 20 Jun 2024
 *      Author: jole
 */

#ifndef INC_SUNPOS_H_
#define INC_SUNPOS_H_

/*
 *
 */

#include <math.h>
#include <iostream>

#include "julianday.h"
#include "meananomaly.h"
#include "equationofcentre.h"

#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif



class sunpos : public julianday, public meananomaly, public equationofcentre
{
	std::string	planet;

	double		M, C;

	//***********************************************************************************
	//	Private, inline functions to calculate back and forth between radians and degrees
	//
	double	RADIANS(double _degrees) { return (_degrees * M_PI / 180.); }
	double	DEGREES(double _radians) { return (_radians * 180. / M_PI); }
	//***********************************************************************************

public:
	sunpos(int _year, short _month, double _day, short _hour, short _minute, double _second, short _tz, bool _verbose, std::string _planet);
	virtual ~sunpos();

	void	sp_printToScreen(void);
};

#endif /* INC_SUNPOS_H_ */
