#include <iostream>
#include <string>
#include "Directory.h"
#include "Entity.h"
#include "File.h"

using namespace std;

File::File(string n) : Entity(n, false) {}

void File::setParent(Directory* d) {
	parent = d;
}

string File::getParent() {
	return parent->getName();
}