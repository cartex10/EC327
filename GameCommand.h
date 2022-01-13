#include "Model.h"
#include "Point2D.h"
#include "View.h"

using namespace std;

#ifndef GameCommand_h
#define GameCommand_h

void DoMoveCommand(Model&, int, Point2D);
void DoMoveToCenterCommand(Model&, int, int);
void DoMoveToGymCommand(Model&, int, int);
void DoStopCommand(Model&, int);
void DoTrainInGymCommand(Model&, int, unsigned int);
void DoRecoverInCenterCommand(Model&, int, unsigned int);
void DoGoCommand(Model&, View&);
void DoRunCommand(Model&, View&);

void DoBattleCommand(Model&, int, int);		//PA4 Additions
void DoMoveToArenaCommand(Model&, int, int);

#endif