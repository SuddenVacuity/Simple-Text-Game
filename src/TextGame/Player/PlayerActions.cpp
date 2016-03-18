
#include <TextGame/Player/PlayerActions.hpp>

namespace TextGame
{

	std::string playerInteract(Creature* ptrCreature, Room* ptrRoom)
	{
		// get object location to check
		int* location = ptrCreature->returnLocation();
		int dir = ptrCreature->direction;

		if (dir == 0)
			location[0] = location[0] - 1;
		else if (dir == 1)
			location[1] = location[1] - 1;
		else if (dir == 2)
			location[0] = location[0] + 1;
		else if (dir == 3)
			location[1] = location[1] + 1;

		int object = returnObjectLocation(ptrRoom->id, location);
		
		std::string string = " ";

		clearData(location);

		// interact with it
		//FIXME find a cleaner way to do this
		if (object < 100)
			string = ">> " + returnRoomString(ptrRoom->id, object);
		else if (object >= 100 && object < 200)
			string = ">> " + returnRoomString(ptrRoom->id, object - 100);
		else if (object >= 200 && object < 300)
			string = ">> " + returnRoomString(ptrRoom->id, object - 200);
		else if (object >= 300 && object < 400)
			string = ">> " + returnRoomString(ptrRoom->id, object - 300);
		else if (object >= 400 && object < 500)
			string = ">> " + returnRoomString(ptrRoom->id, object - 400);
		// add functions after this point once implemented
		else if (object >= 500 && object < 600)
			string = ">> " + returnRoomString(ptrRoom->id, object - 500);
		else if (object >= 600 && object < 700)
			string = ">> " + returnRoomString(ptrRoom->id, object - 600);
		else if (object >= 700 && object < 800)
			string = ">> " + returnRoomString(ptrRoom->id, object - 700);
		else if (object >= 800 && object < 900)
			string = ">> " + returnRoomString(ptrRoom->id, object - 800);
		else if (object >= 900 && object < 1000)
			string = ">> " + returnRoomString(ptrRoom->id, object - 900);
		else
			string = "not implemented";

		return string;
	}

} // end TextGame
