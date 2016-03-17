/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CreatureFloat.cpp (CreatureInfo.hpp)
)					contains all floats for each monster
)
)				
)					
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				creatureFloat (CreatureInfo.hpp)
	)					array of floats for specific monsters
	)
	)				
	)					
	)
	)				
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	const int creatureFloatVal = 19;
	float creatureFloat[][creatureFloatVal] =
	{
		// { hpMult, staMult, speMult, dmgMult, defMult,
		// /**/ strMult, intMult, fitMult, agiMult, wisMult, perMult, spdMult 
		// /**/ strPerLevel, knoPerLevel, fitPerLevel, agiPerLevel, wisPerLevel, perPerLevel, spdPerLevel }
		{ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, /**/ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }, // 0
		{ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f }, // 1 Player
		{ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 1.0f, 0.0f, 1.0f, 0.5f, 0.0f, 0.0f, 0.5f }, // 2 Generic Monster
		{ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, 0.2f, /**/ 0.5f, 0.0f, 1.5f, 1.0f, 0.0f, 0.0f, 0.0f }, // 2 Standard Monster
	};
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnCreatureFloat (CreatureInfo.hpp)
	)					return a specific float for a specific monster
	)
	)				(int id, int num)
	)					int id = monster id , int num = float number
	)
	)				return float;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	float returnCreatureFloat(int id, int num)
	{
		return creatureFloat[id][num];
	}

} // end TextGame
