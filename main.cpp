#include <iostream>
#include <vector>
#include "profile.hpp"
#include "doublyLinkedList.hpp"
#include "movie.hpp"
#include "movieType.hpp"
#include "movieList.hpp"
#include "category.hpp"

using namespace std;

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

/*
Examples:
	DoublyLinkedList<Movie> list;
	list.insert(movie1);
	list.erase(list.find(movie3));

	Movie movie1("A", 2010, "PG", 1);
*/ 

void profileOption(); // Profile's menu options
void queueOption(); // Ways to display profile's queue options
void queueDisplay(unsigned short index, DoublyLinkedProfile& passProfile); // Queue's display menu
void addProfile(DoublyLinkedProfile& passProfile); // Add profiles
void profileDisplay(unsigned short index, DoublyLinkedProfile& passProfile); // Profile's display menu
void addMovie(unsigned short index, DoublyLinkedProfile& passProfile); // Add Movie
void filter(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice, string command);

//void functions for different menus, only like 2 lines in main
//doublylinkedlist of profiles here in main

int main() {
	bool menu = true; // Condition to check if menu is running
	unsigned short choice = 0; // Input from user
	DoublyLinkedProfile list; // List of profiles

	while(menu) {
		cout << "\nWelcome to the Netflix Movie Menu! Please select (or create) a profile:\n";

		if (list.size() == 0) {
			cout << "1. Add New Profile" << endl
				<< "2. Exit Program" << endl << endl;
			cout << "Enter choice: ";
			cin >> choice;

			if(choice == 1) {
				addProfile(list);
			}
			else if(choice == 2) {
				menu = false;
				cout << "Exit Program. Goodbye!";
			}
			else {
				cout << "invaild choice. Please try again." << endl;
			}
		}
		else { 
			for (unsigned short i = 0; i < list.size(); i++) {
				cout << i + 1 << ". " << list[i] << endl;
			}
			cout << (list.size() + 1) << ". Add New Profile" << endl;
			cout << (list.size() + 2) << ". Exit Program" << endl;
			cout << "Enter choice: ";
			cin >> choice;

			double z = choice/(list.size() + 1);

			if(z < 1) {
				choice -= 1;
				profileDisplay(choice, list);
			}
			else if(z == 1) {
				addProfile(list);
			}
			else if (z == 2){
				menu = false;
				cout << "Exit Program. Goodbye!";
			}
			else {
				cout << "invaild choice. Please try again." << endl;
			}
		}
	}
	return 0;
}

void profileOption(){
	cout << "1. Display Movie Queue" << endl
		<< "2. Add Movie to Queue" << endl
		<< "3. Edit Movie in Queue" << endl
		<< "4. Remove Movie from Queue" << endl
		<< "5. Search for Movie in Queue" << endl
		<< "6. Exit Profile" << endl;
}

void queueOption() {
	cout << "Display options:\n\n";
	cout << "1. Highest to lowest Ranking" << endl
		<< "2. Lowest to Highest Ranking" << endl
		<< "3. Filter by Rating" << endl
		<< "4. Filter by Category" << endl
		<< "5. Sorted movie queue" << endl
		<< "6. Exit Display Menu" << endl;
}

void addProfile(DoublyLinkedProfile& passProfile) {
	string label, fName, lName;
	unsigned short age;

	cin.ignore(); // Allows spaces
	cout << "\nEnter Profile label: ";
	getline(cin, label);
	cout << "Enter First Name: ";
	getline(cin, fName);
	cout << "Enter Last Name: ";
	getline(cin, lName);
	cout << "Enter Age: ";
	cin >> age; 
	cout << endl;

	profile temp(fName, lName, label, age);
	passProfile.insert(temp); // Insert new profile to list

	cout << endl;
	cout << "Profile Created!" << endl << endl;
}

void profileDisplay(unsigned short index, DoublyLinkedProfile& passProfile) {
	enum Menu{Display = 1, Add, Edit, Remove, Search, Exit};
	bool menu = true;
	unsigned short choice = 0;
	cout << endl << passProfile[index] << "'s Profile Movie Queue" << endl << endl;

	while(menu) {
		profileOption();
		cout << "Enter choice: ";
		cin >> choice;

		switch (choice) {
		case Display:
			if (passProfile[index].TotalC() == 0){
				cout << "\nThe movie queue is empty! Please add movies to the queue." << endl << endl;
			}
			else{
				queueDisplay(index, passProfile);
			}
			break;
		case Add:
			addMovie(index, passProfile);
			break;
		case Edit:
			
			break;
		case Remove:

			break;
		case Search:

			break;
		case Exit:
			menu = false;
			cout << endl;
			break;
		default:
			cout << "Invailed choice. Try again.";
			break;
		}
	}
}

void addMovie(unsigned short index, DoublyLinkedProfile& passProfile) {
	string name, rating, category;
	unsigned short year, rank;

	cin.ignore(); // Allows spaces
	cout << "\nEnter movie name: ";
	getline(cin, name);

	// Check if year is reasonable
	while(true) {
		cout << "Enter year: ";
		cin >> year;

		if(year < 1800 || year > 2100) {
			cout << "Not a valid year. Try again." << endl;
			continue;
		}
		else {
			break;
		}
	}

	cin.ignore();
	cout << "Category: ";
	getline(cin, category);

	// Checks if rating is possible 
	while(true) {
		cout << "Rating (PG, PG-13, G, R, NC-17): ";
		getline(cin, rating);

		if ((rating != "PG") && (rating != "PG-13") && (rating != "G") && (rating != "R") && (rating != "NC-17")) {
			cout << "Invailed rating. Try again." << endl;
			continue;
		}
		else {
			break;
		}
	}

	// Checks if ranking is possible
	while(true) { 
		cout << "Ranking (1-5): ";
		cin >> rank;

		if(rank < 0 || rank > 5) {
			cout << "Invailed rank. Try again." << endl;
			continue;
		}
		else {
			break;
		}
	}

	cout << endl << endl;
	Movie film(name, rating, category, year, rank); // Create movie object
	passProfile[index].addCategory(film); // Inserts category to profile's list
	unsigned short find = passProfile[index].getIndex(category); // Finds position of category
	passProfile[index].addMovie(film, find); //adds a movie to the appropriate category
	cout << "Movie added to the Queue!" << endl;
}

void queueDisplay(unsigned short index, DoublyLinkedProfile& passProfile) {
	enum Menu{Highest = 1, Lowest, FilterR, FilterC, Sorted, Exit}; // Menu of how to display the movies
	unsigned short choice = 0;
	bool menu = true;
	bool exists = true;
	string command;

	while(menu) {
		queueOption();
		cout << endl << "Enter Option: ";
		cin >> choice;

		if(choice < 1 || choice > 6) {
			continue;
		}

		switch(choice) {
			case Highest:
				break;
			
			case Lowest:
				break;

			case FilterR:
				cin.ignore(); // Allows spaces

				while(true) {
					cout << "Enter Rating (PG, PG-13, G, R, NC-17): ";
					getline(cin, command);

					if ((command != "PG") && (command != "PG-13") && (command != "G") && (command != "R") && (command != "NC-17")) {
						cout << "Invailed rating. Try again." << endl;
					}
					else {
						break;
					}
				}
				filter(index, passProfile, choice, command); // Filters for inquiry
				break;
			case FilterC:
				cin.ignore(); // Allows spaces
				cout << "Enter Category: ";
				getline(cin, command);
				filter(index, passProfile, choice, command); // Filters for inquiry
				break;
			case Sorted:
				break;

			case Exit:
				menu = false; // Returns back to profile menu
				cout << endl;
				break;
			default:
				cout << "Invailed choice. Try again";
				break;
		}
	}
}

void filter(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice, string command) {
	enum Filter{Rating = 3, Category}; // two types of filters
	unsigned short track = 0;
	vector<Movie> temp(track + 1);

	for(unsigned short i = 0; i < passProfile[index].TotalC(); i++){
		for(unsigned short j = 0; j < passProfile[index].totalMovies(i); j++) {
			temp.resize(track + 1);
			Movie t = passProfile[index].getMovie(i, j);
			temp[track] = t;
			track++;
		}
	}

	cout << endl;
	switch(choice) {
	case Rating:
		cout << "The movie(s) in your Queue for Rating " << command << " are displayed below." << endl;
		cout << "---------------------------" << endl;
		for (unsigned short i = 0; i < temp.size(); i++) {
			if (temp[i].getRating() == command) {
				cout << temp[i];
				cout << "---------------------------" << endl;
			}
		}
		break;
	case Category:
		cout << "The movie(s) in your Queue for category " << command << " are displayed below." << endl;
		cout << "---------------------------" << endl;
		for (unsigned short i = 0; i < temp.size(); i++) {
			if (temp[i].getCat() == command) {
				cout << temp[i];
				cout << "---------------------------" << endl;
			}
		}
		break;
	}
}