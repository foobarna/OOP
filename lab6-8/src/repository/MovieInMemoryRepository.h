

/*
 * MovieInMemoryRepository.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef MOVIEINMEMORYREPOSITORY_H_
#define MOVIEINMEMORYREPOSITORY_H_

#include "../domain/MovieRepository.h"

using namespace domain;

namespace repository
{
class MoInMemRepo : public MovieRepository
{
private:
	vector<Movie*> movies;
public:
	 Movie* findByTitle(string title);
	 vector<Movie*> findAll();
	 void save(Movie) throw  (RepositoryException);
	 void updateType(string, string) throw (RepositoryException);
	 void updateAvailable(string, bool) throw (RepositoryException);
	 void updateDesc(string, string) throw (RepositoryException);
	 void removeByTitle(string name) throw (RepositoryException);
	 ~MoInMemRepo();
};
}
#endif /* MOVIEINMEMORYREPOSITORY_H_ */
