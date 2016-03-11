#ifndef TEXTGAME_CREATURE_HPP
#define TEXTGAME_CREATURE_HPP

//	  ==========================================================================================
//	  =============							Declares							================
//	  =============						Creature Classes	 					================
//	  ==========================================================================================

#include <TextGame/CreatureInfo.hpp>


namespace TextGame
{
	class Mobile : public Creature
	{
	public:
		Mobile();
		Mobile(std::string name);

		// update level and stats to match exp amount
		void update();

		//heal
		void heal(int amount);

		//gain exp
		void getExp(int amount);


		//====================================================
		//=============FOR NON PLAYER ONLY====================
		//====================================================

		// spawn at higher than lv 1
		Mobile::Mobile(int mExp, std::string mName);

		// create custom enemy
		void Mobile::setMobile(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult);


	};


} // end TextGame



#endif
