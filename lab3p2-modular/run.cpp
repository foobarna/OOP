/*
 * run.cpp
 *
 *  Created on: Mar 23, 2012
 *      Author: blink
 */
//============================================================================
// Name        : lab3p2-modular
// Author      : Barna Bogdan 913
// Date	       : 23.03.2012
// Statement   : P2. Contest
//============================================================================
#include <iostream>
#include <string>
#include "consoleUI.h"


using namespace std;

int equals(TE e1, TE e2){
	//cout<<"asssssds \n";
	//Participant *a1,*a2;
	//a1 = (Participant*) e1;
	//a2 = (Participant*) e2;
 	//if ((e1.Name == e2.Name) && (e1.Surname == e2.Surname) ) return 1;
	if (isEqual(*(Participant*)e1, *(Participant*)e2)) return 1;
	return 0;
}

int main() {



//	Collection c,b;
//	Participant p;
//	createParticipant(p,"bob", "smith", 65);
//	createCollection(c);
//	b.eq = equals;
//	c.eq = equals;
//	Participant* f=new Participant(p);
//	addToCollection(c,(TE)f);
//	createParticipant(p,"will", "smith", 70);
//	add(c,p);
//	setName(p,"pos2");
//	add(c,p);
//	setName(p,"pos3");
//	add(c,p);
//	//cout<<c.n<<endl;
//	setScore(p,54);
//	insert(c,p,3);
//	setName(p,"pos4");
//	add(c,p);
	//replace(c,1,11011);
//	setScore(p,23);
	//insert(c,p,3);
	//backup(c,b);
	//removeFromTo(c,1,3);
	//setSize(c,c.n -1);
//	lessThan(c,68);
	//sort(c);
	//sortGreaterThan(c,67);
	//cout<<average(c,1,2);
	//cout<<minFromTo(c,1,4);
	//filterMul(c,10);
	//if (equals(c.els[1],c.els[1])) cout<<endl<<c.n<<endl;
//	for (int i=0; i < c.n;i++){
//		if (compare(c.els[1], c.els[i+1])) cout<<c.n<<"--asda";
//		else cout<<"merge\n";
//		cout<<i<<getName(*(Participant*)c.els[i])<<getScore(*(Participant*)c.els[i])<<endl;

//	}
	//if (compare(c.els[1], c.els[0])) cout<<c.n<<"--asda";
	//else cout<<"merge\n";
	//c.eq((TE) p,(TE) p);
	//int* a = new int(13);

//	if (c.eq(&(TE)p,&(TE)p)) cout<<"AAAAasdasdAAAAA"<<endl;
	//cout<<"\n -asdff ---";//<<(*(int*)c.els[1]);
	return 0;

}
//
//void add(Collection& c, Participant p){
//	Participant* f = new Participant(p);
//	addToCollection(c,(TE)f);
//}
