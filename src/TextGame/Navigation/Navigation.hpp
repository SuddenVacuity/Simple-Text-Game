#ifndef TEXTGAME_NAVIGATION_HPP
#define TEXTGAME_NAVIGATION_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Navigation.hpp
)					makes Navigation functions available
)
)			
)			
)
)			
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Rooms.hpp>
#include <TextGame/Combat/Combat.hpp>

namespace TextGame
{

	int** getNavData(int* mLocation, int** data, int* size);

} // end TextGame

#endif
