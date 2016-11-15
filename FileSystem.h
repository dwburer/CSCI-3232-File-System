#include <string>
#include "Directory.h"
#include "Entity.h"

#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

class FileSystem {
protected:
	Directory* currentDirectory;
public:
	FileSystem(Directory* d);
	void list();
	void changeDirectory(string dir);
	string getWorkingDirectory();
};

#endif