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
		CircularLinkedList_state{2,6,5},
		CircularLinkedList_state{5,8,6},
		CircularLinkedList_state{6,2,5}
	));
