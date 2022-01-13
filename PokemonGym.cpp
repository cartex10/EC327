#include "PokemonGym.h"

PokemonGym::PokemonGym():Building() //Default constructor
{
	display_code = 'G';
	PokemonGymStates state = NOT_BEATEN;
	max_number_of_training_units = 10;
	num_training_units_remaining = max_number_of_training_units;
	stamina_cost_per_training_unit = 1;
	dollar_cost_per_training_unit = 1;
	experience_points_per_training_unit = 2;
	cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc)
{
	id_num = in_id;
	max_number_of_training_units = max_training_units;
	num_training_units_remaining = max_training_units;
	stamina_cost_per_training_unit = stamina_cost;
	experience_points_per_training_unit = exp_points_per_unit;
	dollar_cost_per_training_unit = dollar_cost;
	display_code = 'G';
	location = in_loc;
	PokemonGymStates state = NOT_BEATEN;
	cout << "PokemonGym constructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
	return dollar_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
	return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
	return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
	if((budget >= (unit_qty * dollar_cost_per_training_unit)) && (stamina >= (unit_qty * stamina_cost_per_training_unit)))
		return 1;
	else
		return 0;
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{
	if(training_units <= num_training_units_remaining)
	{
		num_training_units_remaining -= training_units;
		return training_units * experience_points_per_training_unit;
	}
	else
	{
		unsigned int temp;
		temp = num_training_units_remaining;
		num_training_units_remaining = 0;
		return temp * experience_points_per_training_unit;
	}
}

bool PokemonGym::Update()
{
	if(IsBeaten())
	{
		state = BEATEN;
		display_code = 'g';
		cout << display_code << id_num << " has been beaten" << endl;
		return 1;
	}
	else
	{
		return 0;
	}
}

bool PokemonGym::IsBeaten()
{
	if(num_training_units_remaining == 0)
	{
		state = BEATEN;
		return 1;
	}
	else
	{
		state = NOT_BEATEN;
		return 0;
	}
}

void PokemonGym::ShowStatus()
{
	cout << "Pokemon Gym Status:" << endl;
	Building::ShowStatus();
	cout << "Max number of training units: " << max_number_of_training_units << endl;
	cout << "Stamina cost per training unit: " << stamina_cost_per_training_unit << endl;
	cout << "Pokemon dollar per training unit: " << dollar_cost_per_training_unit << endl;
	cout << "Experience points per training unit: " << experience_points_per_training_unit << endl;
	if(num_training_units_remaining == 1)
		cout << num_training_units_remaining << " training unit is remaining for this gym" << endl << endl;
	else
		cout << num_training_units_remaining << " training units are remaining for this gym" << endl << endl;
	return;
}

PokemonGym::~PokemonGym()
{
	cout << "PokemonGym destructed." << endl;
}

bool PokemonGym::ShouldBeVisible()
{
	return !(IsBeaten());
}