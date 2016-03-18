#include <TextGame/Testing/Test.hpp>


namespace TextGame
{
	int TestingRoom(Creature* ptrPlayer, int& gameMode)
	{
		if(gameMode != 98)
			return gameMode;

		std::cout << "\nTest room entered.";
		TextGame::Room * room = new TextGame::Room; // remember to delete
		setRoomInfo(1, room); // RoomInteger.cpp
		int tempInteract = 0;

		while (gameMode == 98)
		{
			ptrPlayer->update();

			std::cout << "\nI'll leave the test room open since the main game doesn't have features added.\n\n";

			printMap(ptrPlayer, room); // Map.cpp
			
			// check if player pressed interact
			std::cout << "\n                 ";
			if( tempInteract == 1)
			std::cout << playerInteract(ptrPlayer, room); // PlayerActions.cpp
			tempInteract = 0;

			std::cout << "\n1. add exp";
			std::cout << "\n2. set level";
			std::cout << "\n3. test battle function";
			std::cout << "\n5. Toggle monster encounters";
			std::cout << "\n6. heal";
			std::cout << "\n\n9. Exit to main game(nothing here)";
			std::cout << "\n";

			char choice = _getch(); // Interface.cpp
		
			std::cout << "\n\n\n\n\n";
		
			//set playerlevel
			if (choice == '1')
			{
				std::cout << "Enter amount of exp to add.\n\n";

				ptrPlayer->addExp(TextGame::getNumber()); // CreatureInfo.cpp
				ptrPlayer->heal(ptrPlayer->HpStaSpeMax); // CreatureInfo.cpp

				TextGame::clearScreen(); // Interface.cpp

			}

			if (choice == '2')
			{
				std::cout << "Enter level to start.\n\n";

				ptrPlayer->setLevel(TextGame::getNumber()); // CreatureInfo.cpp

				ptrPlayer->updateLevel();
				ptrPlayer->heal(ptrPlayer->HpStaSpeMax); // Creature.cpp

				TextGame::clearScreen(); // Interface.cpp

			}
		
			// test battle function
			else if (choice == '3')
			{
				TextGame::startBattle(ptrPlayer, gameMode); // Combat.cpp
			}
		
			// toggle encounters
			else if (choice == '5')
			{
				if (room->roomEncounterRate == 0)
					room->roomEncounterRate = 10;
				else
					room->roomEncounterRate = 0;
			}

			else if (choice == '6')
				ptrPlayer->heal(ptrPlayer->HpStaSpeMax);

			//move
			else if (choice == 'w' || choice == 'W' || choice == 'a' || choice == 'A' || choice == 's' || choice == 'S' || choice == 'd' || choice == 'D')
			{
				moveCreature(ptrPlayer, room, choice, gameMode);
			}

			else if (choice == ' ')
				tempInteract = 1;
		
			//leave testing room
			else if (choice == '9')
				gameMode = 1;
			else
			{
				TextGame::clearScreen(); // Interface.cpp
				std::cout << "Invaid input.\n\n";
			}

		}
	
	delete room;
	return gameMode;
	} // end Testing Room
	

} // end TextGame
