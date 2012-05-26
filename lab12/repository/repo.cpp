/*
 * repo.cpp
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#include "repo.h"
#include <iostream>
#include <fstream>

using namespace std;

Repo::Repo(string filename){
	updateBook(filename);
}


Repo::~Repo(){
	for(unsigned i= 0; i < book.size(); i++)
			delete book[i];
}

void Repo::updateBook(string filename){
	string name,city,no;
	ifstream file(filename.c_str(),ios::in);
	while (!file.eof()){
		file>>name;
		file>>no;
		file>>city;
		PhNo* p = new PhNo(name,no,city);
		add(p);
	}
	file.close();
}

void Repo::add(PhNo* p){
	book.push_back(p);
}

vector<PhNo*> Repo::filterByCity(string city){
	vector<PhNo*> v;
	for(unsigned int i=0; i<this->book.size();i++){
		if (city[0]==book[i]->getCity()[0]){
			v.push_back(book[i]);
		}
	}
	return v;
}
