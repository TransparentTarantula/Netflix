#pragma once
#include <stdio.h>
#include <stdexcept>
#include <exception>

using namespace std;

//profile - category - movies each have doublylinkedlist
template <typename Type>
class DoublyLinkedList {
	public:
	DoublyLinkedList() {
		n = 0;
		header  = nullptr;
		tail = nullptr;
	}
	
	unsigned int size() {
		return n;
	}

	bool isEmpty() {
		return n == 0 ? true : false;
	}

	void insert(Type& item) {
		bool tempBool = true ;
		if (n == 0) {
			Node* node = new Node;
			node->data = item;
			node->next = nullptr;
			node->prev = nullptr;
			header = node;
			current = node;
			tail = node;
			n++;
			tempBool = false;
		}
		else {
			Node* temp = header;
			for (unsigned short i = 0; i < n; i++) {
				if (temp->data == item) {
					temp->data = item;
					tempBool = false;
				}
				temp = temp->next;
			}
			if (tempBool == true) {
				Node* temp = new Node;
				temp->data = item;
				temp->next = nullptr;
				temp->prev = tail;
				temp->prev->next = temp;
				tail = temp;
				n++;
			}
		}

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
		return this->tail->data;
	}

	Type& operator[](const unsigned int index) {
		Node* temp = this->header;
		for (int i = 0; i < index; i++) {
			if (this->temp == nullptr) {
				throw out_of_range("out of range biatch");
				break;
			}
			temp = temp->next;
		}
		return temp->data;
	}

	void getNextNode() {
		current = current->next;
	}

	Type& getCurrentNode() {
		return current->data;
	}

	private:
	struct Node {
		Type data;
		Node* prev;
		Node* next;
	};

	unsigned int n;
	Node* header;
	Node* tail;
	Node* current;
};