/*
 * ctrl.h
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#ifndef CTRL_H_
#define CTRL_H_

#include <iostream>
#include "../repository/repo.h"
#include <qlistwidget.h>
#include <qmessagebox.h>

using namespace std;

class Ctrl{
private:
	Ctrl();
	Repo* r;
public:
	Ctrl(Repo* re){
		this->r = re;
	}
	~Ctrl();
	vector<PhNo*> getAll(){ return r->getAll();}
	vector<PhNo*> getFilter(string s){
		vector<PhNo*> v,b;
		v = this->r->getAll();
		for(unsigned i= 0; i < v.size(); i++){
			cout<<v[i]->getCity()<<endl;
			if (v[i]->getCity()[0] == s[0]){
				cout<<v[i]->getCity()<<endl;
				b.push_back(v[i]);
			}
		}
		return b;
	}
	PhNo* findByName(string s){
		vector<PhNo*> v;
		v = this->r->getAll();
		for (unsigned int i=0; i < v.size(); i++){
			if (v[i]->getName()==s)
				return v[i];
		}
	}


};


#endif /* CTRL_H_ */
