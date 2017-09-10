#include <iostream>
#include <cstdio>
using namespace std;
void func(const string& str)
{
	if(str.length() <= 0)
		printf("%.2f\n",0);
	else
	{
		int size = 1;
		int sum = 0;
		double num = 1;
		char before = str[0];

		for(int i = 1; i < str.length(); ++i)
		{
			if(str[i] != before)
			{
				before = str[i];
				sum += size;
				size = 1;
				++num;
			}
			else ++size;
		}	
		sum += size;

		printf("%.2f\n",sum/num);
	}
}

int main()
{
	char s[50];
	cin>>s;
	string str(s);
	func(str);
	return 0;
}
