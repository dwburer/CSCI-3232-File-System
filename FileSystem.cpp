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

	map<string, Entity*>::iterator it;

	for(it = currentDirectory->children.begin(); it != currentDirectory->children.end(); it++ ) {
		cout << it->first << "   ";
	}

	cout << endl;
}

void FileSystem::makeFileSystem(){
	Directory root("/");
	FileSystem system(&root);
	currentDirectory->flushDirectory();
	cout << "You have created a new file system " << endl;
}

void FileSystem::changeDirectory(string dir) {

	if(!dir.compare("..")) {
		cout << "has parent:" << currentDirectory->hasParent << endl;
		if(currentDirectory->hasParent) {
			currentDirectory = currentDirectory->getParent();
		} else {
			cout << dir << ": no such file or directory" << endl;
		}
	} else {
		Entity* newDir = currentDirectory->children[dir];

		if(newDir->isDirectory) {
			currentDirectory = (Directory*) newDir;
			cout << "switching to " << currentDirectory->getName() << " at " << currentDirectory << endl;
		} else {
			cout << dir << ": no such file or directory" << endl;
		}
	}
}

void FileSystem::makeDirectory(string dir) {
	currentDirectory->addChild(new Directory(dir));
	cout << "adding directory " << dir << endl;
}

void FileSystem::removeDirectory(string dir) {
	
	if(currentDirectory->contains(dir)) {
		if(currentDirectory->children[dir]->isDirectory) {
			cout << "found directory " << dir << " deleting" << endl;
			currentDirectory->children.erase(dir);
		} else {
			cout << "error: \"" << dir << "\" is a file, not a directory." << endl;
		}
	} else {
		cout << dir << ": directory not found" << endl;
	}
}

void FileSystem::status(string name) {}

void FileSystem::makeFile(string filename) {
	cout << currentDirectory->getName() << endl;

	currentDirectory->addChild(new File(filename));

	cout << "adding file " << filename << endl;
}

void FileSystem::removeFile(string filename) {

	if(currentDirectory->contains(filename)) {
		if(!currentDirectory->children[filename]->isDirectory) {
			cout << "found file " << filename << " deleting" << endl;
			currentDirectory->children.erase(filename);
		} else {
			cout << "error: \"" << filename << "\" is a directory, not a file." << endl;
		}
	} else {
		cout << filename << ": file not found" << endl;
	}
}

string FileSystem::getWorkingDirectory() {
	string dir;

	if(currentDirectory->hasParent) {

	}

	return currentDirectory->getName();
}