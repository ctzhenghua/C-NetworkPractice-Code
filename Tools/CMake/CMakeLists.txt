#项目的名称
	project(Main)
	
#限定CMake版本
	cmake_minimum_required(VERSION 2.6)
		
#指明本项目包含的一个子目录
	add_subdirectory(src)
	
	
#将当前目录中的源文件名称赋值给变量DIR_SRCS
	aux_source_directory(. DIR_SRCS)
	
	
#指示需要编译成的可执行文件的名称  如 -o
	add_executable(Main ${DIR_SRCS})
	
	
#指明可执行文件 需要链接的库
	Target_link_libraries(Main Test)
