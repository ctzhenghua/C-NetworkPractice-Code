#include "ThreadTest.h"
#include <iostream>
using namespace std;

void createFunc(int num){cout<<"create A thread By Func and the arg is" << num <<endl;}

struct createClass{
	void memFunc(int num)
	{
		cout<<"create A thread By Class Mem Func  and the arg is" << num <<endl;
	}
};

void ThreadTest::create_UsingFunc()
{
	allThread.push_back(new thread(createFunc,5));
}

void ThreadTest::create_UsingLamda()
{
	allThread.push_back( new thread(
					[](int num)
					{
						cout <<"create A thread By Lamda and the arg is"<<num<<endl;
					}
					,4)
			   );
}

void ThreadTest::create_UsingClassMemFunc()
{
	createClass tmp;
	allThread.push_back(new thread(
					&createClass::memFunc,		
					tmp,
					3
					)
			   );
}

void ThreadTest::run()
{	
	for(auto d:allThread)
	{
		d ->join();
	}
}

void ThreadTest::release()
{
	for(auto& d:allThread)
	{
		delete d;
	}
}
