#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "GameObject.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include <list>

using namespace std;

#ifndef Model_h
#define Model_h

class Model
{
private:
	int time;

	//GameObject* object_ptrs[10];
	int num_objects;
	list<GameObject*> object_ptrs;
	list<GameObject*> active_ptrs;

	//Pokemon* pokemon_ptrs[10];
	int num_pokemon;
	list<Pokemon*> pokemon_ptrs;

	//PokemonCenter* center_ptrs[10];
	int num_centers;
	list<PokemonCenter*> center_ptrs;

	//PokemonGym* gym_ptrs[10];
	int num_gyms;
	list<PokemonGym*> gym_ptrs;

	//Rival* rival_ptrs[10];
	int num_rivals;
	list<Rival*> rival_ptrs;

	//BattleArena* arena_ptrs[10];
	int num_arenas;
	list<BattleArena*> arena_ptrs;

public:
	Model();
	virtual ~Model();
	Pokemon* GetPokemonPtr(int);
	PokemonCenter* GetPokemonCenterPtr(int);
	PokemonGym* GetPokemonGymPtr(int);
	void Display(View&);
	bool Update();
	void ShowStatus();

	BattleArena* GetBattleArenaPtr(int);	//PA4 Additions
	Rival* GetRivalPtr(int);
	int GetPokemonNum();
	int GetCenterNum();
	int GetGymNum();
	int GetArenaNum();
	int GetRivalNum();
	void NewCommand(char, int, int, int);
};

#endif