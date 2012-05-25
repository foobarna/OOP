#include "collection.h"
#include <iostream>

using namespace std;

void createCollection(Collection& c, int n, int cp){
	c.cp = cp;
	c.n = n;
	c.els = new TE[c.cp];
	for (int i = 0; i < c.cp; i++)
		c.els[i] = new TE;
	//c.eq = 0;
}

void createCollection(Collection& c){
	createCollection(c,0,DIM);
}

void addToCollection(Collection& c, TE e){
	if (c.cp == c.n) redimCollection(c);
	c.els[c.n++] = e;
}

void destroyCollection(Collection& c){
	delete[] c.els;
	c.cp = 0;
	c.n = 0;
}

int deleteEl(Collection& c, TE e){
	//cout<<"\n ---- \n";
	for (int i = 0; i < c.n; i++) {
		if ( (*c.eq)(c.els[i], e)) { //if operator "==" is not defined for TE then it must be overloaded
			c.els[i] = c.els[c.n-1];
			setSize(c, c.n - 1);
			return 1;
		}
		//else cout<<"1--";
	}
//	TE nil;
//	nil.Name = "";
//	nil.Surname = "";
//	nil.score = 0;
	return 0;
}

void redimCollection(Collection& c){
	c.cp = 2 * c.cp;
	TE* tmp = new TE[c.cp];
	for (int i = 0; i < c.n; ++i)
		tmp[i] = c.els[i];
	delete[] c.els;
	c.els = tmp;
}

int getSize(Collection c){
	return c.n;
}

int getCp(Collection c){
	return c.cp;
}

void setSize(Collection& c, int n){
	c.n = n;
}

void setCp(Collection& c, int cp){
	c.cp = cp;
}
