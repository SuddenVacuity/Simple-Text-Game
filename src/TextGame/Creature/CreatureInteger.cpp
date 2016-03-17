/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CreatureInteger.cpp (CreatureInfo.hpp)
)					contains integer information for each type of monster
)
)				
)				
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				creatureInteger (CreatureInfo.hpp)
	)					array of integer information for each type of monster
	)
	)
	)
	)
	)
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	const int intVal = 26;
	int creatureInteger[][intVal] =
	{	//   {      faction, dropSet, exp, rewardExp, gender
		// /**/ startLV, minlevel, maxlevel, level,
		// /**/ baseHP, baseSta, baseSpe baseATK, baseDEF,
		// /**/ baseStr, baseKno, baseFit, baseAgi, baseWis, basePer, baseSpd,
		// /**/ aggresion, confidence, moral, karma, luck }
		{ 0, 0, 0, 5, 0,/**/ 1, 1, 999, 1,/**/ 15, 10, 5, 3, 3,/**/ 5, 5, 5, 5, 5, 5, 5,/**/ 0, 0, 0, 0, 0 }, // 0
		{ 1, 0, 0, 5, 0,/**/ 1, 1, 999, 1,/**/ 30, 10, 10, 5, 5,/**/ 5, 5, 5, 5, 5, 5, 5,/**/ 0, 0, 0, 0, 0 }, // 1 Player
		{ 0, 0, 0, 5, 0,/**/ 1, 1, 15, 1,/**/ 20, 15, 10, 5, 3,/**/ 5, 5, 5, 5, 5, 5, 5,/**/ 50, 50, 0, 0, 0 }, // 2 Generic Monster
		{ 0, 0, 0, 5, 0,/**/ 1, 1, 15, 1,/**/ 35, 25, 5, 8, 5,/**/ 5, 5, 5, 5, 5, 5, 5,/**/ 50, 50, 0, 0, 0 }, // 3 Standard Monster
	};
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnCreatureInteger (CreatureInfo.hpp)
	)					get a specific integer for a specific monster
	)
	)				(int id, int num)
	)					int id = monster id , int num = integer number
	)
	)				return int;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int returnCreatureInteger(int id, int num)
	{
		return creatureInteger[id][num];
	}

}

