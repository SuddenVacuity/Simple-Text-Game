/*
Gerald Coggins
----------------------------------
[insert name here]

A simple text game: walk around in an open space with random encounters.

TODO:
x	clean up combat and interface
x	clean up more									 --. . . , , , ; ; ; ; 
x	move combat to its own files					 --. . . , , , ; ; ; ;
x	create method of moving around					 --t
x	create area to move around in					 --T
x	add collision									 --
x	make encounters random							 --/ T T T \
x	make array of monster info						 --[ _ O _ ] s =
	make rooms come from a single struct
x	set gamemodes
	add interaction with rooms
	make function to handle encounters
	add weapon/armor/skill/class
	load creature/room/weapon/armor/skill/class info from external files
	add goal

	Always TODO: clean up

=================
FILE MAP
=================
CleanUp.hpp >> Globals.hpp >> start all file lines with these

			PlayerStatistics.hpp >> Combat.hpp		   testRoom.hpp >> Rooms.hpp >> Map.hpp 
CreatureInfo.hpp >> Creature.hpp >> Combat.hpp >> Navigation.hpp >> Movement.hpp >> Map.hpp >> Game.hpp >> main.cpp
				   Interface.hpp >> Combat.hpp												   Test.hpp >> main.cpp


*/

#include <TextGame/Title.hpp>
#include <TextGame/Game.hpp>
#include <TextGame/Testing/Test.hpp>

int main (int argc, char* argv)
{
// initialize globals - once per run

int gameMode = 0;
// 0 = uninitialized
// 1 = ready to play
// 2 = new game
// 98 debug
// 99 = restart
// 100 = quit

while(gameMode != 100)
{
TextGame::Creature *ptrPlayer; // declare a pointer
TextGame::Creature player(1, 1, 5, 5); //declare player
ptrPlayer = &player; // assign address to pointer
ptrPlayer->update(); // Creature.cpp
ptrPlayer->updateHitPoints(); // Creature.cpp


	gameMode = TextGame::titleScreen(gameMode); // Title.cpp

	gameMode = TextGame::TestingRoom(ptrPlayer, gameMode); // Test.cpp

	while (gameMode == 2) // character naming
	{
		std::cout << "Enter your characters name.\n";

		std::string playerName = TextGame::getInput(); // Interface.cpp

		std::cout << "\n\n\n";

		// check for no input
		if(playerName == "\0")
			playerName = ptrPlayer->name;
		//FIXME add a way to check if name is too long

		std::cout << playerName << " is the name you want?\n";
		std::cout << "1. yes 2. no>\n";

		// recive input from cin for choices
		std::string choice = TextGame::getInput(); //Interface.cpp

		if(choice == "1" || choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y" || choice == "\0")
		{
			TextGame::clearScreen(); // Interface.cpp
			ptrPlayer->name = playerName;
			gameMode = 1;
		}
		else if (choice == "2" || choice == "No" || choice == "no" || choice == "N" || choice == "n")
			TextGame::clearScreen(); // Interface.cpp
		else
		{
			TextGame::clearScreen(); // Interface.cpp
			std::cout << "\nInvalid input.\n\n\n";
		}
		} // end character naming

	gameMode = TextGame::mainGame(ptrPlayer, gameMode); // Game.cpp

	if(gameMode == 99)
		gameMode = 0;

}// end game
	return 0;
}// end main