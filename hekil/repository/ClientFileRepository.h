/*
 * ClientFileRepository.h
 *
 *  Created on: May 16, 2012
 *      Author: Aneta
 */

#ifndef CLIENTFILEREPOSITORY_H_
#define CLIENTFILEREPOSITORY_H_
#include "../domain/ClientRepository.h"
using namespace domain;

namespace repository
{

class ClFileRepo : public ClientRepository
{
private:
	char* fileName;
public:
	ClFileRepo(char* fn): fileName(fn){} ;
	Client* findCnp(string cnp);
	vector<Client*> findAll();
	void save(Client) throw (RepositoryException);
	void updateName(string cnp, string newName) throw (RepositoryException);
	void updateTitle(string cnp, string newTitle) throw (RepositoryException);
	void updateNoRentedMovies(string cnp, int newNo) throw (RepositoryException);
	void removeByCnp(string cnp) throw  (RepositoryException);
};

}




#endif /* CLIENTFILEREPOSITORY_H_ */
