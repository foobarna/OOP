//============================================================================
// Name        : lab2p11
// Author      : Barna Bogdan 913/1
// Date	       : 09.03.2012
// Statement   : 11.Let f a function f: A -> B, where A and B are two sets of characters.
//					Check if the function f is a surjection or not.
//============================================================================

#include <iostream>
#include "function.h"

using namespace std;
/*
 * Display a list of options
 */
void displayO(){
	cout<<endl<<"Type 1 to create the function F";
	cout<<endl<<"Type 2 to check if the function F is surjective";
	cout<<endl<<"Type 3 to exit"<<endl;
}

/*
 * Repeatly performs operations on a given function
 */
int menuF(Function &f){
	int cmd;
	createF(f);
	while (1){
		displayO();
		cin>>cmd;
		switch (cmd){
		case 1: {
			int n;
			char a,b;
			cout<<endl<<"Type the no of relations( <10): ";
			cin>>n;
			for (int i=0; i<n; i++)
				cin>>a>>b;
				addRel(f,a,b);
			break;
		}
		case 2: {
			if (f.n==0) cout<<"F was not defined!"<<endl;
				else {
					if (checkSurj(f)){
						cout<<endl<<"Function F is surjective"<<endl;
					} else {
						cout<<endl<<"Function F is not surjective"<<endl;
					}
					createF(f);
				}
			break;
		}
		case 3: return 0;
		default : cout<<"Wrong input!"<<endl; break;
		}
	}
	return 0;
}

int main(){
	Function f;
	menuF(f);
	return 0;
}


