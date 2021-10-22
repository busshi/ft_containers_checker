/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_erase.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:29:44 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;


template< class T >
void	displayContainer( T vec ) {

	typename T::iterator	it, ite = vec.end();

	std::cout << "Testing vector.erase()" << std::endl;

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

template< class T>
void	testingErase( T vec ) {

	displayContainer(vec);
	
	for (size_t i = 0; i < 5; i++)
		vec.erase(vec.begin() + 1);
	displayContainer(vec);

	vec.erase(vec.begin() + 5, vec.begin() + 10);
	displayContainer(vec);

}

int		main( void ) {

	vector<std::string>	vs(42);
	vector<int>			vi(42);
	vector<char>		vc(42);
	vector<std::string>	vs2(42, "hello");
	vector<int>			vi2(42, 42);
	vector<char>		vc2(42, '*');

	vs.insert(vs.begin(), "holà");
	vs2.insert(vs2.begin() + 2, 41, "holà holà");
	
	for (size_t i = 0; i < 5; i++) {

		vi.insert(vi.begin(), i);
		vi2.insert(vi2.begin() + 2, 41, i * 3);
	}

	vc.insert(vc.begin(), '@');
	vc2.insert(vc2.begin() + 2, 41, '=');

	testingErase(vs);
	testingErase(vs2);
	testingErase(vi);
	testingErase(vi2);
	testingErase(vc);
	testingErase(vc2);

	return 0;
}
