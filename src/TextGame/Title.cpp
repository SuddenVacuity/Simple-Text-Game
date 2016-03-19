/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Title.cpp (Title.hpp)
)					Opening function for the program
)
)				
)				Should run right after initialization function
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Title.hpp>

namespace TextGame
{
	int titleScreen(int& gameMode)
	{
	if(gameMode != 0)
		return gameMode;
	else
	{
			TextGame::clearScreen(); // Interface.cpp
			std::cout << "[Insert Title Here]\n\n\n\n\n\n\n";

			std::cout << "press p to enter the test room\n";
			std::cout << "\n1. New Game";
			std::cout << "\n2. Continue << not implemented";
			std::cout << "\n3. Quit";
			std::cout << "\n\n\n";

			char choice = _getch();

			if (choice == '1' || choice == '\0')
				gameMode = 2;
			else if (choice == '2')
				gameMode = 2;
			else if (choice == '3')
			{
				std::cout << "\n\n\nAre you sure you want to quit? Y/N\n\n\n";
				choice = _getch();
				if(choice == 'y' || choice == 'Y')
					gameMode = 100;
			}
			else if (choice == 'p')
				gameMode = 98;
			else if (choice =- 'r')
				gameMode = 99;

			TextGame::clearScreen(); // Interface.cpp

			return gameMode;
		}

	}
} // end TextGame
