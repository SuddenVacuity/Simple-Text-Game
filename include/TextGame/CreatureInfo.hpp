#ifndef TEXTGAME_CREATUREINFO_HPP
#define TEXTGAME_CREATUREINFO_HPP

//	  ==========================================================================================
//	  =============			  This file contains all base monster				================
//	  =============					     information							================
//	  ==========================================================================================

#include <TextGame/Globals.hpp>
#include <string>
#include <cmath>

namespace TextGame
{
	class Creature 
	{
	public:
		u32 id;
		std::string name;
		u32 exp;
		f32 level;

		u32 hitPointsBase;
		u32 damageBase;
		u32 defenseBase;

		f32 hitPointsMult;
		f32 damageMult;
		f32 defenseMult;

		u32 hitPoints;
		f32 damage;
		u32 defense;

		virtual void attack(Creature& c) = 0;
	};

} // end TextGame

#endif	
