/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alubrano <alubrano@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 16:28:18 by alubrano          #+#    #+#             */
/*   Updated: 2026/11/02 16:28:19 by alubrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("value not found");
	return (it);
}

template <typename T>
typename T::const_iterator easyfind(T const &container, int value)
{
	typename T::const_iterator it;
	it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw std::runtime_error("value not found");
	return (it);
}
