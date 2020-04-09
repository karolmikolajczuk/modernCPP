#pragma once

#include <numeric>
#include <string>

namespace modernCPP {

	typedef unsigned long long ull;

	bool validateISBN10(const std::string isbn) {

		if (isbn.length() != 10) 
			throw std::invalid_argument("Wrong arg");


		ull index = 10;

		ull result = std::accumulate(
			std::begin(isbn), std::end(isbn), 0,
			[&](const ull total, char digit) -> ull {
				std::cout << total << " " << digit << '\n';

				return total + ((digit - '0') * index--);
			});

		return !(result % 11);
	}

	bool validateISBN13(const std::string isbn) {
		if (isbn.length() != 13) 
			throw std::invalid_argument("Wrong args");

		size_t count = 1;
		const unsigned short odd = 1, even = 3;
		ull result = std::accumulate(
			std::begin(isbn), std::begin(isbn) + 12, 0,
			[&](const ull total, char digit) -> ull {
				return total + ((digit - '0') * ((count++ % 2) ? odd : even));
			}
		);

		return ((10 - (result % 10))%10) == (isbn.at(12)-'0');
	}
}
