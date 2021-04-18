#ifndef doubly_hpp
#define doubly_hpp

#include <string>
#include <iostream>
#include <stdio.h>
#include <exception>
#include "profile.hpp"

using namespace std;

class DoublyLinkedProfile { //doubly LinkedList of the profile and not template because only the other lists are singly linked lists.
public:
	DoublyLinkedProfile() { //initializes the list with previous to nullptr
		this->track = 0;
		Node* temp = new Node;
		head = temp;
		tail = temp;
		head->prev = nullptr;
		tail->prev = nullptr;
	}

	unsigned short size() { //returns the number of profiles
		return track;
	}

	void insert(profile& other) { //function to insert profiles
		if (track == 0) {//initializes for the head only
			head->data = other;
			tail->data = other;
			head->next = nullptr;
			head->prev = nullptr;
			track++;
		}
		else {//initializes for anything after the head
			Node* temp = new Node;
			temp->data = other;
			Node* h = head;
			while (h->next != nullptr) { //goes to the end of the list to add a new profile
				h = h->next;
			}
			temp->prev = h;
			h->next = temp;
			temp->next = nullptr;
			track++;
		}
	}

	void erase(unsigned short index) { //remember to subract 1 on the other side when calling because the array starts at 0
		if (index > 0 && index < track) { //deletes profiles that are not at the head
			Node* temp = head;
			for (unsigned short i = 0; i < index - 1; i++) {
				temp = temp->next;  //moving through the linked list until the index is reached
			}
			Node* temp2 = head;
			for (unsigned short i = 0; i < index + 1; i++) {
				temp2 = temp2->next;
			}
			if (temp2 != nullptr) {
				temp->next = temp2;
				temp2->prev = temp; //rearranging pointers
			}
			else {
				temp->next = nullptr;
			}
			track--;
		}
		else if (index == 0) { //deleting head if index is 0
			Node* temp = head;
			head = temp->next;
			delete temp;
			track--;
		}
	}

	profile& getHead() { //gets the profile at the beginning
		return head->data;
	}

	profile& getTail() { //gets the profile at the end
		Node* h = head;
		while (h->next != nullptr) {
			h = head->next;
		}
		return head->data;
	}

	profile& operator[](const unsigned short index) { //allows the calling of profile as an array
		if (index < track && index >= 0) {
			Node* temp = head;
			for (unsigned short i = 0; i < index; i++) {
				temp = temp->next;
			}
			if (index == 0) {
				return temp->data;
			}
			if (temp != nullptr) {
				return temp->data;
			}
		}
		else {
			throw out_of_range("Out of Range");
		}
        Node* temp = head;
        return temp->data;  //typically never reaches here, returns head if it does
	}

private:
	struct Node { //creates the structure node with data, tail and head
		profile data;
		Node* prev;
		Node* next;
	};

	unsigned short track; //keeps track of the number of profiles
	Node* head; //head of the list
	Node* tail; //tail of the list
};

#endif 
