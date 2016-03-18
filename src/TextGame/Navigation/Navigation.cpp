/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Navigation.cpp (Navigation.hpp)
)					contains functions to take data from roomObject and prepare it to go to genMap()
)
)				
)				
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Navigation.hpp>


namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				getNavData (Navigation.hpp)
	)					copies data from returnRoomMap based off player location and map size, handles areas outside roomObjects range
	)
	)				(int* mLocation, char** data, int* size)
	)					mLocation = player location , data = roomMap data for getNavData() , size = size of the room (to stay in limits)
	)
	)				return new char** navData; needs to be deleted
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	char** getNavData(int* mLocation, char** data, int* size, int playerVisible)
	{
		//set map edges with player in the center of the map
		//half a row is found with columns
		//+1 to convert to array size
		int sideCol[2];
		sideCol[0] = mLocation[0] + 1 - g_mapSizeRow / 2;
		sideCol[1] = mLocation[0] + 1 + g_mapSizeRow / 2;
		//half a column is found with rows
		int sideRow[2];
		sideRow[0] = mLocation[1] + 1 - g_mapSizeCol / 2;
		sideRow[1] = mLocation[1] + 1 + g_mapSizeCol / 2;

		// define location in the center of the map
		// -1 to convert to array coords
		int playerLocRow = g_mapSizeRow / 2 - 1;
		int playerLocCol = g_mapSizeCol / 2 - 1;

		//FIXME prevent memory leak
		char** navData = new char*[g_mapSizeRow];
	
		// populate create data based on player location
		for (int i = sideCol[0], l = 0; i < sideCol[1]; i++, l++)
		{
			navData[l] = new char[g_mapSizeCol];
			for (int j = sideRow[0], m = 0; j < sideRow[1]; j++, m++)
			{
				// check limits on room data, -1 because size is array size
				if(j < 0 || i < 0 || j > size[1] - 1|| i > size[0] - 1)
				{
					// set areas with no map data to this
					navData[l][m] = ' ';
				}
				else
					navData[l][m] = data[i][j];
			}
		}

		//set Player on map
		if(playerVisible == 1)
			navData[playerLocRow][playerLocCol] = '`';

		return navData;
	}



}
