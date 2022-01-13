# EC327
The final programming assignment for my Software Design class I took in Fall 2019

## Importance
The main concept I learned in this assignment was object oriented programming, as every part of the assignment revolved around writing multiple classes, and making sure they interacted with each other correctly
The next concept I learned was version control, as at the time, this was a new concept to me I had never worked with before. Sadly, as I lost the original repo, the pushes I made are lost, but the lessons I learned have helped me with other projects found on my github.

## How to run
Once the source files have been downloaded, run 'make' in the command line in order to compile the program, then run './PA4' to run the compiled output. This should run the program and immediately show you the default game start, along with a bunch of lines showing what objects have been constructed.

## Playing the game
In order to play the game, follow the commands below to complete the main objective. Your objective is to use both of your pokemon, marked P1 and P2 on the map, to defeat both gyms while being careful that they do not run out of stamina and faint.

### Commands
m ID1 x y
* Commands Pokemon with ID1 to begin moving to location x, y. This does not happen instantly and depends on their movement speed. This applies to all movement in the game. Moving also gives a random amount of Pokemon Dollars, which are necessary to train or recover stamina.

g ID1 ID2
* Commands Pokemon with ID1 to begin moving to Gym with ID2. Gyms are where you can train your pokemon in order to gain experience points.

c ID1 ID2
* Commands Pokemon with ID1 to begin moving to Center with ID2. Centers are where your pokemon can recover stamina, as long as you can pay the cost of recovering at the Center.

s ID1
* Cancels previously set command on Pokemon with ID1.

r ID1 STAM
* Commands Pokemon with ID1 to recover STAM amount of stamina points. Must be done when pokemon is at a Center.

t ID1 TRAIN
* Commands Pokemon with ID1 to train TRAIN amount of times at a Gym.

v
* Continues the game by one step.

x
* Continues the game until the next time a Pokemon has completed a command.

b ID1 ID2
* Commands Pokemon with ID1 to battle with Rival with ID2. Must be done at the correct Battle Arena.

a ID1 ID2
* Commands Pokemon with ID1 to begin moving to Battle Arena with ID2. Battle Arenas are where your Rivals are located, and all Rivals must be defeated in order to beat the game.

n TYPE ID1 x y
* Creates a new object of type TYPE at coordinates x, y. Options are g for Gym, c for Center, p for Pokemon, and r for Rival.

q
* Deconstructs all objects and ends the program.
