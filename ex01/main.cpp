#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int	main( void )
{
	// 1. Subject example
	std::cout << "--- Subject test ---" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// 2. Exceptions
	std::cout << "--- Span full ---" << std::endl;
	try
	{
		sp.addNumber(42);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << "--- Not enough numbers ---" << std::endl;
	Span small(10);
	try
	{
		std::cout << small.shortestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	small.addNumber(1);
	try
	{
		std::cout << small.longestSpan() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	// 3. addRange too big
	std::cout << "--- addRange too big ---" << std::endl;
	std::vector<int> five(5, 0);
	Span tiny(3);
	try
	{
		tiny.addRange(five.begin(), five.end());
	}
	catch (const std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	// 4. 10 000 numbers with addRange
	std::cout << "--- 10000 numbers ---" << std::endl;
	std::srand(std::time(NULL));
	std::vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(std::rand());
	Span big(10000);
	big.addRange(v.begin(), v.end());
	std::cout << "shortest : " << big.shortestSpan() << std::endl;
	std::cout << "longest  : " << big.longestSpan() << std::endl;

	return (0);
}
