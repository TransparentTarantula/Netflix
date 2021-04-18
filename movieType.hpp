#ifndef movieType_hpp
#define movieType_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include "movie.hpp"
#include "movieList.hpp"

using namespace std;

class Type {
public:
	Type() {
		//empty constructor
	}

	Type(string t) {
		this->category = t;
		movielist temp;
		this->list = temp;
	}

	string getType() {
		return category;
	}

	bool operator==(Type& temo) {
		if (category == temo.getType()) {
			return true;
		}
		else
			return false;
	}

	void addM(Movie& other) {
		if (list.same(other) == true) {
			return;
		}
		else
			list.insert(other);
	}

	Movie getM(unsigned short index) {
		return list[index];
	}

	unsigned short totalM() {
		return list.size();
	}

	friend ostream& operator<<(ostream& lhs, Type& rhs);//prints outs profile with formatting

	void removeMovie(unsigned short index) {
		list.erase(index);
	}

	void editMovie(unsigned short index) {
		string name, rating, category;
		unsigned short year, rank;
		cin.ignore();
		cout << "Enter Movie Name: ";
		getline(cin, name);
		while (true) {
			cout << "Enter Year: ";
			cin >> year;
			if (year < 1800 || year > 2100)
				continue;
			else
				break;
		}
		cin.ignore();
		cout << "Enter Category: ";
		getline(cin, category);
		while (true) {
			cout << "Rating: ";
			getline(cin, rating);
			if ((rating != "PG") && (rating != "PG-13") && (rating != "G") && (rating != "R") && (rating != "NC-17")) {
				continue;
			}
			else
				break;
		}
		while (true) {
			cout << "Ranking: ";
			cin >> rank;
			if (rank < 0 || rank > 5) {
				continue;
			}
			else
				break;
		}
        list[index].setName(name);
        list[index].setYear(year);
        list[index].setCat(category);
        list[index].setRanking(rank);
        list[index].setRating(rating);
	}

private:
	movielist list;
	string category;
};

ostream& operator<<(ostream& lhs, Type& rhs) {
	lhs << rhs.getType();
	return lhs;
}
#endif 
