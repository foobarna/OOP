/*
 * MovieRepository.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */


#ifndef MOVIEREPOSITORY_H_
#define MOVIEREPOSITORY_H_

#include "Movie.h"
#include "Exceptions.h"
#include <vector>

namespace domain
{

class MovieRepository
{
public:
	virtual Movie* findByTitle(string title) = 0;
	virtual vector<Movie*> findAll() = 0;
	virtual void save(Movie) throw  (RepositoryException) = 0;
	virtual void updateType(string, string) throw (RepositoryException) = 0;
	virtual void updateDesc(string, string) throw (RepositoryException) = 0;
	virtual void updateAvailable(string, bool) throw (RepositoryException) = 0;
	virtual void removeByTitle(string name) throw (RepositoryException) = 0;
	virtual ~MovieRepository(){}
};

}

#endif /* MOVIEREPOSITORY_H_ */
