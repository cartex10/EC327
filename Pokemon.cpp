#include "Pokemon.h"
#include "GameObject.h"
#include "Point2D.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Vector2D.h"
#include "BattleArena.h"
#include "Rival.h"
#include <math.h>
#include <time.h>
#include <cstdlib>

using namespace std;

Pokemon::Pokemon():GameObject('P')
{
	speed = 5;
	id_num = 0;
	PokemonStates state = STOPPED;
	speed = 0;
	is_in_gym = 0;
	is_in_center = 0;
	stamina = 20;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	name = "Default Pokemon";
	current_center = 0;
	current_gym = 0;
	destination = Point2D();
	delta = Vector2D();

	health = 20;		//PA4 Additions
	store_health = 20;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	target = 0;
	is_in_arena = 0;
	current_arena = 0;

	cout << "Pokemon default constructed" << endl;

}

Pokemon::Pokemon(char in_code):GameObject(in_code)
{
	speed = 5;
	id_num = 0;
	display_code = in_code;
	PokemonStates state = STOPPED;
	speed = 0;
	is_in_gym = 0;
	is_in_center = 0;
	stamina = 20;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	name = "Baby Pokemon";
	current_center = 0;
	current_gym = 0;
	destination = Point2D();
	delta = Vector2D();

	health = 20;		//PA4 Additions
	store_health = 20;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	target = 0;
	is_in_arena = 0;
	current_arena = 0;

	cout << "Pokemon constructed" << endl;
}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc):GameObject(in_loc, in_id, in_code)
{
	speed = in_speed;
	id_num = in_id;
	display_code = in_code;
	PokemonStates state = STOPPED;
	is_in_gym = 0;
	is_in_center = 0;
	stamina = 20;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	name = in_name;
	current_center = 0;
	current_gym = 0;
	destination = in_loc;
	delta = Vector2D();

	health = 20;		//PA4 Additions
	store_health = 20;
	physical_damage = 5;
	magical_damage = 4;
	defense = 15;
	target = 0;
	is_in_arena = 0;
	current_arena = 0;

	cout << "Pokemon constructed" << endl;
}

void Pokemon::StartMoving(Point2D dest)
{
	if((dest.x == location.x) && (dest.y == location.y))
	{
		cout << display_code << id_num << ": I'm already there. See?" << endl;
	}
	else if(IsExhausted())
	{
		cout << display_code << id_num << ": I am exhausted. I may move but you cannot see me." << endl;
	}
	else
	{
		cout << display_code << id_num << ": On my way." << endl;
		state = MOVING;
		SetupDestination(dest);
		if(is_in_gym)
		{
			current_gym->RemoveOnePokemon();
			current_gym = 0;
		}
		if(is_in_center)
		{
			current_center->RemoveOnePokemon();
			current_center = 0;
		}
	}
	return;
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
	SetupDestination(center->GetLocation());
	if(is_in_gym)
	{
		current_gym->RemoveOnePokemon();
		current_gym = 0;
	}
	if(is_in_center)
	{
		current_center->RemoveOnePokemon();
		current_center = 0;
	}
	if(is_in_arena)
	{
		current_arena->RemoveOnePokemon();
		current_arena = 0;
	}
	current_center = center;
	state = MOVING_TO_CENTER;
	if(IsExhausted())
	{
		cout << display_code << id_num << ": I am exhausted so I can't move to recover stamina..." << endl;
	}

	if((location.x == center->GetLocation().x) && (location.y == center->GetLocation().y))
	{
		cout << display_code << id_num << ": I am already at the Pokemon Center!" << endl;
	}
	else
	{
		cout << display_code << id_num << ": on my way to center " << center->GetId() << "." << endl;
	}
	return;
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
	SetupDestination(gym->GetLocation());
	if(is_in_gym)
	{
		current_gym->RemoveOnePokemon();
		current_gym = 0;
	}
	if(is_in_center)
	{
		current_center->RemoveOnePokemon();
		current_center = 0;
	}
	if(is_in_arena)
	{
		current_arena->RemoveOnePokemon();
		current_arena = 0;
	}
	current_gym = gym;
	state = MOVING_TO_GYM;
	if(IsExhausted())
	{
		cout << display_code << id_num << ": I am exhausted so I shouldn't be going to the gym.." << endl;
	}

	if((location.x == gym->GetLocation().x) && (location.y == gym->GetLocation().y))
	{
		cout << display_code << id_num << ": I am already at the Pokemon Gym!" << endl;
	}
	else
	{
		cout << display_code << id_num << ": on my way to gym " << gym->GetId() << "." << endl;
	}
	return;
}

void Pokemon::StartTraining(unsigned int num_training_points)
{
	if(IsExhausted())
	{
		cout << display_code << id_num << ": I am exhausted so no more training for me..." << endl;
		return;
	}
	else if(is_in_gym == 0)
	{	
		cout << display_code << id_num << ": I can only train in a Pokemon Gym!" << endl;
		return;
	}
	else if(current_gym->IsAbleToTrain(num_training_points, pokemon_dollars, stamina) == 0)
	{
		cout << display_code << id_num << ": Not enough stamina and/or money for training" << endl;
		return;
	}
	else if(current_gym->IsBeaten())
	{
		cout << "Cannot train! This Pokemon Gym is already beaten!" << endl;
		return;
	}
	else
	{
		state = TRAINING_IN_GYM;
		if(num_training_points == 1)
		{
			cout << id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() << " with " << num_training_points << " training unit" << endl;
		}
		else
		{
			cout << id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() << " with " << num_training_points << " training units" << endl;
		}

		training_units_to_buy = num_training_points;
		
		return;
	}
	return;
}

void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)			//BROKE
{
	if(current_center->GetDollarCost(num_stamina_points) > pokemon_dollars)
	{
		cout << display_code << id_num << ": Not enough money to recover stamina." << endl;
		return;
	}
	else if(current_center->GetNumStaminaPointsRemaining() < 1)
	{
		cout << display_code << id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center" << endl;
		return;
	}
	else if(is_in_center == 0)
	{
		cout << display_code << id_num << ": I can only recover stamina at a Pokemon Center!" << endl;
		return;
	}
	else
	{
		state = RECOVERING_STAMINA;
		if(num_stamina_points == 1)
		{
			cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina point at Pokemon Center " << current_center->GetId() << endl;
		}
		else
		{
			cout << display_code << id_num << ": Started recovering " << num_stamina_points << " stamina points at Pokemon Center " << current_center->GetId() << endl;
		}

		stamina_units_to_buy = num_stamina_points;

		return;
	}
	return;
}

void Pokemon::Stop()	//Unsure if complete
{
	state = STOPPED;
	cout << display_code << id_num << ": Stopping..." << endl;
	return;
}

bool Pokemon::IsExhausted()
{
	if(stamina == 0)
	{
		state = EXHAUSTED;
		return 1;
	}
	else
	{
		return 0;
	}
}

bool Pokemon::ShouldBeVisible()
{
	if(IsExhausted())
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

void Pokemon::ShowStatus()
{
	cout << name << " status: ";
	
	switch(state)
	{
	case STOPPED:
		cout << "stopped" << endl;
		break;

	case MOVING:
		cout << "moving at a speed of " << speed << " to destination " << destination << " at each step of " << delta << "." << endl;
		break;

	case EXHAUSTED:
		cout << "EXHAUSTED" << endl << endl;
		return;
		break;

	case MOVING_TO_CENTER:
		cout << "heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
		break;

	case MOVING_TO_GYM:
		cout << "heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
		break;

	case IN_CENTER:
		cout << "inside Pokemon Center " << current_center->GetId() << endl;
		break;

	case IN_GYM:
		cout << "inside Pokemon Gym " << current_gym->GetId() << endl;
		break;

	case TRAINING_IN_GYM:
		cout << "training in Pokemon Gym " << current_gym->GetId() << "." << endl;
		break;

	case RECOVERING_STAMINA:
		cout << "recovering stamina in Pokemon Center " << current_center->GetId() << endl;
		break;
		//PA4 Additions
	case IN_ARENA:		
		cout << "preparing for battle in Battle Arena " << current_arena->GetId() << endl;
		break;

	case MOVING_TO_ARENA:
		cout << "heading to Battle Arena " << current_arena->GetId() << endl;
		break;

	case BATTLE:
		cout << "preparing to battle with Rival " << target->get_name() << " at Battle Arena " << current_arena->GetId() << endl;
		break;

	case FAINTED:
		cout << "FAINTED" << endl << endl;
		return;
		break;
	}

	GameObject::ShowStatus();
	cout << "Health: " << health << endl;
	cout << "Stamina: " << stamina << endl;
	cout << "Pokemon Dollars: " << pokemon_dollars << endl;
	cout << "Experience Points: " << experience_points << endl;
	cout << endl;
	return;
}

bool Pokemon::Update()
{
	if(IsExhausted())
	{
		state = EXHAUSTED;
	}
	
	switch(state)
	{
		case STOPPED:
		{ 
			return 0;
			break;
		}

		case MOVING: 
		{
			if(IsExhausted())
			{
				state = EXHAUSTED;
				return 0;
			}
			stamina--;
			pokemon_dollars += GetRandomAmountOfPokemonDollars();
			is_in_center = 0;
			is_in_gym = 0;
			is_in_arena = 0;
			UpdateLocation();
			if((location.x == destination.x) && (location.y == destination.y)) 
			{
				state = STOPPED;
				return 1;
			}
			else
			{
				return 0;				
			}
			break;
		}

		case EXHAUSTED:
		{
			cout << name << " is out of stamina and can't move" << endl;
			return 0;
			break;
		}

		case MOVING_TO_CENTER:
		{
			UpdateLocation();
			stamina--;
			pokemon_dollars += GetRandomAmountOfPokemonDollars();
			is_in_center = 0;
			is_in_gym = 0;
			is_in_arena = 0;
			if((location.x == destination.x) && (location.y == destination.y))
			{
				state = IN_CENTER;
				is_in_center = 1;
				current_center->AddOnePokemon();
				return 1;
			}
			else
			{
				return 0;
			}
			break;
		}

		case MOVING_TO_GYM:
		{
			UpdateLocation();
			stamina--;
			pokemon_dollars += GetRandomAmountOfPokemonDollars();
			is_in_center = 0;
			is_in_gym = 0;
			is_in_arena = 0;
			if((location.x == destination.x) && (location.y == destination.y))
			{
				state = IN_GYM;
				is_in_gym = 1;
				current_gym->AddOnePokemon();
				return 1;
			}
			else
			{
				return 0;
			}
			break;
		}

		case IN_CENTER:
		{
			is_in_center = 1;
			return 0;
			break;
		}

		case IN_GYM:
		{
			is_in_gym = 1;
			return 0;
			break;
		}

		case TRAINING_IN_GYM:
		{
			stamina -= current_gym->GetStaminaCost(training_units_to_buy);
			pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
			unsigned int temp1 = current_gym->TrainPokemon(training_units_to_buy);
			experience_points += temp1;
			if(training_units_to_buy == 1)
				cout << "** " << name << " completed " << training_units_to_buy << " training unit! **" << endl;
			else
				cout << "** " << name << " completed " << training_units_to_buy << " training units! **" << endl;
			if(temp1 == 1)
				cout << "** " << name << " gained " << temp1 << " experience point! **" << endl;
			else
				cout << "** " << name << " gained " << temp1 << " experience points! **" << endl;
			state = IN_GYM;
			return 1;
			break;
		}

		case RECOVERING_STAMINA:
		{
			unsigned int temp = current_center->DistributeStamina(stamina_units_to_buy);
			stamina += temp;
			pokemon_dollars -= current_center->GetDollarCost(stamina_units_to_buy);
			if(temp == 1)
			{
				cout << "** " << name << " recovered " << temp << " stamina point! **" << endl;
			}
			else
			{
				cout << "** " << name << " recovered " << temp << " stamina points! **" << endl;
			}
			state = IN_CENTER;
			return 1;
			break;
		}
		//PA4 Additions
		case IN_ARENA:
		{
			is_in_arena = 1;
			return 0;
			break;
		}

		case MOVING_TO_ARENA:
		{
			UpdateLocation();
			stamina--;
			pokemon_dollars += GetRandomAmountOfPokemonDollars();
			is_in_center = 0;
			is_in_gym = 0;
			is_in_arena = 0;
			if((location.x == destination.x) && (location.y == destination.y))
			{
				state = IN_ARENA;
				is_in_arena = 1;
				current_arena->AddOnePokemon();
				return 1;
			}
			else
			{
				return 0;
			}
			break;
		}

		case BATTLE:
		{
			stamina -= current_arena->GetStaminaCost();
			pokemon_dollars -= current_arena->GetDollarCost();


			if (StartBattle())		//Win Rewards
			{
				health = store_health;
				target->IsAlive();
				target = 0;
				state = IN_ARENA;
				current_arena->RemoveRival();
				return 1;
			}
			else					//Loss Consequences
			{
				health = 0;
				target->IsAlive();
				target = 0;
				state = FAINTED;
				return 0;
			}
		}

		case FAINTED:
		{
			return 0;
			break;
		}
	}
}

string Pokemon::GetName()
{
	return name;
}

Pokemon::~Pokemon()
{
	cout << "Pokemon destructed." << endl;
}

bool Pokemon::UpdateLocation()
{
	Vector2D temp(fabs(destination.x - location.x), fabs(destination.y - location.y));
	if((temp.x <= fabs(delta.x)) && (temp.y <= fabs(delta.y)))
	{
		location = destination;
		cout << display_code << id_num << ": I'm there!" << endl;
		return 1;
	}
	else
	{
		location = location + delta;
		cout << display_code << id_num << ": step..." << endl;
		return 0;
	}
}

void Pokemon::SetupDestination(Point2D dest)
{
	delta = (dest - location) * (speed / GetDistanceBetween(dest, location));
	destination = dest;
	return;
}

double GetRandomAmountOfPokemonDollars()
{
	return rand() % 3;
}

//PA4 Additions
Pokemon::Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc):GameObject(in_code)
{
	speed = in_speed;
	id_num = in_id;
	display_code = in_code;
	PokemonStates state = STOPPED;
	is_in_gym = 0;
	is_in_center = 0;
	stamina = 20;
	experience_points = 0;
	pokemon_dollars = 0;
	training_units_to_buy = 0;
	name = in_name;
	current_center = 0;
	current_gym = 0;
	destination = in_loc;
	delta = Vector2D();

	health = hp;		//PA4 Additions
	store_health = hp;
	physical_damage = phys_dmg;
	magical_damage = magic_dmg;
	defense = def;
	target = 0;
	is_in_arena = 0;
	current_arena = 0;

	cout << "Pokemon constructed" << endl;
}

bool Pokemon::IsAlive()
{
	if(health == 0)
	{
		state = FAINTED;
		return 0;
	}
	else
	{
		return 1;
	}
}

void Pokemon::TakeHit(double physical_damage, double magical_damage, double defense)
{
	double TypePicker;
	double damage;
	TypePicker = rand() % 2;
	if (TypePicker == 0)
	{
		damage = (100 - defense) / 100 * physical_damage;
		health -= damage;
		cout << target->get_name() << " hits " << name << " for " << damage << " physical damage!" << endl;
	}
	else if(TypePicker == 1)
	{
		damage = (100 - defense) / 100 * magical_damage;
		health -= damage;
		cout << target->get_name() << " hits " << name << " for " << damage << " magical damage!" << endl;
	}
	return;
}

void Pokemon::ReadyBattle(Rival* in_target)
{
	if(state != IN_ARENA)
	{
		cout << display_code << id_num << ": I am not in an arena!" << endl;
	}
	else if(!(current_arena->IsAbleToFight(pokemon_dollars, stamina)))
	{
		cout << display_code << id_num << ": I am unable to fight!" << endl;
		state = IN_ARENA;
	}
	else if(current_arena->IsBeaten())
	{
		cout << display_code << id_num << ": I am already the Champion of this arena!" << endl;
		state = IN_ARENA;
	}
	else if(!(in_target->IsAlive()))
	{
		cout << display_code << id_num << ": That enemy is already fainted!" << endl;
		state = IN_ARENA;
	}
	else if(((location.x) != ((in_target->GetLocation()).x)) || ((location.y) != ((in_target->GetLocation()).y)))
	{
		cout << display_code << id_num << ": I am not in the correct Battle Arena!" << endl;
		state = IN_ARENA;
	}
	else
	{
		cout << display_code << id_num << ": I am ready for battle!" << endl;
		target = in_target;
		state = BATTLE;
	}

	return;
}

bool Pokemon::StartBattle()
{
	cout << "The battle between " << name << " and Rival " << target->get_name() << " has begun!" << endl;
	while ((health > 0) && (target->get_health() > 0))		//Battle loop
	{
		TakeHit(target->get_phys_dmg(), target->get_magic_dmg(), defense);
		target->TakeHit(physical_damage, magical_damage, target->get_defense());
	}

	if (health <= 0)		//Loss Consequences
	{
		cout << name << " has lost to Rival " << target->get_name() << "!" << endl << endl;
		return 0;
	}
	else					//Win Rewards
	{
		cout << name << " has defeated Rival " << target->get_name() << "!" << endl << endl;
		return 1;
	}
}

void Pokemon::StartMovingToArena(BattleArena* arena)
{
	SetupDestination(arena->GetLocation());
	if(is_in_gym)
	{
		current_gym->RemoveOnePokemon();
		current_gym = 0;
	}
	if(is_in_center)
	{
		current_center->RemoveOnePokemon();
		current_center = 0;
	}
	if(is_in_arena)
	{
		current_arena->RemoveOnePokemon();
		current_arena = 0;
	}
	current_arena = arena;
	state = MOVING_TO_ARENA;
	if(IsExhausted())
	{
		cout << display_code << id_num << ": I can't battle while I'm exhausted..." << endl;
	}

	if((location.x == arena->GetLocation().x) && (location.y == arena->GetLocation().y))
	{
		cout << display_code << id_num << ": I am already at the Battle Arena!" << endl;
	}
	else
	{
		cout << display_code << id_num << ": on my way to arena " << arena->GetId() << "." << endl;
	}
	return;
}