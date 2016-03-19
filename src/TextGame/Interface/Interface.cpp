/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Interface.cpp (Interface.hpp)
)					general use in/out functions
)
)				
)					
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Interface/Interface.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				getInput (Interface.hpp)
	)					get string from command line input
	)
	)				
	)					
	)
	)				return std::string;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string getInput()
	{
		std::cout << "\n>>";
		std::string cmdInput;
		std::string *result;
	
		std::getline(std::cin, cmdInput);
		std::cin.clear();
	
		result = &cmdInput;

		return *result;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				getNumber (Interface.hpp)
	)					get int from command line input
	)
	)			
	)					
	)
	)				return int;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int getNumber()
	{
		std::stringstream ss;

		ss.clear();
		ss.str("");

		std::string ssinput = "";

		int n;

		while (true) {
			if (!std::getline(std::cin, ssinput))
				return 0;

			ss.str(ssinput);

			if (ss >> n)
				break;

			std::cout << "Invalid number, please try again" << std::endl;


			ss.clear();
			ss.str("");
			ssinput.clear();
		}



		return n;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				clearScreen (Interface.hpp)
	)					clear screen (currently just with new lines)
	)
	)				
	)					
	)
	)				return void;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void clearScreen()
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				quitRestart
	)					quit or restart options
	)
	)				(int& gameMode)
	)					
	)
	)				return int: gameMode
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int quitRestart(int& gameMode)
	{
		std::cout << "\nWould you like to quit or restart?\nPress Q to quit, R to restart or any thing else to continue.";
		char choice = _getch();

		if (choice == 'R' || choice == 'r')
		{
			clearScreen();
			std::cout << "Are you sure you want to restart?\nPress Y to restart.\n\n\n";
			char yesNo = _getch();

			if (yesNo == '1' || yesNo == 'Y' || yesNo == 'y')
				gameMode = 99;
		}

		// quit
		else if (choice == 'Q' || choice == 'q')
		{
			clearScreen();
			std::cout << "Are you sure you want to quit?\nPress Y to quit.\n\n\n";
			char yesNo = _getch();

			if (yesNo == '1' || yesNo == 'Y' || yesNo == 'y')
				gameMode = 100;
		}

		return gameMode;
	}
} // end TextGame
