#ifndef TEXTGAME_NAVIGATION_HPP
#define TEXTGAME_NAVIGATION_HPP

//	  ==========================================================================================
//	  =============																================
//	  =============																================
//	  ==========================================================================================

#include <TextGame/Globals.hpp>

#include <iostream>

namespace TextGame
{
struct Navigation
{
	u32 x, y;

	Navigation()
		: x(10), y(10) {}
	explicit Navigation(u32 xy)
		: x(xy), y(xy) {}
	Navigation(u32 x, u32 y)
		: x(x), y(y) {}
	Navigation(u32 xy[2])
		:x(xy[0]), y(xy[1]) {}

	Navigation(const Navigation& other) = default; // copy constructor

	union
	{
		u32 data[2];
		struct
		{
			u32 x, y;
		};
	};
											 // operators
	inline u32& operator[](size_t index) { return data[index]; }
	inline const u32& operator[](size_t index) const { return data[index]; }

	inline Navigation& operator+(const Navigation& other)
	{
		x = x + other.x, 
		y = y + other.y;
	}

	inline Navigation& operator-(const Navigation& other)
	{
		x = x - other.x,
		y = y - other.y;
	}

	void move(Navigation& move_x, Navigation& move_y);
	void lost(); // return location
};
} // end TextGame

#endif
