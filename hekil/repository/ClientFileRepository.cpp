/*
 * ClientFileRepository.cpp
 *
 *  Created on: May 16, 2012
 *      Author: Aneta
 */
#include "ClientFileRepository.h"
#include <fstream>
#include <cstring>

namespace repository {
vector<Client*> ClFileRepo::findAll()
{
  vector<Client*> allClients;
  ifstream in(fileName);
  if(!in.is_open())
	  cout << "Failed to open clients file!";
  else
  {
	  char name[50], cnp[30], title[50];
	  int noRentedMovies;
	  Client* client;
	  while(!in.eof())
	  {
		    in.getline(name,50);
		    if(strcmp(name,"") != 0){
		    	in.getline(cnp,30);
		    	in.getline(title,50);
		    	in >> noRentedMovies;
		    	in.get();
		    	client = new Client(name, cnp, title, noRentedMovies);
		    	allClients.push_back(client);
		    }
	  }
	  in.close();
  }
  return allClients;
}
Client* ClFileRepo::findCnp(string wantedCnp)
{
	ifstream in(fileName);
	if(!in.is_open())
		cout << "Failed to open clients file!";
	else
	{
		char name[50], cnp[30], title[50];
		int noRM;
		Client* client;

		while(!in.eof())
		{
			in.getline(name,50);
			if(strcmp(name,"") != 0)
			{
				in.getline(cnp,30);
				in.getline(title,50);
				in >> noRM;
				in.get();
				if(string(cnp).compare(wantedCnp) == 0)
				{
					client = new Client(name,cnp,title,noRM);
					in.close();
					return client;
				}
			}
		}
		in.close();
	}
	return NULL;
}
void ClFileRepo::save(Client c) throw (RepositoryException)
{
	Client* client = findCnp(c.getCnp());
	if (client != NULL)
	{
		delete client;
		throw RepositoryException("There is already a client with this cnp!");
	}

	ofstream out;
	out.open(fileName,ios::app);
	if(!out.is_open())
		cout << "Failed to open clients file!";
	else
	{
		out << c.getName() << endl << c.getCnp() << endl << c.getTitle() << endl << c.getNoRentedMovies() << endl;
        out.close();
	}
}
void ClFileRepo::removeByCnp(string cnp) throw (RepositoryException)
{
	vector<Client*> allClients = findAll();
	unsigned i = 0;
	while(i < allClients.size() && allClients[i]->getCnp().compare(cnp) != 0)
		i++;
	if (i == allClients.size())
	{
		for(unsigned j = 0; j < allClients.size(); j++)
			delete allClients[j];
		throw RepositoryException("There is no client with this cnp!");
	}
	else
		allClients.erase(allClients.begin() + i);

    ofstream out;
    out.open(fileName,ios::trunc);
    if(!out.is_open())
    	cout << "Failed to open clients file!";
    else
    {
    	for(unsigned j = 0; j < allClients.size(); j++)
    	{
    		out << allClients[j]->getName() << endl << allClients[j]->getCnp() << endl << allClients[j]->getTitle() << endl << allClients[j]->getNoRentedMovies() << endl;
    		delete allClients[j];
    	}
    	out.close();
    }
}

void ClFileRepo::updateTitle(string cnp, string title) throw (RepositoryException)
{
	vector<Client*> allClients = findAll();
	unsigned i = 0;
	while(i < allClients.size() && allClients[i]->getCnp().compare(cnp) != 0)
		i++;
	if(i == allClients.size())
	{
		for(unsigned j = 0; j < allClients.size(); j++)
			delete allClients[j];
		throw RepositoryException("There is no client with this cnp!");
	}
	allClients[i]->setTitle(title);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open clients file!";
	else
	{
		for(unsigned j = 0; j < allClients.size(); j++)
		{
			out << allClients[j]->getName() << endl << allClients[j]->getCnp() << endl << allClients[j]->getTitle() << endl << allClients[j]->getNoRentedMovies() << endl;
			delete allClients[j];
		}
		out.close();
	}
}
void ClFileRepo::updateNoRentedMovies(string cnp, int newNo) throw (RepositoryException)
{
	vector<Client*> allClients = findAll();
	unsigned i = 0;
	while(i < allClients.size() && allClients[i]->getCnp().compare(cnp) != 0)
		i++;
	if(i == allClients.size())
	{
		for(unsigned j = 0; j < allClients.size(); j++)
			delete allClients[j];
		throw RepositoryException("There is no client with this cnp!");
	}
	allClients[i]->setNoRentedMovies(newNo);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open clients file!";
	else
	{
		for(unsigned j = 0; j < allClients.size(); j++)
		{
			out << allClients[j]->getName() << endl << allClients[j]->getCnp() << endl << allClients[j]->getTitle() << endl << allClients[j]->getNoRentedMovies() << endl;
			delete allClients[j];
		}
		out.close();
	}
}
void ClFileRepo::updateName(string cnp, string newName) throw (RepositoryException)
{
	vector<Client*> allClients = findAll();
	unsigned i = 0;
	while(i < allClients.size() && allClients[i]->getCnp().compare(cnp) != 0)
		i++;
	if(i == allClients.size())
	{
		for(unsigned j = 0; j < allClients.size(); j++)
			delete allClients[j];
		throw RepositoryException("There is no client with this cnp!");
	}
	allClients[i]->setName(newName);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open clients file!";
	else
	{
		for(unsigned j = 0; j < allClients.size(); j++)
		{
			out << allClients[j]->getName() << endl << allClients[j]->getCnp() << endl << allClients[j]->getTitle() << endl << allClients[j]->getNoRentedMovies() << endl;
			delete allClients[j];
		}
		out.close();
	}
}

}



