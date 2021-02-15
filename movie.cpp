#include <iostream>

#include "movie.hpp"
#include "category.hpp"

using namespace std;

movie::movie() {

}

movie::movie(string name, int _year, string _rating, int _ranking, string _category) {
	this->name = name;
	year = _year;
	rating = _rating;
	ranking = _ranking;
	category = _category;
}

string movie::getName() {
	return name;
}
string movie::getRating() {
	return rating;
}
string movie::getCategory() {
	return category;
}
int movie::getYear() {
	return year;
}
int movie::getRanking() {
	return ranking;
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
bool movie::operator==(movie& rhs) {
	return ((this->name == rhs.name) && (this->year == rhs.year));
}
bool movie::operator<(movie& rhs) {
	return this->ranking < rhs.ranking;
}
bool movie::operator<=(movie& rhs) {
	return this->ranking <= rhs.ranking;
}
bool movie::operator>(movie& rhs) {
	return this->ranking > rhs.ranking;
}
bool movie::operator>=(movie& rhs) {
	return this->ranking >= rhs.ranking;
}
ostream& operator<<(ostream& lhs, const movie& rhs) {
	lhs << rhs.name << endl << "Year: " << rhs.year << endl 
		<< "Category: " << rhs.category << endl << "Rated: " 
		<< rhs.rating << endl << "Ranked: " << rhs.ranking << endl;
	return lhs;
}