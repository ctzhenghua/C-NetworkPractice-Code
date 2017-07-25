#include "Node.h"

class LinkedList{
public :
	Node* head;
	int k;
	
public:
	LinkedList():head(nullptr),k(3){}	
	/*
		Famous List Question Here
	 */
	void Print();
	void Build();
	void Release();
	void Reverse();
	void findReverseKth();
	void findMid();
};
