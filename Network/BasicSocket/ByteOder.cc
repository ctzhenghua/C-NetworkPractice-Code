#include <iostream>
using namespace std;


void byteoder()
{
	union
	{
		short value;
		char bytes[sizeof(short)];
	}test;

	test.value = 0x0102;
	

	if(test.bytes[0] == 1 && test.bytes[1] == 2)
		cout << "big endian" <<endl;
	
	else if(test.bytes[0] == 2 && test.bytes[1] == 1)
		cout << "little endian" <<endl;
	
	else cout <<" Unkown type" <<endl;
}

int main()
{
	byteoder();
	return 0;
}
