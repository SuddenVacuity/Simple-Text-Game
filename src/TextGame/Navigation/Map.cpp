/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Map.cpp (Map.hpp)
)					contains functions related to generating the map
)
)			
)			
)
)			
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Map.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				genMap (Map.hpp)
	)					sets player symbol and converts data from getNavData() to a map of characters (prints line by line)
	)
	)				(int line, int** data, int dirFacing)
	)					int line = row of the map to print			int dirFacing = used to choose char to show creatures
	)					int**  data = array[][] containing data from getNavData()
	)				return void; cout to command line
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void genMap(int line, int** data, int dirFacing)
	{
		std::string p = "?";

		if (dirFacing == 0)
			p = returnCreatureString(1, 1);
		else if (dirFacing == 1)
			p = returnCreatureString(1, 2);
		else if (dirFacing == 2)
			p = returnCreatureString(1, 3);
		else if (dirFacing == 3)
			p = returnCreatureString(1, 4);

		//cap on map size
		std::string map[g_mapSizeRow][g_mapSizeCol];

		//FIXME hacky fix to make mapsize odd for centered player
		int mapCol = g_mapSizeCol - 1;

		// -1 to not be larger than the array
		if(line >= g_mapSizeRow)
			line = g_mapSizeRow - 1;

		// populate map[line][col]
		for(int j = 0; j < mapCol; j++)
		{
			if (data[line][j] == 0)
				map[line][j] = ".";

			else if (data[line][j] == 1)
				map[line][j] = "O";

			else if (data[line][j] == 999) // player
				map[line][j] = p;

			else
				map[line][j] = "-";

			std::cout << map[line][j] << " ";
		}

	}

} // end TextGame
