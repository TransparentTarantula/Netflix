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
		header = temp;
		tail = temp;
	}

	unsigned short size() { //returns the number of categories
		return track;
	}

	bool same(Type& other) {
		if (track > 0) {
			Node* h = header;
			for (short i = 0; i < track; i++) {
				if (h->data == other) {
					return true;
				}
				h = header->next;
			}
			return false;
		}
		else
			return false;
	}

	void insert(Type& temp) {//makes everything but the head a category
		if (track == 0) {
			header->data = temp;
			tail->data = temp;
			header->next = nullptr;
			track++;
			return;
		}
		else if (track > 0) {
			if (same(temp) != true) {
				Node* t = new Node;
				t->data = temp;
				Node* head = header;
				while (head->next != nullptr) { //goes to the end of the list to add a 
					head = head->next;
				}
				head->next = t;
				t->next = nullptr;
				track++;
			}
		}
	}

	Type& getHead() { //gets the profile at the beginning
		return header->data;
	}

	Type& getTail() { //gets the profile are the end
		Node* head = header;
		while (head->next != nullptr) {
			head = head->next;
		}
		return head->data;
	}

	Type& operator[](const unsigned short index) { //allows the calling of profile as an array
		if (index < track && index >= 0) {
			Node* temp = header;
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
	}

private:
	struct Node { //creation of a singly linked list structure
		Type data; //following data is the category
		Node* next;
	};
	unsigned short track; //keep track of the number of categories
	Node* header; //head of the list
	Node* tail; //tail of the list
};

#endif //!category_hpp
