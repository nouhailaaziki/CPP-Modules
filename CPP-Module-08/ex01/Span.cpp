#include "Span.hpp"

Span::Span() : _N(0)
{}

Span::Span(unsigned int N) : _N(N)
{}

Span::Span(const Span& other) : _span(other._span), _N(other._N)
{}

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
        throw std::runtime_error("Span is full!");

    _span.push_back(num);
}

unsigned int Span::shortestSpan() const
{
    if (_span.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span!");

    std::vector<int> copy(_span);
    std::sort(copy.begin(), copy.end());

    long long shortest = static_cast<long long>(copy[1]) - copy[0];

    for (size_t i = 2; i < copy.size(); i++)
    {
        long long diff = static_cast<long long>(copy[i]) - copy[i - 1];
        if (diff < shortest)
            shortest = diff;
    }

    return (static_cast<unsigned int>(shortest));
}

unsigned int Span::longestSpan() const
{
    if (_span.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span!");

    std::vector<int>::const_iterator minIt = std::min_element(_span.begin(), _span.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_span.begin(), _span.end());

    long long max = *maxIt;
    long long min = *minIt;

    return (static_cast<unsigned int>(max - min));
}