//============================================================================
// Name        : lab1p11.cpp
// Author      : Barna Bogdan 913
// Date	       : 2.03.2012
// Statement   : 11. Read sequences of positive integer numbers (reading of each sequence
//				ends by 0, reading of all the sequences ends by -1) and determine the maxim
//				element of each sequence and the maxim element of the global sequence.
//============================================================================

#include <iostream>
using namespace std;

int getMax(int a,int b) {
	// Desc		: Return the maximum of the two integer numbers
	// Input	: a, b - integer numbers
	// Precond. : a, b - integer numbers
	// Postcond.: a, b - remain unchanged
	if (a>b) {
		return a;
	}	else {
		return b;
	}
}

void endSeq(int &max1,int &max2) {
	// Desc		: Prints max1, max2 gets the maximum value of max1 and
	//			  max2; and max1 gets 0
	// Input 	: max1, max2 - integer numbers
	// Precon	: max1, max2 - integer numbers
	// Postcon 	: value of max1 is changed globally to 0 and max2 is
	//			  changed, also globally, to maximum of max1 and max2;
	//			  the function return void
	cout<<"The max elem of the prev seq: "<<max1<<endl;
	max2 = getMax(max1,max2);
	max1 =0;
}

int main() {
	int x,max1=0,max2=0;
	while (1)  {
			cout<<"Type the number: "; cin>>x;
			if (x==0) {
				endSeq(max1,max2);
				continue;
			}
			if (x==-1)	{
				endSeq(max1,max2);
				cout<<"The max elem of global: " <<max2<<endl;
				return 0;
			}
			if (x>max1) max1=x;


		}
}
