#pragma once

#include <map>
#include <type_traits>

class ModernCPPGCD {

	typedef unsigned long long ull;

	// key: number, value: how many times exists/divides
	std::map<ull, unsigned int> dividers;

	ull guard_checker;

public:

	ModernCPPGCD() : guard_checker{ 0 } {

	}


	/**

		When no arguments to unpack.
		Just skip this.
		Nothing to work with.

	*/

	void computeHighestCommonDivider() {
		
	}

	/**

		Unpacking arguments and computing
		most common

	*/

	template <typename Number, typename... Numbers>
	ull computeHighestCommonDivider(Number one, Numbers... rest) {
		if (!std::is_arithmetic<Number>::value) return -1;

		++guard_checker;
		
		for (ull divider = 2; divider <= one; ++divider) {
			if (!(one % divider)) {
				if (dividers.find(divider) != dividers.end()) {
					dividers[divider] = dividers.at(divider) + 1;
				}
				else {
					dividers[divider] = 1;
				}
			}
		}

		computeHighestCommonDivider(rest...);

		ull highest_common_divider = 1;
		for (const auto& pair : dividers) {
			if (pair.first > highest_common_divider&&
				pair.second == guard_checker)
				highest_common_divider = pair.first;
		}

		return highest_common_divider;
	}
};
