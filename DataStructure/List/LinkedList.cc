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
	this->tmp = head;
}

void LinkedList::Release()
{
	Node *tmp;
	while(head != nullptr)
	{
		tmp = head;
		head = head->next;
		delete tmp;
	}
}

void LinkedList::Reverse()
{
	if(head == nullptr)
		return;
	
	Node* pre = nullptr, *cur = head, *next = nullptr;
	while(cur != nullptr)
	{
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	head = pre;
}

void LinkedList::findReverseKth()
{
	int i = 0;
	Node* tmp = head, *nodeK = head;
	while(i != k)
	{
		tmp = tmp ->next;
		++i;
	}
	while(tmp != nullptr)
	{
		tmp = tmp->next;
		nodeK = nodeK ->next;
	}
	cout << "Reverse Kth(" << k <<") is: " << nodeK->key <<endl;	
}

void LinkedList::findMid()
{
	Node* doubleHead = head, *singleHead = head;
	while(doubleHead->next != nullptr)	
	{
		doubleHead = doubleHead ->next;
		singleHead = singleHead ->next;

		if(doubleHead->next != nullptr)
			doubleHead = doubleHead ->next;
	}
	cout <<"Mid is " << singleHead->key <<endl;
}

void LinkedList::printReversely()
{
	if(tmp == nullptr)
	{
		tmp = head;
		return;
	}
	else 
	{
		int key = tmp->key;
		tmp = tmp->next;
		printReversely();	
		cout<<key<<" ";
	}
}

bool LinkedList::isContainCircle()
{
	bool flag = false;
	Node* fast = head, *slow = head;

	while(fast != nullptr && fast->next != nullptr)
	{
		fast = fast->next ->next;
		slow = slow->next;

		if(fast == slow)
		{
			flag = true;
			break;
		}
	}

	return flag;
}
