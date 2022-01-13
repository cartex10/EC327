#include <iostream>
#include "Building.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "GameCommand.h"
#include "View.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
	srand(time(0));
	Model model;
	View view;
	char command, TYPE;
	int ID1, ID2, x, y, stam, train;
	//model.Update();

	model.Display(view);
	
	do
	{
		try
		{
			cout << "Enter valid inputs: ";
			cin >> command;
			switch(command)
			{
				case 'm':
				{
					cin >> ID1 >> x >> y;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					Point2D dest(x, y);
					DoMoveCommand(model, ID1, dest);
					break;
				}
				case 'g':
				{
					cin >> ID1 >> ID2;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					else if(ID2 > model.GetGymNum())
					{
						throw Invalid_Input("Pokemon Gym does not exist.");
					}
					DoMoveToGymCommand(model, ID1, ID2);
					break;
				}
				case 'c':
				{
					cin >> ID1 >> ID2;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					else if(ID2 > model.GetCenterNum())
					{
						throw Invalid_Input("Pokemon Center does not exist.");
					}
					DoMoveToCenterCommand(model, ID1, ID2);
					break;
				}
				case 's':
				{
					cin >> ID1;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					DoStopCommand(model, ID1);
					break;
				}
				case 'r':
				{
					cin >> ID1 >> stam;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					DoRecoverInCenterCommand(model, ID1, stam);
					break;
				}
				case 't':
				{
					cin >> ID1 >> train;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					DoTrainInGymCommand(model, ID1, train);
					break;
				}
				case 'v':
				{
					DoGoCommand(model, view);
					break;
				}
				case 'x':
				{
					DoRunCommand(model, view);
					break;
				}
				case 'b':			//PA4 Addition
				{
					cin >> ID1 >> ID2;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					else if(ID2 > model.GetRivalNum())
					{
						throw Invalid_Input("Rival does not exist.");
					}
					DoBattleCommand(model, ID1, ID2);
					break;
				}
				case 'a':			//PA4 Addition
				{
					cin >> ID1 >> ID2;
					if(ID1 > model.GetPokemonNum())
					{
						throw Invalid_Input("Pokemon does not exist.");
					}
					else if(ID2 > model.GetArenaNum())
					{
						throw Invalid_Input("Battle Arena does not exist.");
					}
					DoMoveToArenaCommand(model, ID1, ID2);
					break;
				}
				case 'n':
				{
					cin >> TYPE >> ID1 >> x >> y;

					if (TYPE == 'g')
					{
						if (ID1 <= model.GetGymNum())
						{
							throw Invalid_Input("A Pokemon Gym with specified ID already exists.");
						}
					}
					else if (TYPE == 'c')
					{
						if (ID1 <= model.GetCenterNum())
						{
							throw Invalid_Input("A Pokemon Center with specified ID already exists.");
						}
					}
					else if (TYPE == 'p')
					{
						if (ID1 <= model.GetPokemonNum())
						{
							throw Invalid_Input("A Pokemon with specified ID already exists.");
						}
					}
					else if (TYPE == 'r')
					{
						if (ID1 <= model.GetRivalNum())
						{
							throw Invalid_Input("A Rival with specified ID already exists.");
						}
					}
					else
					{
						throw Invalid_Input("Specified type is invalid.");
					}

					if (ID1 > 9)
					{
						throw Invalid_Input("IDs must not exceed 9.");
					}

					if ((x < 0) || (x > 20) || ( y < 0) || (y > 20))
					{
						throw Invalid_Input("This is outside of the map.");
					}
					model.NewCommand(TYPE, ID1, x, y);

					break;
				}
				case 'q':
				{
					return 0;
				}
			}
		}
		catch(Invalid_Input& except)
		{
			cout << "Invalid Input: " << except.msg_ptr << endl;
		}
	}while(1);
}