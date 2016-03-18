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
	)					char**  data = array[][] containing data from getNavData()
	)				return void; cout to command line
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void genMap(int line, char** data, int dirFacing)
	{
		char p = '?';

		if (dirFacing == 0)
			p = '^';
		else if (dirFacing == 1)
			p = '<';
		else if (dirFacing == 2)
			p = 'v';
		else if (dirFacing == 3)
			p = '>';

		//cap on map size
		char map[g_mapSizeRow][g_mapSizeCol];

		//FIXME hacky fix to make mapsize odd for centered player
		int mapCol = g_mapSizeCol - 1;

		// -1 to not be larger than the array
		if(line >= g_mapSizeRow)
			line = g_mapSizeRow - 1;

		// populate map[line][col]
		for(int j = 0; j < mapCol; j++)
		{
			if (data[line][j] == '`') // player
				map[line][j] = p;

			else
				map[line][j] = data[line][j];

			std::cout << map[line][j] << ' ';
		}

	}

	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				printMap (Map.hpp)
	)					prints each line with genMap() along with map strings and player info
	)
	)				(Creature* ptrPlayer, Room* ptrRoom)
	)					ptrPlayer = pointer to creaturee class player
	)					ptrRoom = pointer to room information is coming from
	)				return void; cout to command line
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void printMap(Creature* ptrPlayer, Room* ptrRoom)
	{
		// get information to make map with
		// need to make temp variables to clear or there's a memory leak
		int* tempLoc = ptrPlayer->returnLocation();
		char** tempData = returnMapArray(ptrRoom->id); // RoomInfo.cpp
		int* tempSize = ptrRoom->returnSize();

		// create and return mapsized array for the map
		char** tempMap = TextGame::getNavData(tempLoc, tempData, tempSize, ptrPlayer->visible); // Navigation.cpp

		//delete new arrays
		TextGame::clearData(tempData, tempSize[0]);
		TextGame::clearData(tempSize);
		TextGame::clearData(tempLoc);

		// print room name and decs
		std::cout << returnRoomString(ptrRoom->id, 1);
		std::cout << "\n";
		std::cout << returnRoomString(ptrRoom->id, 2);
		std::cout << "\n";


		// print map
		std::cout << "\n";  TextGame::genMap(0, tempMap, ptrPlayer->direction); std::cout << returnRoomString(ptrRoom->id, 10);
		std::cout << "\n";  TextGame::genMap(1, tempMap, ptrPlayer->direction); std::cout << returnRoomString(ptrRoom->id, 11);
		std::cout << "\n";  TextGame::genMap(2, tempMap, ptrPlayer->direction); std::cout << returnRoomString(ptrRoom->id, 12);
		std::cout << "\n";  TextGame::genMap(3, tempMap, ptrPlayer->direction);
		std::cout << "\n";  TextGame::genMap(4, tempMap, ptrPlayer->direction);	std::cout << "Name: " << ptrPlayer->name;
		std::cout << "\n";  TextGame::genMap(5, tempMap, ptrPlayer->direction); std::cout << "Level: " << ptrPlayer->level << " Exp tnl: " << ptrPlayer->returnExpTnl();
		std::cout << "\n";  TextGame::genMap(6, tempMap, ptrPlayer->direction); std::cout << "HP: " << ptrPlayer->hitPoints << "/" << ptrPlayer->HpStaSpeMax;
		std::cout << "\n";  TextGame::genMap(7, tempMap, ptrPlayer->direction); std::cout << "enter W A S D to move or SPACE to interact";
		std::cout << "\n";  TextGame::genMap(8, tempMap, ptrPlayer->direction); 

		// delete new array
		TextGame::clearData(tempMap, g_mapSizeCol);
	}

} // end TextGame
