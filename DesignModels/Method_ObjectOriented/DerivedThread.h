#ifndef _COUNT_
#define _COUNT_

#include "Thread.h"

class CountThread : public Thread{
public :
	CountThread(int count_): count(count_){cout<<"derivedConstructor"<<endl;}	
	virtual ~CountThread(){cout<<"derivedDeconstructor"<<endl;}

private:
	void run() override
	{
		while(count--)
		{
			cout<<"derived "<<count <<endl;
		}
	}

private:
	int count;
};

#endif
