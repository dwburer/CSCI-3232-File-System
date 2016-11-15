#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"

using namespace std;

Directory::Directory(string n) : Entity (n, true) {
	hasParent = false;
}

void Directory::addChild(Entity e) {
	children[e.getName()] = e;
}

void Directory::setParent(Directory* d) {
	hasParent = true;
	parent = d;
}

string Directory::getParent() {
	return parent->getName();
}