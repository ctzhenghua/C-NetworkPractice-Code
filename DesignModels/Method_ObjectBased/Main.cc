#include "Thread.h"
void count_func()
{
	int count = 3;
	while(count--)
		cout<<"global func no Arg "<<count<<endl;
}

void count_func_withArgs(int count)
{
	while(count--)
	{
		cout<<"global func with Args"<<count<<endl;
	}
}

class Foo{
public:
	Foo(int count_):count(count_){cout<<"test class"<<endl;}
	void MemberFunc()
	{
		while(count--)
		cout<<"class with func no args"<<count<<endl;
	}	
	void MemberFunc_withArgs(int x)
	{
		while(x--)
		cout<<"class with func with args"<<x<<endl;
	}
private:
	int count;
};

int main()
{
	Foo foo(3);
	Thread* t = new Thread(count_func);
	Thread* t2 = new Thread(bind(count_func_withArgs,3));
	// 使用相同对象，如果两个函数实用相同的变量，会存在竞争
	Thread* t3 = new Thread(bind(&Foo::MemberFunc,&foo));
	Thread* t4 = new Thread(bind(&Foo::MemberFunc_withArgs,&foo,3));
	t->Start();
	t2->Start();
	t3->Start();
	t4->Start();
	t3->Join();
	t->Join();
	t2->Join();
	t4->Join();
	return 0;
}
