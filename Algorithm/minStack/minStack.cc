#include <iostream>
#include <stack>  
using namespace std;  
  
class MinStack {  
private:   
    stack<int> content;  
    stack<int> mins;  
public:  
    void push(int x) {  
        content.push(x);  
        //must add =, duplicate elements.  
        if(mins.empty() || x <= mins.top())  
            mins.push(x);  
    }  
  
    void pop() {  
        int top = content.top();  
        content.pop();  
        if(top == mins.top())  
        {  
            mins.pop();  
        }  
    }  
  
    int top() {  
        return content.top();  
    }  
  
    int getMin() {  
        return mins.top();  
    }  
};  

int main()
{
	MinStack test;
	test.push(3);
	test.push(4);
	test.push(3);
	cout << test.getMin() <<endl;
	test.pop();	
	cout << test.getMin() <<endl;
	test.pop();
	cout << test.getMin() <<endl;
	return 0;
}
