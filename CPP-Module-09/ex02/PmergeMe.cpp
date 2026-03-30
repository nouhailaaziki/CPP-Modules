#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _vecTimeUs(0.0), _deqTimeUs(0.0)
{}

PmergeMe::PmergeMe(const PmergeMe& other)
	:	_original(other._original),
		_vec(other._vec),
		_deq(other._deq),
		_vecTimeUs(other._vecTimeUs),
		_deqTimeUs(other._deqTimeUs)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		_original = other._original;
		_vec = other._vec;
		_deq = other._deq;
		_vecTimeUs = other._vecTimeUs;
		_deqTimeUs = other._deqTimeUs;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::parseOnePositiveInt(const std::string& s, int& out)
{
	if (s.empty())
		return (false);

	size_t i = 0;
	if (s[0] == '+')
		i = 1;
	else if (s[0] == '-')
		return (false);

	if (i >= s.size())
		return (false);

	for (size_t j = i; j < s.size(); ++j)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[j])))
			return (false);
	}

	errno = 0;
	char* endptr = 0;
	long val = std::strtol(s.c_str(), &endptr, 10);

	if (errno == ERANGE || val > static_cast<long>(INT_MAX) || val < static_cast<long>(INT_MIN))
		return (false);
	if (*endptr != '\0')
		return (false);
	if (val <= 0)
		return (false);

	out = static_cast<int>(val);
	return (true);
}

void PmergeMe::parseArguments(int argc, char** argv)
{
	if (argc < 2)
		throw std::invalid_argument("no arguments provided");

	_original.clear();
	for (int i = 1; i < argc; ++i)
	{
		int value = 0;
		if (!parseOnePositiveInt(std::string(argv[i]), value))
			throw std::invalid_argument(std::string("invalid argument '") + argv[i] + "'");
		_original.push_back(value);
	}
}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t k)
{
	std::vector<size_t> order;
	if (k == 0)
		return (order);

	order.push_back(1);
	if (k == 1)
		return (order);

	std::vector<size_t> jac;
	jac.push_back(0);
	jac.push_back(1);
	jac.push_back(1);
	while (jac.back() < k)
	{
		size_t n = jac.size();
		size_t next = jac[n - 1] + 2 * jac[n - 2];
		jac.push_back(next);
	}

	std::vector<bool> added(k + 1, false);
	added[1] = true;

	for (size_t t = 3; t < jac.size(); ++t)
	{
		size_t hi = jac[t];
		if (hi > k)
			hi = k;
		size_t lo = jac[t - 1] + 1;
		if (lo > hi)
			continue;
		for (size_t idx = hi; ; --idx)
		{
			if (!added[idx])
			{
				order.push_back(idx);
				added[idx] = true;
			}
			if (idx == lo)
				break;
		}
	}

	for (size_t idx = 1; idx <= k; ++idx)
	{
		if (!added[idx])
			order.push_back(idx);
	}
	return (order);
}

size_t PmergeMe::binarySearchPosVector(const std::vector<int>& chain, int value)
{
	size_t lo = 0;
	size_t hi = chain.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (chain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}

size_t PmergeMe::binarySearchPosDeque(const std::deque<int>& chain, int value)
{
	size_t lo = 0;
	size_t hi = chain.size();
	while (lo < hi)
	{
		size_t mid = lo + (hi - lo) / 2;
		if (chain[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}

std::vector<int> PmergeMe::mergeInsertionSortVector(std::vector<int> arr) const
{
	size_t n = arr.size();
	if (n < 2)
		return (arr);

	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = arr[n - 1];
		arr.pop_back();
	}

	size_t pairCount = arr.size() / 2;
	std::vector<int> winners(pairCount);
	std::vector<int> losers(pairCount);
	for (size_t i = 0; i < pairCount; ++i)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		winners[i] = a;
		losers[i] = b;
	}

	std::vector<int> chain = mergeInsertionSortVector(winners);

	std::vector<size_t> order = jacobsthalOrder(pairCount);
	for (size_t k = 0; k < order.size(); ++k)
	{
		int value = losers[order[k] - 1];
		size_t pos = binarySearchPosVector(chain, value);
		chain.insert(chain.begin() + pos, value);
	}

	if (hasStraggler)
	{
		size_t pos = binarySearchPosVector(chain, straggler);
		chain.insert(chain.begin() + pos, straggler);
	}

	return (chain);
}

void PmergeMe::sortVector(std::vector<int>& vec)
{
	vec = mergeInsertionSortVector(vec);
}

std::deque<int> PmergeMe::mergeInsertionSortDeque(std::deque<int> arr) const
{
	size_t n = arr.size();
	if (n < 2)
		return (arr);

	bool hasStraggler = (n % 2 == 1);
	int straggler = 0;
	if (hasStraggler)
	{
		straggler = arr[n - 1];
		arr.pop_back();
	}

	size_t pairCount = arr.size() / 2;
	std::deque<int> winners(pairCount);
	std::deque<int> losers(pairCount);
	for (size_t i = 0; i < pairCount; ++i)
	{
		int a = arr[2 * i];
		int b = arr[2 * i + 1];
		if (a < b)
			std::swap(a, b);
		winners[i] = a;
		losers[i] = b;
	}

	std::deque<int> chain = mergeInsertionSortDeque(winners);

	std::vector<size_t> order = jacobsthalOrder(pairCount);
	for (size_t k = 0; k < order.size(); ++k)
	{
		int value = losers[order[k] - 1];
		size_t pos = binarySearchPosDeque(chain, value);
		chain.insert(chain.begin() + pos, value);
	}

	if (hasStraggler)
	{
		size_t pos = binarySearchPosDeque(chain, straggler);
		chain.insert(chain.begin() + pos, straggler);
	}

	return (chain);
}

void PmergeMe::sortDeque(std::deque<int>& deq)
{
	deq = mergeInsertionSortDeque(deq);
}

void PmergeMe::process()
{
	_vec.assign(_original.begin(), _original.end());
	_deq.assign(_original.begin(), _original.end());

	struct timeval start;
	struct timeval end;

	gettimeofday(&start, NULL);
	sortVector(_vec);
	gettimeofday(&end, NULL);
	_vecTimeUs = (end.tv_sec - start.tv_sec) * 1000000.0
		+ (end.tv_usec - start.tv_usec);

	gettimeofday(&start, NULL);
	sortDeque(_deq);
	gettimeofday(&end, NULL);
	_deqTimeUs = (end.tv_sec - start.tv_sec) * 1000000.0
		+ (end.tv_usec - start.tv_usec);
}

void PmergeMe::printBefore() const
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _original.size(); ++i)
	{
		std::cout << _original[i];
		if (i + 1 < _original.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printAfter() const
{
	std::cout << "After: ";
	for (size_t i = 0; i < _vec.size(); ++i)
	{
		std::cout << _vec[i];
		if (i + 1 < _vec.size())
			std::cout << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printTimings() const
{
	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _original.size()
		<< " elements with std::vector : " << _vecTimeUs << " us" << std::endl;
	std::cout << "Time to process a range of " << _original.size()
		<< " elements with std::deque : " << _deqTimeUs << " us" << std::endl;
}