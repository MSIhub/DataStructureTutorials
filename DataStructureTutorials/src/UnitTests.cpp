#include "UnitTests.h"
// Setup test fixtures
class CircularlinkedListTest : public ::testing::Test
{
private:
	int* A = new int[]{ 2, 3, 4, 5, 6 };
	
public:
	CircularLinkedList* circList;

	CircularlinkedListTest()
	{
		circList = new CircularLinkedList(&A[0], 5);
	}



	virtual ~CircularlinkedListTest()
	{
		delete circList;
	}

};
TEST_F(CircularlinkedListTest, assertGetHead)
{
	EXPECT_EQ(2, circList->getHead()->getValue());
}

struct CircularLinkedList_state
{
	int headValue;
	int tailValue;
	int size;

	friend std::ostream & operator << (std::ostream & os, const CircularLinkedList_state & obj)
	{
		os << "Head: " << obj.headValue << " Tail: " << obj.tailValue << " Size: " << obj.size;
		return os;
	}
};

class CircularLinkedListTest1 : public CircularlinkedListTest, public testing::WithParamInterface<CircularLinkedList_state>
{};

TEST_P(CircularLinkedListTest1, isLinkedListValid)
{
	auto as = GetParam();
	EXPECT_EQ(circList->getHead()->getValue(), as.headValue);
	EXPECT_EQ(circList->getTail()->getValue(), as.tailValue);
	EXPECT_EQ(circList->length(), as.size);
}

INSTANTIATE_TEST_SUITE_P(MyGroupTest, CircularLinkedListTest1,
	testing::Values(
		CircularLinkedList_state{2,6,5}
	//	,CircularLinkedList_state{5,8,6},
	//	CircularLinkedList_state{6,2,5}
	));

#pragma region Insert test
// Setup test fixtures
class cll_test_b : public ::testing::Test
{
private:
	int* A = new int[] { 22, 43, 44, 55, 56 };
public:
	CircularLinkedList* circList;
	cll_test_b()	{circList = new CircularLinkedList(&A[0], 5);}
	virtual ~cll_test_b()	{delete circList;}
};


struct cll_insert_state 
{
	int index;
	int x;

	friend std::ostream& operator << (std::ostream& os, const cll_insert_state& obj)
	{
		os << "Index: " << obj.index << ",  x: " << obj.x;
		return os;
	}
};

class cll_test : public cll_test_b, public testing::WithParamInterface<cll_insert_state>
{
};

TEST_P(cll_test, insertTest)
{
	auto as = GetParam();
	circList->insertAt(as.index, as.x);
	EXPECT_EQ(circList->seek(as.index), as.x);
}

INSTANTIATE_TEST_SUITE_P(cll_test_gp, cll_test, testing::Values(
	cll_insert_state{0,66},
	cll_insert_state{1,76},
	cll_insert_state{2,86},
	cll_insert_state{3,96},
	cll_insert_state{4,106},
	cll_insert_state{5,116}
));

#pragma endregion