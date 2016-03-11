#include <TextGame/Interface.hpp>

namespace TextGame
{
	// get input
	std::string getInput()
	{
		std::cout << "\n>>";
		std::string cmdInput;
		std::string *result;
	
		std::getline(std::cin, cmdInput);
		std::cin.clear();
	
		result = &cmdInput;

		return *result;
	}
	int getNumber()
	{
		std::stringstream ss;

		ss.clear();
		ss.str("");

		std::string ssinput = "";

		int n;

		while (true) {
			if (!std::getline(std::cin, ssinput))
				return 0;

			ss.str(ssinput);

			if (ss >> n)
				break;

			std::cout << "Invalid number, please try again" << std::endl;


			ss.clear();
			ss.str("");
			ssinput.clear();
		}



		return n;
	}

	void clearScreen()
	{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	}

	// go back to start of running loop
	// FIXME somehow isPlaying loop continues after this function
	// but does not continue if I do the same thing without a function
	void goBack()
	{
		isPlaying = false;
		isCharNamed = false;
		isBattling = false;
		std::cout << "\nisPlaying is: " << isPlaying;
		std::cout << "\nisCharNamed is: " << isCharNamed;
		std::cout << "\nisBattling is: " << isBattling << "\n";
	}

	void clearData1D(int* data)
	{
		if (data)
			delete data;
	}
	void clearData2D(int** data, int rows)
	{
		if (data)
			for (int i = 0; i < rows; i++)
				if (data[i])
					delete[] data[i];
		delete[] data;
	}





} // end TextGame
