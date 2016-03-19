/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				Creature.cpp (Creature.hpp)
)					nothing yet maybe weapon/armor/skill support later
)
)				
)					
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Creature/Creature.hpp>

namespace TextGame
{
	void getCreatureStats(Creature* ptrCreature)
	{
		TextGame::clearScreen(); // Interface.cpp
		std::cout << "\n==================================";
		std::cout << "\nCharacter Information:";
		std::cout << "\nName: " << ptrCreature->name;
		std::cout << "\n";
		std::cout << "\nLevel: " << ptrCreature->level;
		std::cout << "\nEXP to next: "<< ptrCreature->returnExpTnl();
		std::cout << "\ntotal EXP: " << ptrCreature->exp;
		std::cout << "\n";
		std::cout << "\nHP: " << ptrCreature->hitPoints << " / " << ptrCreature->HpStaSpeMax;
		std::cout << "\n";
		std::cout << "\nDamage: " << ptrCreature->damage;
		std::cout << "\nDefense: " << ptrCreature->defense << "<-- These do nothing.";;
		std::cout << "\nBlock: " << ptrCreature->block << "<-- These do nothing.";;
		std::cout << "\nDodge: " << ptrCreature->dodge << "<-- These do nothing.";
		std::cout << "\n";
		std::cout << "\nstr: " << ptrCreature->str << " kno: " << ptrCreature->kno << " fit: " << ptrCreature->fit << " agi: " << ptrCreature->agi;
		std::cout << "\nwis: " << ptrCreature->wis << " per: " << ptrCreature->per << " spd: " << ptrCreature->spd;

		std::cout << "\n";
		std::cout << "\nPress anything to continue.\n\n";
		char wait = _getch();
		clearScreen();
	}

} // end TextGame
