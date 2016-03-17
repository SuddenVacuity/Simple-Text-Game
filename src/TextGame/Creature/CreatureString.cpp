/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CreatureString.cpp (CreatureInfo.hpp)
)					contains string information for each type of monster
)
)
)
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Globals.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				creatureString (CreatureInfo.hpp)
	)					array of string information for each type of monster
	)
	)
	)
	)
	)
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	// seems like this has to be done outside of creature functions
	const int creatureStringVal = 15;
	std::string creatureString[][creatureStringVal] =
	{
		{ "[0_null]", "$", "$", "$", "$", "[0_cname_0]", "[0_name_0]", "[0_name_1]", "[0_desc_0]", "[0_desc_2]", "[0_decs_3]", "[0_win_0]", "[0_win_1]", "[0_lose_0]", "[0_lose_1]" },
		{ "[1_null]", "^", "<", "v", ">", "Adventurer", "Player", "[0_name_1]", "[0_desc_0]", "[0_desc_2]", "[0_decs_3]", "[0_win_0]", "[0_win_1]", "[0_lose_0]", "[0_lose_1]" },
		{ "[2_null]", "&", "&", "&", "&", "John", "Generic Monster", "F Generic Monster", "The kind of monster", "you would expect to find", "in a place like this.", "[1_victory_0]",  " dances over your dead body.", "[1_win_0]" , " ran away crying." },
		{ "[3_null]", "&", "&", "&", "&", "Smith", "Standard Monster", "F Standard Monster", "These monsters are the kind", "commonly found in places like", "caves, fields, lakes, beaches, bars, mountains, etc... ", "You were eaten by a ", "[2_win_1]", "[2_lose_1]", "fell over unconscious." },
	};
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnCreatureString (CreatureInfo.hpp)
	)					get a specific string for a specific monster
	)
	)				(int id, int num)
	)					int id = monster id , int num = string number
	)
	)				return std::string;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string returnCreatureString(int id, int num)
	{
		return creatureString[id][num];
	}
}

