#include "ThreadTest.h"

int main()
{
	ThreadTest test;
	test.create_UsingFunc();
	test.create_UsingLamda();
	test.create_UsingClassMemFunc();

	test.run();
	test.release();
	return 0;
}
