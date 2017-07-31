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

int BinaryTree::levelTravel(Node* Head)
{
	if(Head == nullptr)
		return;

	queue<Node*> all;
	all.push(Head);

	while(!all.empty())
	{
		cout<<all.front()->key<<endl;
		Node* now = all.front();
		all.pop();

		if(now -> left != nullptr)
			all.push(now -> left);
		if(now ->right != nullptr)
			all.push(now -> right);
	
	}
	return;
}
