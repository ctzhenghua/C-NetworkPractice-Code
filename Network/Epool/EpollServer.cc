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
	Socket Stuff
*/
// Create Socket And Bind to Host
   static int socketCreate(const char* ip, int port);


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
   static void  handle_events(int epollfd, struct epoll_event* events, int num, int listenfd, char *buf);
// Handle SYN   request to Establish NetLink
   static void  handle_accept(int epollfd, int listenfd);
// Handle Read  Event
   static void  do_read(int epollfd, int fd, char *buf);
// Handle Write Event
   static void  do_write(int epollfd, int fd, char *buf);

int main(int argc, char *argv[])
{
#define IP "127.0.0.1"
#define PORT 8888
	int server;
	if(argc == 1)
		server = socketCreate(IP,PORT);
	else if(argc == 2)
		server = socketCreate(argv[1],PORT);
	listen(server,5);
	cout<<"Listening-----"<<endl;
	
	do_epoll(server);
	cout<<"Server Exit!\n";
	return 0;
}

static int socketCreate(const char* ip,int port)
{
	int server, flag = 1;
	sockaddr_in  serverAddr;

	bzero(&serverAddr,sizeof(serverAddr));
	server = socket(AF_INET, SOCK_STREAM, 0);
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(port);
	serverAddr.sin_addr.s_addr = inet_addr(ip);
	
	setsockopt(server,SOL_SOCKET,SO_REUSEADDR,&flag,sizeof(int));
	if(bind(server, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1)
	{
		perror("bind Error!\n");
		exit(1);
	}
	return server;
}

static void do_epoll(int listenfd)
{
	int epollfd;
	vector<struct epoll_event> events(2);
	int ret;
	char buf[1024];
	memset(buf,0,1024);

	// Create An Epoll Discription
	epollfd = epoll_create1(EPOLL_CLOEXEC);
	// Add Listen Event
	add_event(epollfd,listenfd,EPOLLIN);
	while(true)
	{
		ret = epoll_wait(epollfd, &*events.begin(),static_cast<int>(events.size()),-1);
		if((size_t)ret == events.size())
			events.resize(events.size()*2);
		handle_events(epollfd, &*events.begin(), ret, listenfd, buf);
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

static void handle_events(int epollfd, struct epoll_event *events, int num, int listenfd, char* buf)
{
	int fd;
	for(int i = 0; i < num; ++i)
	{
		fd = events[i].data.fd;
		if((fd == listenfd) && (events[i].events & EPOLLIN))
			handle_accept(epollfd, listenfd);
		else if(events[i].events & EPOLLIN)
			do_read(epollfd,fd,buf);
		else if(events[i].events & EPOLLOUT)
			do_write(epollfd,fd,buf);
	}
}


static void handle_accept(int epollfd, int listenfd)
{
	int clifd;
	struct sockaddr_in cliAddr;
	socklen_t cliAddrLen = sizeof(cliAddr);

	clifd = accept(listenfd, (struct sockaddr*)&cliAddr, &cliAddrLen);
	if(clifd == -1)
		perror("Accept Error!\n");
	else
	{
		cout << "accept a new client:" << inet_ntoa(cliAddr.sin_addr) << ":" <<cliAddr.sin_port<<endl;
		add_event(epollfd, clifd, EPOLLIN);
	}

}


static void do_read(int epollfd, int fd, char* buf)
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
		cout << "client Closed!" <<endl;
		close(fd);
		delete_event(epollfd, fd, EPOLLIN);
	}
	else
	{
		cout << "Receive Message:" << buf <<endl;
		modify_event(epollfd, fd, EPOLLOUT);
	}
}

static void do_write(int epollfd, int fd, char* buf)
{
	int nwrite;
	nwrite = write(fd, buf, strlen(buf));
	if(nwrite == -1)
	{
		cout << "write Error\n";
		close(fd);
		delete_event(epollfd, fd, EPOLLOUT);
	}
	else 
		modify_event(epollfd,fd,EPOLLIN);
	memset(buf, 0, 1024);
}
