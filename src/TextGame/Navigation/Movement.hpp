#ifndef TEXTGAME_NAVIGATION_MOVEMENT_HPP
#define TEXTGAME_NAVIGATION_MOVEMENT_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Movement.hpp
)					makes Movement functions available
)
)			
)			
)
)			
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Navigation.hpp>

namespace TextGame
{
	int* returnDirection(Creature* ptrCreature, int choice);
	int moveCreature(Creature* ptrCreature, testRoom* room, char choice,int& gameMode);
} // end TextGame

#endif
