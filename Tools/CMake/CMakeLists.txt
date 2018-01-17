#项目的名称
	PROJECT(Main)
	
#限定CMake版本
	CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
		
#指明本项目包含的一个子目录
	ADD_SUBDIRECTORY(src)
	
	
#将当前目录中的源文件名称赋值给变量DIR_SRCS
	AUX_SOURCE_DIRECTORY(. DIR_SRCS)
	
	
#指示需要编译成的可执行文件的名称  如 -o
	ADD_EXECUTABLE(Main ${DIR_SRCS})
	
	
#指明可执行文件 需要链接的库
	TARGET_LINK_LIBRARIES(Main Test)
