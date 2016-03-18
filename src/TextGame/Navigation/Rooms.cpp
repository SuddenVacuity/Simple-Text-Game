

#include <TextGame/Navigation/Rooms.hpp>


namespace TextGame
{
	Room::~Room() {}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnSize (Rooms.hpp)
	)					returns the rows and columns of the room
	)
	)
	)
	)
	)				return new array[2];
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int* Room::returnSize()
	{
		int* size = new int[2];
		size[0] = roomRows;
		size[1] = roomColumns;

		return size;
	}
} // end TextGame
