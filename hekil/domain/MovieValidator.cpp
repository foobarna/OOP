/*
 * MovieValidator.cpp
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#include "MovieValidator.h"

namespace domain {

void MovieValidator::validate(const Movie& m) throw (ValidatorException)
{
	if(m.getTitle().length() == 0)
		throw ValidatorException("Movie title is empty!");
	if(m.getType().length() == 0)
		throw ValidatorException("Movie type is empty!");
	if(m.getDesc().length() == 0)
		throw ValidatorException("Movie description is empty!");
	if(m.getAvailable() != 0 and m.getAvailable()!=1)
		throw ValidatorException("Movie availability is invalid!");
}

}


