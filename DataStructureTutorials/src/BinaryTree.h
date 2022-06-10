#pragma once
#include <iostream>

class Node
{
public:
	Node* lchild;
	int data;
	Node* rchild;
};

class Queue
{
private:
	int front; 
	int rear; 
	int size;
	Node** Q;
public:
	Queue() { front = rear = -1; size = 10; Q = new Node * [size]; }
	Queue(int size)
	{
		front = rear = -1; 
		this->size = size;
		Q = new Node * [this->size];
	}
	void enqueue(Node* x);
	Node* dequeue();
	void display();


	~Queue() { delete[] Q; }
};

