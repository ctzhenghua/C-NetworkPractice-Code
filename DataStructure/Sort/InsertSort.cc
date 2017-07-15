#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


void Foward(vector<int>& number, int i)
{
	auto t = number.end();
	number.push_back(*t);
	cout <<"Test"<<  number.size() <<endl;
	for(int j = static_cast<int>(number.size()-1); j > i; --j)
		number[j] = number[j-1];
}

/*
 	Find a position to insert a num;
 */
void InsertSort(vector<int>& number, int& temp)
{
	int i = 0;
	for( ; i < static_cast<int>(number.size()) && (temp >= number[i]); ++i);
	
	if(number.size() == 0)
		number.push_back(temp);
	else if(number.size() == i)
		number.push_back(temp);
	else 
	{
		Foward(number,i);		
		number[i] = temp;
	}
}
void print(vector<int>& number)
{
	/*
		std::ostream_iterator<int> out_it (std::cout,", ");
		std::copy (number.begin(), number.end(), out_it );

	 */
	
	std::for_each(number.begin(), number.end(), [](int& x) 
	{
	    cout << x << " ";
	});
	cout << endl;
}
int main()
{
	vector<int > number;
	int n, temp;

	cout << "Please input quality: " <<endl;
	cin >> n ;
	cout << "Please input Each Number!" <<endl;

	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		InsertSort(number,temp);
	}

	print(number);
	return 0;
}
