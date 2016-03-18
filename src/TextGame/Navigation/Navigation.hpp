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
#include <TextGame/Navigation/Rooms/RoomInfo.hpp>

namespace TextGame
{

	char** getNavData(int* mLocation, char** data, int* size, int playerVisible);

} // end TextGame

#endif
