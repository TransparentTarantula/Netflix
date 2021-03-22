#include <string>
#include <iostream>
#include "profile.hpp"

using namespace std;

profile::profile() {
	
}

profile::profile(string label, string first, string last, int age) {
	this->label = label;
	this->fName = first;
	this->lName = last;
	this->age = age;
	totalMovies = 0;
	numCategories = 0;
}

profile::profile(string label, string first, string last, int age, profile& anotherProfile) {
	/*constructor for a WHOLE move to add to someones profile*/
}

string profile::getFname() {
	return fName;
}

string profile::getLname() {
	return lName;
}

string profile::getLabel() {
	return label;
}

int profile::getAge() {
	return age;
}

int profile::getAllMovies() {
	return totalMovies;
}

int profile::getAllCategories() {
	return numCategories;
}

void profile::addMovie(movie& movie) {
	/* adds movie to person's profile */
	category newCategory;

	if(numCategories == 0){
		newCategory = movie.getCategory(); // Assign new category
		newCategory.insertMovie(movie); // Insert the new movie into new category
		categories.insert(newCategory); // Insert new category into doubly linked list categories
		totalMovies++; // Count total number of movies in profile
		numCategories++; // Increment count of categories in profile
	}
	else{
		string genre = movie.getCategory(); // Holds the new movie's category
		DoublyLinkedList<category> temp = categories;
		
		/* 
		* If head of doubly linked list matches the inserted movie's category, insert that movie into
		* its list.
		*/
		
		if(categories.getHead().getName() == genre){
			categories.getHead().addMovie(movie.getName(), movie.getYear(), movie.getRating(), movie.getRanking());
			totalMovies++; // Count total number of movies in profile
		}
		else{
			bool notFound = false;
			string currentCategory;
			newCategory = movie.getCategory(); // Assign new category
			newCategory.insertMovie(movie); // Insert the new movie into new category
			categories.insert(newCategory); // Insert new category into doubly linked list categories
			totalMovies++; // Count total number of movies in profile
			numCategories++; // Increment count of categories in profile
			
			//for(int i = 0; i < numCategories; i++){
			//	currentCategory = temp.getCurrentNode().getName(); // Get current category

			//	/* Insert the movie in the specifiied category */
			//	if(currentCategory == genre){
			//		temp.getHead().addMovie(movie.getName(), movie.getYear(), movie.getRating(), movie.getRanking());
			//		totalMovies++; // Count total number of movies in profile
			//		notFound = true; // Set it false
			//		cout << "1";
			//		break;
			//	} 
			//} 
			//temp.nextNode(); // Moves to the node
													
			//}

			/* If category not found, insert new category */
			/*if(notFound){
				newCategory = movie.getCategory(); // Assign new category
				newCategory.insertMovie(movie); // Insert the new movie into new category
				categories.insert(newCategory); // Insert new category into doubly linked list categories
				totalMovies++; // Count total number of movies in profile
				numCategories++; // Increment count of categories in profile
			}*/
		}
		//cout << categories.getHead().getName();
	}
}

void profile::removeMovie() {
	/*removes movie from person profile*/
}

void profile::editMovie() {
	/*edits a movie in a persons profile*/
}

void profile::findMovie() {
	/*finds a movie in a person's profile*/
}

void profile::DisplayList() {
	DoublyLinkedList<category> temp = categories; // Temporary holds categories
	category currentList;
	cout << "\nMovies in queue by genres" << endl << endl;

	for(int i = 0; i < numCategories; i++){
		currentList = temp.getCurrentNode();
		cout << currentList.getName() << endl;
		
		temp.nextNode();
	}
	cout << endl << endl;
}

profile& profile::setFirst(string first) {
	this->fName = first;
	return *this;
}
profile& profile::setLast(string last) {
	this->lName = last;
	return *this;
}
profile& profile::setLabel(string label) {
	this->label = label;
	return *this;
}
profile& profile::setAge(int age) {
	this->age = age;
	return *this;
}
//category profile::getCategory(string name) {
//	
//}
//category& profile::getCategoryByIndex(int index) {
//
//}