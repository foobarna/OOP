/*
 * MovieFileRepository.cpp
 *
 *  Created on: May 16, 2012
 *      Author: Aneta
 */

#include "MovieFileRepository.h"
#include <fstream>
#include <iostream>

namespace repository {

vector<Movie*>MoFileRepo::findAll()
{
	vector<Movie*> v;
	Movie* pm;
	ifstream in(fileName);
	if(!in.is_open())
		cout <<"Failed to open movies file!findAll()"<<fileName<<endl;
	else
	{
		while(!in.eof())
		{
			pm = new Movie ;
			cout<<v.size()<<"---------------------------------"<<endl;
			in >> *pm;
			if(pm->getTitle().length() == 0)
				delete pm;
			else{
				v.push_back(pm);
			}
			cout<<v.size()<<"---------------------------------"<<endl;
		}
		in.close();
	}
	return v;
}

Movie* MoFileRepo::findByTitle(string title)
{
	Movie* pm = new Movie ;
	ifstream in(fileName);
	if(!in.is_open())
		cout << "Failed to open artists file!findByTitle"<<fileName<<endl;
	else
	{
		while(!in.eof())
		{
			in >> *pm;
			if(pm->getTitle().compare(title) == 0)
			{
				in.close();
				return pm;
			}
		}
		in.close();
	}
	delete pm;
	return NULL;
}

void MoFileRepo::save(Movie m) throw (RepositoryException)
{
	Movie* pm = findByTitle(m.getTitle());
	if (pm != NULL)
	{
		delete pm;
		throw RepositoryException("There is already a movie with this title!");
	}
	ofstream out;
	out.open(fileName,ios::app);
	if(!out.is_open())
		cout << "Failed to open movies file!save()"<<fileName<<endl;
	else
	{
		out << m.getTitle() << "\n" << m.getType() << "\n" << m.getDesc() << "\n"<< m.getAvailable() <<"\n";
		out.close();
	}
}

void MoFileRepo::updateDesc(string title, string desc) throw (RepositoryException)
{
	vector<Movie*> allMovies = findAll();
	unsigned i = 0;
	while(i < allMovies.size() && allMovies[i]->getTitle().compare(title) != 0)
		i++;
	if (i == allMovies.size())
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
			delete allMovies[j];
		throw RepositoryException("There is no artist with this name!");
	}
	allMovies[i]->setDesc(desc);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open artists file!updateDesc"<<fileName<<endl;
	else
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
		{
			out << allMovies[j]->getTitle() << endl << allMovies[j]->getType() << endl<< allMovies[j]->getDesc() << endl<< allMovies[j]->getAvailable() << endl;
			delete allMovies[j];
		}
		out.close();
	}
}

void MoFileRepo::updateAvailable(string title, bool available) throw (RepositoryException)
{
	vector<Movie*> allMovies = findAll();
	unsigned i = 0;
	while(i < allMovies.size() && allMovies[i]->getTitle().compare(title) != 0)
		i++;
	if (i == allMovies.size())
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
			delete allMovies[j];
		throw RepositoryException("There is no artist with this name!");
	}
	allMovies[i]->setAvailable(available);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open artists file!";
	else
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
		{
			out << allMovies[j]->getTitle() << endl << allMovies[j]->getType() << endl<< allMovies[j]->getDesc() << endl<< allMovies[j]->getAvailable() << endl;
			delete allMovies[j];
		}
		out.close();
	}
}

void MoFileRepo::updateType(string title, string type) throw (RepositoryException)
{
	vector<Movie*> allMovies = findAll();
	unsigned i = 0;
	while(i < allMovies.size() && allMovies[i]->getTitle().compare(title) != 0)
		i++;
	if (i == allMovies.size())
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
			delete allMovies[j];
		throw RepositoryException("There is no artist with this name!");
	}
	allMovies[i]->setType(type);

	ofstream out;
	out.open(fileName,ios::trunc);
	if(!out.is_open())
		cout << "Failed to open artists file!";
	else
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
		{
			out << allMovies[j]->getTitle() << endl << allMovies[j]->getType() << endl<< allMovies[j]->getDesc() << endl<< allMovies[j]->getAvailable() << endl;
			delete allMovies[j];
		}
		out.close();
	}
}

void MoFileRepo::removeByTitle(string title) throw (RepositoryException)
{
	vector<Movie*> allMovies = findAll();
	unsigned i = 0;
	while(i < allMovies.size() && allMovies[i]->getTitle().compare(title) != 0)
		i++;
	if(i == allMovies.size())
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
			delete allMovies[j];
		throw RepositoryException("There is no movie with this title!");
	}
	allMovies.erase(allMovies.begin() + i);

	ofstream out;
	out.open(fileName, ios::trunc);
	if(!out.is_open())
		cout << "Failed to open artists file!";
	else
	{
		for(unsigned j = 0; j < allMovies.size(); j++)
		{
			out << allMovies[j]->getTitle() << endl << allMovies[j]->getType() << endl<< allMovies[j]->getDesc() << endl<< allMovies[j]->getAvailable() << endl;
			delete allMovies[j];
		}
		out.close();
	}
}

} /* namespace repository */



