#include <iostream>
#include <vector>
#include <initializer_list>
using namespace std;

class Test{
	public:
		// Constructor
		Test():constNum(1){}
		Test(initializer_list<int> args):constNum(1)
		{
			for(auto value: args)
				values.push_back(value);
		}
		Test(const Test& other):constNum(1)
		{
			values.clear();
			for(auto d: other.values)
				values.push_back(d);
		}

		// Can not change in Method
		int getFirst() const{return values.front();}  

		// Can not change the return value
		const int& getConstFirst(){return values.front();}


	public:
		vector<int> values;
		// const variable initialize list-> Constructor
		const int constNum;
		static int staticNum;
};

int Test::staticNum = 2;

int main()
{
	Test test = {4, 5, 6, 7};

	cout << "int getFirst() const :"<< test.getFirst() << endl;
	cout << "const int getConstFirst() :"<< test.getConstFirst() << endl;
	cout << "const Num:" << test.constNum <<endl;
	cout << "staticNum:" << Test::staticNum << endl;
	return 0;
}
