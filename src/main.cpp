/*
Gerald Coggins
----------------------------------
[insert name here]

A simple text game: walk around in an open space with random encounters.

TODO:
x	clean up combat and interface
	clean up more
	move combat to its own files
	create method of moving around
	create area to move around in
	make encounters random
	add goal

=================
FILE MAP
=================
Types.hpp >> Globals.hpp >> start all file lines with these


CreatureInfo.hpp >> Creature.hpp >> Creature.cpp >>




*/



//#include <TextGame/Interface.hpp>

//#include <TextGame/Navigation.hpp>
#include <TextGame/Creature.hpp>
//#include <TextGame/Combat.hpp>

#include <iostream>
#include <sstream>

int main (int argc, char* argv)
{
bool testingRoom = false;
bool isCharNamed = false;
bool isBattling = false;

bool running = true;
while(running)
{

TextGame::Player player;
std::cout << "[Opening Text Here]\n\n\n";
std::string input; // used by getline()

	while (isCharNamed == false) // character naming
	{
		std::cout << "Enter your characters name.\n";

		// recieve input from getline() for name
		std::getline(std::cin, input);
		std::string playerName = input;
		std::cin.clear();

		std::cout << "\n\n\n";

		// check for no input
		if(playerName == "\0")
			playerName = player.name;
		//FIXME add a way to check if name is too long

		std::cout << playerName << " is the name you want?\n";
		std::cout << "1. yes 2. no>\n";

		// recive input from cin for choices
		// FIXME make function getInput()
		std::getline(std::cin, input);
		std::string choice = input;
		std::cin.clear();

		if(choice == "1" || choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y")
		{
			std::cout << "\n\n\nGame Started\n";
			player.name = playerName;
			isCharNamed = true;
		}
		else if (choice == "2" || choice == "No" || choice == "no" || choice == "N" || choice == "n")
			std::cout << "\n";
		else
			std::cout << "\nInvalid input.\n\n\n";
		} // end character naming

	while (testingRoom == true)
	{
		std::cout << "Welcome to the testing room\n";
		std::cout << "A few debugging and testing features will be put in here.\n\n\n";


		std::cout << "1. set starting level\n";
		std::cout << "4. spawn level 10 monster\n";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "99. Exit\n";


		std::getline(std::cin, input);
		std::string choice = input;
		std::cin.clear();

		std::cout << "\n\n\n\n";

		//set playerlevel
		if(choice == "1")
		{
			std::cout << "Enter level to start.\n\n";

			//FIXME need a better way
			//trying out string stream
			std::stringstream ss;

			ss.clear();
			ss.str("");

			std::string ssinput = "";

			int n;

			while (true) {
				if (!std::getline(std::cin, ssinput))
					return -1;

				ss.str(ssinput);

				if (ss >> n)
					break;

				std::cout << "Invalid number, please try again" << std::endl;

				ss.clear();
				ss.str("");
				ssinput.clear();
			}
		 
			if(n <= 1)
				player.exp = 0;
			else
				player.exp = (n - 1) * 2;

		}

		// battle monsterB
		else if (choice == "4")
		{

			TextGame::EnemyB enemy(18, "Test Monster");
			std::cout << "A wild " << enemy.name << " appeared!\n\n";
			isBattling = true;
			while (isBattling == true)
			{
				//FIXME make a function
				player.hitPoints = player.hitPointsBase * player.hitPointsMult;

				std::cout << "--------------------------\n";
				std::cout << "This debug monster can't hurt you.\n";
				std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
				std::cout << "What will you do?\n";
				std::cout << "1. Attack 2. Run\n\n";

				std::getline(std::cin, input);
				std::string choice = input;
				std::cin.clear();

				if (choice == "1" || choice == "Attack" || choice == "attack" || choice == "A" || choice == "a")
				{
					// make sure hitPoints don't go under 0
					if (enemy.hitPoints < player.damage)
					{
						enemy.hitPoints = 0;
						std::cout << "You did " << player.damage << " damage.\n\n";
					}
					else
					{
						//FIXME player.attack(enemy);
						enemy.hitPoints = enemy.hitPoints - player.damage;
						std::cout << "You did " << player.damage << " damage.\n\n";
					}

					// win
					if (enemy.hitPoints <= 0)
					{
						std::cout << "You Win!\n";
						//FIXME make function V V V
						player.exp = player.exp + 0;
						std::cout << "You gained " << 0 << " exp\n\n";
						//FIXME make function V V V V
						player.level = player.level + player.exp / 2;
						isBattling = false;
					}
					// check enemy is still alive to attack
					if (enemy.hitPoints > 0)
					{
						//make sure hitPoints don't go under 0
						if (player.hitPoints < enemy.damage)
							player.hitPoints = 0;
						else
						{
							std::cout << enemy.name << " is attacking!.\n";
							//FIXME enemy.attack(player);
							player.hitPoints = player.hitPoints - enemy.damage;
							std::cout << "You took " << enemy.damage << " damage.\n\n\n";
						}
					}

					// lose
					if (player.hitPoints <= 0)
					{
						std::cout << "You died.\nGAME OVER.\n\n";
						std::cout << "1. Restart 2. Exit\n\n";

						std::getline(std::cin, input);
						std::string choice = input;
						std::cin.clear();

						// Restart
						if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r")
						{
							std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
							isBattling = false;
							isCharNamed = false;
						}
						// Exit
						else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
						{
							isBattling = false;
							running = false;
						}
						else
							std::cout << "Invaid input.\n\n";

					}

				}

				//run
				else if (choice == "2" || choice == "Run" || choice == "run" || choice == "R" || choice == "r")
				{
					std::cout << "You ran away.\n\n\n";
					isBattling = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			} // end is battling
		}

		else if(choice == "99")
			testingRoom = false;
		else
			std::cout << "Invaid input.\n\n";
	}
	
bool isPlaying = true;
	while (isPlaying)
	{
		// update stats
		player.update(); // Creature.cpp

		isBattling = false;

		std::cout << "==================================\n";
		std::cout << "Reach level 15 to win.\n";
		std::cout << "level " << player.level << "/15\n\n";
		std::cout << "Enter a number to make a choice.\n";

		if(player.level >= 15)
			std::cout << "\n\nEnd. the game\n============\n";

		std::cout << "1. Battle\n2. Check\n3. Rest\n\n9. Restart 10. Quit\n";

		std::getline(std::cin, input);
		std::string choice = input;
		std::cout << "\n\n\n\n";
		std::cin.clear();


		// battle monster
		if (choice == "1" || choice == "Battle" || choice == "battle" || choice == "B" || choice == "b")
		{
			TextGame::EnemyA enemy;

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
				std::cout << "Your Hit Points: " << player.hitPoints << "\n";
				std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
				std::cout << "What will you do?\n";
				std::cout << "1. Attack 2. Run\n\n";

				std::getline(std::cin, input);
				std::string choice = input;
				std::cin.clear();

				if (choice == "1" || choice == "Attack" || choice == "attack" || choice == "A" || choice == "a")
				{
					// make sure hit points don't go under 0
					if (enemy.hitPoints < player.damage)
					{
						enemy.hitPoints = 0;
						std::cout << "You did " << player.damage << " damage.\n\n";
					}
					else
					{
						//FIXME player.attack(enemy);
						enemy.hitPoints = enemy.hitPoints - player.damage;
						std::cout << "You did " << player.damage << " damage.\n\n";
					}

					// win
					if (enemy.hitPoints <= 0)
					{
						std::cout << "You Win!\n";
						//FIXME make function V V V
						player.exp = player.exp + enemy.rewardExp;
						std::cout << "You gained " << enemy.rewardExp << " exp\n\n";
						//FIXME make function V V V
						player.level = player.level + player.exp / 2;
						isBattling = false;
					}

					// check if enemy is still alive to attack
					if (enemy.hitPoints > 0)
					{
						// make sure hit points don't go under 0
						if (player.hitPoints < enemy.damage)
							player.hitPoints = 0;
						else
						{
							//FIXME std::cout << enemy.name << " is attacking!.\n";
							std::cout << "Enemy " << " is attacking!.\n";
							//FIXME enemy.attack(player);
							player.hitPoints = player.hitPoints - enemy.damage;
							std::cout << "You took " << enemy.damage << " damage.\n\n\n";
						}
					}

					// lose
					if (player.hitPoints <= 0)
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
							isBattling = false;
							isCharNamed = false;
							isPlaying = false;
						}
						// exit
						else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
						{
							isBattling = false;
							isPlaying = false;
							running = false;
						}
						else
							std::cout << "Invaid input.\n\n";

					}

				}

				//run
				else if (choice == "2" || choice == "Run" || choice == "run" || choice == "R" || choice == "r")
				{
					std::cout << "You ran away.\n\n\n";
					isBattling = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			} // end is battling
		}

		// check character
		else if(choice == "2" || choice == "Check" || choice == "check" || choice == "C" || choice == "c")
		{
			std::cout <<"==================================\n";
			std::cout << "Character Information:\n\n";
			std::cout << "Name: " << player.name << "\n";
			std::cout << "Level: " << player.level << "\n";
			std::cout << "EXP: " << player.exp << "\n\n";
			std::cout << "Hit Points: " << player.hitPoints << "\n";
			std::cout << "Damage: " << player.damage << "\n";
			std::cout << "Defense: " << player.defense << "<-- Does nothing atm.\n\n\n";
		}

		//rest
		else if (choice == "3" || choice == "Rest" || choice == "rest")
		{
			//FIXME make a function
			player.hitPoints = player.hitPointsBase * player.hitPointsMult;
			std::cout << "You feel rested and ready for battle.\n\n\n";
		}

		//restart
		else if (choice == "9" || choice == "Restart" || choice == "restart")
		{
			std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
			isPlaying = false;
			isCharNamed = false;
		}

		// quit
		else if (choice == "10" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
		{
			isPlaying = false;
			running = false;
		}

		//testing room
		else if (choice == "secret")
		{
			testingRoom = true;
			isPlaying = false;
		}

		// check if win
		else if (choice == "End"|| choice == "end" || choice == "End. the game" || choice == "end. the game" || choice == "End the game" || choice == "end the game")
		{
			if (player.level >= 15)
			{
				std::cout << "You Won!\nThanks for playing!\n\n";
				std::cout << "1. Restart 2. Exit\n\n";

				std::getline(std::cin, input);
				std::string choice = input;
				std::cin.clear();

				if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r")
				{
					std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
					isPlaying = false;
					isCharNamed = false;
				}
				else if (choice == "2" || choice == "Quit" || choice == "quit" || choice == "Q" || choice == "q")
				{
					isPlaying = false;
					running = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			}

			else
				std::cout << "You can't win yet.\n\n";
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