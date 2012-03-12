/*
 * polynom.h
 *
 *  Created on: Mar 12, 2012
 *      Author: blink
 */

#ifndef POLYNOM_H_
#define POLYNOM_H_

#include "element.h"

struct Polynom{
	int grade;
	int max;
	TE* coeffs;
};

void create(Polynom& p,int grade, int max);
void create(Polynom& p);
void createMon(Polynom& p, int grade, int coeff);
void add(Polynom& p, TE coeff);
void resize(Polynom& p);
void mul(Polynom p, Polynom m, Polynom& r);


#endif /* POLYNOM_H_ */
