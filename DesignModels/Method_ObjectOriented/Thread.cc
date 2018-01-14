#include "Thread.h"

void Thread::Start()
{
	pthread_create(&threadId, NULL, Thread_routine, this);	
}

void Thread::Join()
{
	pthread_join(threadId, NULL);
}


void* Thread::Thread_routine(void * arg)
{
	Thread* thread = static_cast<Thread*>(arg);
	thread->run();
	delete thread;
	return NULL;
}	
