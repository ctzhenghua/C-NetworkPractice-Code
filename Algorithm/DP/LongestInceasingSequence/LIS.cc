#include <queue>
#include <iostream>

using namespace std;

struct Node{
	int key;  //Array[i]
	int m;    //Max Left Len
	Node(int k, int _m):key(k),m(_m){}
};

struct NodeCmp{
	bool operator() (const Node& a, const Node& b)const
	{
		if(a.m < b.m)
			return true;
		else if(a.m == b.m)
			return a.key > b.key;
		else return false;	
	}
};

int main()
{
	int num[] = {10, 9, 2, 5, 3, 7, 101, 18};
	vector<int> nums(num, num+sizeof(num)/sizeof(int)); 
	priority_queue<Node, vector<Node>, NodeCmp> max_mANDmin_a;
	max_mANDmin_a.push(Node(nums[0],1));
	for(int i = 1; i < nums.size(); ++i)
	{
		cout <<"top key" <<max_mANDmin_a.top().key << " m:"<<max_mANDmin_a.top().m<<endl;
		if(nums[i] > max_mANDmin_a.top().key)		
			max_mANDmin_a.push(Node(nums[i],max_mANDmin_a.top().m+1));
		else max_mANDmin_a.push(Node(nums[i],1));
	}
	cout << max_mANDmin_a.top().m <<endl;
}
