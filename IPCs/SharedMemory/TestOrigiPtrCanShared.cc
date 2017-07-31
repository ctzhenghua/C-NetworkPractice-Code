#include <iostream>
#include <mutex>
#include <memory>
#include <unistd.h>

using namespace std;

int main()
{
	shared_ptr<int> ptr(new int(1));
	mutex mut;
	pid_t child;

	if(fork() == 0)
	{
		//child
		for(int i = 0; i < 1000; ++i)
		{
			lock_guard<std::mutex> l(mut);
			cout <<"Child: " <<(*ptr)++<< " count is "<< ptr.use_count() <<endl;
		}
	}

	
	for(int i = 0; i < 1000; ++i)
	{
		lock_guard<std::mutex> l(mut);	
		cout <<"Parent: "<< (*ptr)++ << " count is "<< ptr.use_count()<<endl;	
	}
	return 0;
}

