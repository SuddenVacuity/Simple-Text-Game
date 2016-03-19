
#include <TextGame/Interface/Interface.hpp>

namespace TextGame
{

	int winScreen(int& gameMode)
	{
		if (gameMode != 90)
			return gameMode;
		else
		{

			clearScreen();

			std::cout << "\nYou Won the Game!";
			std::cout << "Thanks for playing";
			std::cout <<"\n\n\n\n\n";

			std::cout << "1. Restart\n2. Quit";
			std::cout << "\n";
			char choice = _getch();
			// restart
			if (choice == '1' || choice == 'r' || choice == 'R' || choice == '\0')
			{// FIXME goBack()
			 //TextGame::goBack(); // Interface.cpp
				gameMode = 99;
				clearScreen(); // Interface.cpp
			}
			// exit
			else if (choice == '2' || choice == 'q' || choice == 'Q')
			{
				// FIXME goBack()
				//TextGame::goBack(); // Interface.cpp
				gameMode = 100;
			}
			else
				std::cout << " <<- Invalid input ->>\n\n\n";

			return gameMode;
		}
	}

}