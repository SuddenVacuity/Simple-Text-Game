#ifndef TEXTGAME_CREATURE_HPP
#define TEXTGAME_CREATURE_HPP

//	  ==========================================================================================
//	  =============							Declares							================
//	  =============						Creature Classes	 					================
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
		u32 damage;
		u32 defense;

		u32 hitPointsMax;
		u32 hitDamageMax;
		u32 hitDefenseMax;

		Player();
		Player(std::string name);

		// update level and stats to match exp amount
		void update();

		//heal
		void heal(int amount);

		//gain exp
		void getExp(int amount);

	};

	class Enemy : public Creature
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
		u32 damage;
		u32 defense;

		u32 hitPointsMax;
		u32 hitDamageMax;
		u32 hitDefenseMax;

		u32 rewardExp;

		Enemy();

		// spawn at higher than lv 1
		TextGame::Enemy::Enemy(int mExp, std::string mName);

		// create custom enemy
		void Enemy::setEnemy(std::string mName, int mExp, int mHitPointsBase, int mDamageBase, int mDefenseBase, float mHitPointsMult, float mDamageMult, float mDefenseMult);

		// update level and stats to match exp amount
		void update();

		// heal hit points
		void heal(int amount);
	};

} // end TextGame



#endif
