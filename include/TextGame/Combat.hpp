#ifndef TEXTGAME_COMBAT_HPP
#define TEXTGAME_COMBAT_HPP

//	  ==========================================================================================
//	  =============							 Declares							================
//	  =============						  Battle Funtions						================
//	  ==========================================================================================

#include <TextGame/Globals.hpp>
#include <TextGame/Interface.hpp>
#include <TextGame/Creature.hpp>

namespace TextGame
{
	void mobileAttack(Mobile *attacker, Mobile *target);

	void startBattle(Mobile *ptrPlayer);

	void customMobile(Mobile *ptrMobile);
} // end TextGame

#endif
