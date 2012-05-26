/*
 * PhNo.h
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#ifndef PHNO_H_
#define PHNO_H_
#include <string>

using namespace std;

/*
 * class that handles phone numbers associated with name and city
 */
class PhNo{
private:
	string name;
	string no;
	string city;
	/*
	 * default constructor
	 */
	PhNo();

public:
	/*
	 * constructor with all 3 fields initialized
	 */
	PhNo(string name,string no, string city);
	~PhNo();
	/*
	 * setters for the class PhNo
	 */
	void setName(string name);
	void setNo(string no);
	void setCity(string city);

	/*
	 * getters for the class PhNo
	 */
	string getName();
	string getNo();
	string getCity();
};


#endif /* PHNO_H_ */
