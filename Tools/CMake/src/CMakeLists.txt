#将当前目录中的源文件名称赋值给变量DIR_TEST_SRCS
AUX_SOURCE_DIRECTORY(. DIR_TEST_SRCS)
	
#使用该命令将 当前目录中的源文件 编译成共享库
ADD_LIBRARY(Test ${DIR_TEST_SRCS})
