#include <string>

using namespace std;

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
	string name;
public:
	bool hasParent;
	bool isDirectory;
	Entity();
	Entity(string n, bool dir);
	string getName();
	virtual void setParent(Entity* e)=0;
};

#endif