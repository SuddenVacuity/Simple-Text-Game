
#include <TextGame/Navigation/Rooms/testRoom.hpp>

namespace TextGame
{
	testRoom::~testRoom() {}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnSize (testRoom.hpp)
	)					returns the rows and columns of the room
	)
	)				
	)				
	)
	)				return new array[2];
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int* testRoom::returnSize()
	{
		int* size = new int[2];
		size[0] = roomRows;
		size[1] = roomColumns;

		return size;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnState (testRoom.hpp)
	)					returns the state value of a location in stateData
	)
	)				(int* location)
	)					array[2] containing {row, column}
	)
	)				return int;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int testRoom::returnState(int* location)
	{
		return roomState[location[0]][location[1]];
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnData (testRoom.hpp)
	)					creates array the size of the room and populates it with roomObject
	)
	)				
	)					
	)
	)				return new int* data[]; needs to be deleted to avoid memory leak
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int** testRoom::returnData() // be sure to delete
	{
		int** data = new int*[roomRows];

		// generate table
		for (int i = 0; i < roomRows; i++)
		{
			data[i] = new int[roomColumns];
			for (int j = 0; j < roomColumns; j++)
				data[i][j] = roomObject[i][j];
		}
		return data;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnString (testRoom.hpp)
	)					return string from roomString
	)
	)				(int stringNum)
	)					number of the string to return
	)
	)				return std::string;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string testRoom::returnString(int stringNum)
	{
		// FIXME prevent stringNum fomr being too large
		return roomString[stringNum];
	}
} // end TextGame
