#include <iostream>
#include <string>
#include <map>
#include "Directory.h"
#include "Entity.h"

using namespace std;

Directory::Directory(string n) : Entity (n, true) {
	hasParent = false;
}

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
	map<string, Entity*>::iterator it = children.find(file);
	return it != children.end();
}

Directory* Directory::getParent() {
	return parent;
}