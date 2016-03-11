
//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================

#include <TextGame/Navigation/Navigation.hpp>


namespace TextGame
{


	int** getNavData(int* mLocation, int** data, int* size)
	{
		//cap on map size
		const int row = 16;
		const int col = 16;

		//set map edges with player in the center of the map
		//half a row is found with columns
		int sideCol[2];
		sideCol[0] = mLocation[0] - row / 2;
		sideCol[1] = mLocation[0] + row / 2;
		//half a column is found with rows
		int sideRow[2];
		sideRow[0] = mLocation[1] - col / 2;
		sideRow[1] = mLocation[1] + col / 2;


		//FIXME prevent memory leak
		int** navData = new int*[row];
	
		// populate create data based on player location
		for (int i = sideCol[0], l = 0; i < sideCol[1]; i++, l++)
		{
			navData[l] = new int[col];
			for (int j = sideRow[0], m = 0; j < sideRow[1]; j++, m++)
			{
				// check limits on room data
				if(j < 0 || i < 0 || j > size[1] - 1 || i > size[0] - 1)
				{
					navData[l][m] = 1000;
				}
				else
					navData[l][m] = data[i][j];
			}
		}

		//set Player on map
		navData[7][7] = 999;

		return navData;
	}



}
