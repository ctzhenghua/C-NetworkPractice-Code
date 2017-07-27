#include <iostream>
using namespace std;

using Func= void(*)();
class super{
	public:
		super(int i):a(i){cout <<"constructor -I am super!\n";}
		virtual ~super(){cout << "DeCon- I am super\n";}
		virtual void someMethod(){cout <<"Hello Super!\n";}
		virtual void someMethod2(){cout <<"Hello Super 2!\n";}
		

		void normalMethod(){cout << "Hello Super Normal" <<endl;}
		void normalMethod2() const{cout << "Hello Super Normal2" <<endl;}
	private:
		int a;
};

class sub: public super{
	public:
		sub():super(1){cout <<"constructor -I am Sub!\n";}
		virtual ~sub(){cout << "DeCon- I am Sub\n";}
		virtual void someMethod()override{cout <<"hello Sub\n";}
		virtual void someMethod2(){cout <<"hello Sub 2!\n";}
		virtual void otherMethod(){cout <<"sub other\n";}
		
		
		void normalMethod(){cout << "Hello Sub Normal" <<endl;}
		void normalMethod2() const{cout << "Hello Sub Normal2" <<endl;}
};


void testConstructorAndDymamic()
{
	cout <<R"(After--------- super *test = new sub(); the out will be:)" <<endl;
	super *test = new sub();

	cout << "using super pointer to use override method:" <<endl;
	test->someMethod();

	//this can not compile
	//cout << "using super pointer to use new sub method :" <<endl;
	//test -> otherMethod();

	delete test;
}

void testMemoryOfVirtual()
{
	super b(0);
	Func pfun = nullptr;
	//cout << "virtual Table Address:" << (int*)(&b) <<endl;
	//cout << "virtual Table First Func Address:" << (int*) *(int*)(&b) <<endl;
	//pfun = (Func) *((int*) *(int*)(&b));
	//pfun();
}

void g(const super* A)
{
	A -> normalMethod2();
}

void testOverrideAndHiden()
{
	super *b = new sub();
	b -> someMethod();
	b -> normalMethod();
	b -> normalMethod2();	
	g(b);
	delete b;

	sub t;
	t.normalMethod();
	t.normalMethod2();
}
int main()
{
	
	testOverrideAndHiden();
	return 0;
}
