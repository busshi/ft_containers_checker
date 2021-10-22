/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 23:14:57 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	testingSize( T vec ) {

	std::cout << "Testing size, capacity, max_size\nsize: " << vec.size() << std::endl;
	std::cout << "max_size: " << vec.max_size() << std::endl;
	std::cout << "capacity: " << (vec.capacity() >= vec.size() ? "[ OK ]" : "[ KO ]") << std::endl;
	std::cout << std::boolalpha << "is empty ? " << vec.empty() << std::endl;
}

int		main( void ) {

	vector<std::string>	vs;
	vector<std::string>	vs2(142);
	vector<std::string>	vs3(421, "hello holà");
	vector<int>			vi;
	vector<int>			vi2(142);
	vector<int>			vi3(421, 42);
//	vector<char>		vc;
//	vector<char>		vc2(142);
//	vector<char>		vc3(421, '*');

	testingSize(vs);
	testingSize(vs2);
	testingSize(vs3);
	testingSize(vi);
	testingSize(vi2);
	testingSize(vi3);
//	testingSize(vc);
//	testingSize(vc2);
//	testingSize(vc3);

	return 0;
}
