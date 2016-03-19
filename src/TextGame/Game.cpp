/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Game.cpp (Game.hpp)
)					main game loop
)
)				
)					
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Game.hpp>


namespace TextGame
{

	int mainGame(Creature* ptrPlayer, int& gameMode)
	{
		if(gameMode != 1)
			return gameMode;
		else
		{
			TextGame::Room * room = new TextGame::Room; // remember to delete
			setRoomInfo(3, room); // RoomInteger.cpp
			int tempInteract = 0;

			ptrPlayer->setLocation(9, 3);

			while (gameMode == 1)
			{
				// update stats
				ptrPlayer->update(); // Creature.cpp

				std::cout << "\n\n";

				printMap(ptrPlayer, room); // Map.cpp

				// check if player pressed interact
				std::cout << "\n                 ";
				if (tempInteract == 1)
					std::cout << playerInteract(ptrPlayer, room); // PlayerActions.cpp
				tempInteract = 0;

				std::cout << "\n1. Check Stats\n2. Heal";
	
				if (ptrPlayer->level >= 5)
					std::cout << "\n8. Win\n";
	
				std::cout << "\n\n9. Quit";
	
				char choice = _getch(); // Interface.cpp

				clearScreen();
														   //move
				if (choice == 'w' || choice == 'W' || choice == 'a' || choice == 'A' || choice == 's' || choice == 'S' || choice == 'd' || choice == 'D')
				{
					moveCreature(ptrPlayer, room, choice, gameMode);
				}

				else if (choice == ' ')
					tempInteract = 1;
	
				// check character
				else if (choice == '1'|| choice == 'C' || choice == 'c')
				{
					getCreatureStats(ptrPlayer); // Creature.cpp
				}
	
				//rest
				else if (choice == '2' || choice == 'H' || choice == 'h')
				{
					TextGame::clearScreen(); // Interface.cpp
					ptrPlayer->heal(ptrPlayer->HpStaSpeMax); // CreatureInfo.cpp
					std::cout << "You feel rested and ready for battle.";
	
					std::cout << "\n\n";
				}
	
				// check if win
				else if (choice == '8' || choice == 'W' || choice == 'w')
				{
					if (ptrPlayer->level >= 5)
						gameMode = 90;
				}
	
				//restart
				else if (choice == '9' || choice == 'Q' || choice == 'q')
					gameMode = quitRestart(gameMode);
	
				else
					std::cout << "Invaid input.\n\n";
	
			}
			return gameMode;
		}

	}
	
}// end TextGame
