#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include "Entity.h"

using namespace std;

Entity::Entity() {}

Entity::Entity(string n, bool dir) :
name(n),
isDirectory(dir),
created(time(0)) {}

string Entity::getName() {
	return name;
}

string Entity::getTime() {
	stringstream tmp_time;
	tmp_time << ctime(&created);
	return tmp_time.str();
}