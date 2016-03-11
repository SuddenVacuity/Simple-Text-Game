#ifndef TEXTGAME_CREATUREINFO_HPP
#define TEXTGAME_CREATUREINFO_HPP

//	  ==========================================================================================
//	  =============			    Creature Class that Player and					================
//	  =============					Enemy are based off of     					================
//	  ==========================================================================================

#include <TextGame/Globals.hpp>
#include <cmath>

namespace TextGame
{
	// TODO set hard caps for stats
	class Creature 
	{
	public:
		std::string name;
		std::string namef;
		int exp;
		int level;
		int loc_Row;
		int loc_Col;

		int levelCap;
		int hitPointsCap;
		int damageCap;
		int defenseCap;

		int hitPointsBase;
		int damageBase;
		int defenseBase;

		float hitPointsMult;
		float damageMult;
		float defenseMult;

		int hitPoints;
		int damage;
		int defense;

		int hitPointsMax;
		int damageMax;
		int defenseMax;

		int rewardExp;


	};

} // end TextGame

#endif	
