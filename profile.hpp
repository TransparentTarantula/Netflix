#pragma once
#include <stdio.h>
#include <string>

#include "category.hpp"
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

	void addMovie();
	void removeMovie();
	void editMovie();
	void findMovie();

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

	//DoublyLinkedList<category> categories;

};