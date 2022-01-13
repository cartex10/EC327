#include "Model.h"
#include "Point2D.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "GameObject.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"
#include <cstdlib>
#include <list>

using namespace std;

Model::Model()	//Broke?
{
	time = 0;

	num_objects = 10;
	num_pokemon = 2;
	num_centers = 2;
	num_gyms = 2;
	num_rivals = 2;
	num_arenas = 1;
/*
	pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2, Point2D (5, 1));		//Unnecessary to update if Pikachu and Bulbasaur have the same hp, def, phys damage, and magical damage
	object_ptrs[0] = pokemon_ptrs[0];

	pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10, 1));		
	object_ptrs[1] = pokemon_ptrs[1];

	center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
	object_ptrs[2] = center_ptrs[0];

	center_ptrs[1] = new PokemonCenter(2, 2, 200, Point2D(10, 20));
	object_ptrs[3] = center_ptrs[1];

	gym_ptrs[0] = new PokemonGym(10, 1, 2, 3, 1, Point2D());
	object_ptrs[4] = gym_ptrs[0];

	gym_ptrs[1] = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));
	object_ptrs[5] = gym_ptrs[1];

	arena_ptrs[0] = new BattleArena(1, 3, 4, 1, Point2D(16, 6)); //PA4 Additions
	object_ptrs[8] = arena_ptrs[0];

	arena_ptrs[1] = new BattleArena(1, 6, 8, 2, Point2D(18, 18));
	object_ptrs[9] = arena_ptrs[1];

	rival_ptrs[0] = new Rival("Charmander", 20, 5, 4, 15, 1, arena_ptrs[0]);
	object_ptrs[6] = rival_ptrs[0];

	rival_ptrs[1] = new Rival("Squirtle", 20, 5, 4, 15, 2, arena_ptrs[1]);
	object_ptrs[7] = rival_ptrs[1];
*/
	Pokemon* ptrP1 = new Pokemon("Pikachu", 1, 'P', 2, Point2D (5, 1));
	Pokemon* ptrP2 = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10, 1));
	pokemon_ptrs.push_back(ptrP1);
	pokemon_ptrs.push_back(ptrP2);

	PokemonCenter* ptrC1 = new PokemonCenter(1, 1, 100, Point2D(1, 20));
	PokemonCenter* ptrC2 = new PokemonCenter(2, 2, 200, Point2D(10, 20));
	center_ptrs.push_back(ptrC1);
	center_ptrs.push_back(ptrC2);

	PokemonGym* ptrG1 = new PokemonGym(10, 1, 2, 3, 1, Point2D());
	PokemonGym* ptrG2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5));
	gym_ptrs.push_back(ptrG1);
	gym_ptrs.push_back(ptrG2);

	BattleArena* ptrA1 = new BattleArena(3, 3, 4, 1, Point2D(16, 6));
	//BattleArena* ptrA2 = new BattleArena(1, 6, 8, 2, Point2D(18, 18));
	arena_ptrs.push_back(ptrA1);
	//arena_ptrs.push_back(ptrA2);

	Rival* ptrR1 = new Rival("Charmander", 20, 5, 4, 15, 1, ptrA1);
	Rival* ptrR2 = new Rival("Squirtle", 20, 5, 4, 15, 2, ptrA1);
	rival_ptrs.push_back(ptrR1);
	rival_ptrs.push_back(ptrR2);

	object_ptrs.push_back(ptrP1);
	object_ptrs.push_back(ptrP2);
	object_ptrs.push_back(ptrC1);
	object_ptrs.push_back(ptrC2);
	object_ptrs.push_back(ptrG1);
	object_ptrs.push_back(ptrG2);
	object_ptrs.push_back(ptrR1);
	object_ptrs.push_back(ptrR2);
	object_ptrs.push_back(ptrA1);
	//object_ptrs.push_back(ptrA2);

	active_ptrs.push_back(ptrP1);
	active_ptrs.push_back(ptrP2);
	active_ptrs.push_back(ptrC1);
	active_ptrs.push_back(ptrC2);
	active_ptrs.push_back(ptrG1);
	active_ptrs.push_back(ptrG2);
	active_ptrs.push_back(ptrR1);
	active_ptrs.push_back(ptrR2);
	active_ptrs.push_back(ptrA1);
	//active_ptrs.push_back(ptrA2);

	cout << "Model default constructed" << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
};

Model::~Model()	
{
	list<GameObject*>::iterator i;

	for(auto& i : object_ptrs)
	{
		delete i;
	}

	cout << "Model destructed." << endl;
}

Pokemon* Model::GetPokemonPtr(int id)
{
	list<Pokemon*>::iterator i;

	for(auto& i : pokemon_ptrs)
	{	
		if(id == i->GetId())
		{
			return i;
		}
	}

	//return pokemon_ptrs[id];
}

PokemonCenter* Model::GetPokemonCenterPtr(int id)
{
	list<PokemonCenter*>::iterator i;

	for(auto& i : center_ptrs)
	{	
		if(id == i->GetId())
		{
			return i;
		}
	}
	//return center_ptrs[id];
}

PokemonGym* Model::GetPokemonGymPtr(int id)
{
	list<PokemonGym*>::iterator i;

	for(auto& i : gym_ptrs)
	{	
		if(id == i->GetId())
		{
			return i;
		}
	}

	//return gym_ptrs[id];
}

bool Model::Update()
{
	int count1 = 0;
	int count2 = 0;
	int counto = 0;
	int count3 = 0;

	list<GameObject*>::iterator iActive;
	list<Pokemon*>::iterator iPokemon;
	list<PokemonGym*>::iterator iGym;
	list<Rival*>::iterator iRival;

	time++;
	cout << "Time: " << time << endl;

	for(auto iActive = active_ptrs.begin(); iActive != active_ptrs.end(); ++iActive)
	{
		counto += (*iActive)->Update();

		if(!((*iActive)->ShouldBeVisible()))
		{
			iActive = active_ptrs.erase(iActive);
			active_ptrs.pop_back();
			cout << endl << endl << "<<< Dead object removed >>>" << endl << endl;
		}
	}

	for(auto& iPokemon : pokemon_ptrs)
	{
		if((iPokemon->IsExhausted()) || !(iPokemon->IsAlive()))
		{
			count1++;
		}
	}

	for(auto& iGym : gym_ptrs)
	{
		if(iGym->IsBeaten())
		{
			count2++;
		}
	}

	for(auto& iRival : rival_ptrs)
	{
		if(!(iRival->IsAlive()))
		{
			count3++;
		}
	}

	ShowStatus();

	if(count1 == num_pokemon)
	{
		cout << "GAME OVER: You lose! All of your Pokemon are tired or have fainted!" << endl;
		exit(0);
	}

	if(count2 == num_gyms)
	{
		cout << "GAME OVER: You win! All Pokemon Gyms are beaten!" << endl;			
		exit(0);
	}

	if(count3 == num_rivals)
	{
		cout << "GAME OVER: You win! You are the Champion of every Battle Arena!" << endl;			
		exit(0);
	}

	cout << endl;

	if(counto != 0)
	{
		return 1;
	}

	return 0;
}

void Model::Display(View& view)
{
	list<GameObject*>::iterator i;

	view.Clear();
	for(auto& i : active_ptrs)
	{
		view.Plot(i);
	}
	view.Draw();
	return;
}

void Model::ShowStatus()
{
	list<GameObject*>::iterator i;

	for(auto& i : object_ptrs)
	{
		i->ShowStatus();
	}
	return;
}

//PA4 Additions
BattleArena* Model::GetBattleArenaPtr(int id)
{
	list<BattleArena*>::iterator i;

	for(auto& i : arena_ptrs)
	{	
		if(id == i->GetId())
		{
			return i;
		}
	}

	//return arena_ptrs[id];
}

Rival* Model::GetRivalPtr(int id)
{
	list<Rival*>::iterator i;

	for(auto& i : rival_ptrs)
	{	
		if(id == i->GetId())
		{
			return i;
		}
	}

	//return rival_ptrs[id];
}

int Model::GetPokemonNum()
{
	return num_pokemon;
}

int Model::GetCenterNum()
{
	return num_centers;
}

int Model::GetGymNum()
{
	return num_gyms;
}

int Model::GetArenaNum()
{
	return num_arenas;
}

int Model::GetRivalNum()
{
	return num_rivals;
}

void Model::NewCommand(char TYPE, int ID, int x, int y)
{
	Point2D loc(x, y);
	string Names[10] = {"Butterfree", "Beedrill", "Zubat", "Onix", "Starmie", "Mewtwo", "Pidgey", "Rattata", "Dragonite", "Jigglypuff"};

	if (TYPE == 'g')
	{
		cout << "Pokemon Gym G" << ID << " has been constructed at location " << loc << endl;
		num_gyms++;
		PokemonGym* ptr = new PokemonGym(10, 1, 2, 3, ID, loc);
		gym_ptrs.push_back(ptr);
		object_ptrs.push_back(ptr);
		active_ptrs.push_back(ptr);
	}
	else if (TYPE == 'c')
	{
		cout << "Pokemon Center C" << ID << " has been constructed at location " << loc << endl;
		num_centers++;
		PokemonCenter* ptr = new PokemonCenter(ID, 1, 100, loc);
		center_ptrs.push_back(ptr);
		object_ptrs.push_back(ptr);
		active_ptrs.push_back(ptr);
	}
	else if (TYPE == 'p')
	{
		cout << "Pokemon P" << ID << " has appeared at location " << loc << endl;
		num_pokemon++;
		Pokemon* ptr = new Pokemon(Names[rand() % 10], ID, 'P', 2, loc);
		pokemon_ptrs.push_back(ptr);
		object_ptrs.push_back(ptr);
		active_ptrs.push_back(ptr);
	}
	else if (TYPE == 'r')
	{
		cout << "Rival R" << ID << " has appeared at location " << loc << endl;
		num_rivals++;
		BattleArena* ptrA;

		list<BattleArena*>::iterator i;

		for(auto& i : arena_ptrs)
		{	
			try
			{
				int count = 0;
				if((loc.x == i->GetLocation().x) && (loc.y == i->GetLocation().y))
				{
					count++;
					ptrA = i;
				}
				if (count == 0)
				{
					throw Invalid_Input("Rivals need to be in arenas.");
				}
			}

			catch(Invalid_Input& except)
			{
				cout << "Invalid Input: " << except.msg_ptr << endl;
				return;
			}
		}

		Rival* ptr = new Rival(Names[rand() % 10], 20, 5, 4, 15, 1, ptrA);
		rival_ptrs.push_back(ptr);
		object_ptrs.push_back(ptr);
		active_ptrs.push_back(ptr);
	}
	return;
}