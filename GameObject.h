#include "Point2D.h"

#ifndef GameObject_h
#define GameObject_h

class GameObject
{
protected:
	Point2D location;
	int id_num;
	char display_code;
	char state;

public:
	GameObject(char);
	GameObject(Point2D, int, char);
	Point2D GetLocation();
	int GetId();
	char GetState();
	virtual void ShowStatus();
	virtual bool Update() = 0;
	virtual bool ShouldBeVisible() = 0;
	virtual ~GameObject();
	virtual void DrawSelf(char*);
};

#endif