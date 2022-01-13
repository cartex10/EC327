#include "PokemonCenter.h"
#include "Point2D.h"
#include "Building.h"
#include "GameObject.h"

PokemonCenter::PokemonCenter():Building()	//Default constructor
{
	display_code = 'C';
	stamina_capacity = 100;
	num_stamina_points_remaining = 100;
	dollar_cost_per_stamina = 5;
	PokemonCenterStates state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc)	//Constructor
{
	id_num = in_id;
	location = in_loc;
	dollar_cost_per_stamina = stamina_cost;
	stamina_capacity = stamina_cap;
	display_code = 'C';
	num_stamina_points_remaining = stamina_cap;
	PokemonCenterStates state = STAMINA_POINTS_AVAILABLE;
	cout << "PokemonCenter constructed" << endl;
}

bool PokemonCenter::HasStaminaPoints()	//Returns true or false whether it has stamina points
{
	if(num_stamina_points_remaining > 0)
	{
		return 1;
	}
	else if(num_stamina_points_remaining = 0)
	{
		return 0;
	}
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining() //Stamina point getter
{
	return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget) //Checks whether can afford stamina points
{
	if (stamina_points > budget)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)	//Returns dollar cost of inputted stamina
{
	return stamina_points * dollar_cost_per_stamina;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)	//Returns the available amount of stamina
{
	if (num_stamina_points_remaining <= points_needed)
	{
		unsigned int temp = num_stamina_points_remaining;
		num_stamina_points_remaining = 0;
		return temp;
	}
	else
	{
		num_stamina_points_remaining -= points_needed;
		return points_needed;
	}
}

bool PokemonCenter::Update()	
{
	if (num_stamina_points_remaining == 0)
	{
		state = NO_STAMINA_POINTS_AVAILABLE;
		display_code = 'c';
		cout << "PokemonCenter " << id_num << " has ran out of stamina points." << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

void PokemonCenter::ShowStatus()
{
	cout << "PokemonCenter status: " << endl;
	Building::ShowStatus();
	cout << "Pokemon dollars per stamina point: " << dollar_cost_per_stamina << endl;
	if (num_stamina_points_remaining == 1)
	{
		cout << "has " << num_stamina_points_remaining << " stamina point remaining" << endl << endl;
	}
	else
	{
		cout << "has " << num_stamina_points_remaining << " stamina points remaining" << endl << endl;
	}
}

PokemonCenter::~PokemonCenter()
{
	cout << "PokemonCenter destructed." << endl; 
}

bool PokemonCenter::ShouldBeVisible()
{
	return HasStaminaPoints();
}