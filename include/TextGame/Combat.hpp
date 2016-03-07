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
	void playerAttack(Player *attacker, Enemy *target);
	void enemyAttack(Enemy *attacker, Player *target);

	void startBattle(Player *ptrPlayer);

} // end TextGame

#endif
