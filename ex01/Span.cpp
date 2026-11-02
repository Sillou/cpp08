#include "Span.hpp"



Span::Span( void ) : _maxSize(0)
{
}

Span::~Span()
{
}

Span::Span(Span const &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{

}

Span::Span(unsigned int n) : _maxSize(n)
{

}

Span &Span::operator=(Span const &src)
{
	if (this != &src)
	{
		_maxSize = src._maxSize;
		_numbers = src._numbers;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _maxSize)
		throw std::length_error("Span is full");
	else
		_numbers.push_back(n);
}

void Span::addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	if (_numbers.size() + std::distance(begin, end) > _maxSize)
		throw std::length_error("Span is full");
	_numbers.insert(_numbers.end(), begin, end);
}

long	Span::shortestSpan( void ) const
{
	if (_numbers.size() < 2)
		throw std::logic_error("not enough numbers");
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	long minSpan = (long)sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); i++)
	{
		long span = (long)sorted[i] - sorted[i - 1];
		if (span < minSpan)
			minSpan = span;
	}
	return (minSpan);
}

long	Span::longestSpan( void ) const
{
	if (_numbers.size() < 2)
		throw std::logic_error("not enough numbers");
	long max = *std::max_element(_numbers.begin(), _numbers.end());
	long min = *std::min_element(_numbers.begin(), _numbers.end());
	return (max - min);
}
