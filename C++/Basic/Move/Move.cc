#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> all;
	string str = "Hello";

	all.push_back(str);
	cout<< "After Copy, str is " << str << "And push a " << *all.rbegin() << endl;

	all.push_back(std::move(str));
	cout<< "After Move, str is " << str << "And push a " << *all.rbegin() << endl;

	return 0;
}
