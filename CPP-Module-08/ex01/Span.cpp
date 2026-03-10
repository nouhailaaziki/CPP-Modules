#include "Span.hpp"

Span::Span() : _N(0)
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other)
{
    *this = other;
}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        _span = other._span;
        _N = other._N;
    }
    return (*this);
}

Span::~Span()
{}

void Span::addNumber(int num)
{
    if (_span.size() >= _N)
        throw std::runtime_error("Span is full!!");

    _span.push_back(num);
}

int Span::shortestSpan() const
{
    if (_span.size() < 2)
        throw std::runtime_error("Not enough numbers!!");

    std::vector<int> copy = _span;

    std::sort(copy.begin(), copy.end());

    int shortest = copy[1] - copy[0];

    for (size_t i = 1; i < copy.size() - 1; i++)
    {
        int diff = copy[i + 1] - copy[i];

        if (diff < shortest)
            shortest = diff;
    }

    return (shortest);
}

int Span::longestSpan() const
{
    if (_span.size() < 2)
        throw std::runtime_error("Not enough numbers!!");

    int min = *std::min_element(_span.begin(), _span.end());
    int max = *std::max_element(_span.begin(), _span.end());

    return (max - min);
}