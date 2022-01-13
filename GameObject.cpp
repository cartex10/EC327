#include "GameObject.h"
#include "Point2D.h"

using namespace std;

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)	//Constructor
{
	location = in_loc;
	id_num = in_id;
	display_code = in_code;
	state = 0;
	cout << "GameObject constructed" << endl;
}

GameObject::GameObject(char in_code)	//Constructor
{
	display_code = in_code;
	id_num = 1;
	state = 0;
	cout << "GameObject constructed" << endl;
}

Point2D GameObject::GetLocation()	//Location getter
{
	return location;
}

int GameObject::GetId()	//Id getter
{
	return id_num;
}

char GameObject::GetState()	//State getter
{
	return state;
}

void GameObject::ShowStatus()	//Prints the status of the object
{
	cout << "GameObject status: " << display_code << id_num << " at " << location << endl;
	return;
}

GameObject::~GameObject()
{
	cout << "GameObject destructed." << endl;
}

void GameObject::DrawSelf(char* ptr)
{
	*ptr = display_code;
	*(++ptr) = char(id_num);
}