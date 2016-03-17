/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				PlayerStatistics.cpp (PlayerStatistics.hpp)
)					spy on the player
)
)		
)		
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Player/PlayerStatistics.hpp>

namespace TextGame
{
	int playerStepsTaken = 0;

	void trackPlayerSteps()
	{
		playerStepsTaken++;
	}


} // end TextGame
