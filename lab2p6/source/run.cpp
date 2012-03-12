/*
 * run.cpp
 *
 *  Created on: Mar 12, 2012
 *      Author: blink
 */
#include <iostream>
#include "element.h"
#include "polynom.h"
using namespace std;

#define TE int

void readPolynom(Polynom& p);				//citim de la tastatura gradul si coeficitnetii polynomului
void readMonom(Polynom& m);					//citim de la tastatura gradul si coeficentul monomului
void printPolynom(Polynom p);				//functie de printare a unui polinom
void printMonom(Polynom m);					//functie de printare a unui monom (care este defapt tot un polynom ...)

// cu (TE) in fata la pointeri am facut "conversia" la valoare.


int main() {
	Polynom p,m,r;
	int cmd=1;								//initializam cmd cu 1 pt a putea fi folosit in while, pentru a incepe meniul
	while (cmd!=2){
		cout<<"To multiply polynom P with monom M press 1"<<endl<<"To exit press 2"<<endl;
		cin>>cmd;								//citim optiunea
		if (cmd==1) {
			create(p);							//cream polynomul P, din functie, se initializeaza cu grad 0
			create(m);							// la fel si monomul m
			readPolynom(p);						// se face constructia lui P de la tastatura
			readMonom(m);						// la fel ot m
			create(r,m.grade+p.grade-1,m.grade+p.grade-1);		//cream un r - polinomul rezultat, de dimensiuni m.grade+p.grade
			mul(p,m,r);								//inmultim polinomul p cu monomul m si punem rez in r
			cout<<"P = ";							//tiparire
			printPolynom(p);
			cout<<endl<<"M = ";
			printMonom(m);
			cout<<endl<<"P * M = ";
			printPolynom(r);
			cout<<endl<<endl;
		}
		if ((cmd!=1)&&(cmd!=2)) cout<<"WRONG INPUT"<<endl;
	}

	cout<<endl<<"returned"<<endl;
	return 0;
}


void readPolynom(Polynom& p){
	int grade,coeff;
	cout<<"Give the grade of the polynom P: "; cin>>grade;
	for (int i=0; i <= grade; i++) {
			cout<<"coeff for x^"<<i<<" is "; cin>>coeff;
			add(p,(TE*) coeff);								//cum la inceput grade=0, adaugam coeficientii iar in add() se
		}													//mareste si p.grade dupa aceea.
}

void readMonom(Polynom& m){
	int grade,coeff;
	cout<<"Give the grade of the monom M: "; cin>>grade;
	cout<<"Give the coefficient of the monom M: "; cin>>coeff;
	createMon(m,grade,coeff);								// se apeleaza createMon(), care pune 0 in m.coeffs pana la m.coeffs[grade]
}

void printPolynom(Polynom p) {
	for (int i=0; i < p.grade ; i++) {
		if ((TE)p.coeffs[i]>0)	cout<<"+"<<(TE)p.coeffs[i]<<"x^"<<i;
		else if ((TE)p.coeffs[i]<0) cout<<(TE)p.coeffs[i]<<"x^"<<i;
		}
}

void printMonom(Polynom m) {
	if ((TE)m.coeffs[m.grade-1]>-1) cout<<"+"<<(TE)m.coeffs[m.grade-1]<<"x^"<<m.grade-1;
			else cout<<(TE)m.coeffs[m.grade-1]<<"x^"<<m.grade-1;
}
