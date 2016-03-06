#ifndef TEXTGAME_CREATURE_HPP
#define TEXTGAME_CREATURE_HPP

//	  ==========================================================================================
//	  =============			This file calculates monster info from				================
//	  =============					 base stats and level						================
//	  ==========================================================================================

#include <TextGame/CreatureInfo.hpp>


namespace TextGame
{
	class Player : public Creature
	{
	public:
		std::string name;
		std::string namef;
		u32 exp;
		f32 level;

		u32 hitPointsBase;
		u32 damageBase;
		u32 defenseBase;

		f32 hitPointsMult;
		f32 damageMult;
		f32 defenseMult;

		u32 hitPoints;
		f32 damage;
		u32 defense;

		Player();
		Player(std::string name);

		void update();
		void attack(Creature& c);

	};

	class EnemyA : public Creature
	{
	public:
		u32 id;
		std::string name;
		u32 exp;
		f32 level;

		u32 hitPointsBase;
		u32 damageBase;
		u32 defenseBase;

		f32 hitPointsMult;
		f32 damageMult;
		f32 defenseMult;

		u32 hitPoints;
		f32 damage;
		u32 defense;

		u32 rewardExp;

		EnemyA();

		// spawn at higher than lv 1
		TextGame::EnemyA::EnemyA(int mExp, std::string mName);

		void EnemyA::setEnemy(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult);
		void attack(Creature& c);
	};

	class EnemyB : public Creature
	{
	public:
		u32 id;
		std::string name;
		u32 exp;
		f32 level;

		u32 hitPointsBase;
		u32 damageBase;
		u32 defenseBase;

		f32 hitPointsMult;
		f32 damageMult;
		f32 defenseMult;

		u32 hitPoints;
		f32 damage;
		u32 defense;

		u32 rewardExp = 1;

		EnemyB();

		// spawn at higher than lv 1
		TextGame::EnemyB::EnemyB(int monsterExp, std::string monsterName);

		void attack(Creature& c);
	};
	
} // end TextGame



#endif
