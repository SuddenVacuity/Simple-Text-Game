#ifndef TEXTGAME_NAVIGATION_MAP_HPP
#define TEXTGAME_NAVIGATION_MAP_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Map.hpp
)					makes map generation functions available
)
)			
)			
)
)			
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

#include <TextGame/Player/PlayerActions.hpp>



namespace TextGame
{
	void genMap(int line, char** data, int playerDirection);
	void printMap(Creature* ptrPlayer, Room* ptrRoom);

} // end TextGame

#endif
