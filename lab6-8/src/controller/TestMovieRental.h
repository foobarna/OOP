/*
 * TestMovieRental.h
 *
 */

#ifndef TESTMOVIERENTAL_H_
#define TESTMOVIERENTAL_H_

#include "MovieRental.h"
#include <cstdio>
#include <assert.h>
#include "../repository/MovieInMemoryRepository.h"
#include "../repository/ClientInMemoryRepository.h"

using namespace repository;
using namespace controller;

class TestMovieRental
{
private:
	MovieRepository* movRepo;
	ClientRepository* cliRepo;
	MovieValidator* movVal;
	ClientValidator* cliVal;
	MovieRental* rental;
	void setUp();
	void tearDown();
public:
	TestMovieRental():movRepo(NULL),cliRepo(NULL),movVal(NULL),cliVal(NULL),rental(NULL){}
	void testAddNewMovie();
	void testDeleteMovie();
	void testUpdateMovie();
	void testSearchMovie();
	void testAddNewClient();
	void testUpdateClient();
	void testAll();

};

void TestMovieRental::setUp()
{
	movRepo = new MoInMemRepo();
	cliRepo = new ClInMemRepo();
	movVal = new MovieValidator;
	cliVal = new ClientValidator;
	rental = new MovieRental(movRepo,cliRepo,movVal,cliVal);
}

void TestMovieRental::tearDown()
{
	if(rental != NULL) delete rental;
	if(movRepo != NULL) delete movRepo;
	if(cliRepo != NULL) delete cliRepo;
	if(movVal != NULL) delete movVal;
	if(cliVal != NULL) delete cliVal;
}

void TestMovieRental::testAddNewMovie()
{

	setUp();

	rental->addNewMovie("title1","type1","...",1);

	vector<Movie*> v = rental->getAllMovies();
	assert(v.size() == 1);
	Movie* m = v[0];
	assert(m->getTitle().compare("title1") == 0 && m->getType().compare("type1") == 0);

	try
	{
		rental->addNewMovie("title1","type1","...",1);
		assert(false);
	}
	catch(RepositoryException& ex)
	{
		assert(true);
	}

	try
	{
		rental->addNewMovie("","type2","...",1);
		assert(false);
	}
	catch(ValidatorException& ex)
	{
		assert(true);
	}

	tearDown();
}
void TestMovieRental::testDeleteMovie(){
        setUp();
	    rental->addNewMovie("title1","type1","...",1);
        rental->addNewMovie("title2","type2","....",1);
		vector<Movie*> v = rental->getAllMovies();
		assert(v.size() == 2);
		Movie* m = v[1];
		assert(m->getTitle().compare("title2") == 0 && m->getType().compare("type2") == 0);
		rental->removeMovie("title2");
	    v = rental->getAllMovies();
		assert(v.size()==1);
		assert(v[0]->getTitle().compare("title1") == 0 && v[0]->getType().compare("type1") == 0);
		try
		{
	          rental->removeMovie("title2");
	          assert(false);
		}
		catch(RepositoryException& ex){
			assert(true);
		};
		tearDown();
}
void TestMovieRental::testUpdateMovie()
{
	setUp();
    rental->addNewMovie("title1","type1","...",1);
    rental->addNewMovie("title2","type2","....",1);
    vector<Movie*> v = rental->getAllMovies();
    rental->updateMovieType(v[0]->getTitle(),"drama");
    assert(v[0]->getType().compare("drama")==0);
    rental->updateMovieDesc(v[0]->getTitle(),"a brand new movie");
    assert(v[0]->getDesc().compare("a brand new movie")==0);
    try{
    	rental->updateMovieAvailable("title4",0);
    	assert(false);
    }
	catch(RepositoryException& ex){
		assert(true);
	}
	tearDown();
}
void TestMovieRental::testSearchMovie(){
	setUp();
    rental->addNewMovie("title1","type1","...",1);
    rental->addNewMovie("title2","type2","....",1);
    vector<Movie*> v = rental->getAllMovies();
    assert(rental->searchMovie("title1")==v[0]);
    try{
    	rental->searchMovie("t");
    }catch(RepositoryException& ex){
    	assert(true);
    }
}
void TestMovieRental::testAddNewClient()
{

	setUp();

	rental->addNewClient("name1","cnp1","none",7);

	vector<Client*> v = rental->getAllClients();
	assert(v.size() == 1);
	Client* c = v[0];
	assert(c->getTitle().compare("none") == 0 && c->getName().compare("name1") == 0);

	try
	{
		rental->addNewClient("name2","cnp1","none",1);
		assert(false);
	}
	catch(RepositoryException& ex)
	{
		assert(true);
	}

	try
	{
		rental->addNewClient("","cnp2","none",1);
		assert(false);
	}
	catch(ValidatorException& ex)
	{
		assert(true);
	}

	tearDown();
}
void TestMovieRental::testUpdateClient()
{
	setUp();
	rental->addNewClient("name1","cnp1","none",7);
	rental->addNewClient("name2", "cnp2","none",0);
    vector<Client*> v = rental->getAllClients();
    rental->updateClientName(v[0]->getCnp(),"mihaela");
    assert(v[0]->getName().compare("mihaela")==0);
    rental->updateClientNoRentedMovies(v[0]->getCnp(),0);
    assert(v[0]->getNoRentedMovies()==0);
    try{
    	rental->updateClientName("cnp4","mirela");
    	assert(false);
    }
	catch(RepositoryException& ex){
		assert(true);
	}
	tearDown();
}
void TestMovieRental::testAll()
{
	testAddNewMovie();
    testDeleteMovie();
    testUpdateMovie();
    testSearchMovie();
    testAddNewClient();
    testUpdateClient();
}


#endif /* TESTMOVIERENTAL_H_ */
