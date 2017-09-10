#include <iostream>
#include <vector>
using namespace std;

class Solution {
	public:		    
		int minNumberInRotateArray(vector<int> rotateArray)
		{
			if(rotateArray.size() == 0)
				return 0;
			else
			{
				return DivideAndConquer(0,rotateArray.size()-1, rotateArray);			
			}
	        }
	private:
		int DivideAndConquer(int begin, int end, vector<int>& arr)
		{
			int result;
			while(begin < end)
			{
				int mid = (begin+end)/2;
				if(arr[mid] > arr[mid+1])
				{
					result = arr[mid+1];
					break;
				}
				else if(arr[begin] <= arr[mid])
					begin = mid+1;
				else
					end = mid;

			}
			return result;
		}
};

int main()
{
	Solution t;
	vector<int> arr={3,4,5,1,2};
	cout << t.minNumberInRotateArray(arr) <<endl;
	return 0;
}
