#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"
#include "File.h"
#include "FileSystem.h"

using namespace std;

// FileSystem constructor
FileSystem::FileSystem (Directory* d) : isFormatted(false) {
	root = d;
	currentDirectory = root;
}

// List contents of current directory
void FileSystem::list() {
	cout << "Contents of " << currentDirectory->getName() <<":\n";

	map<string, Entity*>::iterator it;

	for(it = currentDirectory->children.begin(); it != currentDirectory->children.end(); it++ ) {
		if(it->second->isDirectory)
			cout << "[" + it->first + "]" << "   ";
		else
			cout << it->first << "   ";
	}

	cout << endl;
}

// Get current directory
Directory* FileSystem::getCurrentDirectory() {
	return currentDirectory;
}

// Make/format FileSystem for use
void FileSystem::makeFileSystem() {
	root->flushDirectory();
	currentDirectory = root;
	isFormatted = true;
	cout << "New file system created" << endl;
}

// Change current directory to parent or child directory
void FileSystem::changeDirectory(string dir) {
	if(!dir.compare("..")) {
		if(currentDirectory->hasParent) {
			currentDirectory = currentDirectory->getParent();
		} else {
			cout << dir << ": Invalid directory" << endl;
		}
	} else if(currentDirectory->contains(dir)){
		Entity* newDir = currentDirectory->children[dir];

		if(newDir->isDirectory) {
			currentDirectory = (Directory*) newDir;
			cout << "Current directory is now " << currentDirectory->getName() << endl;
		} else {
			cout << dir << ": Is not a directory" << endl;
		}
	} else {
		cout << "The requested destination does not exist " << endl;
	}
}

// Make a new directory
void FileSystem::makeDirectory(string dir) {
	if(!currentDirectory->contains(dir)) {
		Directory* tmp = new Directory(dir);
		currentDirectory->addChild(tmp);
		cout << "Directory " << dir << " created at " << tmp->getTime();
	} else {
		cout << "Error: directory " << dir << " already exists" << endl;
	}
}

// Remove an existing directory
void FileSystem::removeDirectory(string dir) {
	
	if(currentDirectory->contains(dir)) {
		if(currentDirectory->children[dir]->isDirectory) {

			Directory* toDelete = (Directory*)(currentDirectory->children[dir]);

			if(toDelete->children.size() == 0) {
				cout << "Deleting directory " << dir << endl;
				delete currentDirectory->children[dir];
				currentDirectory->children.erase(dir);
			} else {
				cout << "Error: \"" << dir << "\" is not empty" << endl;
			}
		} else {
			cout << "Error: \"" << dir << "\" is a file, not a directory" << endl;
		}
	} else {
		cout << dir << ": No such directory found" << endl;
	}
}

// Make a new file
void FileSystem::makeFile(string filename) {
	if(!currentDirectory->contains(filename)) {
		File* tmp = new File(filename);
		currentDirectory->addChild(tmp);
		cout << "File " << filename << " created at " << tmp->getTime();
	} else {
		cout << "Error: file " << filename << " already exists" << endl;
	}
}

// Remove an existing file
void FileSystem::removeFile(string filename) {

	if(currentDirectory->contains(filename)) {
		if(!currentDirectory->children[filename]->isDirectory) {
			cout << "Deleting file " << filename << endl;
			delete currentDirectory->children[filename];
			currentDirectory->children.erase(filename);
		} else {
			cout << "Error: " << filename << " is a directory, not a file" << endl;
		}
	} else {
		cout << filename << ": No such file found" << endl;
	}
}

// Print file status information
void FileSystem::stat(string filename) {
	if(currentDirectory->contains(filename)) {
		cout << "File " << currentDirectory->children[filename]->getName() << " created " << currentDirectory->children[filename]->getTime();
	} else {
		cout << filename << ": No such file found" << endl;
	}
}

// Get absolute path to current directory
string FileSystem::getWorkingDirectory() {
	string dir = currentDirectory->getName();
	Directory* backtrack = currentDirectory;

	while(backtrack->hasParent) {
		backtrack = backtrack->getParent();
		dir = backtrack->getName() + "/" + dir;
	}

	return !dir.compare("/") ? dir : dir.substr(1, dir.size());
}
