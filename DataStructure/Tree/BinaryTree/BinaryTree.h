#include "Node.h"

class BinaryTree{
public :
	Node* head;
	int k;
	
public:
	BinaryTree():head(nullptr),k(3){}	
	~BinaryTree();
	/*
		Famous List Question Here	 
	*/
	void build();

	int nodeNum(Node* Head);
	int height(Node* Head);
	int levelTravel(Node* Head);
	Node* reBuild(int *preOrder, int preStart, int preEnd,
		      int *inOder,   int inStart,  int inEnd);
};
