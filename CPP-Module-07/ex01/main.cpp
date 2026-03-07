#include "iter.hpp"

template <typename Type>
void	print(const Type& value)
{
	std::cout << value << " ";
}

template <typename Type>
void	increment(Type& value)
{
	value++;
}

void	toUpper(char& c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
}

int	main()
{
	// INT ARRAY
	int numbers[] = {1, 2, 3, 4, 5};
	size_t numbersLen = sizeof(numbers) / sizeof(numbers[0]);

	std::cout << "Before increment:" << std::endl;
	iter(numbers, numbersLen, print<int>);

	iter(numbers, numbersLen, increment<int>);

	std::cout << "\nAfter increment:" << std::endl;
	iter(numbers, numbersLen, print<int>);

    std::cout << std::endl;

	// CHAR ARRAY
	char letters[] = {'a', 'b', 'c', 'd'};
	size_t lettersLen = sizeof(letters) / sizeof(letters[0]);

	std::cout << "\nBefore uppercase:" << std::endl;
	iter(letters, lettersLen, print<char>);

	iter(letters, lettersLen, toUpper);

	std::cout << "\nAfter uppercase:" << std::endl;
	iter(letters, lettersLen, print<char>);

    std::cout << std::endl;

	// STRING ARRAY
	std::string words[] = {"hello", "world", "templates"};
	size_t wordsLen = sizeof(words) / sizeof(words[0]);

	std::cout << "\nString array:" << std::endl;
	iter(words, wordsLen, print<std::string>);

    std::cout << std::endl;

	// CONST ARRAY
	const int constNumbers[] = {10, 20, 30};
	size_t constLen = sizeof(constNumbers) / sizeof(constNumbers[0]);

	std::cout << "\nConst array:" << std::endl;
	iter(constNumbers, constLen, print<int>);

    std::cout << std::endl;
	return (0);
}