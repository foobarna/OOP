#include "hekil.h"

#include <QtGui>
#include <QApplication>

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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MovieRepository* movieRepo = new MoFileRepo("inout/movies.txt");		//to use file storage
    ClientRepository* clientRepo = new ClFileRepo("inout/clients.txt");		//
//    MovieRepository* movieRepo = new MoInMemRepo();						//memory
//    ClientRepository* clientRepo = new ClInMemRepo();						//

    MovieValidator* movieValidator = new MovieValidator();
    ClientValidator* clientValidator = new ClientValidator();
    MovieRental* movieRental = new MovieRental(movieRepo, clientRepo, movieValidator, clientValidator);

//    ConsoleUI* consoleUI = new ConsoleUI(movieRental);					//console UI
//    consoleUI->run();														//

    hekil w(movieRental);													//GUI movies
    w.show();																//
    return a.exec();
}
