/*
 * ClientValidator.cpp
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */
#include "ClientValidator.h"
#include <cstdio>

namespace domain {

void ClientValidator::validate(const Client& c) throw (ValidatorException)
{
	if(c.getCnp().length() == 0)
		throw ValidatorException("Empty cnp!");
	if(c.getName().length() == 0)
			throw ValidatorException("Empty client name!");
	if(c.getTitle().length() == 0)
		throw ValidatorException("Invalid movie!");
	if (c.getNoRentedMovies()< 0)
		throw ValidatorException("Invalid number of rented movies!");
}

} /* namespace domain */



