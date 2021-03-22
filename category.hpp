#pragma once
#include <stdio.h>
#include <string>

#include "movie.hpp"
#include "doublyLinkedList.hpp"

using namespace std;

class category {
	public:
	category();
	category(string name);

	int size();
	void addMovie(string name, short year, string rating, short ranking);
	void removeMovie(int index);
	void insertMovie(movie& movie);
	void displayMovie();
	movie& getMovieByIndex(int index);

	category& setName(string name);
	string& getName();

	bool operator== (category& rhs);
	friend ostream& operator<<(ostream&, category&);

	private:
	string name;
	int numOfMovies;
	DoublyLinkedList<movie> movies;
};