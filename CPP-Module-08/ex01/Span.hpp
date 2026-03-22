#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <stdexcept>
# include <iterator>
# include <cstddef>

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

        template <typename Iterator>
        void addRange(Iterator begin, Iterator end)
        {
            std::ptrdiff_t dist = std::distance(begin, end);

            if (dist > 0 && _span.size() + static_cast<size_t>(dist) > _N)
                throw std::runtime_error("Span capacity exceeded!");

            _span.insert(_span.end(), begin, end);
        }

        unsigned int     shortestSpan() const;
        unsigned int     longestSpan() const;
};

#endif