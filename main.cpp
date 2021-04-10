#include <iostream>

#include "doublyLinkedList.hpp"
#include "movie.hpp"
#include "profile.hpp"
#include "category.hpp"
/*
1) create movie obj
2) create category obj based on movie category which points to list
3) insert movie into list for category obj
4) insert category obj into profile list of categories

category obj = new category(movieObj.getCategory());

for each category, if movie object matches category name, do
category.insertMovie(movieObj), if no category is found, make new category

currentProfile = getProfile(name); <- make this function
categories = currentProfile.getCategories()
*/
using namespace std;
/*
Examples:
	DoublyLinkedList<Movie> list;
	list.insert(movie1);
	list.erase(list.find(movie3));

	Movie movie1("A", 2010, "PG", 1);
*/
short user, numProfile = 0;
profile list[10];
profile currentProfile;
string newName, newCategory, newRating, ratingOption, nameToDelete, yearToDelete;
int newYear, newRanking;
//void functions for different menus, only like 2 lines in main
//doublylinkedlist of profiles here in main

void mainMenu();
void queueMenu();
void personProfile();
void addPersonProfile();
void mainAddMovie();
void filterByRating(string, int);
void filterByCategory(string, int);
void removeAMovie();
void startRunning();

int main() {
	mainMenu();
	return 0;
}

void mainMenu() {
	bool running = true;
	unsigned short option = 0;

	cout << "\nWelcome to the Netflix Movie Menu! Please select (or create) a profile:\n";

	if (numProfile == 0) {
		cout << numProfile + 1 << ". Add New Profile" << endl;
		cout << numProfile + 2 << ". Exit Program" << endl;
	}
	else { 
		for (short i = 0; i < numProfile; i++) {
			cout << i + 1 << ". " << list[i].getLabel() << endl;
		}
		cout << numProfile + 1 << ". Add New Profile" << endl;
		cout << numProfile + 2 << ". Exit Program" << endl;
	}

	cout << "choice: ";
	cin >> option;

	if (option <= numProfile) {
		user = option;
		currentProfile = list[user-1];
		personProfile();
	}

	if (option == numProfile + 1) {
		addPersonProfile();
	}

	if (option == numProfile + 2) {
		running = false;
		cout << "Exit Program. Goodbye!";
	}

	if(running) {
		option = 0;
		mainMenu();
	}
}

void addPersonProfile() {
	string label, fName, lName;
	int age;

	cout << "\n\nEnter Profile label: ";
	cin >> label;
	cout << "Enter First Name: ";
	cin >> fName;
	cout << "Enter Last Name: ";
	cin >> lName;
	cout << "Enter Age: ";
	cin >> age; 
	cout << endl;
	cout << "Profile Created!" << endl << endl;
	profile temp(label, fName, lName, age);
	list[numProfile] = temp;
	numProfile++;
}

void personProfile() {
	bool menu = true;
	unsigned short choice = 0;

	while(menu) {
		queueMenu();
		cout << "choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			if (currentProfile.getAllMovies() == 0){
				cout << "\nThe movie queue is empty! Please add movies to the queue." << endl << endl;
			}
			else{
				currentProfile.displayMovies();
			}
			break;
		case 2:
			mainAddMovie();
			break;
		case 3:
			cout << "Enter rating: ";
			cin >> ratingOption;
			filterByRating(ratingOption, choice);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			menu = false;
			break;
		default:
			break;
		}
	}
}

void queueMenu(){
	cout << endl << currentProfile.getLabel() << "'s Profile Movie Queue" << endl;
	cout << "1. Display Movie Queue" << endl
		<< "2. Add Movie to Queue" << endl
		<< "3. Edit Movie in Queue" << endl
		<< "4. Remove Movie from Queue" << endl
		<< "5. Search for Movie in Queue" << endl
		<< "6. Exit Profile" << endl;
}

void mainAddMovie() {
	cin.ignore(); // Allows spaces
	cout << "\n\nEnter movie name: ";
	getline(cin, newName);

	cout << "Enter year: ";
	cin >> newYear;
	
	while (cin.fail() || (newYear < 1900 || newYear > 2100)) {
		cin.clear();
		cout << "Not a valid year. Try again." << endl;
		cout << "Enter year: ";
		cin >> newYear;
	}

	cin.ignore();
	cout << "Category: ";
	getline(cin, newCategory);

	while(true) {
		cout << "Rating (PG, PG-13, G, R, NC-17): ";
		cin >> newRating;

		if ((newRating != "PG") && (newRating != "PG-13") && (newRating != "G") && (newRating != "R") && (newRating != "NC-17")) {
			cout << "Invailed rating" << endl;
		}
		else {
			break;
		}
	}

	cout << "Ranking (1-5): ";
	cin >> newRanking;

	while (cin.fail() || (newRanking < 1 || newRanking > 5)) {
		cin.clear();
		cout << "Not a valid rating. Try again." << endl;
		cout << "Ranking (1-5): ";
		cin >> newRanking;
	}

	cout << endl << endl;
	movie film(newName, newYear, newRating, newRanking, newCategory);
	currentProfile.addMovie(film);
	list[user-1] = currentProfile;
	cout << "Movie added to the Queue!" << endl;
}

void filterByRating(string givenRating, int movieIndex) {
	if ((newRating != "G") && (newRating != "PG") && (newRating != "PG-13") && (newRating != "R") && (newRating != "NC-17")) {
		cout << "Invalid filter option. Try again.";
		filterByRating(givenRating, movieIndex);
	}
	cout << "The movies in your Queue with Rating " << givenRating << " are displayed below." << endl;
	cout << "----------------------------" << endl;
	cout << /*movieName*/ endl;
	cout << "Year: " /*year*/;
	cout << "Category: " /*category*/;
	cout << "Rated: " /*rating*/;
	cout << "Ranking: ";
	for (int i = 0; i < /*rating.length()*/5; i++) {
		cout << '*';
	}
	cout << endl;
	filterByRating(givenRating, movieIndex + 1);
}

void filterByCategory(string givenCategory, int movieIndex) {
	if ((newRating != "G") && (newRating != "PG") && (newRating != "PG-13") && (newRating != "R") && (newRating != "NC-17")) {
		cout << "Invalid filter option. Try again.";
		filterByRating(givenCategory, movieIndex);
	}
	cout << "The movies in your Queue in Category " << givenCategory << " are displayed below." << endl;
	cout << "----------------------------" << endl;
	cout << /*movieName*/ endl;
	cout << "Year: " /*year*/;
	cout << "Category: " /*category*/;
	cout << "Rated: " /*rating*/;
	cout << "Ranking: ";
	for (int i = 0; i < /*rating.length()*/5; i++) {
		cout << '*';
	}
	cout << endl;
	filterByRating(givenCategory, movieIndex + 1);
}

void removeAMovie() {
	cout << "Enter Movie Name: ";
	cin >> nameToDelete;
	cout << "Enter year: ";
	cin >> yearToDelete;
	if (/*success*/1) {
		cout << nameToDelete << "has been removed from your queue!" << endl;
	}
}