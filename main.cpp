#include <iostream>
#include <vector>

#include "movie.hpp"
#include "profile.hpp"
#include "movieType.hpp"
#include "category.hpp"
#include "doublyLinkedList.hpp"
#include "movieList.hpp"

using namespace std;

void queueMenu(); //movie queue display
void MDisplay(); //ways to display movie
void addprofile(DoublyLinkedProfile& passProfile); //adds profile
void profileDisplay(unsigned short index, DoublyLinkedProfile& passProfile); //profile display Menu
void addMovie(unsigned short index, DoublyLinkedProfile& passProfile); //adds movie
void MovieDisplay(unsigned short index, DoublyLinkedProfile& passProfile); //movie misplay menu
void sort(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice); //displays movies with one of the three sorting methods
void filter(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice, string x); //displays Movies with certain criteria
void remove(unsigned short index, DoublyLinkedProfile& passProfile); //removes a movie from the queue
void search(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice); //search for a movie

int main() {
	unsigned short choice = 0; //user input of the menu
	bool menu = true; //whether or not to continue in the menu
	DoublyLinkedProfile list; //overall profile list

	while (menu) {
		cout << "Welcome to the Netflix Movie Menu! Please select (or create) a profile: " << endl;

		if (list.size() == 0) { //menu when there are no profiles in the list
			cout << "1. Add New Profile" << endl
				 << "2. Exit Program" << endl << endl
				 << "Enter Option: ";
			cin >> choice;

			if (choice == 1) {
				addprofile(list);
			}
			else if (choice == 2) {
				menu = false;
				continue;
			}
			else {
				cout << endl;
				continue;
			}
		}
		else { //menu when there are one of three profiles

			for (unsigned short i = 0; i < list.size(); i++) {
				cout << i + 1 << ". " << list[i] << endl;
			}//displays all profiles created
			cout << (list.size() + 1) << ". " << "Add New Profile" << endl;
			cout << (list.size() + 2) << ". " << "Exit" << endl << endl << "Enter Option: ";
			cin >> choice;

			double x = choice, y = list.size() + 1, z = x / y ; //users input determines how far to move into the menu

			if (z < 1) {//displays the profile choosen
				choice -= 1;
				profileDisplay(choice, list);
				continue;
			}
			else if (z == 1) {//adds a profile
				addprofile(list);
			}
			else { //exits from the program
				menu = false;
				break;
			}
		}
	}
}

void queueMenu() {
	cout << "1. Display Movie Queue" << endl
		<< "2. Add Movie to Queue" << endl
		<< "3. Edit Movie in Queue" << endl
		<< "4. Remove Movie from Queue" << endl
		<< "5. Search for Movie in Queue" << endl
		<< "6. Exit Profile" << endl;
}

void MDisplay() {
	cout << "Display options:" << endl << endl;
	cout << "1. Highest to Lowest Ranking" << endl
		<< "2. Lowest to Highest Ranking" << endl
		<< "3. Filter by Rating" << endl
		<< "4. Filter by Category" << endl
		<< "5. Sorted movie queue" << endl
		<< "6. Exit Display Menu" << endl;
}

void addprofile(DoublyLinkedProfile& passProfile) {
	string first, last, label;
	unsigned short age;
	cin.ignore(); //allows spaces when creating the profile
	cout << "Enter Profile Label: ";
	getline(cin, label);
	cout << "Enter First Name: ";
	getline(cin, first);
	cout << "Enter Last Name: ";
	getline(cin, last);
	cout << "Enter Age: ";
	cin >> age;

	if (passProfile.size() == 0) { //can't copy a profile if one hasn't been previously created
		profile temp(first, last, label, age);
		passProfile.insert(temp); //inserts the profile
	}
	else {
		unsigned short choice = 0;
		cout << "Enter Number of Profile to Copy or 0 to create new profile: ";
		cin >> choice;

		if (choice > 0 && choice < passProfile.size() + 1) { //adds a profile with a movie copy constructor
			profile temp(first, last, label, age, passProfile[choice - 1]);
			passProfile.insert(temp);
			cout << "Profile Created By Copying " << passProfile[choice - 1] << " Profile (" << choice << ")";
			cout << endl << endl << endl;
			return;
		}
		else if (choice == 0) { //creates a new profile with no movies attached
			profile temp(first, last, label, age);
			passProfile.insert(temp);
		}
	}
	cout << endl;
	cout << "Profile Created!" << endl << endl;
}

void profileDisplay(unsigned short index, DoublyLinkedProfile& passProfile) {
	enum Menu { Display = 1, Add, Edit, Remove, Search, Exit }; //displays options
	unsigned choice = 0;
	bool menu = true; //determines whether to leave or stay in this menu
	cout << endl << passProfile[index] << " Movie Queue" << endl << endl;

	while (menu) {
		queueMenu();
		cout << endl << "Enter Option: ";
		cin >> choice;

		if (choice < 1 || choice > 6) { //makes sure that the chosen option is available
			menu = false;
			continue;
		}

		switch (choice) {
		case Display:
			if (passProfile[index].TotalC() == 0) { //can't display if there are no movies
				cout << "The movie queue is empty! Please add a movies to the queue." << endl << endl;
				continue;
			}
			else
				MovieDisplay(index, passProfile); //takes you to the movie display menu
			break;
		case Add:
			addMovie(index, passProfile); //adds a movie
			break;
		case Edit:
			if (passProfile[index].TotalC() == 0) { //can't edit a movie if there are no movies
				cout << "The movie queue is empty! Please add a movies to the queue." << endl << endl;
				continue;
			}
			search(index, passProfile, 1); //searches and edits a movie
			break;
		case Remove:
			if (passProfile[index].TotalC() == 0) {//can't remove a movie if there are none to remove
				cout << "The movie queue is empty! Please add a movies to the queue." << endl << endl;
				continue;
			}
			remove(index, passProfile); //removes a movie
			break;
		case Search:
			if (passProfile[index].TotalC() == 0) { //can't search something that hasn't been created
				cout << "The movie queue is empty! Please add a movies to the queue." << endl << endl;
				continue;
			}
			search(index, passProfile, 0); //search and displays a movie
			break;
		case Exit:
			menu = false; //reverts back to the profile menu
			cout << endl;
			break;
		}
	}
}

void addMovie(unsigned short index, DoublyLinkedProfile& passProfile) {
	string name, rating, category;
	unsigned short year, rank;
	cin.ignore(); //allows spaces in the movie
	cout << "Enter Movie Name: ";
	getline(cin, name);

	while (true) { //makes sure the movies are within a reasonable time frame
		cout << "Enter Year: ";
		cin >> year;
		if (year < 1800 || year > 2100)
			continue;
		else
			break;
	}

	cin.ignore();
	cout << "Category: ";
	getline(cin, category);

	while (true) { //makes sure the rating is real
		cout << "Rating (PG, PG-13, G, R, NC-17): ";
		getline(cin, rating);
		if ((rating != "PG") && (rating != "PG-13") && (rating != "G") && (rating != "R") && (rating != "NC-17")) {
			continue;
		}
		else
			break;
	}

	while (true) {
		cout << "Ranking (1 - 5): "; //makes sure only ranks 1-5 are passed through
		cin >> rank;
		if (rank < 0 || rank > 5) {
			continue;
		}
		else
			break;
	}

	Movie temp(name, year, rating, rank, category); //creates a movie with the input
	Movie t(category); //creates a category
	passProfile[index].addCategory(t); //adds a category to a profile
	unsigned short find = passProfile[index].getIndex(category); //finds the position of the category
	passProfile[index].addMovie(temp, find); //adds a movie to the appropriate category
	cout << endl;
}

void MovieDisplay(unsigned short index, DoublyLinkedProfile& passProfile) {
	enum Menu { Highest = 1, Lowest, FilterR, FilterC, Sorted, Exit }; //menu of how to display the movies
	unsigned short choice = 0;
	bool menu = true; //determines whether to stay or go back to the profile display menu
	//bool exists = true;

	while (menu) {
		MDisplay();
		cout << endl << "Enter Option: ";
		cin >> choice;
		string x; //can't initialize string inside switch statement

		if (choice < 1 || choice > 6) { //makes sure user choice is valid
			menu = false;
			continue;
		}

		switch (choice) {
		case Highest:
			sort(index, passProfile, choice); //takes to the sort menu
			break;
		case Lowest:
			sort(index, passProfile, choice);//takes to the sort menu
			break;
		case FilterR:
			cin.ignore();
			while (true) { //asks which rating to filter by
				cout << "Enter Rating (PG, PG-13, G, R, NC-17): ";
				getline(cin, x);
				if ((x != "PG") && (x != "PG-13") && (x != "G") && (x != "R") && (x != "NC-17")) {
					continue;
				}
				else
					break;
			}
			filter(index, passProfile, choice, x); //filter Function
			break;
		case FilterC:
			cin.ignore();//asks which Category to filter by
			cout << "Enter Category: ";
			getline(cin, x);
			filter(index, passProfile, choice, x); //filter function
			break;
		case Sorted:
			sort(index, passProfile, choice);//takes to the sort menu
			break;
		case Exit:
			menu = false; //returns back to the profile display menu
			cout << endl;
			break;
		}
	}
}

void sort(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice) {
	enum sorting { HL = 1, LH, INSERTION = 5 };
	unsigned short track = 0;
	vector<Movie> temp(track + 1); //puts all the movies into a vector
	for (unsigned short i = 0; i < passProfile[index].TotalC(); i++) {
		for (unsigned short j = 0; j < passProfile[index].totalMovies(i); j++) {
			temp.resize(track + 1);
			Movie t = passProfile[index].getMovie(i, j);
			temp[track] = t;
			track++;
		}
	}
	switch (choice) {
	case HL:
		for (unsigned short i = 0; i < temp.size(); i++) { //sorts the vector by ranking from highest to lowest
			for (unsigned short j = i + 1; j < temp.size(); j++) {
				if (temp[i].getRanking() < temp[j].getRanking()) {
					Movie q = temp[i];
					temp[i] = temp[j];
					temp[j] = q;
				}
			}
		}
		break;
	case LH:
		for (unsigned short i = 0; i < temp.size(); i++) {//sorts the vector by ranking from lowest to highest
			for (unsigned short j = i + 1; j < temp.size(); j++) {
				if (temp[i].getRanking() > temp[j].getRanking()) {
					Movie q = temp[i];
					temp[i] = temp[j];
					temp[j] = q;
				}
			}
		}
		break;
	case INSERTION:
		for (unsigned short i = 1; i < temp.size(); i++) {//sorts the vector alphabetcally using insertion sort
			Movie t = temp[i];
			unsigned short j = i;
			while (j > 0 && temp[j - 1] > t) {
				temp[j] = temp[j - 1];
				j--;
			}
			temp[j] = t;
		}
		break;
	}
	cout << endl << "The movies in your Queue are displayed below." << endl; //displays the movie with the sorting
	cout << "---------------------------" << endl;

	for (unsigned short i = 0; i < temp.size(); i++) {
		cout << temp[i];
		cout << "---------------------------" << endl;
	}
	cout << endl;
}

void filter(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice, string x) {
	enum Filter { Rating = 3, Category }; //two type of filters
	unsigned short track = 0;
	vector<Movie> temp(track + 1); //shoves all the movies into a vector

	for (unsigned short i = 0; i < passProfile[index].TotalC(); i++) {
		for (unsigned short j = 0; j < passProfile[index].totalMovies(i); j++) {
			temp.resize(track + 1);
			Movie t = passProfile[index].getMovie(i, j);
			temp[track] = t;
			track++;
		}
	}
	cout << endl;
	switch (choice) {
	case Rating: //prints out the movies that have the desired rating
		cout << "The movie(s) in your Queue for Rating " << x << " are displayed below." << endl;
		cout << "---------------------------" << endl;
		for (unsigned short i = 0; i < temp.size(); i++) {
			if (temp[i].getRating() == x) {
				cout << temp[i];
				cout << "---------------------------" << endl;
			}
		}
		break;
	case Category: //prints out the movies that have the desired category
		cout << "The movie(s) in your Queue for category " << x << " are displayed below." << endl;
		cout << "---------------------------" << endl;
		for (unsigned short i = 0; i < temp.size(); i++) {
			if (temp[i].getCat() == x) {
				cout << temp[i];
				cout << "---------------------------" << endl;
			}
		}
		break;
	}
}

void remove(unsigned short index, DoublyLinkedProfile& passProfile) {
	string name; unsigned short year;
	cout << endl << "Enter Movie Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Year: ";
	cin >> year;
	passProfile[index].removeM(name, year); //removes the movie of the name and year entered 
	cout << endl << name << " has been removed from your queue!" << endl << endl;
}

void search(unsigned short index, DoublyLinkedProfile passProfile, unsigned short choice) {
	string name; 
	unsigned short year;
	cout << endl << "Enter Movie Name: ";
	cin.ignore();
	getline(cin, name);
	cout << "Enter Year: ";
	cin >> year;
	if (choice == 1) { //searches, displays and edits a desired movie
		Movie t = passProfile[index].SearchM(name, year);
		cout << "---------------------------" << endl << t << "---------------------------" << endl;
		passProfile[index].editM(name, year);
		cout << endl << "Movie has been edited" << endl << endl;
		return;
	}
	Movie t = passProfile[index].SearchM(name, year); //prints out the movie that was asked by name and year
	cout << "---------------------------" << endl << t << "---------------------------" << endl << endl;
}
