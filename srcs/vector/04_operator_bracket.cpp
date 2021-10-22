/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_operator_bracket.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/22 22:27:20 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <string>
#include <iostream>

using CONTAINER::vector;

template< class T >
void	testingOperatorBracket( T vec ) {

	size_t	size = vec.size();

	std::cout << "Testing vector.size()" << std::endl;

	for (size_t i = 0; i < size; i++)
		std::cout << vec[i] << std::endl;
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

	testingOperatorBracket(vs);
	testingOperatorBracket(vs2);
	testingOperatorBracket(vs3);
	testingOperatorBracket(vi);
	testingOperatorBracket(vi2);
	testingOperatorBracket(vi3);
	testingOperatorBracket(vc);
	testingOperatorBracket(vc2);
	testingOperatorBracket(vc3);

	return 0;
}
