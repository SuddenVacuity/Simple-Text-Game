
//	  ==========================================================================================
//	  =============			This file calculates monster info from				================
//	  =============					 base stats and level						================
//	  ==========================================================================================

#include <TextGame/Creature.hpp>

namespace TextGame
{
// TODO: better formulas
TextGame::Player::Player()
{
	name = "Fighter";
	namef = "Fighter";
	exp = 0;
	level = 1 + exp / 2;

	hitPointsBase = 50;
	damageBase = 10;
	defenseBase = 5;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;
}
TextGame::Player::Player(std::string playerName)
{
	name = playerName;
	exp = 0;
	level = 1 + exp / 2;

	hitPointsBase = 50;
	damageBase = 10;
	defenseBase = 5;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;
}

// update level and stats to match exp amount
void Player::update()
{
	level = 1 + exp / 2;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;
}

void Player::heal(int amount)
{
	int value = hitPoints + amount;

	if(value >= hitPointsMax)
		hitPoints = hitPointsMax;
	else
		hitPoints = hitPoints + amount;
}

void Player::getExp(int amount)
{
	exp = exp + amount;
}

// =========================================================================
// =========================================================================
// =========================================================================

// offensive enemy that dies easily
TextGame::Enemy::Enemy()
{
	name = "Generic Monster";
	namef = "Generic Monster";
	exp = 0;
	level = 1 + std::sqrt(exp);

	hitPointsBase = 30;
	damageBase = 15;
	defenseBase = 3;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.25f * level + 1.0f;
	defenseMult = 0.15f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;

	rewardExp = 1;
}
TextGame::Enemy::Enemy(int mExp, std::string mName)
{
	name = mName;
	namef = "TODO";
	exp = mExp;
	level = 1 + exp / 2;

	hitPointsBase = 30;
	damageBase = 15;
	defenseBase = 3;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.25f * level + 1.0f;
	defenseMult = 0.15f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;

	rewardExp = 1 + level / 5;
}

// create custom enemy
void Enemy::setEnemy(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult)
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
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;

	rewardExp = 1 + level / 5;
}

// update level and stats to match exp amount
void Enemy::update()
{
	level = 1 + exp / 2;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	hitPointsMax = hitPointsBase * hitPointsMult;
	hitDamageMax = damageBase * damageMult;
	hitDefenseMax = defenseBase * defenseMult;

	rewardExp = 1 + level / 5;
}

void Enemy::heal(int amount)
{
	int value = hitPoints + amount;

	if (value >= hitPointsMax)
		hitPoints = hitPointsMax;
	else
		hitPoints = hitPoints + amount;
}

} // end TextGame



