/*
 * MovieValidator.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef MOVIEVALIDATOR_H_
#define MOVIEVALIDATOR_H_

#include "Movie.h"
#include "Exceptions.h"
namespace domain {

class MovieValidator {
public:
	void validate ( const Movie& m) throw (ValidatorException);
};

}
#endif /* MOVIEVALIDATOR_H_ */
