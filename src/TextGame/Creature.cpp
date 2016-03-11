
//	  ==========================================================================================
//	  =============			This file calculates monster info from				================
//	  =============					 base stats and level						================
//	  ==========================================================================================

#include <TextGame/Creature.hpp>

namespace TextGame
{
// TODO: better formulas
TextGame::Mobile::Mobile()
{
	name = "Fighter";
	namef = "Fighter";
	exp = 0;
	level = 1 + exp / 2;
	loc_Row = 0;
	loc_Col = 0;

	levelCap = 999;
	hitPointsCap = 10000;
	damageCap = 2000;
	defenseCap = 1000;

	hitPointsBase = 50;
	damageBase = 10;
	defenseBase = 5;

	hitPointsMult = 1.0f + 0.2f * level;
	damageMult = 1.0f + 0.2f * level;
	defenseMult = 1.0f + 0.2f * level;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	damageMax = damageBase * damageMult;
	defenseMax = defenseBase * defenseMult;
}

// update level and stats to match exp amount
void Mobile::update()
{
	level = 1 + exp / 2;

	if (level > levelCap)
		level = levelCap;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	damageMax = damageBase * damageMult;
	defenseMax = defenseBase * defenseMult;

	if (hitPointsMax > hitPointsCap)
	{
		hitPointsMax = hitPointsCap;
	}
	if (damage > damageCap)
	{
		damage = damageCap;
		damageMax = damageCap;
	}
	if (defense > defenseCap)
	{
		defense = defenseCap;
		defenseMax = defenseCap;
	}

}

void Mobile::heal(int amount)
{
	int value = hitPoints + amount;

	if(value >= hitPointsMax)
		hitPoints = hitPointsMax;
	else
		hitPoints = hitPoints + amount;
}

void Mobile::getExp(int amount)
{
	exp = exp + amount;
}

int* Mobile::getLocation()
{
	// FIXME prevent memory leak
	int* result = new int[2];
	result[0] = loc_Row;
	result[1] = loc_Col;

	return result;
}

//====================================================
//=============FOR NON PLAYER ONLY====================
//====================================================


// create custom enemy
void Mobile::setMobile(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult)
{
	name = mName;
	namef = "TODO";
	exp = mExp;
	level = 1 + exp / 2;

	hitPointsBase = mHitPointsBase;
	damageBase = mDamageBase;
	defenseBase = mDefenseBase;

	hitPointsMult = 1.0f + mHitPointsMult * level;
	damageMult = 1.0f + mDamageMult * level;
	defenseMult = 1.0f + mDefenseMult * level;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	damageMax = damageBase * damageMult;
	defenseMax = defenseBase * defenseMult;

	rewardExp = 1 + level / 5;
}



} // end TextGame



