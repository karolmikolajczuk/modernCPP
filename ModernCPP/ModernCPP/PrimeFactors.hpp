#pragma once

#include <vector>
#include <iostream>
#include <iterator>

namespace modernCPP {

	void printPrimeFactors(unsigned long long number) {

		unsigned long long temp_numb = number;
		std::vector<short> divisors;
		size_t divisor = 2;

		while (temp_numb > 1) {
			if (temp_numb % divisor)
				++divisor;
			else {
				divisors.push_back(divisor);
				temp_numb /= divisor;
			}
		}
		
		std::copy(divisors.begin(), divisors.end(),
			std::ostream_iterator<unsigned long long>(std::cout, " "));
	}
}
