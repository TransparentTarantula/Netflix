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

	// If no categories exist for the first time, create new one
	if(numCategories == 0){
		newCategory = movie.getCategory(); // Assign new category
		newCategory.insertMovie(movie); // Insert the new movie into new category
		categories.insert(newCategory); // Insert new category into doubly linked list categories
		totalMovies++; // Count total number of movies in profile
		numCategories++; // Increment count of categories in profile
	}
	else{
		string genre = movie.getCategory(); // Holds the new movie's category
		DoublyLinkedList<category> temp = categories; // Holds the categories temporary
		
		/* 
		* If head of doubly linked list matches the inserted movie's category, insert that movie into its list.
		* Else, insert the movie into its category or create a new one if needed
		*/
		if(categories.getHead().getName() == genre){
			categories.getHead().addMovie(movie.getName(), movie.getYear(), movie.getRating(), movie.getRanking());
			totalMovies++; // Count total number of movies in profile
		}
		else{
			bool notFound = true; // A switch to tell when no category matches the movie
			string currentCategory;
			temp.nextNode(); // points to the next node
			
			for(int i = 1; i < categories.size(); i++){
				currentCategory = temp.getCurrentNode().getName();
				/* Insert the movie in the specifiied category */
				if(currentCategory == genre){
					temp.getCurrentNode().addMovie(movie.getName(), movie.getYear(), movie.getRating(), movie.getRanking());
					totalMovies++; // Count total number of movies in profile
					notFound = false; // Set it false if match found
					break;
				} 
				temp.nextNode(); // points to the next node
			} 									

			/* If category not found, insert new category */
			if(notFound){
				newCategory = movie.getCategory(); // Assign new category
				newCategory.insertMovie(movie); // Insert the new movie into new category
				categories.insert(newCategory); // Insert new category into doubly linked list categories
				totalMovies++; // Count total number of movies in profile
				numCategories++; // Increment count of categories in profile
			}
		}
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

void profile::DisplayMovies() {
	DoublyLinkedList<category> temp = categories; // Temporary holds categories
	category currentCategory; // object holds the current category
	cout << "\nMovies in queue by genres" << endl << endl;

	// Loops to prints out the movies in queue by genre
	for(int i = 0; i < categories.size(); i++){
		currentCategory = temp.getCurrentNode(); // Gets the current node that is pointed in the list
		cout << currentCategory.getName() << ":" << endl;
		currentCategory.displayMovieList(); // Prints the movies from the list
		temp.nextNode(); // Moves to the next node
	}
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