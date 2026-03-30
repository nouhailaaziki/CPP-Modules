#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <deque>
# include <vector>
# include <string>
# include <cerrno>
# include <cctype>
# include <iomanip>
# include <cstdlib>
# include <climits>
# include <iostream>
# include <algorithm>
# include <stdexcept>
# include <sys/time.h>

class PmergeMe
{
	private:
		std::vector<int>	_original;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_vecTimeUs;
		double				_deqTimeUs;

		std::vector<int>	mergeInsertionSortVector(std::vector<int> arr) const;
		std::deque<int>		mergeInsertionSortDeque(std::deque<int> arr) const;

		static size_t	binarySearchPosVector(const std::vector<int>& chain, int value);
		static size_t	binarySearchPosDeque(const std::deque<int>& chain, int value);

		static std::vector<size_t>	jacobsthalOrder(size_t k);

		static bool	parseOnePositiveInt(const std::string& s, int& out);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);
		~PmergeMe();

		void	parseArguments(int argc, char** argv);

		void	process();

		void	printBefore() const;
		void	printAfter() const;
		void	printTimings() const;

		void	sortVector(std::vector<int>& vec);
		void	sortDeque(std::deque<int>& deq);
};

#endif