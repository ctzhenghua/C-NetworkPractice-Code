#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
/*
	Compare Two nearly And Exchange
 */
void QuickSort(vector<int>& number, int left, int right)
{
	// Define the first Element as Pivot
	if(left < right)
	{
		int pivot = number[left];
		int pivot_index = left;
		int i = left, j = right;

		// Define End Condition
		while(i < j)
		{
			// From The Last Element To Find A Lesser Value
			while(j>i)
			{
				if(number[j] < pivot)
				{
					//swap(number[j],number[pivot_index]);
					number[pivot_index] = number[j];
					pivot_index = j;
					break;
				}
				--j;
			}

			// To Find A Greater Value
			while(i<j)
			{
				if(number[i] > pivot)
				{
					//swap(number[i],number[pivot_index]);
					number[pivot_index] = number[i]; 
					pivot_index = i;
					break;
				}
				++i;
			}
		}
		number[i] = pivot;
		QuickSort(number,left,i-1);
		QuickSort(number,i+1, right);
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

	QuickSort(number,0, n-1);
	print(number);
	return 0;
}
