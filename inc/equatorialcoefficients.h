/*
 * equatorialcoefficients.h
 *
 *  Created on: 24 Jun 2024
 *      Author: jole
 */

#ifndef INC_EQUATORIALCOEFFICIENTS_H_
#define INC_EQUATORIALCOEFFICIENTS_H_

#include <string>

#ifndef NUMBEROFPLANETS
#define	NUMBEROFPLANETS	9
#endif

class equatorialcoefficients{

	struct coefficient_table{
		std::string	planet;
		double		A2, A4, A6, EA, D1, D3, D5, ED;
	};

	bool	ma_verbose;

	/*
	coefficient_table	coeff[NUMBEROFPLANETS] = {	"Mercury",	174.7948000,	4.09233445, 0.,
													"Venus",	50.41610000,	1.60213034, 0.,
													"Earth",	357.5291000,	0.98560028, 0.,
													"Mars",		19.37300000,	0.52402068, 0.,
													"Jupiter",	20.02020000,	0.08308529, 0.,
													"Saturn",	317.0207000,	0.03344414, 0.,
													"Uranus",	141.0498000,	0.01172834, 0.,
													"Neptune",	256.2250000,	0.00598103, 0.,
													"Pluto",	14.88200000,	0.00396000,	0.};
	*/


	coefficient_table	coeff[NUMBEROFPLANETS] = {	"Mercury",	-0.0000,	0,			0,			0.0000,		0.0351,		0,			0,			0.0000,
													"Venus",	-0.0304,	0,			0,			0.0001,		2.6367,		0.0009,		0,			0.0036,
													"Earth",	-2.4657,	0.0529,		-0.0014,	0.0003,		22.7908,	0.5991,		0.0492,		0.0003,
													"Mars",		-2.8608,	0.0713,		-0.0022,	0.0004,		24.3880,	0.7332,		0.0706,		0.0011,
													"Jupiter",	-0.0425,	0,			0,			0.0001,		3.1173,		0.0015,		0,			0.0034,
													"Saturn",	-3.2338,	0.0909,		-0.0031,	0.0009,		25.7696,	0.8640,		0.0949,		0.0010,
													"Uranus",	-42.5874,	12.8117,	-2.6077,	17.6902,	56.9083,	-0.8433,	26.1648,	3.34,
													"Neptune",	-3.5214,	0.1078,		-0.0039,	0.0163,		26.7643,	0.9669,		0.1166,		0.060,
													"Pluto",	-19.3248,	3.0286,		-0.4092,	0.5052,		49.8309,	4.9707,		5.5910,		0.19 };



public:
	equatorialcoefficients();
	virtual ~equatorialcoefficients();

	double	ec_getA2(std::string _planet);
};

#endif /* INC_EQUATORIALCOEFFICIENTS_H_ */
