#pragma once

#include <numeric>
#include <type_traits>
#include <stdexcept>
#include <vector>


class ModernCPP {
	typedef unsigned long long ull;

	std::vector<ull> numbers;

public:
	ModernCPP() { }
	
	void lowestcm() { }

	template <typename Number = ull, typename... Args>
	ull lowestcm(Number one, Args... rest) {
		if (!std::is_arithmetic<Number>::value)
			throw std::invalid_argument("Both numbers should be numeric");
		if (one < 0)
			throw std::invalid_argument("Numbers should be higher than 0");

		/*
			Unpack the whole thing
		*/

		// remember number
		this->numbers.push_back(one);
		
		// do the same for the rest of args.
		lowestcm(rest...);

		ull multiplied_all_numbers = 1;
		ull gcd_all_numbers = this->numbers.front();

		for (const auto& num : this->numbers) {
			multiplied_all_numbers *= num;
		}

		for (size_t index = 1; index < this->numbers.size(); ++index) {
			gcd_all_numbers = std::gcd(gcd_all_numbers, this->numbers[index]);
		}

		return multiplied_all_numbers / gcd_all_numbers;
	}


	template <typename Number, typename Number2>
	ull lowestcm_std(Number one, Number2 two) {
		if (!std::is_arithmetic<Number>::value || !std::is_arithmetic<Number2>::value)
			throw std::invalid_argument("Both numbers should be numeric");

		return std::lcm(one, two);
	}

};
