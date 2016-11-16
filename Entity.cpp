#include <iostream>
#include <string>
#include "Entity.h"

Entity::Entity() {
	
}

Entity::Entity(string n, bool dir) {
	name = n;
	isDirectory = dir;
}

string Entity::getName() {
	return name;
}