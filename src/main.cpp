/*
Gerald Coggins
----------------------------------
[insert name here]

A simple text game: walk around in an open space with random encounters.

TODO:
x	clean up combat and interface
x	clean up more
x	move combat to its own files
x	create method of moving around
x	create area to move around in
	add collision
x	make encounters random
	make array of monster info
	make function to handle encounters
	add goal

=================
FILE MAP
=================
Types.hpp >> Globals.hpp >> start all file lines with these

				   Interface.hpp >> Combat.hpp
CreatureInfo.hpp >> Creature.hpp >> Combat.hpp >> Navigation.hpp >> main
									   Map.hpp >> Navigation.hpp
									 Rooms.hpp >> Navigation.hpp
		 Objects.hpp >> Items.hpp >> Rooms.hpp




*/



//#include <TextGame/Interface.hpp> // included in Combat.hpp
//#include <TextGame/Creature.hpp> // included in Combat.hpp
//#include <TextGame/Combat.hpp> // included in Navigation.hpp
#include <TextGame/Navigation/Navigation.hpp>

#include <iostream>

int main (int argc, char* argv)
{
// initialize globals - once per run
testingRoom = true; // Globals.hpp
isCharNamed = false;
isBattling = false;
running = true;

while(running)
{
TextGame::Mobile player; //declare player
TextGame::Mobile *ptrPlayer; // declare a pointer
ptrPlayer = &player; // assign address to pointer

player.loc_Row = 10;
player.loc_Col = 4;

TextGame::testRoom * room = new TextGame::testRoom; // declare raw room pointer

TextGame::clearScreen(); // Interface.cpp
std::cout << "[Opening Text Here]\n\n\n";

	while (isCharNamed == false) // character naming
	{
		std::cout << "Enter your characters name.\n";

		std::string playerName = TextGame::getInput(); // Interface.cpp

		std::cout << "\n\n\n";

		// check for no input
		if(playerName == "\0")
			playerName = player.name;
		//FIXME add a way to check if name is too long

		std::cout << playerName << " is the name you want?\n";
		std::cout << "1. yes 2. no>\n";

		// recive input from cin for choices
		std::string choice = TextGame::getInput(); //Interface.cpp

		if(choice == "1" || choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y" || choice == "\0")
		{
			TextGame::clearScreen(); // Interface.cpp
			player.name = playerName;
			isCharNamed = true;
		}
		else if (choice == "2" || choice == "No" || choice == "no" || choice == "N" || choice == "n")
			TextGame::clearScreen(); // Interface.cpp
		else
		{
			TextGame::clearScreen(); // Interface.cpp
			std::cout << "\nInvalid input.\n\n\n";
		}
		} // end character naming

	while (testingRoom == true)
	{
		// moved to init area
		//TextGame::testRoom * room = new TextGame::testRoom;

		player.heal(player.hitPointsMax);

		// need to make temp variables to clear or there's a memory leak

		int* tempLoc = player.getLocation();
		int** tempData = room->returnData();
		int* tempSize = room->returnSize();

		// create area to move in and return 16x16 array for the map
		int** tempNav = TextGame::getNavData(tempLoc, tempData, tempSize);

		//delete new arrays
		TextGame::clearData2D(tempData, tempSize[0]);
		TextGame::clearData1D(tempSize);
		TextGame::clearData1D(tempLoc);

		std::cout << "I'll leave the test room open since the main game doesn't have features added.\n";
		std::cout << "\n\nNow trying genMap\n";
							// Map.cpp
		std::cout << "\n";  TextGame::genMap(0, tempNav); std::cout << room->returnString(1);
		std::cout << "\n";  TextGame::genMap(1, tempNav); std::cout << room->returnString(3);
		std::cout << "\n";  TextGame::genMap(2, tempNav); std::cout << room->returnString(4);
		std::cout << "\n";  TextGame::genMap(3, tempNav); 
		std::cout << "\n";  TextGame::genMap(4, tempNav);
		std::cout << "\n";  TextGame::genMap(5, tempNav); std::cout << "Name: " << player.name;
		std::cout << "\n";  TextGame::genMap(6, tempNav); std::cout << "Level: " << player.level;
		std::cout << "\n";  TextGame::genMap(7, tempNav); std::cout << "HP: " << player.hitPoints << "/" << player.hitPointsMax;
		std::cout << "\n";  TextGame::genMap(8, tempNav); std::cout << "enter W A S D to move";
		std::cout << "\n";  TextGame::genMap(9, tempNav);
		std::cout << "\n"; TextGame::genMap(10, tempNav); std::cout << "1. set starting level";
		std::cout << "\n"; TextGame::genMap(11, tempNav); std::cout << "2. test battle function";
		std::cout << "\n"; TextGame::genMap(12, tempNav); std::cout << "3. battle monster";
		std::cout << "\n"; TextGame::genMap(13, tempNav); std::cout << "4. test room creation";
		std::cout << "\n"; TextGame::genMap(14, tempNav); std::cout << "5. Toggle monster encounters";
		std::cout << "\n"; TextGame::genMap(15, tempNav); std::cout << "99. Exit to main game(nothing here)";

		TextGame::clearData2D(tempNav, 16);

		std::string choice = TextGame::getInput(); // Interface.cpp

		std::cout << "\n\n\n\n\n";

		//set playerlevel
		if(choice == "1")
		{
			std::cout << "Enter level to start.\n\n";

			int level = TextGame::getNumber(); // Interface.cpp
		 
			if(level <= 1)
				player.getExp(0); // Creature.cpp
			else
				player.getExp((level - 1) * 2);

			player.update();
			player.heal(player.hitPointsMax); // Creature.cpp

			TextGame::clearScreen(); // Interface.cpp

		}

		// test battle function
		else if(choice == "2")
		{
			TextGame::startBattle(ptrPlayer); // Combat.cpp
		}

		// battle monsterB
		else if (choice == "3")
		{
			TextGame::clearScreen(); // Interface.cpp
			TextGame::Mobile enemy;
			TextGame::Mobile *ptrMobile; // declare a pointer
			ptrMobile = &enemy; // assign address to pointer

			TextGame::customMobile(ptrMobile); // Combat.cpp

			std::cout << "A wild " << enemy.name << " appeared!\n\n";
			isBattling = true;
			while (isBattling == true)
			{
				std::cout << "--------------------------\n";
				std::cout << "This debug monster can't hurt you.\n";
				std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
				std::cout << "What will you do?\n";
				std::cout << "1. Attack 2. Run\n\n";

				std::string choice = TextGame::getInput(); // Interface.cpp

				if (choice == "1" || choice == "Attack" || choice == "attack" || choice == "A" || choice == "a" || choice == "\0")
				{
					// make sure hitPoints don't go under 0
					if (enemy.hitPoints < player.damage)
					{
						enemy.hitPoints = 0;
						std::cout << "You did " << player.damage << " damage.\n\n";
					}
					else
					{
						TextGame::mobileAttack(ptrPlayer, ptrMobile);
						std::cout << "You did " << player.damage << " damage.\n\n";
					}

					// win
					if (enemy.hitPoints <= 0)
					{
						TextGame::clearScreen(); // Interface.cpp
						std::cout << "You Win!\n";
						player.getExp(0);
						std::cout << "You gained " << "0" << " exp\n\n";
						player.update();
						isBattling = false;
					}
					// check enemy is still alive to attack
					if (enemy.hitPoints > 0)
					{
						//make sure hitPoints don't go under 0
						if (player.hitPoints < enemy.damage)
						{
							player.hitPoints = 0;
							std::cout << "You took " << "0" << " damage.\n\n\n";
						}
						else
						{
							std::cout << enemy.name << " is attacking!.\n";
							std::cout << "You took " << "0" << " damage.\n\n\n";
						}
					}

					// lose
					if (player.hitPoints <= 0)
					{
						std::cout << "You died.\nHow did you do it?\n\n";
						std::cout << "1. Restart 2. Exit\n\n";

						std::string choice = TextGame::getInput(); // Interface.cpp

						// Restart
						if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r" || choice == "\0")
						{;
							// FIXME goBack()
							//TextGame::goBack(); // Interface.cpp
							isPlaying = false;
							isCharNamed = false;
							isBattling = false;
							TextGame::clearScreen(); // Interface.cpp
						}
						// Exit
						else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
						{
							// FIXME goBack()
							//TextGame::goBack(); // Interface.cpp
							isPlaying = false;
							isCharNamed = false;
							isBattling = false;
							running = false;
						}
						else
						{
							TextGame::clearScreen(); // Interface.cpp
							std::cout << "Invaid input.\n\n";
						}

					}

				}

				//run
				else if (choice == "2" || choice == "Run" || choice == "run" || choice == "R" || choice == "r")
				{
					TextGame::clearScreen(); // Interface.cpp
					std::cout << "You ran away.\n\n\n";
					isBattling = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			} // end is battling
		}

		//change rooms
		else if (choice == "4")
		{
			if (testRoomBool == false)
			{
				delete room;
				TextGame::testRoom2 * room = new TextGame::testRoom2;

				testRoomBool = true;
			}
			else if (testRoomBool == true)
			{
				delete room;
				TextGame::testRoom * room = new TextGame::testRoom;

				testRoomBool = false;
			}
			else
				std::cout << "\nFailed Somehow!\n";
		}

		// toggle encounters
		else if (choice == "5")
		{
			if(room->roomEncounterRate == 0)
				room->roomEncounterRate = 10;
			else
				room->roomEncounterRate = 0;
		}

		//move
		else if (choice == "w" || choice == "W" || choice == "a" || choice == "A" || choice == "s" || choice == "S" || choice == "d" || choice == "D")
		{
			if (choice == "w" || choice == "W")
				player.loc_Row = player.loc_Row - 1;
			else if (choice == "a" || choice == "A")
				player.loc_Col = player.loc_Col - 1;
			else if (choice == "s" || choice == "S")
				player.loc_Row = player.loc_Row + 1;
			else if (choice == "d" || choice == "D")
				player.loc_Col = player.loc_Col + 1;
			else
				std::cout << "Invaid input.\n\n";

			int rand = 0;
			rand = std::rand() % 100;
			if(rand < room->roomEncounterRate)
				TextGame::startBattle(ptrPlayer);
			//add battle type to startBattle
			
		}

		//leave testing room
		else if(choice == "99")
			testingRoom = false;
		else
		{
			TextGame::clearScreen(); // Interface.cpp
			std::cout << "Invaid input.\n\n";
		}
	} // end Testing Room
	
TextGame::clearScreen(); // Interface.cpp
isPlaying = true; // Globals.hpp
	while (isPlaying)
	{
		// update stats
		player.update(); // Creature.cpp

		isBattling = false; // Globals.hpp

		//TextGame::clearScreen(); // Interface.cpp
		std::cout << "\n==================================";
		std::cout << "\nReach level 15 to win.";
		std::cout << "\nlevel " << player.level << "/15";
		std::cout << "\n\nEnter a number to make a choice.";


		std::cout << "\n1. Battle\n2. Check\n3. Heal";

		if (player.level >= 15)
			std::cout << "\n8. Win\n";

		std::cout << "\n\n9. Restart 10. Quit";

		std::string choice = TextGame::getInput(); // Interface.cpp

		std::cout << "\n\n\n\n\n";
		
		// battle monster
		if (choice == "1" || choice == "Battle" || choice == "battle" || choice == "B" || choice == "b" || choice == "\0")
		{
			TextGame:startBattle(ptrPlayer); // Combat.cpp
		}

		// check character
		else if(choice == "2" || choice == "Check" || choice == "check" || choice == "C" || choice == "c")
		{
			TextGame::clearScreen(); // Interface.cpp
			std::cout <<"\n==================================";
			std::cout << "\nCharacter Information:";
			std::cout << "\n\nName: " << player.name;
			std::cout << "\nLevel: " << player.level;
			std::cout << "\nEXP: " << player.exp;
			std::cout << "\n\nHit Points: " << player.hitPoints;
			std::cout << "\nDamage: " << player.damage;
			std::cout << "\nDefense: " << player.defense << "<-- Does nothing atm.";

			std::cout << "\n\n";
		}

		//rest
		else if (choice == "3" || choice == "Heal" || choice == "heal" || choice == "H" || choice == "h")
		{
			TextGame::clearScreen(); // Interface.cpp
			player.heal(player.hitPointsMax); // Creature.cpp
			std::cout << "You feel rested and ready for battle.";

			std::cout << "\n\n";
		}
		
		// check if win
		else if (choice == "8" || choice == "Win" || choice == "win" || choice == "W" || choice == "w")
		{
			if (player.level >= 15)
			{
				std::cout << "You Won!\nThanks for playing!";
				std::cout << "\n\n1. Restart 2. Exit";

				std::string choice = TextGame::getInput(); // Interface.cpp

				if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r" || choice == "\0")
				{
					TextGame::clearScreen(); // Interface.cpp
					isPlaying = false;
					isCharNamed = false;
					isBattling = false;
					// FIXME goBack()
					//TextGame::goBack(); // Interface.cpp
				}
				else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
				{
					// FIXME goBack()
					//TextGame::goBack(); // Interface.cpp
					isPlaying = false;
					isCharNamed = false;
					isBattling = false;
					running = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			}

			else
				std::cout << "You can't win yet.\n\n";
		}

		//restart
		else if (choice == "9" || choice == "Restart" || choice == "restart")
		{
			TextGame::clearScreen(); // Interface.cpp
			isPlaying = false;
			isCharNamed = false;
			isBattling = false;
			// FIXME goBack()
			//TextGame::goBack(); // Interface.cpp
		}

		// quit
		else if (choice == "10" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
		{
			isPlaying = false;
			isCharNamed = false;
			isBattling = false;
			running = false;
			// FIXME goBack()
			//TextGame::goBack(); // Interface.cpp
		}

		//testing room
		else if (choice == "secret")
		{
			testingRoom = true;
			isPlaying = false;
			TextGame::clearScreen(); // Interface.cpp
		}

		else
			std::cout << "Invaid input.\n\n";

	}

	// close program
	if(running == false) 
		return 0;
}// end running
	return 0;
}// end main