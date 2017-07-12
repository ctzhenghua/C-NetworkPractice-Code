#include <iostream>
#include <string>
#include <cstring>
#include <vector>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <sys/types.h>


#include <thread>
using namespace std;

// what is needed in EPOLL?
/*
	1.create
	2.control Event
		Add 
		Remove
	3.wait
 */


// what is Event?
/*
	1.read
	2.write
*/


/*
	Epoll Stuff
*/
// Epoll  Event Process Loop
   static void  do_epoll(int listenfd);
// Add    Epoll Event
   static void  add_event(int epollfd,int fd,int state);
// Delete Epoll Event
   static void  delete_event(int epollfd, int fd, int state);
// Modify Epoll Event
   static void  modify_event(int epollfd, int fd, int state);
// Event Handler
   static void  handle_events(int epollfd, struct epoll_event* events, int num, int clientfd, char *buf);
// Handle Read  Event
   static void  do_read(int epollfd, int fd, int sockfd, char *buf);
// Handle Write Event
   static void  do_write(int epollfd, int fd,int sockfd,  char *buf);

int main(int argc, char *argv[])
{
#define IP "127.0.0.1"
#define PORT 8888
	int client;
	sockaddr_in  serverAddr;

	client = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr(IP);

	
	char buf[1024];
	connect(client,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
	cout<<"connnected"<<endl;
	
	do_epoll(client);
	cout<<"Client  Exit!\n";
	return 0;
}


static void do_epoll(int clientfd)
{
	int epollfd;
	vector<struct epoll_event> events(2);
	int ret;
	char buf[1024];
	memset(buf,0,1024);

	// Create An Epoll Discription
	epollfd = epoll_create1(EPOLL_CLOEXEC);
	// Add Listen Event
	add_event(epollfd,STDIN_FILENO,EPOLLIN);
	while(true)
	{
		ret = epoll_wait(epollfd, &*events.begin(),static_cast<int>(events.size()),-1);
		if(ret == events.size())
			events.resize(ret*2);
		handle_events(epollfd, &*events.begin(), ret, clientfd, buf);
	}
	close(epollfd);
}

static void add_event(int epollfd,int fd, int state)
{
	struct epoll_event ev;
	ev.events = state;
	ev.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_ADD, fd, &ev);
}


static void delete_event(int epollfd,int fd, int state)
{
	struct epoll_event ev;
	ev.events = state;
	ev.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_DEL, fd, &ev);
}


static void modify_event(int epollfd,int fd, int state)
{
	struct epoll_event ev;
	ev.events = state;
	ev.data.fd = fd;
	epoll_ctl(epollfd, EPOLL_CTL_MOD, fd, &ev);
}

static void handle_events(int epollfd, struct epoll_event *events, int num, int sockfd, char* buf)
{
	int fd;
	for(int i = 0; i < num; ++i)
	{
		fd = events[i].data.fd;
		if(events[i].events & EPOLLIN)
			do_read(epollfd,fd,sockfd,buf);
		else if(events[i].events & EPOLLOUT)
			do_write(epollfd,fd,sockfd,buf);
	}
}


static void do_read(int epollfd, int fd,int sockfd, char* buf)
{
	int nread;
	nread = read(fd, buf, 1024);
	if(nread == -1)
	{
		cout <<"read Error" <<endl;
		close(fd);
		delete_event(epollfd, fd, EPOLLIN);
	}
	else if(nread == 0)
	{
		cout << "Server Closed!" <<endl;
		close(fd);
		delete_event(epollfd, fd, EPOLLIN);
	}
	else
	{
		if(fd == STDIN_FILENO)
			add_event(epollfd, sockfd, EPOLLOUT);
		else
		{
			delete_event(epollfd,sockfd, EPOLLIN);
			add_event(epollfd,STDOUT_FILENO, EPOLLOUT);
		}
	}
}

static void do_write(int epollfd, int fd,int sockfd, char* buf)
{
	int nwrite;
	nwrite = write(fd, buf,strlen(buf));
	if(nwrite == -1)
	{
		cout << "write Error!\n";
		close(fd);
	}
	else
	{
		if(fd == STDOUT_FILENO)
			delete_event(epollfd,fd, EPOLLOUT);
		else 
			modify_event(epollfd,fd,EPOLLIN);
	}
	memset(buf, 0, 1024);
}
