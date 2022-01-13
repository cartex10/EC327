#include "Rival.h"
#include "GameObject.h"
#include "BattleArena.h"

using namespace std;

Rival::Rival(string in_name, double hp, double phys_dmg, double magic_dmg, double def, int in_id, BattleArena* arena):GameObject('R')
{
	name = in_name;
	health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	id_num = in_id;
	current_arena = arena;
	RivalStates state = ALIVE_RIVAL;
	location = arena->GetLocation();
	current_arena->AddRival();
}

void Rival::TakeHit(double phys_damage, double magi_damage, double def)
{
	double TypePicker;
	double damage;
	TypePicker = rand() % 2;

	if (TypePicker == 0)
	{
		damage = (100 - def) / 100 * phys_damage;
		health -= damage;
		cout << name << " takes " << damage << " physical damage!" << endl;
	}
	else if(TypePicker == 1)
	{
		damage = (100 - def) / 100 * magi_damage;
		health -= damage;
		cout << name << " takes " << damage << " magical damage!" << endl;	}
	return;
}

double Rival::get_phys_dmg()
{
	return physical_damage;
}

double Rival::get_magic_dmg()
{
	return magical_damage;
}

double Rival::get_defense()
{
	return defense;
}

double Rival::get_health()
{
	return health;
}

bool Rival::Update()
{
	switch(state)
	{
		case ALIVE_RIVAL:
		{	
			if (health < 1)
			{
				state = FAINTED_RIVAL;
				return 1;
			}
			return 0;
			break;
		}
		case FAINTED_RIVAL:
		{
			return 1;
			break;
		}
	}
}

void Rival::ShowStatus()
{
	cout << "Rival " << name << " status: ";

	switch(state)
	{
		case ALIVE_RIVAL:
		{
			cout << "Ready for battle" << endl;
			break;
		}
		case FAINTED_RIVAL:
		{
			cout << "Fainted" << endl;
			break;
		}
	}

	GameObject::ShowStatus();
	cout << endl;

	return;
}

bool Rival::IsAlive()
{
	if (health > 0)
	{
		state = ALIVE_RIVAL;
		return 1;
	}
	else
	{
		state = FAINTED_RIVAL;
		return 0;
	}
}

string Rival::get_name()
{
	return name;
}

Rival::~Rival()
{
	cout << "Rival destructed" << endl;
}

void Rival::DrawSelf(char* ptr)
{
	*ptr = '.';
	return;
}

bool Rival::ShouldBeVisible()
{
	return IsAlive();
}