/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_resize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 23:14:24 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	display( T vec )  {

	typename T::iterator	it, ite = vec.end();

	for (it = vec.begin(); it != ite; it++)
		std::cout << *it << std::endl;
}

template< class T >
void	testingSize( T vec ) {

	std::cout << "\n\nTesting size, capacity, max_size\nsize: " << vec.size() << std::endl;
	std::cout << "max_size: " << vec.max_size() << std::endl;
	std::cout << "capacity: " << (vec.capacity() >= vec.size() ? "[ OK ]" : "[ KO ]") << std::endl;
	std::cout << std::boolalpha << "is empty ? " << vec.empty() << std::endl;
}

template< class T, class Type >
void	testingResize( T vec, Type content ) {

	size_t	size = vec.size();

	display(vec);
	testingSize(vec);

	vec.resize(size * 2, content);
	display(vec);
	testingSize(vec);

	vec.resize(0);
	testingSize(vec);

	vec.resize(10000);
	testingSize(vec);
}

int		main( void ) {

	vector<std::string>	vs;
	vector<std::string>	vs2(14);
	vector<std::string>	vs3(21, "hello holà");
	vector<int>			vi;
	vector<int>			vi2(14);
	vector<int>			vi3(21, 42);
//	vector<char>		vc;
//	vector<char>		vc2(14);
//	vector<char>		vc3(21, '*');

	testingResize(vs, "aaaaaaaaaaaaaaa");
	testingResize(vs2, "bbbbbbbbbbbbbbbbbbbbbbbbbb");
	testingResize(vs3, "ccccccccccc");
	testingResize(vi, 2);
	testingResize(vi2, 3);
	testingResize(vi3, 4);
//	testingResize(vc, 'r');
//	testingResize(vc2, 't');
//	testingResize(vc3, 'y');

	return 0;
}
