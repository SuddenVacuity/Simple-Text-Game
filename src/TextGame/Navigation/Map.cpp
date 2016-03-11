
#include <TextGame/Navigation/Map.hpp>
#include <TextGame/Navigation/Rooms.hpp>

#include <string>


// may not use these


namespace TextGame
{

	// print a line of the map
	void genMap(int line, int** data)
	{
		//cap on map size
		const int col = 16;
		const int row = 16;
		std::string map[row][col];

		int mapSize = 15;

		// populate map[line][col]
			for(int j = 0; j < mapSize; j++)
			{
				if (data[line][j] == 0)
					map[line][j] = ".";

				else if (data[line][j] == 1)
					map[line][j] = "O";


				else if (data[line][j] == 999)
					map[line][j] = "P";

				else
					map[line][j] = "-";

				std::cout << map[line][j] << " ";
			}

	}

} // end TextGame
