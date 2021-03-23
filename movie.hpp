#pragma once
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class movie {
public:
	movie();
	movie(string name, int year, string rating, int ranking, string category);

	string getName();
	string getRating();
	string getCategory();
	int getYear();
	int getRanking();

	movie& setName(string name);
	movie& setYear(int year);
	movie& setRating(string rating);
	movie& setRanking(int ranking);
	movie& setCategory(string category);

	bool operator==(movie& rhs);
	bool operator<(movie& rhs);
	bool operator<=(movie& rhs);
	bool operator>(movie& rhs);
	bool operator>=(movie& rhs);

	friend ostream& operator<<(ostream&, const movie&);

private:
	int year;
	int ranking;
	
	string name;
	string rating;
	string category;
};