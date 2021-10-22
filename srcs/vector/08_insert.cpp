/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_insert.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:29:27 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;


template< class T >
void	displayContainer( T vec ) {

	typename T::iterator	it;
	typename T::iterator	ite = vec.end();

	std::cout << "Testing vector.insert()" << std::endl;

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

int		main( void ) {

	vector<std::string>	vs;
	vector<int>			vi;
	vector<char>		vc;
	vector<std::string>	vs2(42);
	vector<int>			vi2(42);
	vector<char>		vc2(42);
	vector<std::string>	vs3(42, "hello");
	vector<int>			vi3(42, 42);
	vector<char>		vc3(42, '*');

	vs.insert(vs.begin(), "holà");
	vs2.insert(vs2.begin() + 1, 10, "holàlà");
	vs3.insert(vs3.begin() + 2, 41, "holà holà");
	
	for (size_t i = 0; i < 5; i++) {

		vi.insert(vi.begin(), i);
		vi2.insert(vi2.begin() + 1, 10, i * 2);
		vi3.insert(vi3.begin() + 2, 41, i * 3);
	}

	vc.insert(vc.begin(), '@');
	vc2.insert(vc2.begin() + 1, 10, '%');
	vc3.insert(vc3.begin() + 2, 41, '=');

	displayContainer(vs);
	displayContainer(vs2);
	displayContainer(vs3);
	displayContainer(vi);
	displayContainer(vi2);
	displayContainer(vi3);
	displayContainer(vc);
	displayContainer(vc2);
	displayContainer(vc3);

	return 0;
}
