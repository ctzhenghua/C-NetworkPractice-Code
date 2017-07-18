#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;


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

void HeapAdjust(int *a, int i,int size)
{
	int lchild = 2*i; // left child sequnce Num
	int rchild = 2*i+1; // right

	int max = i; // Temparay Value For Exchange The Position
	if(i <= size/2)
	{
		if(lchild <= size && a[lchild] > a[max])
		{
			max = lchild;
		}
		if(rchild <= size && a[rchild] > a[max])
		{
			max = rchild;
		}
		if(max != i)
		{
			swap(a[i], a[max]);
			HeapAdjust(a,max,size);
		}
	}
}
/*
	Complete Binary Tree

	a:Binary Tree Array
	size:array size
 */
void BulidHeap(int *a, int size)
{
	for(int i = size/2; i >= 1; --i)    // if a Node is not a Leaf, then the seqence num will greater than size/2 
	{
		HeapAdjust(a, i, size);
	}
}

void HeapSort(int *a, int size)
{
	BulidHeap(a, size);
	for(int i = size; i >= 1; --i)
	{
		swap(a[1], a[i]);	// change The HeapTop with Array Last
		HeapAdjust(a, 1, i-1);
	}
}
int main()
{
	vector<int > number;
	int n, temp;

	cout << "Please input quality: " <<endl;
	cin >> n ;
	cout << "Please input Each Number!" <<endl;

	number.push_back(0); // To Imit the sequence 0;
	for(int i = 0; i < n; ++i)
	{
		cin >> temp;
		number.push_back(temp);
	}

	HeapSort(&number[0], static_cast<int>(number.size()-1));
	print(number);
	return 0;
}
