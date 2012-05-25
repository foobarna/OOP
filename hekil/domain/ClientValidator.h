/*
 * ClientValidator.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef CLIENTVALIDATOR_H_
#define CLIENTVALIDATOR_H_
#include "Client.h"
#include "Exceptions.h"
namespace domain {

class ClientValidator {
public:
	void validate ( const Client& c) throw (ValidatorException);
};

}



#endif /* CLIENTVALIDATOR_H_ */
