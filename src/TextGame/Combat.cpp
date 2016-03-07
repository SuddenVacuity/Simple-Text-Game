

//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================

#include <TextGame/Combat.hpp>
#include <iostream>

namespace TextGame
{
	void playerAttack(Player *attacker, Enemy *target)
	{
		target->hitPoints = target->hitPoints - attacker->damage;
	}
	void enemyAttack(Enemy *attacker, Player *target)
	{
		target->hitPoints = target->hitPoints - attacker->damage;
	}

	void startBattle(Player *ptrPlayer)
	{
		TextGame::Enemy enemy;
		TextGame::Enemy *ptrEnemy; // declare a pointer
		ptrEnemy = &enemy; // assign address to pointer

		bool isChoosing = true;
		while (isChoosing == true)
		{
			// picking monster to battle
			std::cout << "Pick a monster to battle.\n\n";
			std::cout << "1. Weak\n2. Average\n3. Strong\n";
			std::getline(std::cin, input);
			std::string choice = input;
			std::cin.clear();

			std::cout << "\n\n\n\n";

			//set what monster appears
			//enemy.setEnemy("name", exp, hpbase, dmgbase, defbase, hpmult, dmgmult, defmult)
			if (choice == "1" || choice == "Weak" || choice == "weak" || choice == "W" || choice == "w")
			{
				enemy.setEnemy("Weak Generic Monster", 0, 30, 15, 3, 0.2f, 0.2f, 0.2f); // Creature.cpp
				isChoosing = false;
			}

			else if (choice == "2" || choice == "Average" || choice == "average" || choice == "A" || choice == "a")
			{
				enemy.setEnemy("Average Generic Monster", 8, 30, 15, 3, 0.2f, 0.2f, 0.2f);
				isChoosing = false;
			}

			else if (choice == "3" || choice == "Strong" || choice == "strong" || choice == "S" || choice == "s")
			{
				enemy.setEnemy("Strong Generic Monster", 18, 30, 15, 3, 0.2f, 0.2f, 0.2f);
				isChoosing = false;
			}
			else
				std::cout << "\nInvalid input.\n\n\n";

		}// end isChoosing

		// starting battle
		std::cout << "A wild " << enemy.name << " appeared!\n\n";
		isBattling = true;
		while (isBattling == true)
		{
			std::cout << "--------------------------\n";
			std::cout << "Your Hit Points: " << ptrPlayer->hitPoints << "\n";
			std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
			std::cout << "What will you do?\n";
			std::cout << "1. Attack 2. Run\n\n";

			std::getline(std::cin, input);
			std::string choice = input;
			std::cin.clear();

			if (choice == "1" || choice == "Attack" || choice == "attack" || choice == "A" || choice == "a")
			{
				// make sure hit points don't go under 0
				if (enemy.hitPoints < ptrPlayer->damage)
				{
					enemy.hitPoints = 0;
					std::cout << "You did " << ptrPlayer->damage << " damage.\n\n";
				}
				else
				{
					playerAttack(ptrPlayer, ptrEnemy); // Combat.cpp
					std::cout << "You did " << ptrPlayer->damage << " damage.\n\n";
				}

				// win
				if (enemy.hitPoints <= 0)
				{
					std::cout << "You Win!\n";
					ptrPlayer->getExp(enemy.rewardExp);

					std::cout << "You gained " << enemy.rewardExp << " exp\n\n";
					ptrPlayer->update();

					isBattling = false;
				}

				std::cout << enemy.name << " is attacking!.\n";

				// check if enemy is still alive to attack
				if (enemy.hitPoints > 0)
				{
					// make sure hit points don't go under 0
					if (ptrPlayer->hitPoints < enemy.damage)
						ptrPlayer->hitPoints = 0;
					else
					{
						enemyAttack(ptrEnemy, ptrPlayer); // Combat.cpp
						std::cout << "You took " << enemy.damage << " damage.\n\n\n";
					}
				}

				// lose
				if (ptrPlayer->hitPoints <= 0)
				{
					std::cout << "You died.\nGAME OVER.\n\n";
					std::cout << "1. Restart 2. Quit\n\n";

					std::getline(std::cin, input);
					std::string choice = input;
					std::cin.clear();
					// restart
					if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r")
					{
						std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
						// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
						isPlaying = false;
						isCharNamed = false;
						isBattling = false;
					}
					// exit
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

			} // end chose attack

			//run
			else if (choice == "2" || choice == "Run" || choice == "run" || choice == "R" || choice == "r")
			{
				std::cout << "You ran away.\n\n\n";
				isBattling = false;
			}
			else
				std::cout << "Invaid input.\n\n";
		} // end is battling

		return;
	}



} // end TextGame
