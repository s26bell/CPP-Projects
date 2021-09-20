# Sample Makefile for Project 1
#
# You will need to rename this file to “Makefile” (note the capital M)
# and test it in  the ECE servers, with the command “make” 
# 
# Ensure that after the “make” command an executable with the expected name is 
# created. For this example the expected name for the excecutable is playlistdriver
#

# List all the drivers
all: mstprimdriver

# list the test program all classes (cpp files)
#  cpp files must use #include , to include *.h or *.hpp files

mstprimdriver: mstprimtest.cpp Graph.cpp Vertex.cpp priorityQ.cpp illegal_exception.h
	g++ -std=c++11 -o mstprimdriver mstprimtest.cpp Graph.cpp priorityQ.cpp Vertex.cpp illegal_exception.h

# List all the executables under 'all:'
clean:
	rm mstprimdriver


