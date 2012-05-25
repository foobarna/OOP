
/*
 * Movie.h
 *
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <iostream>

using namespace std;

namespace domain{

class Movie{
private:
		string title; //unique identifier (assume there are no two artists with the same name)
		string type;
		string desc;
		bool available;
public:
    Movie(){};
	Movie(string ti, string t, string d, bool a):title(ti), type(t), desc(d), available(a){}
	const string& getTitle() const {return title;}
	const string& getType() const {return type;}
	const string& getDesc() const {return desc;}
	const bool getAvailable() const {return available;}
	void setTitle(string value) {title = value;}
	void setType(string value) {type = value;}
	void setDesc(string value) {desc = value;}
	void setAvailable(bool value) {available = value;}
	friend ostream& operator << (ostream& out, const Movie& m)
		{
			out << m.title << " " << m.type << " " <<m.desc <<" "<<m.available<< endl;
			return out;
		}
	friend istream& operator >> (istream& in, Movie& m)
		{
			char title[50],type[10],desc[30];
			int avail;
			in.getline(title,50);
			in.getline(type,10);
			in.getline(desc,30);
			in>>avail;
			in.get();
			m.setTitle(title);
			m.setType(type);
			m.setDesc(desc);
			m.setAvailable(avail);
			return in;
		}

};
}



#endif /* MOVIE_H_ */
