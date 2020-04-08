#pragma once
#include <list>
#include <numeric>
#include <stdexcept>
#include <algorithm>


namespace modernCPP {

	template <typename Number>
	std::list<unsigned long long> computeArmstrong(Number limit_min, Number limit_max) {
		if (!std::is_arithmetic<Number>::value)
			throw std::invalid_argument("Wrong type of args");
		if (limit_min > limit_max || limit_min < 1 || limit_max < 1)
			throw std::invalid_argument("Wrong arguments");
		
		std::list<unsigned long long> all_armstrongs;

		for (; limit_min <= limit_max; ++limit_min) {

			// it's ull because we are later powering it
			std::list<unsigned long long> digits;
			Number temporary_number = limit_min;

			while (temporary_number > 0) {
				digits.push_back(temporary_number % 10);
				temporary_number /= 10;
			}

			size_t power = digits.size();
			std::for_each(digits.begin(), digits.end(), [&](unsigned long long& a) { 
				unsigned long long a_t = a;
				
				for (size_t index = 1; index < power; ++index) {
					a *= a_t;
				}
			});

			Number sum_of_powers = std::accumulate(digits.begin(), digits.end(), 0);

			if (sum_of_powers == limit_min) all_armstrongs.push_back(limit_min);
		}

		return all_armstrongs;
	}

}
