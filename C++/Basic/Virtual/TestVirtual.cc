#include <iostream>
using namespace std;
class super{
	public:
		super(int i):a(i){cout <<"constructor -I am super!\n";}
		virtual ~super(){cout << "DeCon- I am super\n";}
		virtual void someMethod(){cout <<"Hello Super!\n";}
	private:
		int a;
};

class sub: public super{
	public:
		sub():super(1){cout <<"constructor -I am Sub!\n";}
		virtual ~sub(){cout << "DeCon- I am Sub\n";}
		virtual void someMethod()override{cout <<"hello Sub\n";}
		virtual void otherMethod(){cout <<"sub other\n";}
};

int main()
{
	super *test = new sub();

	cout << "using super pointer to use override method:" ;
	test->someMethod();

	//this can not compile
	//cout << "using super pointer to use new sub method :" ;
	//test -> otherMethod();

	delete test;
	return 0;
}
