/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CleanUp.cpp (CleanUp.hpp)
)					mostly to delete anything made with new
)
)				
)					
)
)
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/CleanUp.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				clearData (CleanUp.hpp)
	)					delete 1D/2D arrays made with new
	)
	)				(int* data)				(int** data, rows)
	)					data = 1D array			data = 2D array , rows = number of rows in the array
	)											
	)				return: void
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void clearData(int* data)
	{
		if (data)
			delete data;
	}
	void clearData(int** data, int rows)
	{
		if (data)
			for (int i = 0; i < rows; i++)
				if (data[i])
					delete[] data[i];
		delete[] data;
	}

} // end TextGame