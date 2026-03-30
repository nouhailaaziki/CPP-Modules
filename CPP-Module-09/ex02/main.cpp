#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	PmergeMe pm;

	try
	{
		pm.parseArguments(argc, argv);
		pm.printBefore();
		pm.process();
		pm.printAfter();
		pm.printTimings();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
}