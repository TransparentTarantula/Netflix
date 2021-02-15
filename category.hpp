#pragma once
#include <stdio.h>
#include <string>

#include "movie.hpp"
#include "profile.hpp"
#include "doublyLinkedList.hpp"

using namespace std;

class category {
public:
	category();
	category(string name);
	void addMovie(string name, short year, string rating, short ranking);
	void removeMovie(int index);
	void insertMovie(movie& movie);

	void setName(string name);
	string& getName();
	
	bool operator== (category& rhs);

	movie& getMovieByIndex(int index);

	int size();
	
	friend ostream& operator<<(ostream&, category&);

private:
	string name;
	int numOfMovies;
	DoublyLinkedList<movie> movies;
};