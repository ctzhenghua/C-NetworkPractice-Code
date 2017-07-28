#include <iostream>
#include <algorithm>
#include "BinaryTree.h"

using namespace std;


void BinaryTree::build()
{
	
	
}

BinaryTree::~BinaryTree()
{


}


int BinaryTree::nodeNum(Node *Head)
{
	if(Head != nullptr)
	return 1 + nodeNum(Head->left) + nodeNum(Head ->right);

	else return 0;
}


int BinaryTree::height(Node *Head)
{
	if(Head == nullptr)
		return 0;

	else 	return max(height(Head->left), height(Head->right)) + 1;	
}
