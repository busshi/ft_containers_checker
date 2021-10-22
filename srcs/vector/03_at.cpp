/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_at.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:27:35 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	testingAt( T vec ) {

	std::cout << "Testing vector.at()" << std::endl;

	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec.at(i) << std::endl;
	try {

		std::cout << vec.at(vec.size()) << std::endl;
	}
	catch (std::exception & e) {
		
		std::cout << "Exception catched at index [" << vec.size() << "]" << std::endl;
	}
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

	testingAt(vs);
	testingAt(vs2);
	testingAt(vs3);
	testingAt(vi);
	testingAt(vi2);
	testingAt(vi3);
	testingAt(vc);
	testingAt(vc2);
	testingAt(vc3);

	return 0;
}
