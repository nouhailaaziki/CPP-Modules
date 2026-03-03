#include "ScalarConverter.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(const ScalarConverter&)
{}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
	return (*this);
}

static bool isPseudoLiteral(const std::string& str)
{
	return (
		str == "nan" ||
		str == "nanf" ||
		str == "+inf" ||
		str == "-inf" ||
		str == "+inff" ||
		str == "-inff"
	);
}

static void printChar(double value)
{
	std::cout << "char: ";

	if (value < 0 || value > 127 || value != value)
	{
		std::cout << "impossible\n";
		return;
	}

	char c = static_cast<char>(value);

	if (!std::isprint(c))
	{
		std::cout << "Non displayable\n";
		return;
	}

	std::cout << "'" << c << "'\n";
}

static void printInt(double value)
{
	std::cout << "int: ";

	if (value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min()
		|| value != value)
	{
		std::cout << "impossible\n";
		return;
	}

	std::cout << static_cast<int>(value) << "\n";
}

static void printFloat(double value)
{
	std::cout << "float: ";

	float f = static_cast<float>(value);

	if (f == static_cast<int>(f))
		std::cout << std::fixed << std::setprecision(1);

	std::cout << f << "f\n";
}

static void printDouble(double value)
{
	std::cout << "double: ";

	if (value == static_cast<int>(value))
		std::cout << std::fixed << std::setprecision(1);

	std::cout << value << "\n";
}

void ScalarConverter::convert(std::string& input)
{
	double	value;
	char*	end;

	// char
	if (input.length() == 1
		&& !std::isdigit(input[0]))
	{
		value = static_cast<double>(input[0]);
	}
	// pseudo literals
	else if (isPseudoLiteral(input))
	{
		if (input == "nanf" || input == "nan")
			value = std::numeric_limits<double>::quiet_NaN();
		else if (input == "+inf" || input == "+inff")
			value = std::numeric_limits<double>::infinity();
		else
			value = -std::numeric_limits<double>::infinity();
	}
	// float
	else if (input[input.length() - 1] == 'f')
	{
		value = std::strtod(input.c_str(), &end);

		if (*end != 'f' || *(end + 1) != '\0')
		{
			std::cout << "Error: invalid input\n";
			return;
		}
	}
	// int or double
	else
	{
		value = std::strtod(input.c_str(), &end);

		if (*end != '\0')
		{
			std::cout << "Error: invalid input\n";
			return;
		}
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

ScalarConverter::~ScalarConverter()
{}
