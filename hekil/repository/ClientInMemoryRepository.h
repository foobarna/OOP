/*
 * ClientInMemoryRepository.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef CLIENTINMEMORYREPOSITORY_H_
#define CLIENTINMEMORYREPOSITORY_H_
#include "../domain/ClientRepository.h"
using namespace domain;

namespace repository
{

class ClInMemRepo : public ClientRepository
{
private:
	vector<Client*> clients;
public:
	Client* findCnp(string cnp);
	vector<Client*> findAll();
	void save(Client) throw (RepositoryException);
	void updateName(string cnp, string newName) throw (RepositoryException);
	void updateTitle(string cnp, string newTitle) throw (RepositoryException);
	void updateNoRentedMovies(string cnp, int newNo) throw (RepositoryException);
	void removeByCnp(string cnp) throw  (RepositoryException);
	~ClInMemRepo();
};

}


#endif /* CLIENTINMEMORYREPOSITORY_H_ */
