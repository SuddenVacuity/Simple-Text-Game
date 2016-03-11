#ifndef TEXTGAME_NAVIGATION_HPP
#define TEXTGAME_NAVIGATION_HPP

//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================


#include <TextGame/Navigation/Map.hpp>
#include <TextGame/Navigation/Rooms.hpp>
#include <TextGame/Combat.hpp>

#include <iostream>

namespace TextGame
{


	int** getNavData(int* mLocation, int** data, int* size);



} // end TextGame

#endif
