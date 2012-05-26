/*
 * testPhNo.h
 *
 *  Created on: May 25, 2012
 *      Author: blink
 */

#ifndef TESTPHNO_H_
#define TESTPHNO_H_

#include "PhNo.h"
#include <assert.h>

using namespace std;

/*
 * class to test PhNo class
 */
class testPhNo{
public:
	/*
	 * function that runs the tests
	 */
	void runTest();
};

void testPhNo::runTest(){
	PhNo* p1 = new PhNo("name1","043-325-523","Cluj");
	PhNo* p2 = new PhNo("name2","243-635-523","");

	assert(p1->getName()=="name1");
	assert(p2->getCity()=="");
	assert(p2->getName()=="name2");
	delete p1;
	delete p2;
	//assert(p1->getNo()=="");
}

#endif /* TESTPHNO_H_ */
