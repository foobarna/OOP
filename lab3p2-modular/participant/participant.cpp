#include "participant.h"
#include <string>
#include <iostream>

using namespace std;

void createParticipant(Participant& a, string name, string surname, int score){
	a.Name = name;
	a.Surname = surname;
	a.score = score;
}

string getName(Participant a){
	return a.Name;
}

string getSurname(Participant a){
	return a.Surname;
}

string getFullN(Participant a){
	string s;
	s = a.Name + " " + a.Surname;
	return s;
}

int getScore(Participant a){
	return a.score;
}

void setName(Participant& a, string n){
	a.Name = n;
}

void setSurname(Participant& a, string s){
	a.Surname = s;
}

void setScore(Participant& a, int score){
	a.score = score;
}

int isEqual(Participant a, Participant b){
	if ((a.Name == b.Name) && (a.Surname == b.Surname)) return 1;
	return 0;
}


int compareScore(Participant a, Participant b){
	if (a.score > b.score) return 1;
	if (a.score < b.score) return -1;
	return 0;
}
