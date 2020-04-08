#pragma once

#include <vector>
#include <numeric>

namespace modernCPP {

	typedef unsigned long long ULL;

	ULL abundantNumber(ULL number) {
		std::vector<short> digits;
		digits.push_back(1);

		for (size_t divisor = 2; divisor <= number / 2; ++divisor) {
			if (!(number % divisor)) digits.push_back(divisor);
		}

		ULL accu_value = std::accumulate(digits.begin(), digits.end(), 0);

		return (accu_value > number) ? accu_value - number : 0;
	}
}
