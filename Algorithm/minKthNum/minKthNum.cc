#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

struct Node{
	int key;
	int index;
	Node(int k, int i):key(k),index(i){}
};

struct NodeCmp{
	bool operator() (const Node& a,const Node& b)const
	{
		return a.key < b.key;
	}
};

struct NodeIndexCmp{
	bool operator() (const Node& a,const Node& b)const
	{
		return a.index > b.index;
	}
};


int main()
{
	int n,k;
	cin >> n >> k;
	
	priority_queue<Node, vector<Node>, NodeCmp > heap; //=  pri.. heap
	for(int i = 0; i < n; ++i)
	{
		int tmp;
		cin >> tmp;
		if(i >= k)
		{
			if(tmp < heap.top().key)
			{
				heap.pop();
				heap.push(Node(tmp,i));
			}
		}
		else heap.push(Node(tmp,i));
	}

	priority_queue<Node, vector<Node>, NodeIndexCmp> result;
	for(int i = 0; i < k; ++i)
	{
		result.push(heap.top());
		heap.pop();
	}

	for(int i = 0; i < k; ++i)
	{
		cout << result.top().key <<endl;
		result.pop();
	}
}
