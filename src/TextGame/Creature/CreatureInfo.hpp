#ifndef TEXTGAME_CREATUREINFO_HPP
#define TEXTGAME_CREATUREINFO_HPP
/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CreatureInfo.hpp
)					makes Creature class and Creature functions available
)
)				
)				Include in 
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Player/PlayerStatistics.hpp>


namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				
	)				Functions to return values from storage arrays
	)
	)				
	)					
	)
	)				
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	std::string returnCreatureString(int id, int num); // CreatureString.cpp
	bool returnCreatureBool(int id, int num); // CreatureBool.cpp
	int returnCreatureInteger(int id, int num); // CreatureInteger.cpp
	float returnCreatureFloat(int id, int num); // CreatureFLoat.cpp

	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				
	)				 class Creature
	)				 	main class used by creatures
	)				
	)				
	)
	)				
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	class Creature 
	{
	private:
		float m_logLevel;
	public:
		Creature();
		//Creature(int id);
		//Creature(int id, int x);
		Creature(int c_Id, int c_Level, int c_Row, int c_Col);

		int id;

		int loc_Row;
		int loc_Col;
		int direction;
		int visible;

		std::string name = "Adventurer";

		int fac;
		int dropSet;
		_int64 exp;
		int rewardExp;
		int gender;

		int startLV;
		int minLevel;
		int maxLevel;
		int level;
		
		int hitPointsBase;
		int staminaBase;
		int specialBase;
		int damageBase;
		int defenseBase;

		int strBase;
		int knoBase;
		int fitBase;
		int agiBase;
		int wisBase;
		int perBase;
		int spdBase;

		int aggresion;
		int confidence;
		int moral;
		int karma;
		int luck;

		float hitPointsMult;
		float staminaMult;
		float specialMult;
		float damageMult;
		float defenseMult;

		float strMult;
		float knoMult;
		float fitMult;
		float agiMult;
		float wisMult;
		float perMult;
		float spdMult;

		float strPerLevel;
		float knoPerLevel;
		float fitPerLevel;
		float agiPerLevel;
		float wisPerLevel;
		float perPerLevel;
		float spdPerLevel;

		int str;
		int kno;
		int fit;
		int agi;
		int wis;
		int per;
		int spd;

		int hitPoints;
		int stamina;
		int special;
		int damage;
		int defense;
		int block;
		int dodge;

		unsigned int HpStaSpeMax;
		unsigned int damageMax;
		unsigned int defenseMax;

		int levelCap;
		int statCap;

		unsigned int HpStaSpeCap;
		unsigned int damageCap;
		unsigned int defenseCap;

		/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
		)
		)				Start Functions
		)
		)					
		)
		)
		%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

		// update level and stats to match exp amount
		void Creature::updateHitPoints();
		void Creature::update();

		//heal
		void Creature::heal(int amount);

		//gain exp
		void Creature::setLevel(int n);
		_int64 Creature::returnNextExp(); // to check exp needed to be next level
		void Creature::updateLevel();
		void Creature::addExp(int amount);
		int Creature::returnExpTnl();
		int* Creature::returnLocation();
		int Creature::getRewardExp(Creature* ptrCreature);
		void Creature::setLocation(int row, int col);

		//====================================================
		//=============FOR NON PLAYER ONLY====================
		//====================================================

		// create custom enemy
		void Creature::setMobileLevel(Creature* ptrPlayer);

	};

} // end TextGame

#endif	
