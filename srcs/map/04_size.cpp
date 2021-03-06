/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldubar <aldubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 16:44:16 by aldubar           #+#    #+#             */
/*   Updated: 2021/10/31 12:39:15 by aldubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cont.hpp"

template< class T, class A >
void	run( T map, A array, int size, std::string keyType, std::string valueType ) {

	checkSize(map, keyType, valueType);

	std::cout << "Insert pairs key/value..." << std::endl << std::endl;

	ft::pair<typename T::iterator, bool> ret;
	
	for (int i = 0; i < size; i++) {

		ret = map.insert(ft::make_pair(i, array[i]));
		std::cout << "Pair key [" << ret.first->first << "] value: [" << ret.first->second << "]";
		std::cout << (ret.second ? " has been inserted" : " failed to be inserted") << std::endl;
	}

	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "-------------------------" << std::endl;
}

template< class T, class A >
void	run( T map, A key, A value, int size, std::string keyType, std::string valueType ) {

	checkSize(map, keyType, valueType);

	std::cout << "Insert pairs key/value..." << std::endl << std::endl;

	ft::pair<typename T::iterator, bool> ret;
	
	for (int i = 0; i < size; i++) {

		ret = map.insert(ft::make_pair(key[i], value[i]));
		std::cout << "Pair key [" << ret.first->first << "] value: [" << ret.first->second << "]";
		std::cout << (ret.second ? " has been inserted" : " failed to be inserted") << std::endl;
	}

	display(map, keyType, valueType);
	checkSize(map, keyType, valueType);

	std::cout << "-------------------------" << std::endl;
}

int		main( void ) {

	alarm(3);

	std::cout << "\033[33m[+] Testing capacity member functions...\033[0m" << std::endl << std::endl;

	std::string arrayS[] = {"z??ro", "un", "deux", "trois", "quatre", "cinq", "six", "sept", "huit", "neuf", "dix"};
	int			size = *(&arrayS + 1) - arrayS;

	ft::map<int, std::string>	map;
	run(map, arrayS, size, INT, STR);


	ft::map<std::string, std::string>	map2;
	run(map2, arrayS, arrayS, size, STR, STR);



	int	arrayI[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	size = *(&arrayI + 1) - arrayI;

	ft::map<int, int>	map3;
	run(map3, arrayI, size, INT, INT);

	
	int	arrayI2[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	ft::map<int, int>	map4;

	run(map4, arrayI2, arrayI2, size, INT, INT);


	return 0;
}
