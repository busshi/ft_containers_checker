/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_push_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:28:41 by aldubar          ###   ########.fr       */
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

	std::cout << "Testing vector.push_back()" << std::endl;

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

	for (size_t i = 0; i < 20; i++) {

		if (i % 2) {
			vs.push_back("holà");
			vs2.push_back("holàlà");
			vs3.push_back("holà holà");
		}
		if (i % 2 == 0) {
			vs.push_back("good bye");
			vs.push_back("good bye good");
			vs.push_back("good bye bye");
		}
	}

	for (size_t i = 0; i < 20; i++) {

		if (i % 2) {
			vi.push_back(i);
			vi2.push_back(i);
			vi3.push_back(i);
		}
		if (i % 2 == 0) {
			vi.push_back(i * 2);
			vi2.push_back(i * 2);
			vi3.push_back(i * 2);
		}
	}

	for (size_t i = 0; i < 20; i++) {

		if (i % 2) {
			vc.push_back('@');
			vc2.push_back('%');
			vc3.push_back('=');
		}
		if (i % 2 == 0) {
			vc.push_back('!');
			vc2.push_back('?');
			vc3.push_back(';');
		}
	}

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
