#include <TextGame/Testing/Test.hpp>


namespace TextGame
{
	void enterTestRoom()
	{
		std::cout << "\nEnter the debug room?\n1. yes else. no";
		std::string choice = getInput();
		if (choice == "1")
			testingRoomMenu();
			
	}

	void testingRoomMenu()
	{

	}
	
	int TestingRoom(Creature* ptrPlayer, int& gameMode)
	{
		if(gameMode != 0)
			return 1;
		int result = 0;

		std::cout << "\nTest room entered.";
		TextGame::testRoom * room = new TextGame::testRoom;
	 	bool testRoomBool = false;
		bool testingTrue = true;
		while (testingTrue == true)
		{
			// moved to init area
			//TextGame::testRoom * room = new TextGame::testRoom;
			
			ptrPlayer->update();
			//ptrPlayer->heal(ptrPlayer->HpStaSpeMax);
		
			// need to make temp variables to clear or there's a memory leak
			int* tempLoc = ptrPlayer->returnLocation();
			int** tempData = room->returnData();
			int* tempSize = room->returnSize();
		
			// create area to move in and return 16x16 array for the map
			int** tempNav = TextGame::getNavData(tempLoc, tempData, tempSize);
		
			//delete new arrays
			TextGame::clearData(tempData, tempSize[0]);
			TextGame::clearData(tempSize);
			TextGame::clearData(tempLoc);
		
			std::cout << "\nI'll leave the test room open since the main game doesn't have features added.";
			std::cout << "\n\nNow trying genMap\n";

			// Map.cpp
			std::cout << "\n";  TextGame::genMap(0, tempNav, ptrPlayer->direction); std::cout << room->returnString(1);
			std::cout << "\n";  TextGame::genMap(1, tempNav, ptrPlayer->direction); std::cout << room->returnString(3);
			std::cout << "\n";  TextGame::genMap(2, tempNav, ptrPlayer->direction); std::cout << room->returnString(4);
			std::cout << "\n";  TextGame::genMap(3, tempNav, ptrPlayer->direction); 
			std::cout << "\n";  TextGame::genMap(4, tempNav, ptrPlayer->direction);
			std::cout << "\n";  TextGame::genMap(5, tempNav, ptrPlayer->direction); std::cout << "Name: " << ptrPlayer->name;
			std::cout << "\n";  TextGame::genMap(6, tempNav, ptrPlayer->direction); std::cout << "Level: " << ptrPlayer->level << " Exp tnl: " << ptrPlayer->returnExpTnl();
			std::cout << "\n";  TextGame::genMap(7, tempNav, ptrPlayer->direction); std::cout << "HP: " << ptrPlayer->hitPoints << "/" << ptrPlayer->HpStaSpeMax;
			std::cout << "\n";  TextGame::genMap(8, tempNav, ptrPlayer->direction); std::cout << "enter W A S D to move";
			std::cout << "\n\n1. add exp";
			std::cout << "\n2. set level";
			std::cout << "\n3. test battle function";
			std::cout << "\n4. test room creation";
			std::cout << "\n5. Toggle monster encounters";
			std::cout << "\n6. heal";
			std::cout << "\n\n9. Exit to main game(nothing here)";
			std::cout << "\n";

			char choice = _getch(); // Interface.cpp
		
			std::cout << "\n\n\n\n\n";
		
			//set playerlevel
			if (choice == '1')
			{
				std::cout << "Enter level to start.\n\n";

				ptrPlayer->addExp(TextGame::getNumber()); // CreatureInfo.cpp

				ptrPlayer->update();
				ptrPlayer->heal(ptrPlayer->HpStaSpeMax); // Creature.cpp

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
				result = TextGame::startBattle(ptrPlayer); // Combat.cpp
				if(result == 99 || result == 100)
					testingTrue = false;
			}
		
			//change rooms
			else if (choice == '4')
			{
				//FIXME make rooms come from a single struct
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
				result = moveCreature(ptrPlayer, room, choice);
				if (result == 100)
					testingTrue = false;
			}
		
			//leave testing room
			else if (choice == '9')
				testingTrue = false;
			else
			{
				TextGame::clearScreen(); // Interface.cpp
				std::cout << "Invaid input.\n\n";
			}

			TextGame::clearData(tempNav, g_mapSizeCol);
		}
	
	delete room;
	testingTrue = false;
	return result;
	} // end Testing Room
	

} // end TextGame

