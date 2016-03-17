/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Movement.cpp (Movement.hpp)
)					contains functions for moving creatures
)
)			
)			
)
)			
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Navigation/Movement.hpp>

namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				returnDirection (Map.hpp)
	)					returns movement direction and sets direction facing based on input
	)
	)				(Creature* ptrCreature, int choice)
	)					ptrCreature = pointer to creature to be moved , choice = input
	)
	)				return new int[2] move; needs to be deleted
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int* returnDirection(Creature* ptrCreature, int choice)
	{
		int* move = new int[2];
		move[0] = 0;
		move[1] = 0;

		if (choice == 'w' || choice == 'W') {
			ptrCreature->direction = 0;
			move[0] = -1;
		}
		else if (choice == 'a' || choice == 'A') {
			ptrCreature->direction = 1;
			move[1] = -1;
		}
		else if (choice == 's' || choice == 'S') {
			ptrCreature->direction = 2;
			move[0] = 1;
		}
		else if (choice == 'd' || choice == 'D') {
			ptrCreature->direction = 3;
			move[1] = 1;
		}
		else
			std::cout << "movement failure: moveCreature in Movement.cpp";
		
		return move;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				moveCreature (Movement.hpp)
	)					checks if creature can move and moves the creature based on input
	)
	)				(Creature* ptrCreature, testRoom* room, char choice)
	)				ptrCreature = pointer to creature to move , room = pointer to room creature is in
	)							choice = input
	)				return int; changes creature location and map updates to show
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int moveCreature(Creature* ptrCreature, testRoom* room, char choice, int& gameMode)
	{
		int result = 1;
		// get creature location
		int* location = ptrCreature->returnLocation();

		int* move = returnDirection(ptrCreature, choice); // be sure to delete this

		//check if input is valid
		if(move[0] + move[1] != 0)
		{
			//change location to match where creature is stepping
			location[0] = location[0] + move[0];
			location[1] = location[1] + move[1];
			int roomData = room->returnState(location);

			// check the spot creature is trying to move to
			// 1 is solid, 
			if(roomData != 1)
			{
				ptrCreature->loc_Row = ptrCreature->loc_Row + move[0];
				ptrCreature->loc_Col = ptrCreature->loc_Col + move[1];
				trackPlayerSteps();
			}
			else
				std::cout << "\nCannot go that way.";

		}

		clearData(move);
		clearData(location);
		// delete (new) array

		// make this its own function
		int rand = 0;
		rand = std::rand() % 100;
		if (rand < room->roomEncounterRate)
			result = TextGame::startBattle(ptrCreature, gameMode);
		//FIXME add battle type to startBattle
		return result;
	}

} // end TextGame
