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

// Cannot show the level info
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

Node* BinaryTree::reBuild(int *preOrder, int preStart, int preEnd,
		      int *inOder,   int inStart,  int inEnd)
{	
	// Boundary Testing
	if(preOrder == nullptr || inOrder == nullptr)	
		return ;

	Node *root = new Node();
	root->key = preOder[preStart];	
		
	// find the mid in InOrder and count left num
	int count = 0, i = inStart;
	while(inOrder[i] != root->key)
	{
		++count;
		++i;
	}
	
	root->left = reBuild(preOrder, preStart+1, preStart+1+count,
			     inOrder,  inStart, i-1);
	
	root->right = reBuild(preOrder, preStart+1+count, preEnd,
			     inOrder,  i+1, inEnd);

	return root;
}
