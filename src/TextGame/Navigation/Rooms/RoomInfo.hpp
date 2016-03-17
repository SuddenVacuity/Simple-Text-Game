#ifndef TEXTGAME_NAVIGATION_ROOMS_ROOMINFO_HPP
#define TEXTGAME_NAVIGATION_ROOMS_ROOMINFO_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				RoomInfo.hpp
)					makes Room class and Room functions available
)
)
)				Include in
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Globals.hpp>
#include <TextGame/Navigation/Rooms/testRoom.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)
	)				Functions to return values from storage arrays
	)
	)
	)
	)
	)
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string returnRoomString(int id, int num); // RoomString.cpp
	int returnRoomInteger(int id, int num); // RoomInteger.cpp

	void setRoomInfo(int id, testRoom* ptrRoom);

	// TEST room functions
	int TeRo_returnObject(int* location);
	char** TeRo_returnMap(); // be sure to delete

} // end TextGame

#endif
