#include <iostream>
#include <string>
#include "Directory.h"
#include "Entity.h"
#include "File.h"

using namespace std;

File::File(string n) : Entity(n, false) {}

string File::getParent() {
	return parent->getName();
}

void File::setParent(Entity* e) {
	hasParent = true;
	parent = (Directory*) e;
}