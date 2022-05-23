#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Node {
private:
	int value;
	Node* next = nullptr;
public:
	//default constructor
	Node(int value) { this->value = value; }

	//Accessors (getters)
	Node* getNext() { return this->next; }
	int getValue() { return this->value; }

	//Mutators (setters)
	void setNext(Node* next) { this->next = next; }
	void setValue(int value) { this->value = value; }
};



void printLinkedList(Node* node);

Node* reverseLinkedList(Node* node);

void linkedListtest();
#endif // 