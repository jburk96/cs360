#include <iostream>
#include <cstdlib>
using namespace std;

#include "ListNode.h"

ListNode::ListNode(int val)
{
	value = val;
	nextPtr = NULL;
}

ListNode::~ListNode()
{

}

int ListNode::getValue()
{
	return value;
}

ListNode* ListNode::getNext()
{
	return nextPtr;
}

void ListNode::setNext(ListNode* n)
{
	nextPtr = n;
}

void ListNode::print()
{
	cout << value << endl;
}
