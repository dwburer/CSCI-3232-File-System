#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"
#include "File.h"
#include "FileSystem.h"

using namespace std;

FileSystem::FileSystem (Directory* d) {
	root = d;
	currentDirectory = root;
}

void FileSystem::list() {
	cout << "Contents of " << currentDirectory->getName() <<":\n";
	map<string, Entity>::iterator it;
	for(it = currentDirectory->children.begin(); it != currentDirectory->children.end(); it++ ) {
		cout << it->first << "   ";
	}
	cout << endl;
}

void FileSystem::changeDirectory(string dir) {
	Entity* newDir = &(currentDirectory->children[dir]);
	if(newDir->isDirectory) {
		currentDirectory = (Directory*) newDir;
		cout << "switching to " << currentDirectory->getName() << " at " << currentDirectory << endl;
	} else {
		cout << dir << ": no such file or directory" << endl;
	}
}
void FileSystem::makeDirectory(string dir){};
void FileSystem::removeDirectory(string dir){};
void FileSystem::status(string name){};
void FileSystem::makeFile(string filename){};
void FileSystem::removeFile(string filename){};
void FileSystem::exit(){};

string FileSystem::getWorkingDirectory() {
	string dir;

	if(currentDirectory->hasParent) {

	}

	return currentDirectory->getName();
}