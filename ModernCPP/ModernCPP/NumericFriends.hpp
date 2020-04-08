#pragma once

#include <iostream>
#include <vector>
#include <numeric>


namespace modernCPP {

	typedef unsigned long long ULL;
	typedef std::pair<ULL, ULL> ull_p;

	// first argument is the number that we take divisors from.
	// second argument is the number that we compare with sum of divisors.
	bool numericFriends(ULL one, ULL two) {
		std::vector<ULL> divisors;
		divisors.push_back(1);

		for (ULL index = 2; index <= one / 2; ++index) {
			if (one % index == 0) divisors.push_back(index);
		}

		ULL accu = std::accumulate(divisors.begin(), divisors.end(), 0);

		return accu == two;
	}
}
