#include <iostream>
#include <string>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
using namespace std;

int main()
{
	int client;
	int port = 8888;
	sockaddr_in  serverAddr;


	client = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	
	char buf[1024];
	connect(client,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	cout<<"connnected"<<endl;

	if(read(client, buf,sizeof(buf)) == 0)
	{
		cout<<"closed"<<endl;
		close(client);
	}

	// Some Business
	
	return 0;
}
