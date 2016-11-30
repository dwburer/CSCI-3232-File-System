#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"

using namespace std;

Directory::Directory(string n) : Entity (n, true), hasParent(false) {}

void Directory::addChild(Entity* e) {
	children[e->getName()] = e;
	e->setParent(this);
}

void Directory::setParent(Entity* e) {
	hasParent = true;
	parent = (Directory*) e;
}
void Directory::flushDirectory() {
	children.clear();
}

bool Directory::contains(string file) {
	return children.count(file) != 0;
}

Directory* Directory::getParent() {
	return parent;
}