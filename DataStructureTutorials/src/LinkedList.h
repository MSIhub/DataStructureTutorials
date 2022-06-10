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

static Node* head = nullptr;
static Node* tail = nullptr;
static Node* second = nullptr;
static Node* third = nullptr;

Node* createLinkedList(int* A, int n);

bool isLoop();

void printLinkedList(Node* node);

int count(Node* node);

int addLinkedList(Node* node);

int addLinkedListRecursion(Node* node);

Node* reverseLinkedList(Node* node);

int MaximumElementLinkedlist(Node* p);

void insertAt(int iVal, int iIdx);

void InsertLast(int x);

Node* searchLinear(Node* p, int key);

void insertSortLinkedList(int x);

int deleteAt(int dIdx);

bool isSorted();

void removeDuplicateSorted();

void reverseSlidingNode();

void reverseSlidingNodeRecursive();

void linkedListtest();
void linkedListtest2();
#endif // 