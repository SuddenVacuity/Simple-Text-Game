/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				RoomInteger.cpp (RoomInfo.hpp)
)					contains integer information for each Room
)
)
)
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Rooms/RoomInfo.hpp>
namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				roomInteger (RoomInfo.hpp)
	)					array of integer information for each Room
	)
	)
	)
	)
	)
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	const int roomIntVal = 5;
	int roomInteger[][roomIntVal] =
	{	//   { times visited, rows, cols, encouter set, encounter rate }
		{ 0, 1, 1, 0, 0 }, // 0
		{ 0, 16, 16, 0, 0 }, // 1 testRoom
		{ 0, 16, 16, 0, 0 }, // 2 testRoom2
		{ 0, 26, 26, 1, 5 }, // 3 town
		{ 0, 36, 36, 2, 10 }, // 4 forest
		{ 0, 51, 51, 3, 10 }, // 5 cave
	};
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnRoomInteger (CreatureInfo.hpp)
	)					get a specific integer for a specific room
	)
	)				(int id, int num)
	)					int id = room id , int num = integer number
	)
	)				return int;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int returnRoomInteger(int id, int num)
	{
		return roomInteger[id][num];
	}

	void setRoomInfo(int id, testRoom* ptrRoom) // get information and apply it to room
	{
		ptrRoom->roomTimesVisited = returnRoomInteger(id, 0);
		ptrRoom->roomRows = returnRoomInteger(id, 1);
		ptrRoom->roomColumns = returnRoomInteger(id, 2);
		ptrRoom->roomEncounterSet = returnRoomInteger(id, 3);
		ptrRoom->roomEncounterRate = returnRoomInteger(id, 4);
	}
}

