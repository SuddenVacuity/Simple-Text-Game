
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
	std::string name = "Hero(ine)";
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

// offensive enemy that dies easily
TextGame::EnemyA::EnemyA()
{
	//id = 0;
	std::string name = "Generic Monster";
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
}
void EnemyA::attack(Creature& c)
{
	c.hitPoints = c.hitPoints - damage;
	return;
}

// defensive enemy that does low damage
TextGame::EnemyB::EnemyB()
{
	//id = 1;
	std::string name = "Standard Monster";
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
}
void EnemyB::attack(Creature& c)
{
	c.hitPoints = c.hitPoints - damage;
	return;
}


} // end TextGame



