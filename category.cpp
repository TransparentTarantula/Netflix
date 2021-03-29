#include "category.hpp"

using namespace std;

category::category() {
	
}

category::category(string name) {
	/*returns the category of a movie by the name of the movie */
	this->name = name;
	numOfMovies = 0;
}

int category::size() {
	return this->numOfMovies;
}

void category::addMovie(string name, short year, string rating, short ranking) {
	movie film(name, year, rating, ranking, "none");
	insertMovie(film);
}

void category::removeMovie(int index) {
	/*remove movie from person[index] profile*/
}

void category::insertMovie(movie& movie) {
	/* inserts movie into a list of movies that are already there */
	movies.insert(movie); // Inserts movie into a list 
	numOfMovies++; // Increment count of movie for the category
}

void category::displayMovieList() {
	DoublyLinkedList<movie> temp = movies; // Temperarory holds the list of movies 
	movie currentMovie;
	
	for(int i = 0; i < movies.size(); i++){
		currentMovie = temp.getCurrentNode(); // Gets the node that is currently being pointed
		cout << currentMovie.getName() << endl;
		temp.getNextNode(); // Points to the next node
	}
	cout << endl;
}

//movie& category::getMovieByIndex(int index) {
//	
//}

category& category::setName(string name) {
	this->name = name;
	return *this;
}

string& category::getName() {
	return this->name;
}

bool category::operator==(category& rhs) {
	return (this->name == rhs.name);
}

ostream& operator<<(ostream& lhs, category& rhs) {
	return lhs;
}