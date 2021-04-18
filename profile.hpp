#ifndef profile_hpp
#define profile_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include "movie.hpp"
#include "movieType.hpp"
#include "category.hpp"

using namespace std;

class profile {
public:
	profile() {//empty constructor

	}

	profile(string first, string last, string label, unsigned short age) {//default constructor 
		this->first = first;
		this->last = last;
		this->label = label;
		this->age = age;
		Category temp;
		this->list = temp;
	}

	profile(string first, string last, string label, unsigned short age, const profile& temp) {//new profile with copy constructor of movies
		this->first = first;
		this->last = last;
		this->label = label;
		this->age = age;
		this->list = temp.list;
	}

	string getLast() {//gets last name
		return last;
	}

	string getFirst() {//gets first name
		return first;
	}

	string getLabel() {//gets profile label
		return label;
	}

	unsigned short getAge() {//gets age
		return age;
	}

	profile& setLast(string last) {
		this->last = last;
		return *this;
	}//sets/changes last name

	profile& setFirst(string first) {
		this->first = first;
		return *this;
	}//sets/changes first name

	profile& setLabel(string label) {
		this->label = label;
		return *this;
	}
	profile& setAge(unsigned short age) {
		this->age = age;
		return *this;
	}//sets/changes age

	friend ostream& operator<<(ostream& lhs, profile& rhs);//prints outs profile with formatting

	void addCategory(Movie& other) {    //adds category to existing categories in a profile
		string temp = other.getCat();
		Type t(temp);
		if (list.same(t) == true) {
			return; //checks to see if category already exists
		}
		else
			list.insert(t);
	}

	void getCategory() {
		for (unsigned short i = 0; i < list.size(); i++) {
			cout << list[i] << endl;
		}
	}

	unsigned short TotalC() {
		return list.size();
	}

	void addMovie(Movie& other, unsigned short index) {
		list[index].addM(other);
	}

	Movie getMovie(unsigned short index, unsigned short position) {
		return list[index].getM(position);
	}

	unsigned short totalMovies(unsigned short index) {
		return list[index].totalM();
	}

	unsigned short getIndex(string t) {
		Type temp(t);
		for (unsigned short i = 0; i < list.size(); i++) {
			if (list[i] == temp) {
				return i;
			}
		}
        return 0;
	}

	void removeM(string name, unsigned short year) {
		for (unsigned short i = 0; i < list.size(); i++) {
			for (unsigned short j = 0; j < list[i].totalM(); j++) {
				if ((list[i].getM(j).getName() == name) && (list[i].getM(j).getYear() == year)) {
					list[i].removeMovie(i); //checks for matching name and year then calls function to remove the movie
				}
			}
		}
	}

	Movie SearchM(string name, unsigned short year) {
		for (unsigned short i = 0; i < list.size(); i++) {
			for (unsigned short j = 0; j < list[i].totalM(); j++) {
				if ((list[i].getM(j).getName() == name) && (list[i].getM(j).getYear() == year)) {
					return list[i].getM(i); //checks for matching name and year and then returns the movie profile
				}
			}
		}
        return list[0].getM(0);
	}

	void editM(string name, unsigned short year) {
		for (unsigned short i = 0; i < list.size(); i++) {
			for (unsigned short j = 0; j < list[i].totalM(); j++) {
				if ((list[i].getM(j).getName() == name) && (list[i].getM(j).getYear() == year)) {
					list[i].editMovie(i); //checks for matching name and year and then calls the function where the movie profile can be edited
				}
			}
		}
	}

private:
	string first; //first name
	string last; //last name
	string label; //profile label
	unsigned short age; //age 
	Category list;
};

ostream& operator<<(ostream& lhs, profile& rhs) { //prints outs profile with formatting
	lhs << rhs.getLabel();
	return lhs;
}

#endif 
