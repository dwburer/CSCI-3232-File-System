#include <string>
#include "Directory.h"
#include "Entity.h"

#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

class FileSystem {
protected:
	Directory* currentDirectory;
	Directory* root;
public:
	bool isFormatted;
	FileSystem(Directory* d);
	void makeFileSystem();
	void list();
	void changeDirectory(string dir);
	void makeDirectory(string dir);
	void removeDirectory(string dir);
	void status(string name);
	void makeFile(string filename);
	void removeFile(string filename);
	void stat(string filename);
	string getWorkingDirectory();
};

#endif