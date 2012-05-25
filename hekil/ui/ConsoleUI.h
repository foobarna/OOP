/*
 * ConsoleUI.h
 *
 *  Created on: May 3, 2012
 *      Author: Aneta
 */

#ifndef CONSOLEUI_H_
#define CONSOLEUI_H_

#include "../controller/MovieRental.h"
using namespace controller;

namespace ui {

class ConsoleUI {
private:
	MovieRental* movieRental;

	void showMenu();
	int readOption();
	void addMovie();
	void updateMovieType();
	void updateMovieDesc();
	void removeMovie();
	void printAllMovies();
	void searchMovie();
	void addClient();
	void updateClientName();
	void updateClientNoRentedMovies();
	void rentAMovie();
	void returnAMovie();
	void removeClient();
	void printAllClients();
	void searchClient();
	void printMoviesByType();
//	void printAlbumsOfArtist();
	void printClientsByTypeOfMovie();
	void printMostActiveClientsDsc();
//	void printBestSoldAlbums();
public:
	ConsoleUI(MovieRental* rental) : movieRental(rental) {}
	void run();


};

} /* namespace ui */


#endif /* CONSOLEUI_H_ */
