/*
 * MovieInMemoryRepository.cpp
 *
 *  Created on: May 1, 2012
 *      Author: Aneta
 */
#include "MovieInMemoryRepository.h"

namespace repository {

Movie* MoInMemRepo::findByTitle(string title)
{
	unsigned i = 0;
	while(i < movies.size() && movies[i]->getTitle().compare(title) != 0)
		i++;
	if(i < movies.size())
		return movies[i];
	return NULL;
}

vector<Movie*> MoInMemRepo::findAll()
{
	return movies;
}

void MoInMemRepo::save(Movie movie) throw (RepositoryException)
{
	Movie* a = findByTitle(movie.getTitle());
	if(a != NULL)
		throw RepositoryException("A movie with this title already exists!");
	movies.push_back(new Movie(movie));
}

void MoInMemRepo::updateType(string title, string newType) throw (RepositoryException)
{
	Movie* a = findByTitle(title);
	if(a == NULL)
		throw RepositoryException("There is no movie with this title!");
	else
	{
		a->setType(newType);
	}
}

void MoInMemRepo::updateAvailable(string title, bool newAvailable) throw (RepositoryException)
{
	Movie* a = findByTitle(title);
	if(a == NULL)
		throw RepositoryException("There is no movie with this title!");
	else
	{
		a->setAvailable(newAvailable);
	}
}

void MoInMemRepo::updateDesc(string title, string newDesc) throw (RepositoryException)
{
	Movie* a = findByTitle(title);
	if(a == NULL)
		throw RepositoryException("There is no movie with this title!");
	else
	{
		a->setDesc(newDesc);
	}
}

void MoInMemRepo::removeByTitle(string title) throw (RepositoryException)
{
	unsigned i = 0;
	while(i < movies.size() && movies[i]->getTitle().compare(title) != 0)
		i++;
	if (i < movies.size())
		movies.erase(movies.begin() + i);
	else
		throw RepositoryException("No movie with this title!");
}

MoInMemRepo::~MoInMemRepo()
{
	for(unsigned i = 0; i < movies.size();i++)
		delete movies[i];
}

} /* namespace repository */




