#ifndef TEXTGAME_NAVIGATION_ROOMS_HPP
#define TEXTGAME_NAVIGATION_ROOMS_HPP 

#include <TextGame/Globals.hpp>
#include <TextGame/Navigation/Map.hpp>
   
namespace TextGame
{
	/*
	int roomState[roomRows][roomColumns] =	000 default
											001 solid
											010 floor

	*/

struct testRoom
{
	bool roomVisited;
	int roomEncounterRate = 0;
	std::string roomString[10] =
	{ 
		"[test roomString[0]]",
		"Welcome to the Testing Room", 
		"Testing Room", 
		"This is a room made just for testing mechanics.",
		"The room is filled with various test functions."
	};

	static const int roomRows = 16;
	static const int roomColumns = 16;
	int roomObject[roomRows][roomColumns] = 
	{   //1		2	  3		4	  5		6	  7		8		
		{ 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 },  // 1
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 2
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 3
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 4
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 5
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 6
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 7
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 8
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 9
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 10
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 11
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 12
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 13
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 14
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 15
		{ 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 }   // 16
	};

	int roomState[roomRows][roomColumns] =
	{
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 }
	};

	//================================================================================
	//================================================================================
	~testRoom();

	std::string returnString(int stringNum);
	int* testRoom::returnSize();
	int** returnData();
};


struct testRoom2
{
	bool roomVisited;
	int roomEncounterRate = 0;
	std::string roomString[10] =
	{
		"[test roomString[0]]",
		"This is the Secondary Test Room",
		"Testing Room",
		"This is a room is just like the other.",
		"Only with differences."
	};

	static const int roomRows = 16;
	static const int roomColumns = 16;
	int roomObject[roomRows][roomColumns] =
	{   //1		2	  3		4	  5		6	  7		8		
		{ 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 },  // 1
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 2
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 3
		{ 001 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 000 , 001 },  // 4
		{ 001 , 000 , 000 , 001 , 000 , 001 , 000 , 000 , 000 , 000 , 001 , 000 , 001 , 000 , 000 , 001 },  // 5
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 6
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 7
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 8
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 9
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 10
		{ 001 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 001 },  // 11
		{ 001 , 000 , 000 , 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 , 000 , 000 , 001 },  // 12
		{ 001 , 000 , 000 , 000 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 000 , 000 , 000 , 001 },  // 13
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 14
		{ 001 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 000 , 001 },  // 15
		{ 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 , 001 }   // 16
	};

	int roomState[roomRows][roomColumns] =
	{
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 },
		{ 00 , 00 , 00 , 00 , 00 , 00 , 00 , 00 }
	};

	//================================================================================
	//================================================================================
	~testRoom2();

	std::string returnString(int stringNum);
	int* testRoom2::returnSize();
	int** returnData();
};



struct redRoom
{
	bool roomVisited;
	std::string roomString[10] =
	{
		"",
		"Red Room", 
		"1st Primary Adjunct", 
		"This Room is entirely red.", 
		"Everything from floor to ceiling is red."
	};

	static const int roomRows = 8;
	static const int roomColumns = 8;
	int roomSize[roomRows][roomColumns] = { 0, 0 };
	int roomData[roomRows][roomColumns] = { 0, 0 };
};

struct blueRoom
{
	bool roomVisited;
	std::string roomString[10] =
	{
		"",
		"Blue Room", 
		"2nd Primary Adjunct", 
		"This Room is entirely blue.", 
		"Everything from floor to ceiling is blue."
	};

	static const int roomRows = 8;
	static const int roomColumns = 8;
	int roomSize[roomRows][roomColumns] = { 0, 0 };
	int roomData[roomRows][roomColumns] = { 0, 0 };
};

struct greenRoom
{
	bool roomVisited;
	std::string roomString[10] =
	{
		"",
		"Green Room", 
		"3rd Primary Adjunct", 
		"This Room is entirely green.", 
		"Everything from floor to ceiling is green."
	};

	static const int roomRows = 8;
	static const int roomColumns = 8;
	int roomSize[roomRows][roomColumns] = { 0, 0 };
	int roomData[roomRows][roomColumns] = { 0, 0 };
};





} // end TextGame

#endif

