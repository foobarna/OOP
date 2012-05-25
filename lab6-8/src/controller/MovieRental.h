/*
 * MovieRental.h
 *
 *  Created on: May 3, 2012
 *      Author: Aneta
 */

#ifndef MOVIERENTAL_H_
#define MOVIERENTAL_H_

#include "../domain/MovieRepository.h"
#include "../domain/ClientRepository.h"
#include "../domain/MovieValidator.h"
#include "../domain/ClientValidator.h"
#include <map>

using namespace domain;

namespace controller {

class MovieRental {
private:
	MovieRepository* movieRepo;
	ClientRepository* clientRepo;
	MovieValidator* movieValidator;
	ClientValidator* clientValidator;
public:
	/*desc:constructs an object of class MovieRental with given values
	 * pre:all the parameters must be valid
	 * post:retuns an object of type MovieRental
	 */
	MovieRental(MovieRepository* movr, ClientRepository* clir, MovieValidator* movval, ClientValidator* clival):
		movieRepo(movr), clientRepo(clir), movieValidator(movval), clientValidator(clival){}
	/*
	 * desc:adding a new movie in the movie repository
	 * pre:all the parameters must be valid
	 * post:if all the parameters are valid adds the new movie to the movie repository
	 *      else throws an error message
	 */
	void addNewMovie(string title, string type, string desc, bool available) throw (ValidatorException, RepositoryException);
    /*
     * desc:updates the type of a given movie
     * pre:all parameters must be valid
     * post:if all parameters are valid updates the movie type
     *      else throws an error message
     */
	void updateMovieType(string title, string newType) throw (ValidatorException, RepositoryException);
	/*
	 * desc:
	 * pre:
	 * post:
	 */
	void updateMovieDesc(string title, string newDesc) throw (ValidatorException, RepositoryException);
	/*
	 * desc:
	 * pre:
	 * post:
	 */
    void updateMovieAvailable(string title, bool available) throw (ValidatorException, RepositoryException);
    /*
    * desc:removes a movie from the movie repository
    * pre:all parameters must be valid
    * post:if the parameters are valid removes the movie with the given title
    *      else throws an error message
    */
    void removeMovie(string title) throw (RepositoryException);
    /*
     * desc:search a movie in the movie repository
   	 * pre:all the parameters must be valid
   	 * post:if the parameters are valid returns the movie with the given title
   	 *      else throws an error message
   	 */
	Movie* searchMovie(string Title);
	/*
	 * desc:returns all the movies from the movie repository
	 * pre:
	 * post:returns a vector with all the movies from the repository
	 */
	vector<Movie*> getAllMovies();
	/*
	 * desc:
	 * pre:
	 * post:
	 */
	void addNewClient(string name, string cnp, string title, int noRentedMovies) throw(MyException);
	/*
	 * desc:
	 * pre:
	 * post:
	 */
	void updateClientName(string cnp, string newClientName) throw (MyException);
	/*
	 * desc:
	 * pre:
	 * post:
	 */
	void updateClientNoRentedMovies(string cnp, int newNo) throw (MyException);
	/*
	 * desc:a client rents a movie
	 * pre:all the parameters must be valid
	 * post:if the parameters are valid the movie becomes unavailable and client.title recives the title of the movie
	 *      else throws an error message
	 */
	void rentAMovie(string cnp, string title) throw (MyException);
	/*
	 * desc:a client returns a movie
	 * pre:all the parameters must be valid
	 * post:if the parameters are valid the movie becomes available and client.title recives "none" and client.noRentedMovies is incremented
	 *      else throws an error message
	 */
	void returnAMovie(string cnp, string title) throw (MyException);
	/*
     * desc:
	 * pre:
	 * post:
	 */
	void removeClient(string cnp) throw (RepositoryException);
	/*
	 * desc:
	 * pre:
	 * post:
	 */
    Client* searchClient(string cnp);
    /*
     * desc:
     * pre:
     * post:
     */
	vector<Client*> getAllClients();
	/*
	 * desc:returns all the movies that have a given type
	 * pre:type:string must be valid
	 * post:if type is valid it will return a vector with all the movies that have the given type
	 *      else will return an empty vector
	 */
	vector<Movie*> getMoviesOfType(string type);
	/*
	 * desc:returns all clients that rented a certain type of movies
	 * pre:type:string must be valid
	 * post:if type is valid it will return a vector with all the clients that had rented the given type of movies
	 */
	vector<string> getClientsByTypeOfMovie(string type);
	/*
	 * desc:returns an report about the activity of the clients
	 * pre:
	 * post:returns the no of all rented movies by client and the name of the client in descending order
	 */
	multimap<int,string> getMostActiveClientsDsc();

};

} /* namespace controller */



#endif /* MOVIERENTAL_H_ */
