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
#include <TextGame/Navigation/Rooms.hpp>

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

	// use this on rooms after creating them
	void setRoomInfo(int id, Room* ptrRoom);

	// wrappers to load room info without calling a function from every room
	int returnObjectLocation(int id, int* location);
	char** returnMapArray(int id);

	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)			
	)			Start Room specific return functions
	)				the return functions need to be here so RoomInfo.cpp can see them
	)			
	)			add room_returnMap and room_returnObject for each room here
	)				add them to the array in RoomInfo.cpp - spot in array must match room id
	)			
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

	// test room functions
	char** TeRo_returnMap(); // be sure to delete
	int TeRo_returnObject(int* location);


	char** Forest_returnMap();
	int Forest_returnObject(int* location);

} // end TextGame

#endif
