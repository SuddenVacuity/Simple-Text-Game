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

				   Interface.hpp >> Combat.hpp >> main
CreatureInfo.hpp >> Creature.hpp >> Combat.hpp >> main




*/



//#include <TextGame/Interface.hpp> // included in Combat.hpp
//#include <TextGame/Creature.hpp> // included in Combat.hpp
#include <TextGame/Combat.hpp>
//#include <TextGame/Navigation.hpp>

#include <iostream>
#include <sstream>

int main (int argc, char* argv)
{
// initialize globals - once per run
testingRoom = false; // Globals.hpp
isCharNamed = false;
isBattling = false;
running = true;

while(running)
{
TextGame::Player player; //declare player
TextGame::Player *ptrPlayer; // declare a pointer
ptrPlayer = &player; // assign address to pointer

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

		std::cout << "Name: " << player.name << "\nHP: " << player.hitPoints << "/" << player.hitPointsMax << "\n\n\n";

		std::cout << "1. set starting level\n";
		std::cout << "2. test battle function\n";
		std::cout << "4. spawn monster\n";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "99. Exit to main game\n";


		std::getline(std::cin, input);
		std::string choice = input;
		std::cin.clear();

		std::cout << "\n\n\n\n";

		//set playerlevel
		if(choice == "1")
		{
			std::cout << "Enter level to start.\n\n";

			//FIXME
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
				player.getExp(0); // Creature.cpp
			else
				player.getExp((n - 1) * 2);

			player.update();
			player.heal(player.hitPointsMax); // Creature.cpp

		}

		// test battle function
		else if(choice == "2")
		{
			TextGame::startBattle(ptrPlayer); // Combat.cpp
		}

		// battle monsterB
		else if (choice == "4")
		{

			TextGame::Enemy enemy(28, "Test Monster");
			TextGame::Enemy *ptrEnemy; // declare a pointer
			ptrEnemy = &enemy; // assign address to pointer

			std::cout << "A wild " << enemy.name << " appeared!\n\n";
			isBattling = true;
			while (isBattling == true)
			{
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
						TextGame::playerAttack(ptrPlayer, ptrEnemy);
						std::cout << "You did " << player.damage << " damage.\n\n";
					}

					// win
					if (enemy.hitPoints <= 0)
					{
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
							player.hitPoints = 0;
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

						std::getline(std::cin, input);
						std::string choice = input;
						std::cin.clear();

						// Restart
						if (choice == "1" || choice == "Restart" || choice == "restart" || choice == "R" || choice == "r")
						{
							std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
							// FIXME goBack()
							//TextGame::goBack(); // Interface.cpp
							isPlaying = false;
							isCharNamed = false;
							isBattling = false;
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
	
isPlaying = true; // Globals.hpp
	while (isPlaying)
	{
		// update stats
		player.update(); // Creature.cpp

		isBattling = false; // Globals.hpp

		std::cout << "==================================\n";
		std::cout << "Reach level 15 to win.\n";
		std::cout << "level " << player.level << "/15\n\n";
		std::cout << "Enter a number to make a choice.\n";


		std::cout << "1. Battle\n2. Check\n3. Heal\n\n";

		if (player.level >= 15)
			std::cout << "8. Win\n";

		std::cout << "9. Restart 10. Quit\n";

		std::getline(std::cin, input);
		std::string choice = input;
		std::cin.clear();

		std::cout << "\n\n\n\n";
		
		// battle monster
		if (choice == "1" || choice == "Battle" || choice == "battle" || choice == "B" || choice == "b")
		{
			TextGame:startBattle(ptrPlayer); // Combat.cpp
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
		else if (choice == "3" || choice == "Heal" || choice == "heal" || choice == "H" || choice == "h")
		{
			player.heal(player.hitPointsMax); // Creature.cpp
			std::cout << "You feel rested and ready for battle.\n\n\n";
		}
		
		// check if win
		else if (choice == "8" || choice == "Win" || choice == "win" || choice == "W" || choice == "w")
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
			std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
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