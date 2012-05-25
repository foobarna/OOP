/*
 * function.h
 *
 *  Created on: Mar 10, 2012
 *      Author: blink
 */

#ifndef FUNCTION_H_
#define FUNCTION_H_

const int DIM=10;

/*
 * declares a Function
 */
struct Function{
	char A[DIM],B[DIM];
	int n;
};
/*
 * Initializes a function
 */
void createF(Function &f);

/*
 * Adds a relation for a given function
 */
void addRel(Function &f, char a, char b);

/*
 * checks if the given function has surjectivity
 */
int checkSurj(Function f);

#endif /* FUNCTION_H_ */
