#ifndef TEXTGAME_NAVIGATION_ROOMS_HPP
#define TEXTGAME_NAVIGATION_ROOMS_HPP 
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Rooms.hpp
)					container for room data
)
)
)					Include in Rooms
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Combat/Combat.hpp>
namespace TextGame
{

	struct Room
	{
		int id = 0;
		int roomTimesVisited = 0;
		int roomEncounterSet = 0;
		int roomEncounterRate = 0;

		int roomRows = 16;
		int roomColumns = 16;
		~Room();

		int* returnSize();
	};

} // end TextGame

#endif

