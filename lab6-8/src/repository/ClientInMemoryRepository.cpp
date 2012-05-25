/*
 * ClientInMemoryRepository.cpp
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */
#include "ClientInMemoryRepository.h"
namespace repository {

Client* ClInMemRepo::findCnp(string cnp)
{
	unsigned i = 0;
	while(i < clients.size() && clients[i]->getCnp().compare(cnp) != 0)
		i++;
	if(i < clients.size())
		return clients[i];
	return NULL;
}

vector<Client*> ClInMemRepo::findAll()
{
	return clients;
}

void ClInMemRepo::save(Client client) throw (RepositoryException)
{
	Client* c = findCnp(client.getCnp());
	if(c == NULL)
		clients.push_back(new Client(client));
	else throw RepositoryException("There is a client with this cnp!");
}

void ClInMemRepo::updateName(string cnp, string newName) throw (RepositoryException)
{
	Client* c = findCnp(cnp);
	if (c == NULL)
		throw RepositoryException("There is no client with the specified cnp!");
	c->setName(newName);
}

void ClInMemRepo::updateTitle(string cnp, string newTitle) throw (RepositoryException)
{
	Client* c = findCnp(cnp);
	if (c == NULL)
		throw RepositoryException("There is no client with the specified cnp!");
	c->setTitle(newTitle);

}
void ClInMemRepo::updateNoRentedMovies(string cnp, int newNo) throw (RepositoryException)
{
	Client* c = findCnp(cnp);
	if (c == NULL)
		throw RepositoryException("There is no client with the specified cnp!");
	c->setNoRentedMovies(newNo);
}
void ClInMemRepo::removeByCnp(string cnp) throw (RepositoryException)
{
	unsigned i = 0;
	while(i < clients.size() && clients[i]->getCnp().compare(cnp) != 0)
		i++;
	if(i < clients.size())
		clients.erase(clients.begin() + i);
	else
		throw RepositoryException("There is no client with this cnp!");
}

ClInMemRepo::~ClInMemRepo()
{
	for(unsigned i= 0; i < clients.size(); i++)
		delete clients[i];
}
} /* namespace repository */




