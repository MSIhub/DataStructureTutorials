#pragma once
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

//Self Referential structure
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

class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		this->head = nullptr; 
		this->tail = nullptr;
	}
	LinkedList(int* A, int n);

	~LinkedList() 
	{
		Node* p = this->head;
		while (this->head)
		{
			this->head = this->head->getNext();
			delete p;
			p = this->head;
		}
		delete this->tail;
	};

	Node* getHead() { return this->head; }
	Node* getTail() { return this->tail; }

	void display();
	int length();
	int sum();
	int max();	
	int min();	
	bool isSorted();
	bool isLoop();
	void insertAt(int index, int x);
	void InsertLast(int x);
	int deleteAt(int index);
	void reverse();
	Node* searchLinear(int key);
	void insertSorted(int x);
	void removeDuplicateSorted();
	void concat(LinkedList * n2);
	void mergeSorted(LinkedList* n2);
	Node * reverseRecursion(Node* node);
};

class CircularLinkedList
{
private:
	Node* head; 
	Node* tail;
public:
	CircularLinkedList()
	{
		this->head = nullptr;
		this->tail = nullptr;
	}

	Node* getHead() { return this->head; }
	Node* getTail() { return this->tail; }

	CircularLinkedList(int* A, int n);
	int length();
	void display();
	void insertAt(int index, int x);
	void displayR(Node* p);

};


void linkedListtest();
void CircularlinkedListtest();




#endif // 