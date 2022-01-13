#include "GameCommand.h"
#include "Model.h"
#include "Point2D.h"
#include "View.h"

using namespace std;

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id))->GetName() << " to " << p1 << endl;
	(model.GetPokemonPtr(pokemon_id))->StartMoving(p1);	
	return;
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id))->GetName() << " to center " << center_id + 1 << endl;
	(model.GetPokemonPtr(pokemon_id))->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
	return;
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id))->GetName() << " to gym " << gym_id + 1 << endl;
	(model.GetPokemonPtr(pokemon_id))->StartMovingToGym(model.GetPokemonGymPtr(gym_id));		
	return;
}

void DoStopCommand(Model& model, int pokemon_id)
{
	cout << "Stopping " << (model.GetPokemonPtr(pokemon_id))->GetName() << " P" << pokemon_id << endl;
	(model.GetPokemonPtr(pokemon_id))->Stop();
	return;	
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
	cout << "Training " << (model.GetPokemonPtr(pokemon_id))->GetName() << endl;
	(model.GetPokemonPtr(pokemon_id))->StartTraining(training_units);
	return;
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
	cout << "Recovering " << (model.GetPokemonPtr(pokemon_id))->GetName() << "'s stamina" << endl;
	(model.GetPokemonPtr(pokemon_id))->StartRecoveringStamina(stamina_points);
	return;
}

void DoGoCommand(Model& model, View& view)
{
	cout << "Advancing one tick." << endl;
	model.Update();
	model.Display(view);
	return;
}

void DoRunCommand(Model& model, View& view)
{
	int count = 0;
	int upcount = 0;
	do
	{
		cout << "Advancing one tick." << endl;
		upcount = model.Update();
		model.Display(view);
		count++;
	}while((upcount == 0) && (count < 5));
	return;
}

//PA4 Additions
void DoBattleCommand(Model& model, int pokemon_id, int rival_id)
{
	cout << (model.GetPokemonPtr(pokemon_id))->GetName() << " wants to challenge " << (model.GetRivalPtr(rival_id))->get_name() << " to a battle!" << endl;
	(model.GetPokemonPtr(pokemon_id))->ReadyBattle(model.GetRivalPtr(rival_id));
	return;
}

void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id)
{
	cout << "Moving " << (model.GetPokemonPtr(pokemon_id))->GetName() << " to arena " << arena_id + 1 << endl;
	(model.GetPokemonPtr(pokemon_id))->StartMovingToArena(model.GetBattleArenaPtr(arena_id));		
	return;
}