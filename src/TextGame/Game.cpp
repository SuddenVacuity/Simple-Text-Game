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

		while (gameMode == 1)
		{
			// update stats
			ptrPlayer->update(); // Creature.cpp
	
								//TextGame::clearScreen(); // Interface.cpp
			std::cout << "\n==================================";
			std::cout << "\nReach level 15 to win.";
			std::cout << "\nlevel " << ptrPlayer->level << "/15";
			std::cout << "\n\nEnter a number to make a choice.";
	
	
			std::cout << "\n1. Battle\n2. Check\n3. Heal";
	
			if (ptrPlayer->level >= 15)
				std::cout << "\n8. Win\n";
	
			std::cout << "\n\n9. Restart 10. Quit";
	
			std::string choice = TextGame::getInput(); // Interface.cpp
	
			std::cout << "\n\n\n\n\n";
	
			// battle monster
			if (choice == "1" || choice == "Battle" || choice == "battle" || choice == "B" || choice == "b" || choice == "\0")
			{
			TextGame:startBattle(ptrPlayer, gameMode); // Combat.cpp
			}
	
			// check character
			else if (choice == "2" || choice == "Check" || choice == "check" || choice == "C" || choice == "c")
			{
				TextGame::clearScreen(); // Interface.cpp
				std::cout << "\n==================================";
				std::cout << "\nCharacter Information:";
				std::cout << "\n\nName: " << ptrPlayer->name;
				std::cout << "\nLevel: " << ptrPlayer->level;
				std::cout << "\nEXP: " << ptrPlayer->exp;
				std::cout << "\n\nHit Points: " << ptrPlayer->hitPoints;
				std::cout << "\nDamage: " << ptrPlayer->damage;
				std::cout << "\nDefense: " << ptrPlayer->defense << "<-- Does nothing atm.";
	
				std::cout << "\n\n";
			}
	
			//rest
			else if (choice == "3" || choice == "Heal" || choice == "heal" || choice == "H" || choice == "h")
			{
				TextGame::clearScreen(); // Interface.cpp
				ptrPlayer->heal(ptrPlayer->HpStaSpeMax); // Creature.cpp
				std::cout << "You feel rested and ready for battle.";
	
				std::cout << "\n\n";
			}
	
			// check if win
			else if (choice == "8" || choice == "Win" || choice == "win" || choice == "W" || choice == "w")
			{
				if (ptrPlayer->level >= 15)
				{
					std::cout << "You Won!\nThanks for playing!";
					std::cout << "\n\n1. Restart 2. Exit";
	
					std::string choice = TextGame::getInput(); // Interface.cpp
	
					if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r" || choice == "\0")
					{
						TextGame::clearScreen(); // Interface.cpp
						gameMode = 99;
						// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
					}
					else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
					{
						// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
						gameMode = 100;
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
				gameMode = 99;
				// FIXME goBack()
				//TextGame::goBack(); // Interface.cpp
			}
	
			// quit
			else if (choice == "10" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
			{
				gameMode = 100;
				// FIXME goBack()
				//TextGame::goBack(); // Interface.cpp
			}
	
			else
				std::cout << "Invaid input.\n\n";
	
		}
		return gameMode;
	}
	
}// end TextGame
