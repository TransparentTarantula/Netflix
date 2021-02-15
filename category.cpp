#include "category.hpp"

using namespace std;

category::category() {

}

void category::addMovie(string name, short year, string rating, short ranking) {
	/*add movie to person's profile*/
}
void category::removeMovie(int index) {
	/*remove movie from person[index] profile*/
}
void category::insertMovie(movie& movie) {
	/*inserts movie into a list of movies that are already there*/
}

void category::setName(string name) {
	this->name = name;
}
string& category::getName() {
	return name;
}

bool category::operator==(category& rhs) {
	return (this->name == rhs.name);
}

category::category(string name) {
	/*returns the category of a movie by the name of the movie*/
}

//movie& category::getMovieByIndex(int index) {
//	
//}

int category::size() {
	return 0;
}

ostream& operator<<(ostream& lhs, category& rhs) {
	return lhs;
}