#include "consoleUI.h"
using namespace std;

void showMenu(){
	cout<<"1a. Add a score for the last participant"<<endl;
	cout<<"1b. Insert a participant with score at a given position"<<endl;
	cout<<"2a. Remove the score given a position"<<endl;
	cout<<"2b. Remove the score for a range of 2 position given"<<endl;
	cout<<"2c. Replace the score for a given position"<<endl;
	cout<<"3a. Write the participants with a score less then the one given"<<endl;
	cout<<"3b. Write the participant in descending order by score"<<endl;
	cout<<"3c. Write the participants in descending order with the score greater then the one given"<<endl;
	cout<<"4a. Write the average score from 2 positions given"<<endl;
	cout<<"4b. Write the lowest score from a range of 2 position given"<<endl;
	cout<<"4c. Write the score multiple of X from a range of 2 given positions"<<endl;
	cout<<"5a. Filter the list retaining scores multiple of X"<<endl;
	cout<<"5b. Filter the list retaining score greater then X"<<endl;
	cout<<"6a. Undo"<<endl;
	cout<<"exit"<<endl;
}

string getOption(){
	string cmd;
	cout<<"Option: ";
	cin>>cmd;
	return cmd;
}
