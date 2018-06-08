/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 4
	Description - This program has a constructor, destructor, getLeft, 
	getRight, getValue, setLeft, setRight. There are three instance 
	variables for the node class. The instance variables are an 
	integer value, a node pointer called left, and a node pointer 
	called right. This program gives the ability to access each of the 
	instance variables and to set the left and right nodes. Lastly, 
	this program deletes the left and right node pointers.
*/

#include <iostream>
using namespace std;

#include "Node.h"
/*
	Node - this is the constructor for the class. It is given an 
	integer. Value is then set to equal the integer given. Left and 
	right are set to null.
*/
Node::Node(int val)
{
	value = val;
	left = NULL;
	right = NULL;
}

/*
	~Node - this is the destructor for the class. It deletes the left 
	and right node pointer instances.
*/
Node::~Node()
{
	cout << "cleaning node: " << value << endl;
	delete left;
	delete right;
}

/*
	getValue - Has no parameters and returns the value of the node.
*/
int Node::getValue()
{
	return value;
}

/*
	getLeft - has no parameters and returns the left node pointer.
*/
Node* Node::getLeft()
{
	return left;
}

/*
	getRight - has no parameters and returns the right node pointer.
*/
Node* Node::getRight()
{
	return right;
}

/*
	setLeft - is given a node pointer and sets left equal to it. 
	Does not return anything.
*/
void Node::setLeft(Node* l)
{
	left = l;
}

/*
	setRight - is given a node pointer and sets right equal to it. 
	Does not return anything.
*/
void Node::setRight(Node* r)
{
	right = r;
}
