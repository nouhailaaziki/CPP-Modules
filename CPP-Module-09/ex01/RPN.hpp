#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <cerrno>
# include <sstream>
# include <cstdlib>
# include <climits>
# include <iostream>
# include <stdexcept>

class RPN {
	private:
		std::stack<int>	stack;

	public:
		RPN();
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void evaluate(const std::string &expression);

	private:
		void processToken(const std::string &token);

		bool isOperator(const std::string &token) const;
		bool isNumber(const std::string &token) const;

		void performOperation(char op);

		int calculate(int left, int right, char op) const;
};

#endif