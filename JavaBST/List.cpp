#include <iostream>
#include <cstdlib>
using namespace std;

#include "List.h"

List::List()
{
	head = NULL;
}

List::~List()
{	
	if (head != NULL)
	{
		ListNode *n;
		while (head != NULL)
		{
			n = head;
			while (n->getNext() != NULL)
			{
				n = n->getNext();
			}
			
			delete n;
		}
	}
}

void List::addNode(int value)
{	
	if (head == NULL)
		head = new ListNode(value);
		
	else
	{
		ListNode *n = head;
		while (n->getNext() != NULL)
			n = n->getNext();
			
		n->setNext(new ListNode(value));
	}
}

ListNode *List::search(int value)
{
	if (head == NULL)
		return NULL;
		
	ListNode *n = head;
	while(n->getNext() != NULL && n->getNext()->getValue() != value)
		n = n->getNext();
	
	if (n->getNext()->getValue() == value)
		return n;
		
	return NULL;
}

int List::getLength()
{
	int i = 0;
	
	if (head == NULL)
		return i;
		
	ListNode *n = head;
	while(n->getNext() != NULL)
	{
		i++;
		n = n->getNext();
	}
	
	return i++;
}

void List::printList()
{
	cout << "Here is your list:" << endl;
	
	ListNode *n = head;
	cout << n->getValue() << endl;
	while(n->getNext() != NULL)
	{
		cout << n->getNext()->getValue() << endl;
		n = n->getNext();
	}
}

//void List::sortList()
//{
//	
//}
