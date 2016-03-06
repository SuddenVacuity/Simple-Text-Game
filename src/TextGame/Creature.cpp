
//	  ==========================================================================================
//	  =============																================
//	  =============																================
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
}


void Player::update()
{
	level = 1 + exp / 2;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.2f * level + 1.0f;

	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;
}
void Player::attack(Creature& c)
{
	c.hitPoints = c.hitPoints - damage;
	return;
}

// =========================================================================
// =========================================================================
// =========================================================================

// offensive enemy that dies easily
TextGame::EnemyA::EnemyA()
{
	//id = 0;
	name = "Generic Monster";
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

	rewardExp = 1;
}

// spawn at higher than lv 1
TextGame::EnemyA::EnemyA(int mExp, std::string mName)
{
	//id = 0;
	name = mName;
	exp = mExp;
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

	rewardExp = 1;
}

void EnemyA::setEnemy(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult)
{
	name = mName;
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

	rewardExp = 1 + level / 5;
}
void EnemyA::attack(Creature& c)
{
	c.hitPoints = c.hitPoints - damage;
	return;
}

// =========================================================================
// =========================================================================
// =========================================================================

// defensive enemy that does low damage
TextGame::EnemyB::EnemyB()
{
	//id = 1;
	name = "Standard Monster";
	exp = 0;
	level = 1 + std::sqrt(exp);

	hitPointsBase = 80;
	damageBase = 20;
	defenseBase = 25;

	hitPointsMult = 0.25f * level + 1.0f;
	damageMult = 0.2f * level + 1.0f;
	defenseMult = 0.25f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	rewardExp = 1;
}

// spawn at higher than lv 1
TextGame::EnemyB::EnemyB(int monsterExp, std::string monsterName)
{
	//id = 0;
	name = monsterName;
	exp = monsterExp;
	level = 1 + std::sqrt(exp);

	hitPointsBase = 60;
	damageBase = 15;
	defenseBase = 3;

	hitPointsMult = 0.2f * level + 1.0f;
	damageMult = 0.25f * level + 1.0f;
	defenseMult = 0.15f * level + 1.0f;

	hitPoints = hitPointsBase * hitPointsMult;
	damage = damageBase * damageMult;
	defense = defenseBase * defenseMult;

	rewardExp = 1;
}

void EnemyB::attack(Creature& c)
{
	c.hitPoints = c.hitPoints - damage;
	return;
}


} // end TextGame



