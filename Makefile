all: main

main: main.cpp Entity.cpp Directory.cpp File.cpp FileSystem.cpp
	g++ main.cpp Entity.cpp Directory.cpp File.cpp FileSystem.cpp -o FileSys
