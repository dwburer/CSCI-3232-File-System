#include <string>
#include <ctime>

using namespace std;

#ifndef ENTITY_H
#define ENTITY_H

class Entity {
protected:
	string name;
	time_t created;
public:
	bool hasParent;
	bool isDirectory;
	Entity();
	Entity(string n, bool dir);
	string getName();
	string getTime();
	virtual void setParent(Entity* e)=0;
};

#endif