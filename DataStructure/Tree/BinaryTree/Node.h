#ifndef _NODE_
#define _NODE_
class Node{
public:	
	int key;
	Node *left;
	Node *right;
public:
	Node()=default;
	Node(int _key):key(_key),left(nullptr),right(nullptr){}
};

#endif
