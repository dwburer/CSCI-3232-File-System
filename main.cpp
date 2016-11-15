#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"
#include "File.h"
#include "FileSystem.h"

using namespace std;

void parseCommand(string c, FileSystem &f) {
	string arg[2];
	if(c.find(" ") != string::npos) {
		arg[0] = (c.substr(0, c.find(" ")));
	} else {
		arg[0] = c;
	}
	if(c.length() > arg[0].length()) {
		arg[1] = (c.substr((c.find(" ") + 1), c.length()));
	}
	if(!arg[0].compare("ls")) {
		f.list();
	} else if(!arg[0].compare("cd")) {
		cout << "|" << arg[1] << "|";
		f.changeDirectory(arg[1]);
	//} else if(!cmd.compare("mkfs")) {
		//f.makefilesystem();
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
