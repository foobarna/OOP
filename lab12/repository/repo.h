/*
 * repo.h
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#ifndef REPO_H_
#define REPO_H_

#include "../domain/PhNo.h"
#include <vector>

using namespace std;

class Repo{
private:
	vector<PhNo*> book;
	Repo();

public:
	Repo(string filename);
	~Repo();
	void add(PhNo* entry);
	int getSize(){ return book.size();}
	void updateBook(string filename);
	vector<PhNo*> getAll(){ return this->book;}
	vector<PhNo*> filterByCity(string city);
};



#endif /* REPO_H_ */
