#include "LinkedList.h"

void printLinkedList(Node* node)
{
	Node* tmp = node;
	while (tmp != nullptr)
	{
		std::cout << tmp->getValue() << "->";
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
}

Node* reverseLinkedList(Node* node)
{
	if (node == nullptr || node->getNext() == nullptr)
		return node;
	Node* p = reverseLinkedList(node->getNext());
	node->getNext()->setNext(node);
	node->setNext(nullptr);
	return p;	
}

Node* mergeSortedLinkedList(Node* nodeA, Node* nodeB)
{
	if (nodeA == nullptr) return nodeB;
	if (nodeB == nullptr) return nodeA;
	
	if (nodeA->getValue() <= nodeB->getValue())
	{
		nodeA->setNext(mergeSortedLinkedList(nodeA->getNext(), nodeB));
		return nodeA;
	}
	else
	{
		nodeB->setNext(mergeSortedLinkedList(nodeA, nodeB->getNext()));
		return nodeB;
	}
}

void linkedListtest()
{
	Node* n1 = new Node(1);
	Node* n2 = new Node(2);
	Node* n3 = new Node(3);
	Node* n4 = new Node(4);
	Node* n5 = new Node(5);

	n1->setNext(n2);
	n2->setNext(n3);
	n3->setNext(n4);
	n4->setNext(n5);

	Node* m1 = new Node(50);
	Node* m2 = new Node(60);
	Node* m3 = new Node(70);
	Node* m4 = new Node(80);
	Node* m5 = new Node(90);

	m1->setNext(m2);
	m2->setNext(m3);
	m3->setNext(m4);
	m4->setNext(m5);


	printLinkedList(n1);
	auto mergeSorted = mergeSortedLinkedList(n1, m1);
	printLinkedList(mergeSorted);
	auto reverse = reverseLinkedList(mergeSorted);
	printLinkedList(reverse);

}

