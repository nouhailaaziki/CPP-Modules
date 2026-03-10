#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>

class Span
{
    private:
        std::vector<int>    _span;
        unsigned int        _N;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void    addNumber(int num);

        int     shortestSpan() const;
        int     longestSpan() const;
};

#endif