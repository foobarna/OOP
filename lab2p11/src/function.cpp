/*
 * function.cpp
 *
 *  Created on: Mar 13, 2012
 *      Author: blink
 */

#include "function.h"
#include <iostream>

using namespace std;

void createF(Function &f){
	f.n=0;
	char a='0';
	for (int i=0; i < DIM; i++){
		f.A[i]=a;
		f.B[i]=a;
	}
}

void addRel(Function &f, char a, char b){
	f.A[f.n]=a;
	f.B[f.n]=b;
	++f.n;
}

int checkSurj(Function f) {
	int b[DIM] = {0};
	for (int i = 0; i < f.n; i++){
		if (f.B[i] != '0') {
			if (f.A[i]!='0') b[i]+=1;
		}
	}
	for (int i = 0; i < f.n; i++) cout<<b[i];
	for (int i = 0; i < f.n; i++) {
		if (f.B[i] != '0') {
			if (b[i]==0) return 0;
		}
	}
	return 1;
}


