/*
 * Client.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#include "Movie.h"

namespace domain {

class Client {
private:

	string cnp;
	string name;
	int noRentedMovies;
	string title;

public:
	Client(string cnp, string name, string title, int no):cnp(cnp), name(name), noRentedMovies(no), title(title){}
	const string& getCnp() const {return cnp;}
	string getTitle() const {return title;}
	const string& getName() const {return name;}
	int getNoRentedMovies() const {return noRentedMovies;}
	void setCnp(string value) {cnp = value;}
	void setTitle(string value) {title = value;}
	void setName(string value) {name = value;}
	void setNoRentedMovies(int value) {noRentedMovies = value;}

	friend ostream& operator<<(ostream& out, const Client& c)
	{
		out << c.cnp << " " << c.name << " " <<c.noRentedMovies << " " <<c.title << endl;
		return out;
	}


};

}



#endif /* CLIENT_H_ */
