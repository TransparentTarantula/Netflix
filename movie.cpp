#include "movie.hpp"

using namespace std;

movie::movie() {

}

movie::movie(string name, int _year, string _rating, int _ranking, string _category) {
	this->name = name;
	this->year = _year;
	this->rating = _rating;
	this->ranking = _ranking;
	this->category = _category;
}

string movie::getName() {
	return this->name;
}
string movie::getRating() {
	return this->rating;
}
string movie::getCategory() {
	return this->category;
}
int movie::getYear() {
	return this->year;
}
int movie::getRanking() {
	return this->ranking;
}
movie& movie::setName(string name) {
	this->name = name;
	return *this;
}
movie& movie::setYear(int year) {
	if (year < 1900 || year > 2100)
		throw invalid_argument("invalid year");
	else {
		this->year = year;
		return *this;
	}
}
movie& movie::setRating(string rating) {
	if ((rating != "G") && (rating != "PG") && (rating != "PG-13") && (rating != "R") && (rating != "NC-17"))
		throw invalid_argument("invalid rating");
	else {
		this->rating = rating;
		return *this;
	}
}
movie& movie::setRanking(int ranking) {
	if (ranking < 1 || ranking > 5)
		throw invalid_argument("invalid ranking");
	else {
		this->ranking = ranking;
		return *this;
	}
}
movie& movie::setCategory(string category) {
	this->category = category;
	return *this;
}
bool movie::operator== (movie& rhs) {
	return ((this->name == rhs.name) && (this->year == rhs.year));
}
bool movie::operator< (movie& rhs) {
	return this->ranking < rhs.ranking;
}
bool movie::operator<= (movie& rhs) {
	return this->ranking <= rhs.ranking;
}
bool movie::operator> (movie& rhs) {
	return this->ranking > rhs.ranking;
}
bool movie::operator>= (movie& rhs) {
	return this->ranking >= rhs.ranking;
}
ostream& operator<< (ostream& lhs, movie& rhs) {
	cout << "---------------------------" << endl;
	lhs << rhs.getName() << endl 
	    << "Year: " << rhs.getYear() << endl 
		<< "Category: " << rhs.getCategory() << endl 
		<< "Rated: " << rhs.getRating() << endl;
	string p = "";
	for(unsigned short i = 0; i < rhs.getRanking(); i++){
		p.append("*");
	}
	lhs << "Rank: " << p << endl;
	return lhs;
}