#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

#include "category.hpp"
#include "movie.hpp"
#include "doublyLinkedList.hpp"

using namespace std;

class profile {
public:
	profile();

	profile(string label, string first, string last, int age);
	profile(string label, string first, string last, int age, profile& anotherProfile);

	string getFname();
	string getLname();
	string getLabel();
	int getAge();
	int getAllMovies();
	int getAllCategories();

	void addMovie(movie& movie);
	void removeMovie();
	void editMovie();
	void findMovie();
	void displayMovies();
	void addCategories(movie& movie);

	profile& setFirst(string first);
	profile& setLast(string last);
	profile& setLabel(string label);
	profile& setAge(int age);

	//category getCategory(string name);
	//category& getCategoryByIndex(int index);

private:
	int age;
	int totalMovies;
	int numCategories;

	string label;
	string fName;
	string lName;

	DoublyLinkedList<category> categories;
};