/*
 * polynom.cpp
 *
 *  Created on: Mar 12, 2012
 *      Author: blink
 */

#include "element.h"
#include "polynom.h"

void create(Polynom& p,int grade, int max) {
	p.grade = grade;
	p.max = max;
	p.coeffs = new TE[p.max];				//se creeaza in p.coeff referinta
	for (int i=0; i < p.grade ; i++){		//
		p.coeffs[i] =new TE;				//
	}
}

void create(Polynom& p) {
	create(p,0,DIM);						//cand creeam prima data un polynom, aceste e de grad 0.
}

void createMon(Polynom& m, int grade, int coeff) {
	for (int i=0; i < grade; i++)			// initializam monomul pana la GRADE cu 0,
		add(m,0);							// iar la la GRADE ii dam valoarea din COEFF
	add(m,(TE*) coeff);
}

void add(Polynom& p, TE coeff) {			//adaugam in polinomul p, un nou coeficient, care tot
	if (p.grade==p.max) resize(p);			//timpul il adaugam la sfarsit
	p.coeffs[p.grade++] = coeff;			// prin p.grade++ ; dupa ce atribuim coeficientul la grad,
}											// marim p.grade cu 1

void resize(Polynom& p){					// redimensionam p.coeffs, prin crearea unui nou vector
	p.max*=2;								// care il atriubuim inapoi la p.coeffs
	TE* tmp = new TE[p.max];
	for (int i=0; i<p.grade;i++)
		tmp[i]=p.coeffs[i];
	delete[] p.coeffs;
	p.coeffs = tmp;
}

void mul(Polynom p, Polynom m, Polynom& r){
	int a,b,c;										//in a,b,c punem valorile coeficientilor
	for (int i=0; i<r.grade; i++)					//initializam coeficientii polinomului p cu 0.
		r.coeffs[i]=0;
	b = (int) m.coeffs[m.grade-1];					//b este tot timpul coeficientul monomului m
	for (int i=0; i < p.grade; i++) {
		a=(int)p.coeffs[i];							//atribuim pe rand fieCARE  coefient lui a
		c=a*b;										// facem inmultirea dinre coeficintul lui p si lui m
		r.coeffs[i+m.grade-1] = (TE) c;				// atribuim valorile inmultirii coeficientilor lui r - polinomul rezultat
	}
}
