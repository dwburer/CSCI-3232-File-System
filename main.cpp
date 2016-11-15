#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"
#include "File.h"
#include "FileSystem.h"

using namespace std;

void parseCommand(string c, FileSystem &f) {
	if(!c.compare("ls")) {
		f.list();
	} else if(!c.compare("cd")) {
		f.changeDirectory("photos");
	} else {
		cout << c << ": command not found." << endl;
	}
}

int main() {

	bool running = true;
	string command;
	
	Directory root("/");
	root.addChild(*(new File("apple")));
	root.addChild(*(new File("slapple")));
	root.addChild(*(new File("grapple")));
	root.addChild(*(new Directory("photos")));

	FileSystem system(&root);

    while(running) {
    	cout << "prompt@CSCI-3232:" << system.getWorkingDirectory() << "$ ";
    	getline(cin, command);
    	parseCommand(command, system);
    }
    
}