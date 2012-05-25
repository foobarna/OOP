#ifndef COLLECTION_H_
#define COLLECTION_H_

#include "../element/element.h"

struct Collection {
	int n;
	int cp;
	TE* els;
	equalsPtr eq;
};

int equals(TE, TE);

void createCollection(Collection& c, int n, int cp);
void createCollection(Collection& c);
void addToCollection(Collection& c, TE e);
void destroyCollection(Collection& c);
int deleteEl(Collection& c, TE e);
void redimCollection(Collection& c);

int getSize(Collection c);
int getCp(Collection c);

void setSize(Collection& c,int n);
void setCp(Collection& c, int cp);

#endif /* COLLECTION_H_ */
