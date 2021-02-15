#pragma once
#include <stdio.h>
#include <stdexcept>
#include <exception>

using namespace std;

//pofile - category - movies each have doublylinkedlist
template <typename Type>
class DoublyLinkedList {
public:
	DoublyLinkedList() {
		n = 0;
		header  = nullptr;
		trailer = nullptr;
	}
	~DoublyLinkedList() {

	}
	unsigned int size() {
		return n;
	}
	bool isEmpty() {
		return n == 0 ? true : false;
	}
	void insert(Type& e) {
		/*bool tempBool{ true };
		if (n == 0) {
			Node* temp = new Node;
			header = temp;
			trailer = temp;
			temp->data = e;
			temp->next = nullptr;
			temp->prev = nullptr;
			n++;
			tempBool = false;
		}
		else {
			t = header;
			for (unsigned short i = 0; i < n; i++) {
				if (t->data == e) {
					t->data = e;
					tempBool = false;
				}
				t = t->next;
			}
			if (tempBool == true) {
				Node* temp = new Node;
				temp->data = e;
				temp->next = nullptr;
				temp->prev = trailer;
				temp->prev->next = temp;
				trailer = temp;
				n++;
			}
		}*/
	}
	unsigned int find(Type& e) {
		/*bool temp = true;
		t = header;
		for (unsigned short i = 0; i < n; i++) {
			if (t->data == e) {
				temp = false;
				return i;
			}
			t = t->next;
		}
		if (temp == true) {
			throw exception("exception");
		}
		return 0;*/
	}
	void erase(unsigned int index) {
		/*erases movie from a person's profile*/
	}

	/*void show() {
	useles function
	}*/

	void sort() {
		/*sorts movies!*/
	}

	Type& getHead() {
		return this->header->data;
	}

	Type& getTail() {
		return this->trailer->data;
	}

	Type& operator[](const unsigned int index) {
		this->temp = this->header;
		for (int i = 0; i < index; i++) {
			if (this->temp == nullptr) {
				throw out_of_range("out of range biatch");
				break;
			}
			temp = temp->next;
		}
		return temp->data;
	}

private:
	struct Node {
		Type data;
		Node* prev;
		Node* next;
	};

	unsigned int n;
	Node* header;
	Node* trailer;
	Node* temp;
};