#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
/*
	Compare Two nearly And Exchange
 */
void PopSort(vector<int>& number)
{
	for(int i = 0; i < static_cast<int>(number.size()-1); ++i)
	{
		for(int j = i+1; j < static_cast<int>(number.size()); ++j)
		{
			if(number[i] < number[j])
			{
				// Exchange
				int tmp;
				tmp = number[i];
				number[i] = number[j];
				number[j] = tmp;
			}
		}
	}

	/*
		std::ostream_iterator<int> out_it (std::cout,", ");
		std::copy (number.begin(), number.end(), out_it );

	 */
	
	std::for_each(number.begin(), number.end(), [](int& x) 
	{
	    cout << ++x << " ";
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
		number.push_back(temp);
	}

	PopSort(number);
	return 0;
}
