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
	void titleScreen()
	{
		TextGame::clearScreen(); // Interface.cpp
		std::cout << "[Opening Text Here]\n\n\n";
	}
} // end TextGame
