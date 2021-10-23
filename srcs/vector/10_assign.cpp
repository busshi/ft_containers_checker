/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_assign.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/23 03:19:31 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>
#include <unistd.h>

using CONTAINER::vector;

template< class T >
void	display( T vec ) {

	typename T::iterator		it, ite = vec.end();

	std::cout << "Testing vector.assign()" << std::endl;

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

template< class T, class Type >
void	testingAssign( T vec, Type content ) {

	display(vec);

	vec.assign(10, content);
	display(vec);

	T	copy = vec;
	copy.assign(vec.begin() + 1, vec.begin() + 5);
	display(copy);
}

int		main( void ) {

	alarm(3);

	vector<std::string>	vs;
	vector<std::string>	vs2(42);
	vector<std::string>	vs3(42, "hello");
	vector<int>			vi;
	vector<int>			vi2(42);
	vector<int>			vi3(42, 42);
	vector<char>		vc;
	vector<char>		vc2(42);
	vector<char>		vc3(42, '*');

	testingAssign(vs, "aaaaaaaaaaaaaaaa");
	testingAssign(vs2, "eeeeeeeeeeeeeeeeeeeeeeee");
	testingAssign(vs3, "pppppppppp");
	testingAssign(vi, 42);
	testingAssign(vi2, 43);
	testingAssign(vi3, 44);
	testingAssign(vc, '$');
	testingAssign(vc2, '&');
	testingAssign(vc3, '?');

	return 0;
}
