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
	Category() { //creates the Category list
		Node* temp = new Node;
		head = temp;
		tail = temp;
	}

	unsigned short size() { //returns the number of categories
		return track;
	}

	bool same(Type& other) {    //function checks to see if category already exists
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

	void insert(Type& temp) {//makes everything but the head a category
		if (track == 0) {
			head->data = temp;
			tail->data = temp;
			head->next = nullptr;
			track++;
			return;
		}
		else if (track > 0) {
			if (same(temp) != true) {
				Node* t = new Node;
				t->data = temp;
				Node* h = head;
				while (h->next != nullptr) { //goes to the end of the list to add a category
					h = h->next;
				}
				h->next = t;
				t->next = nullptr;
				track++;
			}
		}
	}

	Type& getHead() { //gets the profile at the beginning
		return head->data;
	}

	Type& getTail() { //gets the profile at the end
		Node* h1 = head;
		while (h1->next != nullptr) {
			h1 = h1->next;
		}
		return h1->data;
	}

	Type& operator[](const unsigned short index) { //allows the calling of profile as an array
		if (index < track && index >= 0) {
			Node* temp = head;
			for (unsigned short i = 0; i < index; i++) {
				temp = temp->next;
			}
			if (temp != nullptr) {
				return temp->data;
			}
		}
		else {
			throw out_of_range("Out of Range");
		}
        Node *temp = head;
        return temp->data;
	}

private:
	struct Node { //creation of a singly linked list structure
		Type data; //following data is the category
		Node* next;
	};
	unsigned short track; //keep track of the number of categories
	Node* head; //head of the list
	Node* tail; //tail of the list
};



#endif 
