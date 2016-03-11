
#include <TextGame/Navigation/Map.hpp>
#include <TextGame/Navigation/Rooms.hpp>

#include <string>


// may not use these


namespace TextGame
{

	// print a line of the map
	void genMap(int line, int** data, int* size)
	{
		//cap on map size
		const int col = 16;
		const int row = 16;
		std::string map[row][col];

		if (size[0] >= row)
			size[0] = row - 1;
		if (size[1] >= col)
			size[1] = col - 1;

		// populate map[line][col]
			for(int j = 0; j < size[1]; j++)
			{
				if (data[line][j] == 0)
					map[line][j] = ".";

				else if(data[line][j] == 1)
					map[line][j] = "O";

				else
					map[line][j] = "-";

				std::cout << map[line][j] << " ";
			}

	}

} // end TextGame
