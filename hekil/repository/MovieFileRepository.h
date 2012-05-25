/*
 * MovieFileRepository.h
 *
 *  Created on: May 16, 2012
 *      Author: Aneta
 */

#ifndef MOVIEFILEREPOSITORY_H_
#define MOVIEFILEREPOSITORY_H_
#include "../domain/MovieRepository.h"

using namespace domain;

namespace repository
{
class MoFileRepo : public MovieRepository
{
private:
	char* fileName;
public:
	 MoFileRepo(char* fn) : fileName(fn){};
	 Movie* findByTitle(string title);
	 vector<Movie*> findAll();
	 void save(Movie) throw  (RepositoryException);
	 void updateType(string, string) throw (RepositoryException);
	 void updateAvailable(string, bool) throw (RepositoryException);
	 void updateDesc(string, string) throw (RepositoryException);
	 void removeByTitle(string name) throw (RepositoryException);
};
}



#endif /* MOVIEFILEREPOSITORY_H_ */
