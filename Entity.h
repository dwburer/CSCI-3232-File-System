#include <string>

using namespace std;

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
	string name;
public:
	Entity();
	Entity(string n, bool dir);
	string getName();
	bool isDirectory;
};

#endif