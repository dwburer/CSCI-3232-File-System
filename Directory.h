#include <string>
#include <map>
#include "Entity.h"

#ifndef DIRECTORY_H
#define DIRECTORY_H

class Directory : public Entity {
protected:
	Directory* parent;
public:
	map <string, Entity*> children;
	bool hasParent;
	Directory(string n);
	bool contains(string file);
	void addChild(Entity* e);
	void setParent(Entity* e);
	Directory* getParent();
};

#endif