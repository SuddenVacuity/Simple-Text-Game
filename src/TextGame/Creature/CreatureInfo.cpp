/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
)				CreatureInfo.cpp (CreatureInfo.hpp)
)					contains Creature class constuctors and functions
)
)			
)					
)
)				
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
#include <TextGame/Creature/CreatureInfo.hpp>


namespace TextGame
{
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				class: Creature (CreatureInfo.hpp)
	)					container for player and enemies
	)
	)				(int c_Id, int c_Level, int c_Row, int c_Col)
	)					c_Id = monster id , c_Level = monster level , c_Row = row location , c_Col = column location
	)
	)				
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	Creature::Creature()
	{
		id = 0;

		loc_Row = 0;
		loc_Col = 0;
		direction = 0;
		visible = 1;
		
		std::string name = "Adventurer"; // CreatureInfo.hpp

		fac			= returnCreatureInteger(id, 0);
		dropSet		= returnCreatureInteger(id, 1);
		exp			= returnCreatureInteger(id, 2);
		rewardExp	= returnCreatureInteger(id, 3);
		gender		= returnCreatureInteger(id, 4);

		startLV		= returnCreatureInteger(id, 5);
		minLevel	= returnCreatureInteger(id, 6);
		maxLevel	= returnCreatureInteger(id, 7);
		level		= returnCreatureInteger(id, 8);

		hitPointsBase	= returnCreatureInteger(id, 9);
		staminaBase		= returnCreatureInteger(id, 10);
		specialBase		= returnCreatureInteger(id, 11);
		damageBase 		= returnCreatureInteger(id, 12);
		defenseBase		= returnCreatureInteger(id, 13);

		strBase = returnCreatureInteger(id, 14);
		knoBase = returnCreatureInteger(id, 15);
		fitBase = returnCreatureInteger(id, 16);
		agiBase = returnCreatureInteger(id, 17);
		wisBase = returnCreatureInteger(id, 18);
		perBase = returnCreatureInteger(id, 19);
		spdBase = returnCreatureInteger(id, 20);

		aggresion	= returnCreatureInteger(id, 21);
		confidence	= returnCreatureInteger(id, 22);
		moral		= returnCreatureInteger(id, 23);
		karma		= returnCreatureInteger(id, 24);
		luck		= returnCreatureInteger(id, 25);

		hitPointsMult = returnCreatureFloat(id, 0);
		staminaMult	= returnCreatureFloat(id, 1);
		specialMult	= returnCreatureFloat(id, 2);
		damageMult	= returnCreatureFloat(id, 3);
		defenseMult	= returnCreatureFloat(id, 4);

		strMult = returnCreatureFloat(id, 5);
		knoMult = returnCreatureFloat(id, 6);
		fitMult = returnCreatureFloat(id, 7);
		agiMult = returnCreatureFloat(id, 8);
		wisMult = returnCreatureFloat(id, 9);
		perMult = returnCreatureFloat(id, 10);
		spdMult = returnCreatureFloat(id, 11);

		strPerLevel = returnCreatureFloat(id, 12);
		knoPerLevel = returnCreatureFloat(id, 13);
		fitPerLevel = returnCreatureFloat(id, 14);
		agiPerLevel = returnCreatureFloat(id, 15);
		wisPerLevel = returnCreatureFloat(id, 16);
		perPerLevel = returnCreatureFloat(id, 17);
		spdPerLevel = returnCreatureFloat(id, 18);

		// limits
		levelCap = 999;
		statCap = 999999;

		//max possible
		HpStaSpeCap = 999999;
		damageCap = 999999;
		defenseCap = 999999;

	}
	// id, name, locations for row and column
	Creature::Creature(int c_Id, int c_Level, int c_Row, int c_Col)
	{
		id = c_Id;

		loc_Row = c_Row;
		loc_Col = c_Col;
		direction = 0;
		visible = 1;

		std::string name = "Adventurer"; // CreatureInfo.hpp

		fac = returnCreatureInteger(id, 0);
		dropSet = returnCreatureInteger(id, 1);
		exp = returnCreatureInteger(id, 2);
		rewardExp = returnCreatureInteger(id, 3);
		gender = returnCreatureInteger(id, 4);

		startLV = returnCreatureInteger(id, 5);
		minLevel = returnCreatureInteger(id, 6);
		maxLevel = returnCreatureInteger(id, 7);
		level = c_Level;

		hitPointsBase = returnCreatureInteger(id, 9);
		staminaBase = returnCreatureInteger(id, 10);
		specialBase = returnCreatureInteger(id, 11);
		damageBase = returnCreatureInteger(id, 12);
		defenseBase = returnCreatureInteger(id, 13);

		strBase = returnCreatureInteger(id, 14);
		knoBase = returnCreatureInteger(id, 15);
		fitBase = returnCreatureInteger(id, 16);
		agiBase = returnCreatureInteger(id, 17);
		wisBase = returnCreatureInteger(id, 18);
		perBase = returnCreatureInteger(id, 19);
		spdBase = returnCreatureInteger(id, 20);

		aggresion = returnCreatureInteger(id, 21);
		confidence = returnCreatureInteger(id, 22);
		moral = returnCreatureInteger(id, 23);
		karma = returnCreatureInteger(id, 24);
		luck = returnCreatureInteger(id, 25);

		hitPointsMult = returnCreatureFloat(id, 0);
		staminaMult = returnCreatureFloat(id, 1);
		specialMult = returnCreatureFloat(id, 2);
		damageMult = returnCreatureFloat(id, 3);
		defenseMult = returnCreatureFloat(id, 4);

		strMult = returnCreatureFloat(id, 5);
		knoMult = returnCreatureFloat(id, 6);
		fitMult = returnCreatureFloat(id, 7);
		agiMult = returnCreatureFloat(id, 8);
		wisMult = returnCreatureFloat(id, 9);
		perMult = returnCreatureFloat(id, 10);
		spdMult = returnCreatureFloat(id, 11);

		strPerLevel = returnCreatureFloat(id, 12);
		knoPerLevel = returnCreatureFloat(id, 13);
		fitPerLevel = returnCreatureFloat(id, 14);
		agiPerLevel = returnCreatureFloat(id, 15);
		wisPerLevel = returnCreatureFloat(id, 16);
		perPerLevel = returnCreatureFloat(id, 17);
		spdPerLevel = returnCreatureFloat(id, 18);

		// limits
		levelCap = 999;
		statCap = 999999;

		//max possible
		HpStaSpeCap = 999999;
		damageCap = 999999;
		defenseCap = 999999;

	}

	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				Creature::update (CreatureInfo.hpp) TODO: each stat into its own function so they can be done seperately
	)					update stats to match level
	)
	)				
	)					
	)
	)				return void;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

	void Creature::updateHitPoints()
	{
		hitPoints = (1 + hitPointsBase) * (1 + fit / 100) * (1 + (hitPointsMult * level) * m_logLevel);
	}

	void Creature::update()
	{
		m_logLevel = log(level); // multiplier from level

		// start calculating final stats
		str = (1 + strBase) * (1 + strMult * level) + (strPerLevel * level);
		kno = (1 + knoBase) * (1 + knoMult * level) + (knoPerLevel * level);
		fit = (1 + fitBase) * (1 + fitMult * level) + (fitPerLevel * level);
		agi = (1 + agiBase) * (1 + agiMult * level) + (agiPerLevel * level);
		wis = (1 + wisBase) * (1 + wisMult * level) + (wisPerLevel * level);
		per = (1 + perBase) * (1 + perMult * level) + (perPerLevel * level);
		spd = (1 + spdBase) * (1 + spdMult * level) + (spdPerLevel * level);

		stamina = (1 + staminaBase) * (1 + str / 150) * (1 + (staminaMult * level) * m_logLevel);
		special = (1 + specialBase) * (1 + kno / 150) * (1 + (specialMult * level) * m_logLevel);
		damage = (1 + damageBase) * (1 + str / 150) * (1 + (damageMult * level) * m_logLevel);
		defense = (1 + defenseBase) * (1 + fit / 150) * (1 + (defenseMult * level) * m_logLevel);
		block = (1 + str / 100) * (1 + fit / 150);
		dodge = (1 + agi / 100) * (1 + spd / 150);

		//current max
		HpStaSpeMax = (1 + hitPointsBase) * (1 + fit / 100) * (1 + (hitPointsMult * level) * m_logLevel);
		damageMax = (1 + damageBase) * (1 + str / 150) * (1 + (damageMult * level) * m_logLevel);
		defenseMax = (1 + defenseBase) * (1 + fit / 150) * (1 + (defenseMult * level) * m_logLevel);

		if (HpStaSpeMax > HpStaSpeCap)
		{
			HpStaSpeMax = HpStaSpeCap;
		}
		if (defense > defenseCap)
		{
			defense = defenseCap;
			defenseMax = defenseCap;
		}

	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				Creature::heal (CreatureInfo.hpp)
	)					add to hitPoints but not go over max hitPoints
	)
	)				(int amount)
	)					amount to heal
	)
	)				return void;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void Creature::heal(int amount)
	{
		hitPoints = hitPoints + amount;
		if (hitPoints > HpStaSpeMax)
			hitPoints = HpStaSpeMax;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				Creature::setLevel (CreatureInfo.hpp)
	)					set level from 1 to levelCap and change total exp to match
	)
	)				(int n)
	)					n = level to set
	)
	)				return void:
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void Creature::setLevel(int n)
	{
		if(n > 0 && n <= levelCap)
			level = n;
		else if (n > levelCap)
			level = levelCap;
		else
			level = 1;

		n = level;

		if(n == 1)
			exp = 0;
		else
			exp = pow(n - 1, 3) * 20 + 180;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				
	)				Exp Functions
	)
	)				
	)				
	)
	)				
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	// return: total exp needed to reach next level (CreatureInfo.hpp)
	_int64 Creature::returnNextExp()
	{
		int nextLev = level;

		_int64 nextExp = pow(nextLev, 3) * 20 + 180;

		return nextExp;
	}

	// update level to match exp (loops until level is caught up) (CreatureInfo.hpp)
	// does not go past levelCap
	void Creature::updateLevel()
	{
		// -1 to not end up with 0 exp tnl
		_int64 nextExp = returnNextExp() - 1;
		for (; exp > nextExp && level < levelCap;)
		{
			level = level++;
			nextExp = returnNextExp() - 1;
		}
		//FIXME add cap to exp
	}

	// add amount of exp then run updateLevel() (CreatureInfo.hpp)
	void Creature::addExp(int amount)
	{
		exp = exp + amount;
		updateLevel();
	}

	// return: exp needed to get from current exp to the next level (CreatureInfo.hpp)
	int Creature::returnExpTnl()
	{
		// -1 to get total exp to get to previous level
		_int64 curExp = pow(level - 1, 3) * 20 + 180;

		int expTnl = returnNextExp() - exp;

		return expTnl;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				Creature::returnLocation (CreatureInfo.hpp)
	)					get Creature's location
	)
	)				
	)					
	)
	)				return new int[2] result; must be deleted to avoid memory leak
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int* Creature::returnLocation() // MEMLEAK creates new array be sure to delete
	{
		int* result = new int[2];
		result[0] = loc_Row;
		result[1] = loc_Col;

		return result;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				Creature::getrewardExp (CreatureInfo.hpp)
	)					returns exp base on monster base rewardExp and level
	)
	)				(Creature* ptrCreature)
	)					must be a pointer to Creature class to get exp from
	)
	)				return int;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	int Creature::getRewardExp(Creature* ptrCreature)
	{
		return pow(ptrCreature->level , 2) * ptrCreature->rewardExp + 50;
	}
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				setLocation (CreatureInfo.hpp)
	)					set the location of a creature
	)
	)				(int row, int col)
	)					row = row to move to , col = column to move to
	)
	)				return void:
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void Creature::setLocation(int row, int col)
	{
		loc_Row = row;
		loc_Col = col;
	}
	//====================================================
	//=============FOR NON PLAYER ONLY====================
	//====================================================
	/*%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
	)				setMobileLevel (CreatureInfo.hpp)
	)					makes creature level match (within the creaures limits) the level of input creature
	)
	)				(Creature* ptrCreature)
	)					must be a pointer to Creature class to match level to
	)
	)				return void;
	%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
	void Creature::setMobileLevel(Creature* ptrPlayer)
	{
		if(ptrPlayer->level < minLevel)
			level = minLevel;
		else if(ptrPlayer->level > maxLevel )
			level = maxLevel;
		else
			level = ptrPlayer->level;
	}

} // end TextGame
