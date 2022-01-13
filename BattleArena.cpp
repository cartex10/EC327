#include "BattleArena.h"
#include "Building.h"

using namespace std;

BattleArena::BattleArena():Building()
{
	display_code = 'A';
	pokemon_count = 0;
	max_num_rivals = 3;
	num_rivals_remaining = 3;
	dollar_cost_per_fight = 4;
	stamina_cost_per_fight = 3;
	state = RIVALS_AVAILABLE;

	cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_id, Point2D in_loc):Building('A', in_id, in_loc)
{
	pokemon_count = 0;
	max_num_rivals = max_rivals;
	num_rivals_remaining = 0;
	dollar_cost_per_fight = dollar_cost;
	stamina_cost_per_fight = stamina_cost;
	state = RIVALS_AVAILABLE;
	location = in_loc;
	id_num = in_id;

	cout << "BattleArena constructed" << endl;
}

unsigned int BattleArena::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
	if (num_rivals_remaining == 0)
	{
		return 0;
	}
	else 
	{
		return 1;
	}
}

double BattleArena::GetDollarCost()
{
	return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
	return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
	if((budget >= dollar_cost_per_fight) && (stamina >= stamina_cost_per_fight))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool BattleArena::Update()
{
	switch(state)
	{
		case RIVALS_AVAILABLE:
		{
			if (num_rivals_remaining == 0)
			{
				state = NO_RIVALS_AVAILABLE;
				return 1;
			}
			return 0;
			break;
		}
		case NO_RIVALS_AVAILABLE:
		{
			return 0;
			break;
		}
	}
}

bool BattleArena::IsBeaten()
{
	if (num_rivals_remaining == 0)
	{
		state = NO_RIVALS_AVAILABLE;
		return 1;
	}
	else 
	{
		state = RIVALS_AVAILABLE;
		return 0;
	}
}

void BattleArena::ShowStatus()
{
	cout << "BattleArena state: ";
	switch (state)
	{
		case RIVALS_AVAILABLE:
		{
			cout << "RIVALS_AVAILABLE" << endl;
			break;
		}
		case NO_RIVALS_AVAILABLE:
		{
			cout << "NO_RIVALS_AVAILABLE" << endl;
			break;
		}
	}

	GameObject::ShowStatus();
	Building::ShowStatus();
	cout << "Max number of rivals: " << max_num_rivals << endl;
	cout << "Stamina cost per fight: " << stamina_cost_per_fight << endl;
	cout << "Pokemon dollar per fight: " << dollar_cost_per_fight << endl;

	if (num_rivals_remaining == 1)
	{
		cout << num_rivals_remaining << " rival is remaining in this arena" << endl;	
	}
	else
	{
		cout << num_rivals_remaining << " rivals are remaining in this arena" << endl;
	}

	cout << endl;

	return;
}	

BattleArena::~BattleArena()
{
	cout << "BattleArena destructed." << endl;
}

void BattleArena::RemoveRival()
{
	if (num_rivals_remaining > 0)
	{
		num_rivals_remaining--;
	}
	return;
}

bool BattleArena::ShouldBeVisible()
{
	return HasEnoughRivals();
}

void BattleArena::AddRival()
{
	if (num_rivals_remaining == max_num_rivals)
	{
		return;
	}
	else
	{
		num_rivals_remaining++;
		return;
	}
}