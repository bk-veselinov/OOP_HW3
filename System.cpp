#include "System.h"
#include <iostream>
#include <exception>

constexpr int BUFFER_SIZE = 1024;


void System::run()
{
	initializeFunction();

	std::cout << "Choose how to calculate the values of the function:\n";
	std::cout << "[1] - with bounds\n";
	std::cout << "[2] - with consecotive values\n";
	int type;
	std::cin >> type;

	if (type == 1)
	{
		initializeBound();
		calculateFunctionWithBound();
	}
	else if(type == 2)
	{
		calculateFunctionWithConsecotiveValues();
	}
	else
	{
		throw std::exception("Invalid type for function calculation");
	}
}

void System::initializeBound()
{
	std::cout << "Enter left bound: ";
	std::cin >> leftBound;
	std::cout << "\nEnter right bound: ";
	std::cin >> rightBound;
	std::cout << "\n";
}

void System::initializeFunction() 
{
	std::cout << "Enter file name: ";

	char* fileName = new char[BUFFER_SIZE];
	FunctionFactory factory;
	function = factory.PartialFunctionFactory(fileName);
	delete fileName;

}

void System::calculateFunctionWithBound()const
{
	if (leftBound > rightBound)
	{
		throw std::exception("The left bound is bigger then the right one");
	}
	for (size_t i = leftBound; i < rightBound; i++)
	{
		try {
			std::cout << "f(" << i << ')' << " = " << (*function)(i) << "\n";

		}
		catch (std::exception) {
			std::cout << "The function is not defined for x = " << i << '\n';
		}
	}
}

void System::calculateFunctionWithConsecotiveValues()const
{
	char* command = new char[BUFFER_SIZE];
	std::cout << "Now you have to enter commands\n Enter NEXT in order to calculate the next value\n";
	std::cout << "Enter END to stop calculating values\n Any other command would be conidered as if END was entered\n ";

	for (size_t i = INT32_MIN; i < INT32_MAX; i++)
	{
		std::cout << "Enter command: ";
		std::cin.getline(command, BUFFER_SIZE);

		if (!strcmp(command, "NEXT"))
		{
			try {
				std::cout << "f(" << i << ')' << " = " << (*function)(i) << "\n";

			}
			catch (std::exception) {
				std::cout << "The function is not defined for x = " << i << '\n';
			}
		}
		else
		{
			break;
		}
	}
	delete[] command;
}

System::~System()
{
	delete function;
}
