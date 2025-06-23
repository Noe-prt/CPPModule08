#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>

class Span
{
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    
    template<typename Iterator>
    void addRange(Iterator begin, Iterator end);
    
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Span is already full";
        }
    };

    class NoSpanException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "No span can be found";
        }
    };
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end)
{
    while (begin != end)
    {
        addNumber(*begin);
        ++begin;
    }
}

#endif 