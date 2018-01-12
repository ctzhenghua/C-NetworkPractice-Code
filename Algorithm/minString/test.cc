#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

set<int> result;
//DFS
int findMinumString(string str)
{
	for(int i = 0; i < str.length(); ++i)
	{
		for(int j = 1; i+j < str.length() && i-j >= 0; ++j)
		{
			int k = i;
			int len = 1;
			while(str.substr(k,j) == str.substr(i-j,j))
			{
				++len;

				if(k+j < str.length())
					k += j;
				else break;
			}		
			if(j*len > j+to_string(len).length()+2)
			{
				result.insert( i-1 + j+2+to_string(len).length() + findMinumString(str.substr(k,str.length()-1-k)));
			}

		}
	}
	result.insert(str.length());
	return *result.begin();
}

int main()
{
	string str;
	getline(cin, str);
	cout <<findMinumString(str)<<endl;
	return 0;
}
