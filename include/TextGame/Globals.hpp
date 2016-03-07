#ifndef TEXTGAME_GLOBALS_HPP
#define TEXTGAME_GLOBALS_HPP

//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================

#include <TextGame/Types.hpp>
#include <iostream>

static bool running = true; // if false the program closes
static bool testingRoom = false; // set to true to access testing area

static bool isCharNamed = false; 
static bool isPlaying = true;
static bool isBattling = false;

static std::string input; // receives input from getline()

namespace TextGame
{

} // end TextGame

#endif
