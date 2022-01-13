#include "Point2D.h"
#include "Building.h"
#include "GameObject.h"
using namespace std;

#ifndef PokemonCenter_h
#define PokemonCenter_h

enum PokemonCenterStates
{
	STAMINA_POINTS_AVAILABLE = 0,
	NO_STAMINA_POINTS_AVAILABLE = 1
};

class PokemonCenter:public Building
{
private:
	unsigned int stamina_capacity;
	unsigned int num_stamina_points_remaining;
	double dollar_cost_per_stamina;

public:
	PokemonCenter();
	PokemonCenter(int, double, unsigned int, Point2D);
	bool HasStaminaPoints();
	unsigned int GetNumStaminaPointsRemaining();
	bool CanAffordStaminaPoints(unsigned int, double);
	double GetDollarCost(unsigned int);
	unsigned int DistributeStamina(unsigned int);
	bool Update();
	void ShowStatus();
	~PokemonCenter();
	bool ShouldBeVisible();
};

#endif