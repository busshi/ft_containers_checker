/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_pop_back.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:42:12 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	display( T vec ) {

	typename T::iterator		it, ite = vec.end();

	std::cout << "Testing vector.pop_back()" << std::endl;

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

template< class T >
void	testingPopBack( T vec ) {

	display(vec);

	for (size_t i = 0; i < 10; i++)
		vec.pop_back();

	display(vec);
}

int		main( void ) {

	vector<std::string>	vs(42);
	vector<std::string>	vs2(42, "hello");
	vector<int>			vi(42);
	vector<int>			vi2(42, 42);
	vector<char>		vc(42);
	vector<char>		vc2(42, '*');

	testingPopBack(vs);
	testingPopBack(vs2);
	testingPopBack(vi);
	testingPopBack(vi2);
	testingPopBack(vc);
	testingPopBack(vc2);

	return 0;
}
