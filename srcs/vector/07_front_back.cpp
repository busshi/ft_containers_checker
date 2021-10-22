/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_front_back.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:29:07 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	testingFrontBack( T vec ) {

	std::cout << "Testing vector.front() and vector.back()" << std::endl;

	std::cout << vec.front() << std::endl;
	std::cout << vec.back() << std::endl;
}

int		main( void ) {

	vector<std::string>	vs(42, "hello");
	vector<int>			vi(42, 42);
	vector<char>		vc(42, '*');

	testingFrontBack(vs);
	testingFrontBack(vi);
	testingFrontBack(vi);

	for (size_t i = 0; i < 20; i++) {

		if (i % 2)
			testingFrontBack(vs);
		vs.push_back("holà");
		if (i % 2 == 0)
			testingFrontBack(vs);
		vs.push_back("good bye");
	}

	for (size_t i = 0; i < 20; i++) {

		if (i % 2)
			testingFrontBack(vi);
		vi.push_back(i);
		if (i % 2 == 0)
			testingFrontBack(vi);
		vi.push_back(i * 2);
	}

	for (size_t i = 0; i < 20; i++) {

		if (i % 2)
			testingFrontBack(vc);
		vc.push_back('@');
		if (i % 2 == 0)
			testingFrontBack(vc);
		vc.push_back('!');
	}

	return 0;
}
