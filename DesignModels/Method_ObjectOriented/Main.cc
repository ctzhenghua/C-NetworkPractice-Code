#include "Thread.h"
#include "DerivedThread.h"

int main()
{
	CountThread *t = new CountThread(3);
	t->Start();
	t->Join();
	return 0;
}
