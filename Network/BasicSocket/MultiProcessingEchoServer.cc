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
	int server;
	int port = 8888;
	int flag = 1;
	sockaddr_in  serverAddr, clientAddr;

	server = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	setsockopt(server,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(int));
	bind(server, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	listen(server,50);

	cout<<"Listening-----"<<endl;

	socklen_t clientAddrLen = sizeof(clientAddr);
	while(1)
	{
		int clientTmp = accept(server,(struct sockaddr*)&clientAddr,&clientAddrLen);
		cout<<inet_ntoa(clientAddr.sin_addr)<<":"<<clientAddr.sin_port<<endl;
		close(clientTmp);
		cout<<"accept and close" <<endl;
		//Fork Something
	}
	return 0;
}
