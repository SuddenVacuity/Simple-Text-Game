#ifndef TEXTGAME_COMBAT_HPP
#define TEXTGAME_COMBAT_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Combat.hpp
)					Makes Combat.cpp function available
)
)				
)				Include in 
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Interface/Interface.hpp>
#include <TextGame/Player/PlayerStatistics.hpp>
#include <TextGame/Creature/Creature.hpp>

namespace TextGame
{
	void mobileAttack(Creature* attacker, Creature* target);
	int startBattle(Creature* ptrPlayer);

} // end TextGame

#endif
