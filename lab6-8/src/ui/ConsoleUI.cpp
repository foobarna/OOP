/*
 * ConsoleUI.cpp
 *
 *  Created on: May 3, 2012
 *      Author: Aneta
 */
#include "ConsoleUI.h"

#include <map>

namespace ui {

void ConsoleUI::run()
{
	int opt;
	do
	{
		showMenu();
		opt = readOption();
		switch(opt)
		{
		case 0: break;
		case 1: addMovie();
		        break;
		case 2: updateMovieType();
		        break;
		case 3: updateMovieDesc();
		        break;
		case 4: removeMovie();
		        break;
		case 5: printAllMovies();
		        break;
		case 6: searchMovie();
				break;
		case 7: addClient();
				break;
		case 8: updateClientName();
				break;
		case 9: updateClientNoRentedMovies();
				break;
		case 10: rentAMovie();
				break;
		case 11: returnAMovie();
				break;
		case 12: removeClient();
				break;
		case 13: printAllClients();
				break;
		case 14:searchClient();
				break;
		case 15:printMoviesByType();
				break;
		case 16:printClientsByTypeOfMovie();
				break;
		case 17:printMostActiveClientsDsc();
		        break;
		}

	}while(opt != 0);
}

void ConsoleUI::showMenu()
{
	cout << "Menu: " << endl;
	cout << "1. Add movie" << endl;
	cout << "2. Update movie type" << endl;
	cout << "3. Update movie desc" << endl;
	cout << "4. Remove movie" << endl;
	cout << "5. Print all movies" << endl;
	cout << "6. Search movie" << endl;
	cout << "7. Add client" << endl;
	cout << "8. Update client name" << endl;
	cout << "9. Update client no of rented movies" << endl;
	cout << "10. Rent a movie" << endl;
	cout << "11. Return a movie" << endl;
	cout << "12. Remove client" << endl;
	cout << "13. Print all clients" << endl;
	cout << "14. Search client" << endl;
	cout << "15. Print all movies of a given type" << endl;
	cout << "16. Print all clients that have rented movies of a given type" << endl;
	cout << "17. Print most active clients in descending order"<< endl;
	cout << "0. EXIT" << endl;
}

int ConsoleUI::readOption()
{
	int opt;
	do
	{
		cout << endl << "Give option (0 to 17):";
		cin >> opt;
	} while(opt < 0 || opt > 17);
	return opt;
}

void ConsoleUI::addMovie()
{
	char title[50], type[10], desc[20];
	bool available;

	cout << "Give movie title:";
	cin.get();
    cin.getline(title,50);
    cout << "Give movie type:";
    cin.getline(type,10);
    cout<< "Give movie description:";
    cin.getline(desc,20);
    cout<< "Give movie availability(1 for Available or 0 for Unavailable):";
    cin>>available;
    try
    {
    	movieRental->addNewMovie(title,type,desc,available);
    	cout << "Movie added successfully!" << endl << endl;
    }
    catch(MyException& ex)
    {
    	cout << "Failed to add movie: " << ex.getMessage() << endl << endl;
    }
}

void ConsoleUI::updateMovieType()
{
	char title[50], newType[10];

	cout << "Give the title of the movie to update: ";
	cin.get();
	cin.getline(title,50);
	cout << "Give new type: ";
	cin.getline(newType,10);
	try
	{
		movieRental->updateMovieType(title,newType);
		cout << "Movie updated successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to update movie: " << ex.getMessage() << endl << endl;;
	}
}
void ConsoleUI::updateMovieDesc()
{
	char title[50], newDesc[20];

	cout << "Give the title of the movie to update: ";
	cin.get();
	cin.getline(title,50);
	cout << "Give new description: ";
	cin.getline(newDesc,10);
	try
	{
		movieRental->updateMovieDesc(title,newDesc);
		cout << "Movie updated successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to update movie: " << ex.getMessage() << endl << endl;;
	}
}

void ConsoleUI::removeMovie()
{
	char title[50];

	cout << "Give the title of the movie to remove: ";
	cin.get();
	cin.getline(title,50);
	try
	{
		movieRental->removeMovie(title);
		cout << "Movie removed successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to remove movie: " << ex.getMessage() << endl << endl;
	}
}

void ConsoleUI::printAllMovies()
{
	vector<Movie*> allMovies = movieRental->getAllMovies();
	for(unsigned i = 0; i < allMovies.size(); i++)
	{
		cout << *allMovies[i];
	}
	cout << endl;
}

void ConsoleUI::searchMovie()
{
	char title[50];
	Movie* movie;

	cout << "Give the title of the movie to search: ";
	cin.get();
	cin.getline(title,50);
	movie = movieRental->searchMovie(title);
	if(movie != NULL)
		cout << "Found: " << *movie << endl;
	else
		cout << "No movie with this title has been found!" << endl << endl;
}

void ConsoleUI::addClient()
{
	char name[50], cnp[13] , title[50];
	int noRentedMovies;

	cout << "Give the client name: ";
	cin.get();
	cin.getline(name, 50);
	cout << "Give client cnp: ";
	cin >> cnp;
	cout << "Give title of the current rented movie: ";
	cin.get();
	cin.getline(title,50);
	cout << "Give no of rented movies: ";
	cin >> noRentedMovies;
	//Movie* movie=movieRental->searchMovie(title);
	try
	{
		movieRental->addNewClient(name, cnp, title, noRentedMovies);
		cout << "Client added successfully!" << endl << endl;

	}
	catch(MyException& ex)
	{
		cout << "Failed to add client: " << ex.getMessage() << endl << endl;
	}
}

void ConsoleUI::updateClientName()
{
	char name[50], cnp[13];

	cout << "Give the cnp of the client to update: ";
	cin >> cnp;
	cout << "Give new name: ";
	cin.get();
	cin.getline(name, 50);
	try
	{
		movieRental->updateClientName(cnp, name);
		cout << "Client updated successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to update client: " << ex.getMessage() << endl << endl;
	}
}

void ConsoleUI::updateClientNoRentedMovies()
{
	char cnp[13];
	int noRentedMovies;

	cout << "Give the cnp of the client to update: ";
	cin >> cnp;
	cout << "Give the new no of rented movies: ";
	cin >> noRentedMovies;
	try
	{
		movieRental->updateClientNoRentedMovies(cnp, noRentedMovies);
		cout << "Client updated successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to update client: " << ex.getMessage() << endl << endl;
	}
}
void ConsoleUI::rentAMovie()
{
	char cnp[13], title[50];

	cout << "Give the cnp of the client that wants to rent a movie: ";
	cin >> cnp;
	cout << "Give the title that the client wants to rent: ";
	cin.get();
	cin.getline(title, 50);
	try
	{
		movieRental->rentAMovie(cnp, title);
		cout << "The movie was rented successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed: " << ex.getMessage() << endl << endl;
	}
}
void ConsoleUI::returnAMovie()
{
	char cnp[13], title[50];

	cout << "Give the cnp of the client that wants to return a movie: ";
	cin >> cnp;
	cout << "Give the title that the client wants to return: ";
	cin.get();
	cin.getline(title, 50);
	try
	{
		movieRental->returnAMovie(cnp, title);
		cout << "The movie was returned successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed: " << ex.getMessage() << endl << endl;
	}
}
void ConsoleUI::removeClient()
{
	char cnp[13];

	cout << "Give the cnp of the client to remove: ";
	cin >> cnp;
	try
	{
		movieRental->removeClient(cnp);
		cout << "Client removed successfully!" << endl << endl;
	}
	catch(MyException& ex)
	{
		cout << "Failed to remove album: " << ex.getMessage() << endl << endl;
	}
}

void ConsoleUI::searchClient()
{
	char cnp[13];
	Client* client;

	cout << "Give the cnp of the client to search: ";
	cin >> cnp;
	client = movieRental->searchClient(cnp);
	if (client == NULL)
		cout << "There is no client with the specified cnp!" << endl << endl;
	else
		cout << "Found: " << *client << endl;
}

void ConsoleUI::printAllClients()
{
	vector<Client*> clients = movieRental->getAllClients();
	for (unsigned i = 0; i < clients.size(); i++)
		cout << *clients[i];
	cout << endl;
}

void ConsoleUI::printMoviesByType()
{
	char type[10];
	vector<Movie*> m;

	cout << "Give type: ";
	cin >> type;
	m = movieRental->getMoviesOfType(type);
	for(unsigned i=0; i < m.size(); i++)
		cout << *m[i];
	cout << endl;

}
void ConsoleUI::printClientsByTypeOfMovie(){
	char type[10];
	vector<string> v;

	cout << "Give type: ";
	cin >> type;
	v = movieRental->getClientsByTypeOfMovie(type);
	for(unsigned i=0; i < v.size(); i++)
			cout << v[i]<<endl;
	cout << endl;
}

void ConsoleUI::printMostActiveClientsDsc()
{
	multimap< int,string> result =movieRental->getMostActiveClientsDsc();
	multimap<int, string>::reverse_iterator it;

	for(it=result.rbegin();it!= result.rend(); it++)
		cout<<it->first<<" "<<it->second<<endl;
	result.clear();
}

} /* namespace ui */




