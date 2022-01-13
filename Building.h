#include "GameObject.h"
#include "Point2D.h"

using namespace std;

#ifndef Building_h
#define Building_h

class Building:public GameObject
{
private:
	unsigned int pokemon_count;
public:
	Building();
	Building(char, int, Point2D);
	void AddOnePokemon();
	void RemoveOnePokemon();
	virtual void ShowStatus();
	bool ShouldBeVisible();
};

#endif