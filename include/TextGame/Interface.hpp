#ifndef TEXTGAME_INTERFACE_HPP
#define TEXTGAME_INTERFACE_HPP

#include <TextGame/Globals.hpp>
#include <iostream>
#include <sstream>

namespace TextGame
{

	std::string getInput(); // get input
	int getNumber(); // get input

	void clearScreen();

	void goBack(); // go back to start of running loop

	void clearData1D(int* data);
	void clearData2D(int** data, int rows);


} // end TextGame


#endif
