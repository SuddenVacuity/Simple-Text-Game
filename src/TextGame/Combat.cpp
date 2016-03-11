

//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================

#include <TextGame/Combat.hpp>
#include <iostream>

namespace TextGame
{
	void mobileAttack(Mobile *attacker, Mobile *target)
	{
		target->hitPoints = target->hitPoints - attacker->damage;
	}

	void startBattle(Mobile *ptrPlayer)
	{
		clearScreen(); // Interface.cpp
		TextGame::Mobile enemy;
		TextGame::Mobile *ptrMobile; // declare a pointer
		ptrMobile = &enemy; // assign address to pointer

		bool isChoosing = true;
/*		while (isChoosing == true)
		{
			// picking monster to battle
			std::cout << "Pick a monster to battle.";
			std::cout << "\n\n1. Weak\n2. Average\n3. Strong";
			std::string choice = getInput();

			std::cout << "\n\n\n\n\n";

			//set what monster appears
			//enemy.setMobile("name", exp, hpbase, dmgbase, defbase, hpmult, dmgmult, defmult)
			//FIXME make function to make monsters
			if (choice == "1" || choice == "Weak" || choice == "weak" || choice == "W" || choice == "w" || choice == "\0")
			{
				enemy.setMobile("Weak Generic Monster", 0, 30, 15, 3, 0.2f, 0.2f, 0.2f); // Creature.cpp
				isChoosing = false;
			}

			else if (choice == "2" || choice == "Average" || choice == "average" || choice == "A" || choice == "a")
			{
				enemy.setMobile("Average Generic Monster", 8, 30, 15, 3, 0.2f, 0.2f, 0.2f);
				isChoosing = false;
			}

			else if (choice == "3" || choice == "Strong" || choice == "strong" || choice == "S" || choice == "s")
			{
				enemy.setMobile("Strong Generic Monster", 18, 30, 15, 3, 0.2f, 0.2f, 0.2f);
				isChoosing = false;
			}
			else
				std::cout << " <<- Invalid input ->>\n\n\n";

		}// end isChoosing
*/

		//FIXME add overload and arrays to do this
		enemy.setMobile("Monster", ptrPlayer->exp, 30, 15, 3, 0.2f, 0.2f, 0.2f); // Creature.cpp

		// starting battle
		clearScreen(); // Interface.cpp
		std::cout << "A wild " << enemy.name << " appeared!";
		isBattling = true;
		while (isBattling == true)
		{
			std::cout << "\n\n--------------------------";
			std::cout << "\nYour Hit Points: " << ptrPlayer->hitPoints;
			std::cout << "\nEnemy Hit Points: " << enemy.hitPoints;
			std::cout << "\n\nWhat will you do?";
			std::cout << "\n1. Attack 2. Run";

			std::cout << "\n\n";

			std::string choice = getInput(); // Inteface.cpp

			if (choice == "1" || choice == "Attack" || choice == "attack" || choice == "A" || choice == "a" || choice == "\0")
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
					ptrPlayer->getExp(enemy.rewardExp);

					std::cout << "\nYou gained " << enemy.rewardExp << " exp";
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

					std::string choice = getInput(); // Interface.cpp

					// restart
					if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r" || choice == "\0")
					{// FIXME goBack()
						//TextGame::goBack(); // Interface.cpp
						isPlaying = false;
						isCharNamed = false;
						isBattling = false;

						ptrPlayer->heal(ptrPlayer->hitPointsMax);
						clearScreen(); // Interface.cpp
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
						std::cout << " <<- Invalid input ->>\n\n\n";

				}

			} // end chose attack

			//run
			else if (choice == "2" || choice == "Run" || choice == "run" || choice == "R" || choice == "r")
			{
				clearScreen(); // Interface.cpp
				
				std::cout << "You ran away.";
				isBattling = false;
			}
			else
				std::cout << " <<- Invalid input ->>\n\n\n";
		} // end is battling

		return;
	}


	void customMobile(Mobile *ptrMobile)
	{
		
		std::string name = getInput();
		int exp, levelCap, hitPointsCap, damageCap, defenseCap;
		int hitPointsBase, damageBase,  defenseBase;
		float hitPointsMult, damageMult,  defenseMult;
	}

} // end TextGame
