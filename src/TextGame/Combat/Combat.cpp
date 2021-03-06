/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Combat.cpp (Combat.hpp)
)					Main combat file
)
)				
)				
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Combat/Combat.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				mobileAttack (Combat.hpp)
	)					one Creature can attack another
	)
	)				(Creature* attacker, Creature* target)
	)					must be pointer to class Creature ,attacker attacks target
	)
	)				return int; battle result 0 = lose 1 = win 2 = run
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void mobileAttack(Creature* attacker, Creature* target)
	{
		target->hitPoints = target->hitPoints - attacker->damage;
	}

	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				startBattle (Combat.hpp) TODO: break this into smaller functions
	)					initializes a battle
	)
	)				(Creature* ptrPlayer, int& gameMode)
	)					must be a pointer of class Creature to enter battle (will generally be player)
	)					gameMode = game mode
	)				return int; gamemode
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

	int startBattle(Creature* ptrPlayer, int& gameMode)
	{
		clearScreen(); // Interface.cpp

		// id, level, locRow, locCol
		TextGame::Creature enemy(2, 1, 5, 5);
		TextGame::Creature *ptrMobile; // declare a pointer
		ptrMobile = &enemy; // assign address to pointer
		// FIXME make function to do all this
		ptrMobile->name = returnCreatureString(ptrMobile->id, 6);
		ptrMobile->setMobileLevel(ptrPlayer);
		ptrMobile->update();
		ptrMobile->updateHitPoints();

		// starting battle
		clearScreen(); // Interface.cpp
		std::cout << "A wild Lv: "<< enemy.level << " " << enemy.name << " appeared!";
		bool isBattling = true;
		while (isBattling == true)
		{
			std::cout << "\n\n--------------------------";
			std::cout << "\nYour Hit Points: " << ptrPlayer->hitPoints;
			std::cout << "\nEnemy Hit Points: " << enemy.hitPoints;
			std::cout << "\n\nWhat will you do?";
			std::cout << "\n1. Attack 2. Run";

			std::cout << "\n\n";

			char choice = _getch(); // Inteface.cpp

			clearScreen();

			if (choice == '1' || choice == '\0')
			{
				// make sure hit points don't go under 0
				if (enemy.hitPoints < ptrPlayer->damage)
				{
					enemy.hitPoints = 0;
					std::cout << "You did " << ptrPlayer->damage << " damage.";
				}
				else
				{
					mobileAttack(ptrPlayer, ptrMobile); // Combat.cpp
					std::cout << "You did " << ptrPlayer->damage << " damage.";
				}

				// win
				if (enemy.hitPoints <= 0)
				{
					clearScreen(); // Interface.cpp
					std::cout << "\n\nYou Win!";
					ptrPlayer->addExp(ptrPlayer->getRewardExp(ptrMobile));

					std::cout << "\nYou gained " << ptrPlayer->getRewardExp(ptrMobile) << " exp";
					ptrPlayer->update();
					isBattling = false;
				}


				// check if enemy is still alive to attack
				if (enemy.hitPoints > 0)
				{
				std::cout << "\n\n" << enemy.name << " is attacking!.\n";
					// make sure hit points don't go under 0
					if (ptrPlayer->hitPoints < enemy.damage)
						ptrPlayer->hitPoints = 0;
					else
						mobileAttack(ptrMobile, ptrPlayer); // Combat.cpp

					std::cout << "You took " << enemy.damage << " damage.";
					
				}

				// lose
				if (ptrPlayer->hitPoints <= 0)
				{
					std::cout << "\n\n\nYou died.\nGAME OVER.";
					std::cout << "\n\n1. Restart 2. Quit";

					char choice = _getch(); // Interface.cpp

					// restart
					if (choice == '1' || choice == 'r' || choice == 'R')
					{// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
						gameMode = 99;
						isBattling = false;

						ptrPlayer->heal(ptrPlayer->HpStaSpeMax);
						clearScreen(); // Interface.cpp
					}
					// exit
					else if (choice == '2' || choice == 'q' || choice == 'Q')
					{
						// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
						gameMode = 100;
						isBattling = false;
					}
					else
						std::cout << " <<- Invalid input ->>\n\n\n";

				}

			} // end chose attack

			//run
			else if (choice == '2')
			{
				clearScreen(); // Interface.cpp
				std::cout << "You ran away.";

				isBattling = false;
			}
			else
				std::cout << " <<- Invalid input ->>\n\n\n";
		} // end is battling

		return gameMode;
	}


} // end TextGame
