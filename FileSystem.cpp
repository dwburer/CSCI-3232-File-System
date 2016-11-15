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
void FileSystem::makeDirectory(string dir){
	currentDirectory->addChild(*(new Directory(dir)));
	cout << "adding directory " << dir << endl;
}
void FileSystem::removeDirectory(string dir){
	map<string, Entity>::iterator it = currentDirectory->children.find(dir);
	if(it != currentDirectory->children.end()){
		cout << "found directory " << dir << " deleting" << endl;
		currentDirectory->children.erase(dir);
	} else {
		cout << "directory not found" << endl;
	}
}
void FileSystem::status(string name){}
void FileSystem::makeFile(string filename){
	cout << currentDirectory->getName() << endl;
	currentDirectory->addChild(*(new File(filename)));
	cout << "adding file" << filename << endl;
}
void FileSystem::removeFile(string filename){
	map<string, Entity>::iterator it = currentDirectory->children.find(filename);
	if(it != currentDirectory->children.end()){
		cout << "found file " << filename << " deleting" << endl;
		currentDirectory->children.erase(filename);
	} else {
		cout << "file not found" << endl;
	}
}

string FileSystem::getWorkingDirectory() {
	string dir;

	if(currentDirectory->hasParent) {

	}

	return currentDirectory->getName();
}