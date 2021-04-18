#ifndef movie_hpp
#define movie_hpp

#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Movie {
public:
	Movie() {

	} //empty Constructor

	Movie(string name, unsigned short year, string rating, unsigned short ranking, string cat) {
		this->name = name;
		this->year = year;
		this->rating = rating;
		this->ranking = ranking;
		this->cat = cat;
	}//default constructor

	Movie(string cat) {
		this->cat = cat;
	}

	string getName() {
		return name;
	}//gets Name

	string getRating() {
		return rating;
	}//gets Rating

	string getCat() {
		return cat;
	}//gets the Category

	unsigned short getYear() {
		return year;
	}//gets Year

	unsigned short getRanking() {
		return ranking;
	}//gets Ranking

	Movie& setName(string name) {
		this->name = name;
		return *this;
	}//sets/changes name

	Movie& setYear(unsigned short year) {
		this->year = year;
		return *this;
	}//sets/changes year

	Movie& setRating(string rating) {
		this->rating = rating;
		return *this;
	}//sets/changes rating

	Movie& setRanking(unsigned short ranking) {
		this->ranking = ranking;
		return *this;
	}//sets/changes ranking

	Movie& setCat(string cat) {
		this->cat = cat;
		return *this;
	}//sets/changes the category

	bool operator== (Movie& rhs) {
		if (name == rhs.getName() && year == rhs.getYear()) {
			return true;
		}
		else
			return false;
	}//overloading == operator

	bool operator!= (Movie& rhs) {
		if (name != rhs.getName() && year != rhs.getYear()) {
			return true;
		}
		else
			return false;
	}//overloading != operator

	bool operator>(Movie& rhs) {
		if (name > rhs.getName()) {
			return true;
		}
		else
			return false;
	}

	friend ostream& operator<<(ostream& lhs, Movie& rhs); //prints out Movie info in a formatted manner

private:
	string name;
	unsigned short year;
	string rating;
	unsigned short ranking;
	string cat;
};

ostream& operator<<(ostream& lhs, Movie& rhs) { //prints outs profile with formatting
	lhs << rhs.getName() << endl
		<< "Year: " << rhs.getYear() << endl
		<< "Category: " << rhs.getCat() << endl
		<< "Rated: " << rhs.getRating() << endl;
	string p = "";
	for (unsigned short i = 0; i < rhs.getRanking(); i++) {
		p.append("*");
	}
	lhs << "Rank: " << p << endl;
	return lhs;
}

#endif 
