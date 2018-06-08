/*
	Jesse Burk
	CS 360 Spring 2018
	Assignment 4
	Description - The purpose of this program is to implement the 
	basic operations for a binary search tree. These operations 
	include a constructor and destructor, insert, search, and 
	print. This program inserts integer data into the tree and 
	is then capable of pinting the tree in either ascending or 
	descending order. This program is also able to search for a 
	value in the tree. The program will print whether the value 
	was found or not. Lastly, this program will clean up any 
	allocated memory used in during the creation of the program.
*/

#include <iostream>
using namespace std;

#include "BinaryTree.h"

/*
	BinaryTree - This is the constructor for BinaryTree. 
	This sets the root equal to NULL.
*/
BinaryTree::BinaryTree()
{
	cout << "In BinaryTree constructor" << endl;
	root = NULL;
}

/*
	~BinaryTree - This is the destructor for BinaryTree. 
	This calls the cleanupTree() function.
*/
BinaryTree::~BinaryTree()
{
	cout << "In BinaryTree destructor" << endl;
	cleanupTree();
}

/*
	cleanupTree() - this calls cleanupTree(Node*) and passes it the 
	root value of the tree. Does not have any parameters and does 
	not return anything.
*/
void BinaryTree::cleanupTree()
{
	cleanupTree(root);
}

/*
	cleanupTree(Node*) - Accepts the root node from the tree 
	and then deletes that node. This function does not return anything.
*/
void BinaryTree::cleanupTree(Node *leaf)
{
	delete leaf;
}

/*
	addNode(int) - This function accepts an integer value to insert as 
	a new node into the binary tree. If the root value is null than 
	this program creates a new node that holds the value given. 
	Otherwise, this program will call addNode(int, Node*). This 
	program does not return anything.
*/
void BinaryTree::addNode(int value)
{
	cout << "adding value: " << value << endl;
    if (root == NULL)
    	root = new Node (value);
    	
    else
    	addNode (value, root);
}

/*
	addNode(int, Node*) - this function accepts a integer value, and a 
	Node pointer. This program will recursively call either the left or 
	right child depending on the value given and will create a new 
	node that holds the value given and places it in the correct 
	position on the tree. This function will not add duplicate values.
*/
void BinaryTree::addNode(int value, Node *leaf)
{
	if (leaf->getValue() > value)
	{
		if (leaf->getLeft() != NULL)
			addNode (value, leaf->getLeft());
		
		else
		{
			Node *branch = new Node(value);
			leaf->setLeft(branch);
		}
	}
    
    else if (leaf->getValue() < value)
    {
    	if (leaf->getRight() != NULL)
    		addNode (value, leaf->getRight());
    		
    	else
    	{
    		Node *branch = new Node(value);
    		leaf->setRight(branch);
    	}
    }
}

/*
	search(int) - this function will test to see if the root value is 
	the same as the integer value given in the parameter list. If so, 
	the value will be found and the program will return a Node 
	pointer. Otherwise, if the root value is null, the program will say 
	so. If the root value is not null and does not hold the same value 
	as the value given, this function calls search(int, Node*).
*/
Node *BinaryTree::search(int value)
{
	cout << "BinaryTree::searching for " << value << endl;
	
	Node *leaf = root;
	Node *q = NULL;
	
	if (leaf != NULL)
	{
		if (leaf->getValue() == value)
		{
			cout << "found it!" << endl;
			q = leaf;
		}
			
		else if (leaf->getValue() > value)
			q = search(value, leaf->getLeft());
		
		else if (leaf->getValue() < value)
			q = search(value, leaf->getRight()); 
	}
	
	else
		cout << "tree empty, value not found" << endl;
	
	return q;
}

/*
	search(int, Node*) - this function accepts an integer value to 
	search for, and a Node pointer to start the search from. if the 
	node given is null then the value was not found. If the value 
	in the node is equal to the value given, the value was found 
	and the program will return the node pointer. If the node is 
	not null and the value does not match the value given, the 
	function recursively calls the left or right child of the 
	current node pointer until the value has been found or 
	reaches a null node.
*/
Node *BinaryTree::search(int value, Node *leaf)
{
	Node *q = NULL;
	
	if (leaf != NULL)
	{
		if (leaf->getValue() == value)
		{
			cout << "found it!" << endl;
			q = leaf;
		}
			
		else if (leaf->getValue() > value)
			q = search(value, leaf->getLeft());
		
		else if (leaf->getValue() < value)
			q = search(value, leaf->getRight()); 
	}
	
	else
		cout << "value not found" << endl;
	
	return q;
}

/*
	printTree - this function is given a boolean value and does 
	not return anything. If the bool is true, the function calls 
	printTreeAscending(). If the bool is false, the function 
	calls printTreeDescending().
*/
void BinaryTree::printTree(bool ascending)
{
	if (root != NULL)
	{
		if (ascending == true)
		{
			cout << "========== printing tree ascending ==========" << endl;
			printTreeAscending(root);
		}
		
		else
		{
			cout << "========== printing tree descending ==========" << endl;
			printTreeDescending(root);
		}
	}
	
	cout << "done printing tree." << endl;
}

/*
	printTreeAscending - this function is given the root node and 
	begins to recursively print the values of each node 
	in ascending order. This function does not return anything.
*/
void BinaryTree::printTreeAscending(Node *leaf)
{
	if (leaf != NULL)
	{
		printTreeAscending(leaf->getLeft()); 
		cout << "val: " << leaf->getValue() << endl; 
		printTreeAscending(leaf->getRight());
	}
}

/*
	printTreeDescending - this function is given the root node and 
	begins to recursively print the values of each node 
	in descending order. This function does not return anything.
*/
void BinaryTree::printTreeDescending(Node *leaf)
{
	if (leaf != NULL)
	{
		printTreeDescending(leaf->getRight()); 
		cout << "val: " << leaf->getValue() << endl;
		printTreeDescending(leaf->getLeft());
	}
}
