#include "Node.h"

class LinkedList{
public :
	Node* head;
	
public:
	LinkedList():head(nullptr){}	
	/*
		Famous List Question Here
	 */
	void Print();
	void Build();
	void Release();
	void Reverse();
};
