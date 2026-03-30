#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./RPN <inverted Polish mathematical expression>\n";
		return (1);
	}

	try
	{
		RPN calculator;
		calculator.evaluate(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
}