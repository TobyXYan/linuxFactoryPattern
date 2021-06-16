###################Simple Make###########################################
#target: dependencies
#	action

#output: main.o message.o
#	g++ main.o message.o -o output
#-o create executable

#main.o: main.cc
#	g++ -c main.cc

#message.o: message.cc message.h
#	g++ -c message.cc
#-c just compile not generate executable
#-c will use x.cc 's name x, and generate x.o
###################Simple Make###########################################

CC = gcc
CXX = g++

# define any compile-time flags
# -fPIC is required for compiling a .so(dll)
#-fvisibility=hidden is required to make methos in .so unexposed
CFLAGS = -Wall -g -fPIC -fvisibility=hidden

# define the C source files
SRCS = Factories.cc Products.cc

OBJS = $(SRCS:.cc=.o)

# define the executable file 
# Note that better to prefix .so with lib, there is a convertion for projects wants to use .so
OUTLIB = libProductsFac.so

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: all copyout clean

all:    $(OUTLIB) copyout
	@echo  Simple compiler named $(OUTLIB) has been compiled

#Here $(MAIN) depends on $(OBJS), if use normal pattern, the following should be 
#$(CXX) -c yy.cc; but here we don't do this one by one, it's implemented by %.o:%.cc
#So we have no souce file to put before -o, but $(OBJS) are reuired to build $(MAIN) along with $(LIBS)
#Hence, $(OBJS) is required to put after -o
# -shared and -fPIC are required for building a .so(dll)
$(OUTLIB): $(OBJS) 
	$(CXX) -shared -fPIC -o $@ $^

# this is a suffix replacement rule for building .o's from .cc's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .cc file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
#
# $< files that caused the action, here are .cc files
# the name of first prerequisite
# It tells GNU make "here's how to build a .o file from a .c file with the same name
%.o:%.cc
	$(CXX) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) *.o *~ $(OUTLIB)

copyout:
	cp $(OUTLIB) ../libs
	cp IFactory.h ../include
	cp Factories.h ../include
	cp IProduct.h ../include
	cp Products.h ../include


# DO NOT DELETE THIS LINE -- make depend needs i


#
#	-o：指定生成可执行文件的名称。使用方法为：g++ -o afile file.cpp file.h ... （可执行文件不可与待编译或链接文件同名，否则会生成相应可执行文件且覆盖原编译或链接文件），如果不使用-o选项，则会生成默认可执行文件a.out。
#   -c：只编译不链接，只生成目标文件。
#-g：添加gdb调试选项。

#CC: Program for compiling C programs; default cc
#CXX: Program for compiling C++ programs; default G++
#CFLAGS: Extra flags to give to the C compiler
#CXXFLAGS: Extra flags to give to the C++ compiler
#CPPFLAGS: Extra flags to give to the C preprosessor
#LDFLAGS: Extra flags to give to compilers when they are supposed to invoke the linker
