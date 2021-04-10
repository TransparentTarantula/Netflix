#ifndef category_hpp
#define category_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include <exception>
#include "movieType.hpp"

using namespace std;

class Category {
public:
	// Creates the category list
	Category() {
		track = 0;
		head = nullptr;
		tail = nullptr;
	} 

	// Returns the number of categories
	unsigned short size() {
		return track;
	} 

	// Checks if there's a preexisting category
	bool same(Type& item) {
		if (track > 0) {
			Node* temp = head;

			for(short i = 0; i < track; i++) {
				if(temp->data == item) {
					return true;
				}
				temp = temp->next;
			}
			return false; // If no matches are found
		}
		else {
			return false;
		}
	}

	// Insert category into singly linked list at the end
	void insert(Type& item) {
		Node *temp = new Node;
		temp->data = item;
		temp->next = nullptr;

		if(track == 0) { // Adds to the linked list for the first time
			head = temp;
			tail = temp;
			track++;
		}
		else { // Adds at the end of the linked list
			if(same(item) != true) {
				tail->next = temp;
				tail = tail->next;
				track++;
			}
		}
	}

	// Returns the head of the list
	Type& getHead() {
		return head->data;
	}

	// Returns the tail of the list
	Type& getTail() {
		return tail->data;
	}

	// Allows the calling of category as an array
	Type& operator[](const unsigned short index) {
		if(index < track && index >= 0) {
			Node* temp = head;

			for(unsigned short i = 0; i < index; i++) {
				if(temp != nullptr) {
					return temp->data;
				}	
				temp = temp->next;
			}
		}
		else {
			throw out_of_range("Out of Range");
		}
	}

private:
	struct Node {
		Type data;
		Node* next;
	};

	unsigned short track;
	Node* head;
	Node* tail;
};

#endif // !category_hpp