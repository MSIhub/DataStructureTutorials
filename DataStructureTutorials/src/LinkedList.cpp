#include "LinkedList.h"

LinkedList::LinkedList(int * A, int n)
{
	int i; 
	Node* tmp;
	this->head = (Node*)malloc(sizeof(Node));
	this->head->setValue(A[0]);
	this->head->setNext(nullptr);
	this->tail = head;

	for (i = 1; i < n; i++)
	{
		tmp = new Node(A[i]);
		tmp->setNext(nullptr);
		this->tail->setNext(tmp);
		this->tail = tmp;
	}
}

void LinkedList::display()
{
	Node* tmp = this->head;
	while (tmp != nullptr)
	{
		std::cout << tmp->getValue() << "->";
		tmp = tmp->getNext();
	}
	std::cout << std::endl;
}

int LinkedList::length()//O(n) Time, O(1) space
{
	Node* tmp = this->head;
	int ct = 0;
	while (tmp != nullptr)
	{
		ct++;
		tmp = tmp->getNext();
	}
	return ct;
}

int LinkedList::sum()
{
	Node* node = this->head;
	int sum = 0;
	while (node)
	{
		sum += node->getValue();
		node = node->getNext();
	}
	return sum;
}

int LinkedList::max()
{
	Node* p = this->head;
	int max = INT_MIN;
	while (p)
	{
		if (p->getValue() > max)
			max = p->getValue();
		p = p->getNext();
	}
	return max;
}

int LinkedList::min()
{
	Node* p = this->head;
	int min = INT_MAX;
	while (p)
	{
		if (p->getValue() < min)
			min = p->getValue();
		p = p->getNext();
	}
	return min;
}

bool LinkedList::isSorted()
{
	Node* p = this->head;
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

bool LinkedList::isLoop()
{
	Node* p, * q;
	p = q = this->head;
	do
	{
		p= p->getNext();
		q = q->getNext();
		q = q ? q->getNext() : q;
	} while (p && q && p != q);
	return (p = q) ? true : false;
}

void LinkedList::insertAt(int iVal, int iIdx)
{
	Node* iNode = new Node(iVal);
	Node* p = this->head;
	if (iIdx < 0 || iIdx > this->length())
		return;

	if (iIdx == 0)//insert at head
	{
		iNode->setNext(p);
		p = iNode;
		return;
	}
	int itr = 1;
	while (p && itr < iIdx - 1)
	{
		p = p->getNext();
		itr++;
	}

	iNode->setNext(p->getNext());
	p->setNext(iNode);
}

void LinkedList::InsertLast(int x)
{
	Node* iNode = new Node(x);
	if (this->head == nullptr)
		this->head = this->tail = iNode;
	else
	{
		this->tail->setNext(iNode);
		this->tail = iNode;
	}
}

int LinkedList::deleteAt(int dIdx)
{
	Node* p, * q;
	int retVal = -1, idx = 0;

	if (dIdx == 1)
	{
		retVal = this->head->getValue();
		p = this->head;
		this->head = this->head->getNext();
		delete p;
	}
	else
	{
		p = this->head;
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

void LinkedList::reverse()
{
	Node* p = this->head;
	Node* q = nullptr;
	Node* r = nullptr;
	this->tail = head;
	while (p != nullptr)
	{
		r = q;
		q = p;
		p = p->getNext();
		q->setNext(r);
	}
	this->head = q;
}

Node* LinkedList::searchLinear(int key)
{//with Move to Head improvement
	Node* p = this->head;
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

void LinkedList::insertSorted(int x)
{
	Node* iNode = new Node(x);
	Node* p = this->head;
	if (this->head == nullptr)
	{
		this->head = iNode;
		return;
	}
	if (x < this->head->getValue())
	{
		iNode->setNext(this->head);
		this->head = iNode;
		return;
	}
	while (p->getNext() && (p->getNext())->getValue() < x)
		p = p->getNext();
	iNode->setNext(p->getNext());
	p->setNext(iNode);
	//Add function for tail pointer
}

void LinkedList::removeDuplicateSorted()
{
	//check for empty LL and just 1 LL
	Node* p = this->head;
	
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

Node* LinkedList::reverseRecursion(Node* node)
{
	if (node == nullptr || node->getNext() == nullptr)
	{
		this->tail = node;
		return node;
	}
	Node* p = reverseRecursion(node->getNext());
	node->getNext()->setNext(node);
	node->setNext(nullptr);
	return p;
}

void  LinkedList::concat(LinkedList * n2)
{
	if (this->isLoop())
		return;

	Node* p = this->head;
	while(p->getNext() !=nullptr)
		p = p->getNext();
	p->setNext(n2->getHead());
	
	while(p)
		p = p->getNext();
	this->tail = p;
}

void LinkedList::mergeSorted(LinkedList * n2)
{
	Node* outhead, * outtail;
	Node* p = this->head;
	Node* q = n2->getHead();

	if (p->getValue() < q->getValue())
	{
		outhead = outtail = p;
		p = p->getNext();
		outtail->setNext(nullptr);
	}
	else
	{
		outhead = outtail = q;
		q = q->getNext();
		outtail->setNext(nullptr);
	}

	while (p && q)
	{
		if (p->getValue() < q->getValue())
		{
			outtail->setNext(p);
			outtail = p;
			p = p->getNext();
			outtail->setNext(nullptr);
		}
		else
		{
			outtail->setNext(q);
			outtail = q;
			q = q->getNext();
			outtail->setNext(nullptr);
		}
	}
	if (p) outtail->setNext(p);
	if (q) outtail->setNext(q);

	this->head = outhead;
	this->tail = outtail;

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
	
	int A[] = { 3,4,7, 10,15 };
	LinkedList* n1 = new LinkedList(&A[0], 5);
	n1->display();
	std::cout <<"\nLength: " << n1->length() << std::endl;
	std::cout <<"\nSum: " << n1->sum() << std::endl;
	std::cout <<"\nMax: " << n1->max() << std::endl;
	std::cout <<"\nMin: " << n1->min() << std::endl;
	
	Node* temp = nullptr;
	temp = n1->searchLinear(77);
	if (temp != nullptr)
		std::cout << "\nKey found: " << temp->getValue() << std::endl;
	else
		std::cout << "key not found" << std::endl;

	n1->insertAt(55, 4);
	n1->display();
	std::cout << "Deleted element: " << n1->deleteAt(4) << std::endl;
	n1->display();
	n1->insertSorted(16);
	n1->insertSorted(19);
	std::cout << std::boolalpha << n1->isSorted() << std::noboolalpha << std::endl;

	n1->removeDuplicateSorted();
	n1->display();
	//n1->reverse();
	//n1->display();

	////Creating a LOOP in the node
	//Node* t1, * t2;
	//t1 = n1->getHead()->getNext()->getNext();
	//t2 = n1->getHead()->getNext();
	//while (t2->getNext()!=nullptr)
	//	t2 = t2->getNext();

	//t2->setNext(t1);
	std::cout << std::boolalpha << "IsLoop: " << n1->isLoop() << std::noboolalpha << std::endl;

	int B[] = { 51,54,57, 60,65 };
	LinkedList* n2 = new LinkedList(&B[0], 5);
	n2->display();
	/*n1->concat(n2);
	n1->display();*/
	n1->mergeSorted(n2);
	n1->display();

}


/// <summary>
/// Recursive version of the implemented function above
/// </summary>
/// <param name="node"></param>
/*void printLinkedListRecursive(Node* node)
{
	//reverseSlidingNodeRecursive(nullptr, head);
	if (node != NULL)
	{
		std::cout << node->getValue() << "->";
		printLinkedListRecursive(node->getNext());
	}
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
int MaximumElementLinkedlistRecursive(Node* p)
{
	int x = 0;
	if (p == nullptr)
		return INT_MIN;
	x = MaximumElementLinkedlistRecursive(p->getNext());
	return (x > p->getValue()) ? x : p->getValue();
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

Node* searchLinearRecursion(Node* p, int key)
{
	if(p == nullptr) return nullptr;
	if (p->getValue() == key) return p;
	return searchLinearRecursion(p->getNext(), key);
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

*/


#pragma region CircularLinkedList
CircularLinkedList::CircularLinkedList(int * A, int n)
{
	this->head = new Node(A[0]);
	this->head->setNext(head);//head pointing to itself
	this->tail = this->head;

	for (int i = 1; i < n; i++)
	{
		Node* t = new Node(A[i]);
		t->setNext(this->tail->getNext());//tail pointing to head always
		this->tail->setNext(t);
		this->tail = t;
	}

}

int CircularLinkedList::length()//O(n) Time, O(1) space
{
	int ct = 0;
	Node* p = this->head;
	do
	{
		std::cout << p->getValue() << "->";
		ct++;
		p = p->getNext();
	} while (p != this->head);
	return ct;
}


void CircularLinkedList::display()
{
	Node* p = this->head;
	do
	{
		std::cout << p->getValue() << "->";
		p = p->getNext();
	} while (p != this->head);
	std::cout << std::endl;
}


void CircularLinkedList::insertAt(int index, int x)
{

}

void CircularLinkedList::displayR(Node* p)
{
	static int flag = 0;
	if (p != head || flag == 0)
	{
		flag = 1;
		std::cout << p->getValue() << "->";
		displayR(p->getNext());
	}
}

void CircularlinkedListtest()
{
	int A[] = { 2, 3,4 ,5 ,6 };
	CircularLinkedList cl(&A[0], 5);// creating in stack

	cl.display();
	cl.displayR(cl.getHead());
}

#pragma endregion