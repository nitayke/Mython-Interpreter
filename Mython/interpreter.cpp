#include "type.h"
#include "InterperterException.h"
#include "parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Nitay Kessner"


int main(int argc,char **argv)
{
	std::cout << WELCOME << YOUR_NAME << std::endl;

	std::string input_string;
	Type* type;

	// get new command from user
	std::cout << ">>> ";
	std::getline(std::cin, input_string);
	
	while (input_string != "quit()")
	{
		// prasing command
		if (input_string == "")
		{
			std::cout << ">>> ";
			std::getline(std::cin, input_string);
			continue;
		}
		try
		{
			type = Parser::parseString(input_string);
			if (type->isPrintable())
			{
				std::cout << type->toString() << std::endl;
			}
			if (type->getIsTemp())
			{
				delete type;
			}
		}
		catch (const InterperterException& e)
		{
			std::cout << e.what() << std::endl;
		}

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);
	}
	
	Parser::clearVariables();

	return 0;
}


