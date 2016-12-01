// CSCI-3232-A File System Emulator project
// Daniel Burer, James Gormley, Katelyn Greer

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stdlib.h>
#include "Directory.h"
#include "Entity.h"
#include "File.h"
#include "FileSystem.h"

using namespace std;

// Parses command and calls approproate FileSystem functions
void parseCommand(string c, FileSystem &f) {
	vector<string> dirArgs;
	string arg[2];
	arg[1] = "/";
	size_t pos = 0;

	if(c.find(" ") != string::npos) {
		arg[0] = (c.substr(0, c.find(" ")));
	} else {
		arg[0] = c;
	}

	if(c.length() > arg[0].length()) {
		arg[1] = (c.substr((c.find(" ") + 1), c.length()));
	}

	if(!arg[0].compare("mkfs")) {
		f.makeFileSystem();
	} else if(!f.isFormatted) {
		cout << "Error: FileSystem must be formatted before use" << endl;
		return;
	} else if(!arg[0].compare("ls")) {
		f.list();
	} else if(!arg[0].compare("cd")) {
		if(!arg[1].compare("/")) {
			cout << "Usage: cd <directory>" << endl;
		} else {
 			f.changeDirectory(arg[1]);
		}
	} else if (!arg[0].compare("rmfile")) {
		if(!arg[1].compare("/")) {
			cout << "Usage: rmfile <file>" << endl;
		} else {
			f.removeFile(arg[1]); 
		}
	} else if (!arg[0].compare("mkfile")) {
		if(!arg[1].compare("/")) {
			cout << "Usage: mkfile <file>" << endl;
		} else {
			f.makeFile(arg[1]); 
		}
	} else if (!arg[0].compare("rmdir")) {
		if(!arg[1].compare("/")) {
			cout << "Usage: rmdir <directory>" << endl;
		} else {
			f.removeDirectory(arg[1]);
		}
	} else if (!arg[0].compare("mkdir")) {
		if(!arg[1].compare("/")) {
			cout << "Usage: rmdir <directory>" << endl;
		} else {
			f.makeDirectory(arg[1]);
		}
	} else if (!arg[0].compare("stat")) {
		if(!arg[1].compare("/")){
			cout << "Usage: stat <file|directory>" << endl;
		} else {
			f.stat(arg[1]);
		}
	} else if (!arg[0].compare("exit")) {
		cout << "Exiting..." << endl;
		exit(0);
	} else {
		cout << c << ": command not found." << endl;
	}
}

int main() {

	bool running = true;
	string command;
	
	Directory root("/");
	FileSystem system(&root);

	cout << "Welcome to CSCI Shell Prompt!" << endl;

    while(running) {
    	cout << "prompt@CSCI-3232:" << system.getWorkingDirectory() << "$ ";
    	getline(cin, command);
    	parseCommand(command, system);
    }    
}
