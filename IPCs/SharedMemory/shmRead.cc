#include <unistd.h>
#include <sys/shm.h>
#include "shmData.h"
#include <cstring>
#include <thread>
#include <iostream>

using namespace std;

bool  run = true;

void readFunc()
{
	int shmID;
	shmData *shm = nullptr;
	
	// create Shared Memory
	shmID =  shmget((key_t)1234, sizeof(shmData), 0666|IPC_CREAT);
	if(shmID == -1)
	{	
		cout << "shared Memory Error" <<endl;
		return ;
	}
	
	// map the sharedMomory to Process Momory
	shm = reinterpret_cast<shmData*>( shmat(shmID, 0, 0) );
	shm->written = false; 	

	while(run)
	{
		if(shm -> written)
		{
			cout<< "read :" <<shm->text<<endl;
			shm->written = false;
			if(strcmp(shm->text,"end") == 0 )
				run = false;
		}
		sleep(1);			
	}

	// unregister shm
	if(shmdt(shm) == -1)
	{
		cout <<"shmdt falid" <<endl;
		return ;
	}
	// UnMap the sharedMemory
	if(shmctl(shmID, IPC_RMID, 0) == -1)
	{
		cout <<"shmdt faild" << endl;
		return ;
	}
}

void writeFunc()
{
	int shmID;
	shmData *shm = nullptr;
	
	// create Shared Memory
	shmID =  shmget((key_t)1234, sizeof(shmData), 0666|IPC_CREAT);
	if(shmID == -1)
	{	
		cout << "shared Memory Error" <<endl;
		return ;
	}
	
	// map the sharedMomory to Process Momory
	shm = reinterpret_cast<shmData*>( shmat(shmID, 0, 0) );

	while(run)
	{
		if(shm -> written)
		{
			cout<< "------->waiting read "<<endl;
			sleep(1);
		}
		else
		{
			char buf[1024];
			cin >> buf;

			strcpy(shm->text, buf);
			shm->written = true;

			if(strcmp(buf, "end") == 0)
				run = false;
		}	
	}

	// unregister shm
	if(shmdt(shm) == -1)
	{
		cout <<"shmdt falid" <<endl;
		return ;
	}
}

int main(int agc, char* argv[])
{
	// Because it is IPC, so We need two Process Not thread!
	if(agc != 2)
	{
		cout <<"usage: ./shm read|write" <<endl;
		return -1;
	}
		
	if(strcmp(argv[1],"read") == 0 )
	{
		thread t(readFunc);
		t.join();
	}
	else if(strcmp(argv[1],"write") == 0 )
	{
		thread t(writeFunc);
		t.join();
	}

	return 0;
}


