#include <thread>
#include <vector>
using namespace std;

class ThreadTest{
private :
	vector<thread*> allThread;

public:
	ThreadTest(){}
	~ThreadTest(){}


public:
	void create_UsingFunc();
	void create_UsingLamda();
	void create_UsingClassMemFunc();




	void run();	
	void release();	
};
