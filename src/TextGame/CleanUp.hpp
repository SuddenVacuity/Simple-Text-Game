#ifndef TEXTGAME_CLEANUP_HPP
#define TEXTGAME_CLEANUP_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CleanUp.hpp
)					make clean up functions available
)
)				
)				Include in Global.hpp
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

namespace TextGame
{

	void clearData(int* data);
	void clearData(int** data, int rows);

} // end TextGame

#endif
