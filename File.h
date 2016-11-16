#include <string>
#include "Entity.h"
#include "Directory.h"

#ifndef FILE_H
#define FILE_H

class File : public Entity {
protected:
	Directory* parent;
public:
	File(string n);
	void setParent(Entity* e);
	string getParent();
};

#endif