#include <TextGame/Navigation/Rooms/RoomInfo.hpp>

namespace TextGame
{
	// wrapper so I can call from roomObject for different rooms with one function
	int returnObjectLocation(int id, int* location)
	{
		int ObjectLocation[] =
		{
			0, // 0 null
			TeRo_returnObject(location), // 1 TeRo.cpp
			TeRo_returnObject(location), // 2 TeRo.cpp
			Forest_returnObject(location), // 3 Forest.cpp
		};

		return ObjectLocation[id];
	}

	// wrapper so I can return roomMap for different rooms with one function
	char** returnMapArray(int id)
	{
		//FIXME possible memory leak here
		char** MapArray[] =
		{
			TeRo_returnMap(), // call null
			TeRo_returnMap(), // 1 TeRo.cpp
			TeRo_returnMap(), // 2 TeRo.cpp
			Forest_returnMap(), // 3 Forest.cpp
		};

		return MapArray[id];
	}
} // end TextGame
