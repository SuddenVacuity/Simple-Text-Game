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
	)				randomBattle
	)					checks for a random battle when taking a step
	)
	)				variables
	)					origin
	)
	)				return:
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int randomBattle(Creature* ptrCreature, Room* ptrRoom, int& gameMode)
	{
		// make this its own function
		int rand = 0;
		rand = std::rand() % 100;
		if (rand < ptrRoom->roomEncounterRate)
			gameMode = TextGame::startBattle(ptrCreature, gameMode);

		//FIXME add battle type to startBattle
		return gameMode;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				checkStepObject (Movement.hpp)
	)					checks the next tile before movement and determines how to respond
	)
	)				(Creature* ptrCreature, int roomData, int* move)
	)				ptrCreature = pointer to creature to move , roomData = returned value from room object array
	)							move = { row, col } movement
	)				return void; changes creature location and can start a battle
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

	int checkStepObject(Creature* ptrCreature, Room* ptrRoom, int roomData, int* move, int& gameMode) // check how to respond to next square when moving
	{
		// check the spot creature is trying to move to
		// 100~500 can walk, all else is solid

		if (roomData >= 100 && roomData < 500)
		{
			ptrCreature->loc_Row = ptrCreature->loc_Row + move[0];
			ptrCreature->loc_Col = ptrCreature->loc_Col + move[1];
			trackPlayerSteps();
		}
		else
			std::cout << "\nCannot go that way.";

		// check if a battle is possible
		if (roomData >= 200 && roomData < 300 || roomData >= 400 && roomData < 500)
			randomBattle(ptrCreature, ptrRoom, gameMode);

		// set if creature is visible
		if(roomData >= 300 && roomData < 500)
			ptrCreature->visible = 0;
		else
			ptrCreature->visible = 1;

		return gameMode;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				moveCreature (Movement.hpp)
	)					checks if creature can move and moves the creature based on input
	)
	)				(Creature* ptrCreature, Room* room, char choice)
	)				ptrCreature = pointer to creature to move , room = pointer to room creature is in
	)							choice = input
	)				return int; changes creature location and map updates to show
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/



	int moveCreature(Creature* ptrCreature, Room* ptrRoom, char choice, int& gameMode)
	{
		// get creature location
		int* location = ptrCreature->returnLocation();

		int* move = returnDirection(ptrCreature, choice); // be sure to delete this

		
		//FIXME possible memory leak
		//check if input is valid
		if(move[0] + move[1] != 0)
		{
			//change location to match where creature is stepping
			location[0] = location[0] + move[0];
			location[1] = location[1] + move[1];
			int roomData = returnObjectLocation(ptrRoom->id, location);

			// needs to be an int so if quit/restart is chosen in battle it gets passed on
			gameMode = checkStepObject(ptrCreature, ptrRoom, roomData, move, gameMode);
		}

		clearData(location);
		clearData(move);
		// delete (new) array
		return gameMode;
	}

} // end TextGame
