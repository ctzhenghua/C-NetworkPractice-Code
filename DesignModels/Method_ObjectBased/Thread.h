#ifndef _Thread_
#define _Thread_
#include <iostream>
#include <functional>
#include <pthread.h>
#include <unistd.h>

using namespace std;
// 基础类，不使用虚函数
class Thread{
public:
	typedef function<void ()>ThreadFunc;
	Thread(ThreadFunc func_):func(func_){cout<<"base Constructor"<<endl;}
	virtual ~Thread(){cout<<"base Deconstructor"<<endl;}

public:
	void Start();// using pthread_create, so the third type is [[ void* (*start_routine) (void*) ]]  
	void Join(); // using pthread_join
	
private:
	static void* Thread_routine(void* arg);
	void run();


private:
	pthread_t threadId;
	ThreadFunc func;
};

#endif
