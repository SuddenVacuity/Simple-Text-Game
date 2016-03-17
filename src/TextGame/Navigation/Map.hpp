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
#include <TextGame/Globals.hpp>
#include <TextGame/Navigation/Rooms.hpp>
#include <TextGame/Navigation/Movement.hpp>

// may not use these

namespace TextGame
{
	void genMap(int line, int** data, int playerDirection);

} // end TextGame

#endif
