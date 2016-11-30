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

void parseCommand(string c, FileSystem &f) {
	vector<string> dirArgs;
	string arg[2];
	arg[1] = "0";
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
		cout << "error: FileSystem must be formatted before use" << endl;
		return;
	} else if(!arg[0].compare("ls")) {
		f.list();
	} else if(!arg[0].compare("cd")) {
		if(!arg[1].compare("0")){
			cout << "Please specify destination" << endl;
		} else {

			// Splitting path into individual commands
			if(arg[1].find("/") != string::npos) {

				Directory* validate;
				bool valid = true;
				string delimiter = "/";
				string s = arg[1];
				vector<string>::iterator path_iterator;

				while ((pos = s.find(delimiter)) != string::npos) {
					string newDir = s.substr(0, pos);
					dirArgs.insert(path_iterator, s.substr(0, pos));
					s.erase(0, pos + delimiter.length());
					++path_iterator;
				}

				validate = f.getCurrentDirectory();

				for(vector<string>::iterator it = dirArgs.begin(); it != dirArgs.end(); it++) {
					
					cout << "Checking if " << validate->getName() << " contains " << *it << endl;

					if (!validate->contains(*it)) {
						valid = false;
					} else {
						validate = (Directory*)validate->children[*it];
					}
				}

				if(valid) {
					for(vector<string>::iterator it = dirArgs.begin(); it != dirArgs.end(); ++it) {
						cout << *it << " ";
						f.changeDirectory(*it);
					}

					f.changeDirectory(s);
				}

     		} else {
     			f.changeDirectory(arg[1]);
     		}

		}
	} else if (!arg[0].compare("rmfile")) {
		f.removeFile(arg[1]); 
	} else if (!arg[0].compare("mkfile")) {
		f.makeFile(arg[1]); 
	} else if (!arg[0].compare("rmdir")) {
		f.removeDirectory(arg[1]); 
	} else if (!arg[0].compare("mkdir")) {
		f.makeDirectory(arg[1]); 
	} else if (!arg[0].compare("stat")) {
		f.stat(arg[1]); 
	} else if (!arg[0].compare("exit")) {
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
