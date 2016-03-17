/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Rooms.cpp
)					will handle room info. Right now it just has 2nd test room
)
)				
)				
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Rooms.hpp>


namespace TextGame
{
	testRoom2::~testRoom2() {}

	// returns int array data
	std::string testRoom2::returnString(int stringNum)
	{
		// FIXME prevent stringNum fomr being too large
		return roomString[stringNum];
	}
	int* testRoom2::returnSize()
	{
		//FIXME prevent memory leak
		int* size = new int[2];
		size[0] = roomRows;
		size[1] = roomColumns;

		return size;
	}
	int testRoom2::returnState(int* location)
	{
		return roomState[location[0]][location[1]];
	}
	int** testRoom2::returnData()
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
} // end TextGame
