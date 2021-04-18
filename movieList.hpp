#ifndef movieList_hpp
#define movieList_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include <exception>
#include "movie.hpp"

using namespace std;

class movieList { //singly linked list for the movies
public:
	movieList() { //creates the movie list
		Node* temp = new Node;
		head = temp;
		tail = temp;
	}

	unsigned short size() { //returns the number of movies in a given category
		return track;
	}

	bool check(Movie& other) {
		if (track > 0) {
			Node* h = head;
			for (short i = 0; i < track; i++) {
				if (h->data == other) {
					return true;
				}
				h = head->next;
			}
			return false;
		}
		else
			return false;
	}

	void insert(Movie& temp) {//makes everything but the head a category
		if (track == 0) {
			head->data = temp;
			tail->data = temp;
			head->next = nullptr;
			track++;
			return;
		}
		else if (track > 0)
		{
			if (check(temp) != true) {
				Node* t = new Node;
				t->data = temp;
				Node* h1 = head;
				while (h1->next != nullptr) { //goes to the end of the list to add a new profile
					head = head->next;
				}
				h1->next = t;
				t->next = nullptr;
				track++;
			}
		}
	}

	void erase(unsigned short index) {
		if (index > 0 && index < track) {
			Node* t1 = head;
			for (unsigned short i = 0; i < index - 1; i++) {
				t1 = t1->next;
			}
			Node* t2 = head;
			for (unsigned short i = 0; i < index + 1; i++) {
				t2 = t2->next;
			}
			t2->next = t2;
		}
		else if (index == 0) {
			Node* t = head;
			head = t->next;
		}
		track--;
	}

	Movie& getHead() { //gets the profile at the beginning
		return head->data;
	}

	Movie& getTail() { //gets the profile are the end
		Node* h = head;
		while (h->next != nullptr) {
			h = h->next;
		}
		return h->data;
	}

	Movie& operator[](const unsigned short index) { //allows the calling of profile as an array
		if (index < track && index >= 0) {
			Node* t = head;
			for (unsigned short i = 0; i < index; i++) {
				t = t->next;
			}
			if (t != nullptr) {
				return t->data;
			}
		}
		else {
			throw out_of_range("Out of Range");
		}
	}

private:
	struct Node {
		Movie data; //following data is the movies that have the same category
		Node* next;
	};
	unsigned short track; //number of films 
	Node* head;
	Node* tail;
};

#endif 
