#include <iostream>
#include "LinkedList.h"

using namespace std;
void LinkedList::Print()
{
	Node* p = head;
	while(p  != nullptr)
	{
		cout << p->key <<" ";
		p = p->next;
	}
	cout<<endl;
}

void LinkedList:: Build()
{
	head = new Node(-1);
	Node* tmp = head;

	for(int i = 0; i < 10; ++i)
	{
		Node* create = new Node(i);
		tmp -> next = create;
		tmp = create;
	}
}

void LinkedList::Reverse()
{

}

