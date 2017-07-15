#include <iostream>

using namespace std;
int main()
{
	// Test For Right Value Referrence.
	int x = 0;
	int &r1 = x;
	int &&r2 = x++;

	cout << "r1 is :" << r1 <<endl;   // Result is 1
	cout << "r2 is :" << r2 <<endl;	  // Result is 0  which means 'X++' x is a Temparay Value, Then x=x+1 which is a left value;
	return 0;
}
