#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(const RPN& other) : stack(other.stack)
{}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
		stack = other.stack;
	return (*this);
}

RPN::~RPN()
{}

void RPN::evaluate(const std::string &expression)
{
	while (!stack.empty())
		stack.pop();

	std::stringstream stream(expression);
	std::string token;

	while (stream >> token)
		processToken(token);

	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression.");

	std::cout << stack.top() << std::endl;
}

void RPN::processToken(const std::string &token)
{
	if (isNumber(token))
	{
		std::stringstream stream(token);
		int value = 0;
		if (!(stream >> value))
			throw std::runtime_error("Invalid number.");
		stack.push(value);
	}
	else if (isOperator(token))
		performOperation(token[0]);
	else
		throw std::runtime_error("Invalid token: '" + token + "'.");
}

bool RPN::isOperator(const std::string &token) const
{
	return (token.length() == 1
			&& token.find_first_not_of("+-*/") == std::string::npos);
}

bool RPN::isNumber(const std::string &token) const
{
	char *end;
	errno = 0;
	long value = std::strtol(token.c_str(), &end, 10);
	return (errno == 0
			&& *end == '\0'
			&& value >= INT_MIN
			&& value <= 9);
}

void RPN::performOperation(char op)
{
	if (stack.size() < 2)
		throw std::runtime_error("Invalid expression: operator requires two operands.");
	int right = stack.top();
	stack.pop();
	int left = stack.top();
	stack.pop();
	int result = calculate(left, right, op);
	stack.push(result);
}

int RPN::calculate(int left, int right, char op) const
{
	long long result;

	switch (op)
	{
		case '*':
			result = static_cast<long long>(left) * right;
			break;

		case '/':
			if (right == 0)
				throw std::runtime_error("Division by zero.");
			if (left == INT_MIN && right == -1)
				throw std::runtime_error("Result overflow.");
			result = left / right;
			break;

		case '+':
			result = static_cast<long long>(left) + right;
			break;

		case '-':
			result = static_cast<long long>(left)- right;
			break;

		default:
			throw std::runtime_error("Unknown operator.");
	}
	if (result > INT_MAX || result < INT_MIN)
		throw std::runtime_error("Result overflow.");
	return (static_cast<int>(result));
}