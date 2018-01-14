#ifndef _Thread_
#define _Thread_
#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;
//抽象基类，所以定义虚析构
class Thread{
public:
	Thread(){cout<<"base Constructor"<<endl;}
	virtual ~Thread(){cout<<"base Deconstructor"<<endl;}

public:
	void Start();// using pthread_create, so the third type is [[ void* (*start_routine) (void*) ]]  
	void Join(); // using pthread_join
	
private:
	static void* Thread_routine(void* arg);
	virtual void run() = 0;


private:
	pthread_t threadId;
};

#endif
