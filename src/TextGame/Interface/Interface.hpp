#ifndef TEXTGAME_INTERFACE_HPP
#define TEXTGAME_INTERFACE_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Interface.hpp
)					makes interface functions available and defines _getch functions
)
)				
)					Include in Globals.hpp
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#if defined(_WIN32) || defined(_WIN64) || defined (__WIN32__) || defined(__WINDOWS__)
#include <conio.h>

#else // set getch for unix
// defined(__unix__) // defined(__APPLE__) && defined(__MACH__)

#include <terminos.h>
#include <stdio.h>

// taken from online source hopefully it works
static struct terminos bufOff, bufOn;

void initTerminos(int echo) 
{
	tcgetattr(0, &buffOff);
	bufOn = bufOff;
	bufOn.c_lflag &= ~ICANON;
	bufOn.c_lflag &= echo ? ECHO : ~ECHO;
	tcsetattr(0, TCSANOW, &bufOn);
}

void resetTerminos(void)
{
	tcsetattr(0,TCSANOW, &old)
}

char getch_(int echo)
{
	char c;
	initTerminos(echo);
	c = getchar();
	resetTerminos();
	return c;
}

char _getch(void)
{
	return getch_(0);
}

char _getche(void)
{
	return getch_(1);
}

#endif // load conio.h on windows and set getch for unix

#include <TextGame/Globals.hpp>

namespace TextGame
{

	std::string getInput(); // get input
	int getNumber(); // get input
	void clearScreen();
	int winScreen(int& gameMode); // Win.cpp
	int quitRestart(int& gameMode);

} // end TextGame


#endif
