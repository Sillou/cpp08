/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:31 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:32 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <iterator>
#include <algorithm>



class Span
{
private:
	unsigned int _maxSize;
	std::vector<int> _numbers;

public:
	Span(Span const &src);
	Span( void );
	Span(unsigned int n);
	Span &operator=(Span const &src);
	~Span();

	void	addNumber(int n);
	void	addRange(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
	long	shortestSpan( void ) const;
	long	longestSpan( void ) const;


};



#endif
