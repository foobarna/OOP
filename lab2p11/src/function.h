/*
 * function.h
 *
 *  Created on: Mar 10, 2012
 *      Author: blink
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

const int DIM=10;

struct Function{
	char A[DIM],B[DIM];
	int n;
};

void createF(Function &f);
void addRel(Function &f, char a, char b);
int checkSurj(Function f);

#endif /* FUNCTION_H_ */
