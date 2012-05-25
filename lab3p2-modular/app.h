#ifndef APP_H_
#define APP_H_

#include "collection/collection.h"
#include "participant/participant.h"

void add(Collection& c, Participant p);
void insert(Collection& c, Participant p, int k);

void remove(Collection& c, int k);
void removeFromTo(Collection& c, int a, int b);
void replace(Collection& c, int k, int score);

void lessThan(Collection& c, int score);
void sort(Collection& c);
void sortGreaterThan(Collection& c,int score);

int average(Collection& c, int a, int b);
int minFromTo(Collection& c, int a, int b);
void mulFromTo(Collection& c, int m, int a, int b);

void filterMul(Collection& c, int x);
void greaterThan(Collection& c, int score);

int compare(TE e1, TE e2);
Participant getP(Collection& c, int pos);
void backup(Collection c, Collection& b);

#endif /* APP_H_ */
