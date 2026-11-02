/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:22 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:23 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main( void )
{
	std::vector<int> vec;
	for(int i = 0; i < 5; i++)
		vec.push_back(i);

	std::cout << *easyfind(vec,3) << std::endl;
	try
	{
		std::cout << *easyfind(vec, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::list<int> lst;
	for (int i = 0; i < 5; i++)
		lst.push_back(i * 10);
	try
	{
		std::cout << *easyfind(lst, 40) << std::endl;
		std::cout << *easyfind(lst, 42) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}


	return (0);
}
