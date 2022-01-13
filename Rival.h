#include "GameObject.h"
#include "BattleArena.h"

using namespace std;

#ifndef Rival_h
#define Rival_h

enum RivalStates
{
	ALIVE_RIVAL = 0,
	FAINTED_RIVAL = 1
};

class Rival:public GameObject
{
protected:
	double health;
	double physical_damage;
	double magical_damage;
	double defense;
	bool is_in_arena;
	BattleArena* current_arena;
	string name;

public:
	Rival(string, double, double, double, double, int, BattleArena*);
	void TakeHit(double, double, double);
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	bool Update();
	void ShowStatus();
	bool IsAlive();
	string get_name();
	virtual ~Rival();
	void DrawSelf(char*);
	virtual bool ShouldBeVisible();
};

#endif