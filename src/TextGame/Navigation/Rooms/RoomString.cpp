/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				RoomString.cpp (RoomInfo.hpp)
)					contains string information for each room
)
)
)
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <string>

namespace TextGame
{	
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				roomString (RoomInfo.hpp)
	)					array of string information for each room
	)
	)
	)
	)
	)
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	// seems like this has to be done outside of creature functions
	const int roomStringVal = 26;
	std::string roomString[][roomStringVal] =
	{
		{ "[0_0]",		
		/*name, desc*/"[0_1]", "[0_2]", 
		/*basic secenery action*/"[0_3]", "[0_4]", "[0_5]", "[0_6]", "[0_7]", "[0_8]", "[0_9]",
		/*signs and messages*/"[0_10]", "[0_11]", "[0_12]", "[0_13]", "[0_14]", "[0_15]", "[0_16]", "[0_17]", 
		/*signs and messages*/"[0_18]", "[0_19]", "[0_20]", "[0_21]", "[0_22]", "[0_23]", "[0_24]", "[0_25}", },
		{ "[1_test]",
		/*name, desc*/"Testing Room", "Add a description of the room here to display under room name.",
		/*basic secenery action*/"Nothing here", "It's a test wall.", "[1_5]", "[1_6]", "[1_7]", "[1_8]", "[1_9]",
		/*signs and messages*/"Welcome to the Testing Room!", "This is a room made just for testing mechanics", "it is filled with various test functions.", "[1_13]", "[1_14]", "[1_15]", "[1_16]", "[1_17]",
		/*signs and messages*/"Monsters can appear here.", "It doesn't always tell you.", "You can walk under here.", "You can walk under here too but its not safe.", "[1_22]", "[1_23]", "[1_24]", "[1_25}", },
		{ "[2_test2]", 
		/*name, desc*/"Secondary Testing Room", "[2_2]",
		/*basic secenery action*/"[2_3]", "It's a buggy wall.", "[2_5]", "[2_6]", "[2_7]", "[2_8]", "[2_9]",
		/*signs and messages*/"This is the Secondary Test Room.", "This is a room is just like the other.", "Only different.", "[2_13]", "[2_14]", "[2_15]", "[2_16]", "[2_17]",
		/*signs and messages*/"[2_18]", "[2_19]", "[2_20]", "[2_21]", "[2_22]", "[2_23]", "[2_24]", "[2_25}", },
		{ "[3_town]", 
		/*name, desc*/"Town", "[Town Description]",
		/*basic secenery action*/"Nothing here.", "You touched it.", "[3_5]", "[3_6]", "[3_7]", "[3_8]", "[3_9]",
		/*signs and messages*/"Town Info 1", "Town Info 2", "Town Info 3", "[3_13]", "[3_14]", "[3_15]", "[3_16]", "[3_17]",
		/*signs and messages*/"[3_18]", "[3_19]", "[3_20]", "[3_21]", "[3_22]", "[3_23]", "[3_24]", "[3_25}", },
		{ "[4_forest]", 
		/*name, desc*/"Forest", "[Forest Description]", 
		/*basic secenery action*/"Nothing here.", "Nothing happened.", "[4_5]", "[4_6]", "[4_7]", "[4_8]", "[4_9]",
		/*signs and messages*/"Forest Info 1", "Forest Info 2", "Forest Info 3", "[4_13]", "[4_14]", "[4_15]", "[4_16]", "[4_17]",
		/*signs and messages*/"[4_18]", "[4_19]", "[4_20]", "[4_21]", "[4_22]", "[4_23]", "[4_24]", "[4_25}", },
		{ "[5_cave]", 
		/*name, desc*/"Cave", "[Cave Description]", 
		/*basic secenery action*/"Nothing here.", "It's a solid wall.", "[5_5]", "[5_6]", "[5_7]", "[5_8]", "[5_9]",
		/*signs and messages*/"Cave Info 1", "Cave Info 2", "Cave Info 3", "[4_13]", "[4_14]", "[4_15]", "[4_16]", "[4_17]",
		/*signs and messages*/"[4_18]", "[4_19]", "[4_20]", "[4_21]", "[4_22]", "[4_23]", "[4_24]", "[4_25}", },
	};
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnroomString (RoomInfo.hpp)
	)					get a specific string for a specific room
	)
	)				(int id, int num)
	)					int id = room id , int num = string number
	)
	)				return std::string;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string returnRoomString(int id, int num)
	{
		return roomString[id][num];
	}

} // end TextGame