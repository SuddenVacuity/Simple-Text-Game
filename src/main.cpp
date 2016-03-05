/*
Gerald Coggins
----------------------------------
[insert name here]

A simple text game: walk around in an open space with random encounters.

TODO:
	clean up combat and interface
	move combat to its own files
	create method of moving around
	create area to move around in
	make encounters random
	add goal

=================
FILE MAP
=================
Types.hpp >> Globals.hpp >> start all file lines with these


CreatureInfo.hpp >> Creature.hpp >> Creature.cpp




*/

#include <iostream>

//#include <TextGame/Navigation.hpp>
#include <TextGame/Creature.hpp>
//#include <TextGame/Combat.hpp>


int main (int argc, char* argv)
{
bool testingRoom = false;
bool isCharNamed = false;

bool running = true;
while(running)
{

TextGame::Player player;
std::cout << "No time for a story :(\n\n\n";

	while (isCharNamed == false) // character naming
	{
		std::cout << "Enter your characters name.\n";

		// recieve input from cin for name
		char input[33];
		std::cin.getline(input, 33);

		std::string playerName = input;
		std::cin.clear();

		std::cout << "\n\n\n";
		if(playerName == "\0")
			playerName = "testname";
		//FIXME add a way to check if name is too long

		std::cout << playerName << " is the name you want?\n";
		std::cout << "1. yes 2. no>\n";

		// recive input from cin for choices
		std::cin.getline(input, 3);
		int choice = atoi(input);
		std::cin.clear();

		if(choice == 1)
		{
			std::cout << "\n\n\nGame Started\n";
			player.name = playerName;
			isCharNamed = true;
		}
		else if (choice == 2)
			std::cout << "\n";
		else
			std::cout << "\nInvalid input.\n\n\n";
		} // end character naming

	while (testingRoom == true)
	{
		std::cout << "Welcome to the testing room\n";
		std::cout << "A few debugging and testing features will be put in here.\n\n\n";


		std::cout << "1. start at lv 5\n";
		std::cout << "2. start at lv 10\n";
		std::cout << "3. start at lv 14\n";
		std::cout << "\n";
		std::cout << "\n";
		std::cout << "99. Exit\n";

		char input[3];
		std::cin.getline(input, 3);
		int choice = atoi(input);

		std::cout << "\n\n\n\n";
		std::cin.clear();

		if(choice == 1)
			player.exp = 8;
		else if(choice == 2)
			player.exp = 18;
		else if(choice == 3)
			player.exp = 26;
		else if(choice == 99)
			testingRoom = false;
		else
			std::cout << "Invaid input.\n\n";
	}
	

bool isPlaying = true;
	while (isPlaying)
	{
		// update stats
		player.update();

		bool isBattling = false;

		// check if win
		if (player.level >= 15)
		{
			std::cout << "You Won!\nThanks for playing!\n\n";
			std::cout << "1. Restart 2. Exit\n\n";
			char input[3];
			std::cin.getline(input, 3);
			int choice = atoi(input);
			std::cin.clear();

			if (choice == 1)
			{
				std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
				isPlaying = false;
				isCharNamed = false;
			}
			else if (choice == 2)
			{
				isPlaying = false;
				running = false;
			}
			else
				std::cout << "Invaid input.\n\n";

		}


		std::cout << "==================================\n";
		std::cout << "Reach level 15 to win.\n";
		std::cout << "level " << player.level << "/15\n\n";
		std::cout << "Enter a number to make a choice.\n";
		std::cout << "1. Check 2. Rest \n3. Battle 4. Battle \n\n9. Restart 10. Exit\n";

		char input[3]; 
		std::cin.getline(input, 3);
		int choice = atoi(input); 
		std::cout << "\n\n\n\n";
		std::cin.clear();

		// check character
		if(choice == 1)
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

		// rest
		else if (choice == 2)
		{
			//FIXME make a function
			player.hitPoints = player.hitPointsBase * player.hitPointsMult;
			std::cout << "You feel rested.\n\n\n";
		}

		// battle monsterA
		else if(choice == 3)
		{
			TextGame::EnemyA enemy;
			//FIXME std::cout << "A wild " << enemy.name << "appeared!\n\n";
			std::cout << "A wild " << "Enemy " << "appeared!\n\n";
			isBattling = true;
			while (isBattling == true)
			{
				std::cout << "--------------------------\n";
				std::cout << "Your Hit Points: " << player.hitPoints << "\n";
				std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
				std::cout << "What will you do?\n";
				std::cout << "1. Attack 2. Run\n\n";

				char input[3];
				std::cin.getline(input, 3);
				int choice = atoi(input);
				std::cin.clear();

				if(choice == 1)
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
						player.exp = player.exp + 1;
						std::cout << "You gained 1 exp\n\n";
						//FIXME make function V V V
						player.level = player.level + player.exp / 2;
						isBattling = false;
					}

					// check if enemy is still alive to attack
					if(enemy.hitPoints > 0)
					{
						// make sure hit points don't go under 0
						if(player.hitPoints < enemy.damage)
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
					if(player.hitPoints <= 0)
					{
						std::cout << "You died.\nGAME OVER.\n\n";
						std::cout << "1. Restart 2. Exit\n\n";
						std::cin.getline(input, 3);
						int choice = atoi(input);
						// restart
						if(choice == 1)
						{
							std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
							isBattling = false;
							isCharNamed = false;
							isPlaying = false;
						}
						// exit
						else if(choice == 2)
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
				else if(choice == 2)
				{
					std::cout << "You ran away.\n\n\n";
					isBattling = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			} // end is battling
		}

		// battle monsterB
		else if(choice == 4)
		{

			TextGame::EnemyB enemy;
			//FIXME std::cout << "A wild " << enemy.name << "appeared!\n\n";
			std::cout << "A wild " << "Enemy " << "appeared!\n\n";
			isBattling = true;
			while (isBattling == true)
			{
				std::cout << "--------------------------\n";
				std::cout << "Your Hit Points: " << player.hitPoints << "\n";
				std::cout << "Enemy Hit Points: " << enemy.hitPoints << "\n\n";
				std::cout << "What will you do?\n";
				std::cout << "1. Attack 2. Run\n\n";

				char input[3];
				std::cin.getline(input, 3);
				int choice = atoi(input);
				std::cin.clear();

				if (choice == 1)
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
						player.exp = player.exp + 2;
						std::cout << "You gained 1 exp\n\n";
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
						std::cout << "1. Restart 2. Exit\n\n";
						std::cin.getline(input, 3);
						int choice = atoi(input);

						// Restart
						if (choice == 1)
						{
							std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
							isBattling = false;
							isCharNamed = false;
							isPlaying = false;
						}
						// Exit
						else if (choice == 2)
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
				else if (choice == 2)
				{
					std::cout << "You ran away.\n\n\n";
					isBattling = false;
				}
				else
					std::cout << "Invaid input.\n\n";
			} // end is battling
		}

		//restart
		else if (choice == 9)
		{
			std::cout << "\n\n\n\n>>>>>>>>>>>>>>>>>>>>  RESTART >>>>>>>>>>>>>>>>>>>>\n\n\n\n\n\n\n\n\n\n";
			isPlaying = false;
			isCharNamed = false;
		}

		// quit
		else if (choice == 10) 
		{
			isPlaying = false;
			running = false;
		}

		//testing room
		else if (choice == 95)
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

}// end main