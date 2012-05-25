/*
 * MovieRental.cpp
 *
 */

#include "MovieRental.h"

#include <list>
#include <cstring>

namespace controller {

void MovieRental::addNewMovie(string title, string type, string desc, bool available) throw (ValidatorException, RepositoryException)
{
	Movie movie(title, type, desc, available);
	movieValidator->validate(movie);
	movieRepo->save(movie);
}

void MovieRental::updateMovieType(string title, string newType) throw (ValidatorException, RepositoryException)
{
	movieRepo->updateType(title, newType);
}
void MovieRental::updateMovieDesc(string title, string newDesc) throw (ValidatorException, RepositoryException)
{
	movieRepo->updateDesc(title, newDesc);
}
void MovieRental::updateMovieAvailable(string title, bool available) throw (ValidatorException, RepositoryException)
{
	movieRepo->updateAvailable(title, available);
}
void MovieRental:: removeMovie(string title) throw (RepositoryException)
{   string n="none";
	vector<Client*> v=clientRepo->findAll();
	for(unsigned i=0;i<v.size();i++ )
		if(v[i]->getTitle()==title){
			clientRepo->updateTitle(v[i]->getCnp(),n);
			clientRepo->updateNoRentedMovies(v[i]->getCnp(),v[i]->getNoRentedMovies()+1);
		}
	movieRepo->removeByTitle(title);
}

Movie* MovieRental::searchMovie(string title)
{
	return movieRepo->findByTitle(title);
}

vector<Movie*> MovieRental::getAllMovies()
{
	return movieRepo->findAll();
}

void MovieRental::addNewClient(string name, string cnp, string title, int noRentedMovies) throw(MyException)
{
	Movie* m = searchMovie(title);
	string n;
	n="none";
	if(m == NULL && title.compare(n)!=0)
		throw MyException("The specified movie does not exist.");
	else if(title.compare(n)==0)
			{
	    		Client client(cnp,name,title,noRentedMovies);
	    		clientValidator->validate(client);
	    		clientRepo->save(client);
			}
	     else if(m!=NULL && m->getAvailable()==1){

                	    	Client client(cnp,name,title,noRentedMovies);
	    	 	    		clientValidator->validate(client);
	    	 	    		clientRepo->save(client);
	    	 	    	    movieRepo->updateAvailable(m->getTitle(),0);
	            }
	            else throw MyException("The specified movie is not available.");
}

void MovieRental::updateClientName(string cnp, string newClientName) throw (MyException)
{

		clientRepo->updateName(cnp,newClientName);
}

void MovieRental::updateClientNoRentedMovies(string cnp,int newNo) throw (MyException)
{

		clientRepo->updateNoRentedMovies(cnp,newNo);
}
void MovieRental::rentAMovie(string cnp, string title) throw (MyException)
{
	Movie* m = searchMovie(title);
	Client* c=searchClient(cnp);
	if(m == NULL or m->getAvailable()==0)
			throw MyException("The specified movie does not exist or is not available. Please add valid data!");
	else if(c==NULL or c->getTitle()!="none")
		      throw MyException("The specified client does not exist or he already has a rented movie. Please add valid data!");
	     else
	      {
		    //Client client(cnp, newClientName, newTitle, newNoRentedMovies);
	        //clientValidator->validate(client);
		   clientRepo->updateTitle(cnp,title);
		   movieRepo->updateAvailable(title,0);
	}
}
void MovieRental::returnAMovie(string cnp, string title) throw (MyException)
{
	Movie* m = searchMovie(title);
	Client* c=searchClient(cnp);
	if(m == NULL or m->getAvailable()==1)
			throw MyException("The specified movie does not exist or is not rented. Please add valid data!");
	else if(c==NULL or c->getTitle()=="none")
		      throw MyException("The specified client does not exist or he has no rented movie . Please add valid data!");
	     else if (c->getTitle()!=title)
	    	      throw MyException("This client an this movie dosen't have any link. Please add valid data");
	          else
				  {
					//Client client(cnp, newClientName, newTitle, newNoRentedMovies);
					//clientValidator->validate(client);
				   clientRepo->updateTitle(cnp,"none");
				   movieRepo->updateAvailable(title,1);
				   clientRepo->updateNoRentedMovies(cnp,clientRepo->findCnp(cnp)->getNoRentedMovies()+1);
				  }
}
void MovieRental::removeClient(string cnp) throw (RepositoryException)
{
	if (clientRepo->findCnp(cnp)->getTitle()!="none")
		movieRepo->updateAvailable(clientRepo->findCnp(cnp)->getTitle(),1);
	clientRepo->removeByCnp(cnp);
}

Client* MovieRental::searchClient(string cnp)
{
	return clientRepo->findCnp(cnp);
}

vector<Client*> MovieRental::getAllClients()
{
	return clientRepo->findAll();
}

vector<Movie*> MovieRental::getMoviesOfType(string type)
{
	vector<Movie*> m;
	vector<Movie*> all = getAllMovies();
	for(unsigned i=0; i < all.size(); i++)
		if(all[i]->getType().compare(type) == 0)
			m.push_back(all[i]);
	return m;
}

vector<string> MovieRental::getClientsByTypeOfMovie(string type)
{
	vector<string> v;
	vector<Client*> allClients = getAllClients();
	//vector<Album*> allAlbums = getAllAlbums();
	for(unsigned i = 0; i < allClients.size(); i++)
	{
		if (searchMovie(allClients[i]->getTitle())->getType()==type)
		       v.push_back(allClients[i]->getName());
	}
    return v;
}
multimap<int, string> MovieRental::getMostActiveClientsDsc(){
    multimap<int,string> result;
    //vector<int> v;
    ///Client* aux;
    vector<Client*> c=getAllClients();

    /*for(unsigned i=0; i<c.size(); i++)
    	for(unsigned j=i; j<c.size(); j++)
    		if (c[i]->getNoRentedMovies()<c[j]->getNoRentedMovies()){
    			aux=c[i];
    			c[i]=c[j];
    			c[j]=aux;
    		}*/
//    for(unsigned i=0; i<c.size(); i++)
//    	cout<<c[i]->getName()<<endl;
    for(unsigned i=0; i<c.size(); i++){
    	result.insert(pair<int,string>(c[i]->getNoRentedMovies() , c[i]->getName()));
    }
    return result;
}

} /* namespace controller */



