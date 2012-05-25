/*
 * MovieRentalApp.cpp
 *
 *     P3. Movie rentalWrite an application for movie rental.
	The application will store:
		• movies: (title, description, type,etc)
		• clients: (name, cnp,etc)
		Create an application which allows to:
		• manage the list of movies and clients.
		• add, remove, update and list  movies and clients
		• search for a  movie; search for a client.
		• Rent/return movies
		• Reporting. The reporting part of the application will allow generating a list of clients or
		books (maybe of certain type) ordered based on the user preference. Examples: most
		rented movies, most active clients, clients with rented movies ordered alphabetically, by
		number of rents, by year of apparition
 */

#include "ui/ConsoleUI.h"
#include "controller/MovieRental.h"
#include "repository/MovieInMemoryRepository.h"
#include "repository/ClientInMemoryRepository.h"
#include "repository/MovieFileRepository.h"
#include "repository/ClientFileRepository.h"
#include "domain/MovieValidator.h"
#include "domain/ClientValidator.h"
#include "controller/TestMovieRental.h"

using namespace ui;
using namespace controller;
using namespace repository;
using namespace domain;

class MovieRentalApp
{
public:
	MovieRentalApp();
	~MovieRentalApp();
    void run();
private:
	MovieRental* movieRental;
	ConsoleUI* consoleUI;
	MovieRepository* movieRepo;
	ClientRepository* clientRepo;
	MovieValidator* movieValidator;
	ClientValidator* clientValidator;
};

void runTests()
{
	TestMovieRental tmr;
	tmr.testAll();
}

int main()
{
	runTests();

	MovieRentalApp movieRentalApp;
	movieRentalApp.run();

	return 0;
}

MovieRentalApp::MovieRentalApp()
{

	movieRepo = new MoFileRepo("src/inout/movies.txt");
	clientRepo = new ClFileRepo("src/inout/clients.txt");
	movieValidator = new MovieValidator();
	clientValidator = new ClientValidator();
	movieRental = new MovieRental(movieRepo, clientRepo, movieValidator, clientValidator);
	consoleUI = new ConsoleUI(movieRental);
}

MovieRentalApp::~MovieRentalApp()
{
	delete consoleUI;
	delete movieRental;
	delete clientValidator;
	delete movieValidator;
	delete clientRepo;
	delete movieRepo;
}

void MovieRentalApp::run()
{
	consoleUI->run();
}




