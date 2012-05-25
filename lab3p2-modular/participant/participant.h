#ifndef PARTICIPANT_H_
#define PARTICIPANT_H_

#include <string>

using namespace std;

struct Participant {
	string Name;
	string Surname;
	int score;
};

void createParticipant(Participant& a, string name, string surname, int score);

string getName(Participant a);
string getSurname(Participant a);
string getFullN(Participant a);
int getScore(Participant a);

void setName(Participant& a, string n);
void setSurname(Participant& a, string s);
void setScore(Participant& a, int score);

int isEqual(Participant a, Participant b);
int compareScore(Participant a, Participant b);

#endif /* PARTICIPANT_H_ */
