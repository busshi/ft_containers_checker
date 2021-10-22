/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_ctor.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:27:41 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	testingCtor( T vec ) {

	typename T::iterator		it, ite = vec.end();

	std::cout << "Testing constructors" << std::endl;

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

int		main( void ) {

	vector<std::string>	vs;
	vector<std::string>	vs2(42);
	vector<std::string>	vs3(42, "hello");
	vector<int>			vi;
	vector<int>			vi2(42);
	vector<int>			vi3(42, 42);
	vector<char>		vc;
	vector<char>		vc2(42);
	vector<char>		vc3(42, '*');

	testingCtor(vs);
	testingCtor(vs2);
	testingCtor(vs3);
	testingCtor(vi);
	testingCtor(vi2);
	testingCtor(vi3);
	testingCtor(vc);
	testingCtor(vc2);
	testingCtor(vc3);

	return 0;
}
