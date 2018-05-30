#include <iostream>
using namespace std;

#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	cout << "In BinaryTree constructor" << endl;
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	cout << "In BinaryTree destructor" << endl;
}

void BinaryTree::cleanupTree()
{

}

void BinaryTree::cleanupTree(Node *leaf)
{

}

void BinaryTree::addNode(int value)
{
	cout << "adding value: " << value << endl;
    if (root == NULL)
    	root = new Node (value);
    	
    else
    	addNode (value, root);
}

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
    
    else
    {
    	if (leaf->getRight() != NULL)
    		addNode (value, leaf->getLeft());
    		
    	else
    	{
    		Node *branch = new Node(value);
    		leaf->setRight(branch);
    	}
    }
}

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

void BinaryTree::printTree(bool ascending)
{
	if (root != NULL)
	{
		if (ascending == true)
			printTreeAscending(root);
		
		else
			printTreeDescending(root);
	}
	
	cout << "done printing tree." << endl;
}

void BinaryTree::printTreeAscending(Node *leaf)
{
	cout << "========== printing tree ascending ==========" << endl;
	if (leaf != NULL)
		cout << printTreeAscending(leaf->getLeft()) << "\n" << leaf->getValue() << "\n" << printTreeAscending(leaf->getRight());
}

void BinaryTree::printTreeDescending(Node *leaf)
{
	cout << "========== printing tree descending ==========" << endl;
	if (leaf != NULL)
		cout << printTreeDescending(leaf->getRight()) << "\n" << leaf->getValue() << "\n" << printTreeDescending(leaf->getLeft());
}
