CC =	g++
CFLAGS = -Wall -std=c++1y
SRC = $(wildcard src/*.cpp) 
#main.cpp win32_helper.cpp player.cpp mem_find.cpp
t7hook: 
	$(CC) $(CFLAGS) -o bin\t7hook.exe $(SRC)