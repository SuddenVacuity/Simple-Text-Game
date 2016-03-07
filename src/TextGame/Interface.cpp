#include <TextGame/Interface.hpp>

namespace TextGame
{
	// go back to start of running loop
	// FIXME somehow isPlaying loop continues after this function
	// but does not continue if I do the same thing without a function
	void goBack()
	{
		isPlaying = false;
		isCharNamed = false;
		isBattling = false;
		std::cout << "\nisPlaying is: " << isPlaying;
		std::cout << "\nisCharNamed is: " << isCharNamed;
		std::cout << "\nisBattling is: " << isBattling << "\n";
	}





} // end TextGame
