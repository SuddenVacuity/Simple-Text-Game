#ifndef TEXTGAME_CREATUREINFO_HPP
#define TEXTGAME_CREATUREINFO_HPP

//	  ==========================================================================================
//	  =============			    Creature Class that Player and					================
//	  =============					Enemy are based off of     					================
//	  ==========================================================================================

#include <TextGame/Globals.hpp>
#include <string>
#include <cmath>

namespace TextGame
{
	// TODO set hard caps for stats
	class Creature 
	{
	public:
		std::string name;
		std::string namef;
		u32 exp;
		f32 level;

		u32 hitPointsBase;
		u32 damageBase;
		u32 defenseBase;

		f32 hitPointsMult;
		f32 damageMult;
		f32 defenseMult;

		u32 hitPoints;
		u32 damage;
		u32 defense;

		u32 hitPointsMax;
		u32 hitDamageMax;
		u32 hitDefenseMax;

		u32 rewardExp;
	};

} // end TextGame

#endif	
