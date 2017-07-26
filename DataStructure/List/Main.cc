#include <iostream>
#include "LinkedList.h"


int main()
{
	LinkedList link;
	link.Build();
	link.Print();
	//link.Reverse();
	//link.Print();
	//link.findReverseKth();
	//link.findMid();
	link.printReversely();
	link.Release();
	return 0;
}
