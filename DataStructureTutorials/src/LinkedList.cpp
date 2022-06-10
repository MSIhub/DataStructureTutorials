#include "LinkedList.h"

Node* createLinkedList(int * A, int n)
{
	int i; 
	Node* tmp;
	head = (Node*)malloc(sizeof(Node));
	head->setValue(A[0]);
	head->setNext(nullptr);
	tail = head;

	for (i = 1; i < n; i++)
	{
		tmp = new Node(A[i]);
		tmp->setNext(nullptr);
		tail->setNext(tmp);
		tail = tmp;
	}
	return head;
}

bool isLoop()
{
	Node* p, * q;
	p = q = head;
	do
	{
		p= p->getNext();
		q = q->getNext();
		q = q ? q->getNext() : q;
	} while (p && q && p != q);
	return (p = q) ? true : false;
}

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


void printLinkedListRecursive(Node* node)
{
	if (node != NULL)
	{
		std::cout << node->getValue() << "->";
		printLinkedListRecursive(node->getNext());
	}
}

int count(Node* node)//O(n) Time, O(1) space
{
	int ct = 0;
	while (node != nullptr)
	{
		ct++;
		node = node->getNext();
	}
	return ct;
}



int countRecursive(Node* node)//O(n) Time, O(n) space (call stack)
{
	int x = 0;
	if (node)
	{
		x = count(node->getNext());
		return x + 1;
	}
	else
		return x;
}

int addLinkedList(Node* node)
{
	int sum = 0;
	while (node)
	{
		sum += node->getValue();
		node = node->getNext();
	}
	return sum;
}

int addLinkedListRecursion(Node* node)
{
	int sum = 0;
	if (node)
	{
		sum = addLinkedListRecursion(node->getNext());
		return  sum + node->getValue();
	}
	else
		return sum;
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

int MaximumElementLinkedlist(Node* p)
{
	int max = INT_MIN;
	while (p)
	{
		if (p->getValue() > max)
			max = p->getValue();
		p = p->getNext();
	}
	return max;
}

int MaximumElementLinkedlistRecursive(Node* p) 
{
	int x = 0;
	if (p == nullptr)
		return INT_MIN;
	x = MaximumElementLinkedlistRecursive(p->getNext());
	return (x > p->getValue()) ? x : p->getValue();
}


void insertAt(int iVal, int iIdx)
{
	Node* iNode = new Node(iVal);
	Node* p = head;
	if (iIdx < 0||iIdx > count(p))
		return;

	if (iIdx == 0)//insert at head
	{
		iNode->setNext(p);
		p = iNode;
		return;
	}
	int itr = 1;
	while (p && itr < iIdx-1)
	{
		p = p->getNext();
		itr++;
	}
	
	iNode->setNext(p->getNext());
	p->setNext(iNode);
}

void InsertLast(int x)
{
	Node* iNode = new Node(x);
	if (head == nullptr)
		head = tail = iNode;
	else
	{
		tail->setNext(iNode);
		tail = iNode;
	}
}

Node* searchLinear(Node * p, int key)
{//with Move to Head improvement
	Node* q = nullptr;
	while (p)
	{
		if (p->getValue() == key)
		{
			q->setNext(p->getNext());
			p->setNext(head);
			head = p;
			return p;
		}

		q = p;
		p = p->getNext();
	}
	return nullptr;
}

Node* searchLinearRecursion(Node* p, int key)
{
	if(p == nullptr) return nullptr;
	if (p->getValue() == key) return p;
	return searchLinearRecursion(p->getNext(), key);
}


void insertSortLinkedList(int x)
{
	Node* iNode = new Node(x);
	Node* p = head;
	if (head == nullptr)
	{
		head = iNode;
		return;
	}
	if (x < head->getValue())
	{
		iNode->setNext(head);
		head = iNode;
		return;
	}
	while (p->getNext() && (p->getNext())->getValue() < x)
		p = p->getNext();
	iNode->setNext(p->getNext());
	p->setNext(iNode);
}

int deleteAt(int dIdx)
{
	Node* p, * q;
	int retVal = -1, idx = 0;

	if (dIdx == 1)
	{
		retVal = head->getValue();
		p = head;
		head = head->getNext();
		delete p;
	}
	else
	{
		p = head;
		q = nullptr;
		for (idx = 0; idx < dIdx - 1 && p; idx++)
		{
			q = p;
			p = p->getNext();
		}
		if (p)
		{
			q->setNext(p->getNext());
			retVal = p->getValue();
			delete p;
		}
	}
	return retVal;
}


bool isSorted()
{
	Node* p = head;
	int prevVal = INT_MIN;
	while (p != nullptr)
	{
		if (p->getValue() < prevVal)
			return false;
		prevVal = p->getValue();
		p = p->getNext();
	}
	return true;
}

void removeDuplicateSorted()
{
	//check for empty LL and just 1 LL
	Node* p = head;
	
	while (p->getNext() != nullptr)
	{
		Node* q = p->getNext();
		if (p->getValue() != q->getValue())
		{
			p = p->getNext();
			q = q->getNext();
		}
		else
		{
			p->setNext(q->getNext());
			delete q;
		}
	}
}

void reverseSlidingNode()
{
	Node* p = head;
	Node* q = nullptr;
	Node* r = nullptr;
	tail = head;
	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->getNext();
		q->setNext(r);
	}
	head = q;
}

void reverseSlidingNodeRecursive(Node* p, Node* q)
{
	if (q)
	{
		reverseSlidingNodeRecursive(q, q->getNext());
		q->setNext(p);
	}
	else
		head = p;
}

void concatLinkedLists()
{

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

void linkedListtest2()
{
	
	int A[] = { 3,4,7, 10,15 };
	Node * n1 = createLinkedList(&A[0], 5);
	printLinkedList(n1);
	std::cout << std::endl;
	printLinkedListRecursive(n1);
	std::cout <<"\n" << count(n1) << std::endl;
	std::cout <<"\n" << countRecursive(n1) << std::endl;
	std::cout <<"\n" << addLinkedList(n1) << std::endl;
	std::cout <<"\n" << addLinkedListRecursion(n1) << std::endl;
	std::cout <<"\n" << MaximumElementLinkedlist(n1) << std::endl;
	std::cout << "\n" << MaximumElementLinkedlistRecursive(n1) << std::endl;

	/*Node* temp = nullptr;
	temp = searchLinear(n1, 7);
	temp = searchLinear(n1, 15);
	if (temp != nullptr)
		std::cout << "\nKey found: " << temp->getValue() << std::endl;
	else
		std::cout << "key not found" << std::endl;*/

	printLinkedList(head);

	//insertAt(55, 2);
	//printLinkedList(head);
	InsertLast(54);
	printLinkedList(head);
	insertSortLinkedList(16);
	
	printLinkedList(head);
	std::cout << "Deleted element: " << deleteAt(4) << std::endl;
	insertSortLinkedList(54);
	insertSortLinkedList(5);
	insertSortLinkedList(5);
	insertSortLinkedList(5);
	printLinkedList(head);

	std::cout <<std::boolalpha <<isSorted() << std::endl;
	std::cout << std::noboolalpha;

	removeDuplicateSorted();
	printLinkedList(head);
	reverseSlidingNode();
	printLinkedList(head);
	reverseSlidingNodeRecursive(nullptr, head);
	printLinkedList(head);

	////Creating a LOOP in the node
	//Node* t1, * t2;
	//t1 = head->getNext()->getNext();
	//t2 = head->getNext();
	//while (t2->getNext()!=nullptr)
	//	t2 = t2->getNext();

	//t2->setNext(t1);
	std::cout << std::boolalpha << "IsLoop: " << isLoop() << std::endl;
	std::cout << std::noboolalpha;
	




}