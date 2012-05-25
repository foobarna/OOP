/*
 * ClientRepository.h
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */

#ifndef CLIENTREPOSITORY_H_
#define CLIENTREPOSITORY_H_

#include "Client.h"
#include "Exceptions.h"
#include <vector>

namespace domain
{

class ClientRepository
{
public:
	virtual Client* findCnp(string cnp) = 0;
	virtual vector<Client*> findAll() = 0;
	virtual void save(Client) throw (RepositoryException) = 0;
	virtual void updateName(string cnp, string newName) throw (RepositoryException) = 0;
	virtual void updateNoRentedMovies(string cnp, int newNo) throw (RepositoryException) = 0;
	virtual void updateTitle(string cnp, string newTitle) throw (RepositoryException) = 0;
	virtual void removeByCnp(string cnp) throw  (RepositoryException) = 0;
	virtual ~ClientRepository(){};
};

}



#endif /* CLIENTREPOSITORY_H_ */
