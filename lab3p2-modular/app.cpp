//#include "collection/collection.h"
//#include "participant/participant.h"
#include "app.h"
#include <iostream>

using namespace std;

void add(Collection& c, Participant p){
	Participant* f = new Participant(p);
	addToCollection(c,(TE)f);
}

void insert(Collection& c, Participant p, int k){
	Participant* f = new Participant(p);
	setSize(c,getSize(c) + 1);
	for (int i = getSize(c) - 1; i > k - 1; i--)
		c.els[i]=c.els[i-1];
	c.els[k-1] = (TE)f;
	//cout<<k<<getFullN(*(Participant*)c.els[k-1]);
}

void remove(Collection& c, int k){
	Participant* p = new Participant(getP(c,k));
	deleteEl(c,(TE)p);
	delete p;
}
void removeFromTo(Collection& c, int a, int b){
	for (int i = a; i < b; i++)
		remove(c,i);
}

void replace(Collection& c, int k, int score){
	setScore(*(Participant*)c.els[k-1],score);
}

int compare(TE e1, TE e2){
	return compareScore(*(Participant*)e1,*(Participant*)e2);
}

void lessThan(Collection& c, int score){
	int i=0;
	while (i < getSize(c)){
		if (getScore(getP(c,i+1)) > score){
			remove(c,i+1);
			--i;
		}
		++i;
	}
}

void sort(Collection& c){
	TE aux;
	for (int i = 0; i < getSize(c)-1; i++)
		for (int j = i+1; j < getSize(c); j++){
			if (getScore(getP(c,i+1)) < getScore(getP(c,j+1))){
				aux = c.els[i];
				c.els[i] = c.els[j];
				c.els[j] = aux;
			}
		}
}

void sortGreaterThan(Collection& c,int score){
	greaterThan(c,score);
	sort(c);
}

int average(Collection& c, int a, int b){
	int sum=0,avg=0;
	for (int i = a; i <= b; i++)
		sum +=getScore(getP(c,i));
	avg=sum/(b-a+1);
	return avg;
}

int minFromTo(Collection& c, int a, int b){
	int min = getScore(getP(c,a));
	for (int i = a; i <= b; i++)
		if (getScore(getP(c,i)) < min ) min = getScore(getP(c,i));
	return min;
}

void mulFromTo(Collection& c, int m, int a, int b){
	int i=a;
	while (i < getSize(c)){
		if (getScore(getP(c,i+1))/m != 0 ){
			remove(c,i+1);
			--i;
		}
	++i;
	}
}

void filterMul(Collection& c, int x){
	int i=0;
	while (i < getSize(c)){
		if (getScore(getP(c,i+1))%x != 0 ){
			remove(c,i+1);
			--i;
		}
	++i;
	}
}

void greaterThan(Collection& c, int score){
	int i=0;
	while (i < getSize(c)){
		if (getScore(getP(c,i+1)) < score){
			remove(c,i+1);
			--i;
		}
		++i;
	}
}

//////////////

Participant getP(Collection& c, int pos){
	return *(Participant*)c.els[pos-1];
}

void backup(Collection c, Collection& b){
	createCollection(b);
	for (int i=0 ; i < getSize(c); i++) {
		addToCollection(b,c.els[i]);
	}
}
