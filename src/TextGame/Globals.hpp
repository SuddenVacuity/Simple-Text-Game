#ifndef TEXTGAME_GLOBALS_HPP
#define TEXTGAME_GLOBALS_HPP

/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Globals.hpp
)					makes global variables and common std headers available
)
)				
)				Include in start of each header header path
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <cstdint>

#include <TextGame/CleanUp.hpp>

static bool running = true; // if false the program closes

static bool isCharNamed = false; 
static bool isBattling = false;

// FIXME both map size values currently have to be even numbers
static const int g_mapSizeCol = 10;
static const int g_mapSizeRow = 10;



#endif
