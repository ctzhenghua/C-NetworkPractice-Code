#ifndef _NODE_
#define _NODE_
class Node{
public:	
	int key;
	Node *next;
public:
	Node()=default;
	Node(int _key):key(_key),next(nullptr){}
};

#endif
