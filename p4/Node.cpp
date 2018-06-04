#include <iostream>
using namespace std;

#include "Node.h"

Node::Node(int val)
{
	value = val;
	left = NULL;
	right = NULL;
}

Node::~Node()
{
	cout << "cleaning node: " << value << endl;
	delete left;
	delete right;
}

int Node::getValue()
{
	return value;
}

Node* Node::getLeft()
{
	return left;
}

Node* Node::getRight()
{
	return right;
}

void Node::setLeft(Node* l)
{
	left = l;
}

void Node::setRight(Node* r)
{
	right = r;
}
