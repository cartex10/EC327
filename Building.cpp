#include "Building.h"
#include "GameObject.h"
#include "Point2D.h"

using namespace std;

Building::Building():GameObject(('B'))
{
	Point2D temp;
	id_num = 1;
	state = 0;
	location = temp;
	pokemon_count = 0;
	cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc):GameObject(in_loc, in_Id, in_code)
{
	display_code = in_code;
	id_num = in_Id;
	state = 0;
	location = in_loc;
	pokemon_count = 0;
	cout << "Building constructed" << endl;
}

void Building::AddOnePokemon()
{
	pokemon_count++;
	return;
}

void Building::RemoveOnePokemon()
{
	if(pokemon_count > 0)
	{
		pokemon_count--;
	}
	return;
}

void Building::ShowStatus()
{
	if(pokemon_count == 1)
		cout << pokemon_count << " pokemon is in this building." << endl;
	else
		cout << pokemon_count << " pokemon are in this building." << endl;
	return;
}

bool Building::ShouldBeVisible()
{
	return 1;
}