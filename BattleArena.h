#include "Building.h"

using namespace std;

#ifndef BattleArena_h
#define BattleArena_h

enum BattleArenaStates
{
	RIVALS_AVAILABLE = 0,
	NO_RIVALS_AVAILABLE = 1
};

class BattleArena:public Building
{
private:
	unsigned int max_num_rivals;
	unsigned int num_rivals_remaining;
	double dollar_cost_per_fight;
	unsigned int stamina_cost_per_fight;
	unsigned int pokemon_count;

public:
	BattleArena();
	BattleArena(unsigned int, unsigned int, double, int, Point2D);
	unsigned int GetNumRivalsRemaining();
	bool HasEnoughRivals();
	double GetDollarCost();
	unsigned int GetStaminaCost();
	bool IsAbleToFight(double, unsigned int);
	bool Update();
	bool IsBeaten();
	void ShowStatus();
	virtual ~BattleArena();
	void RemoveRival();
	bool ShouldBeVisible();
	void AddRival();
};

#endif