#pragma once

#include <iostream>
#include "LowerCommonPrimeNumber.hpp"

class ModernCPPPrimeSixths {
	typedef unsigned long long ULL;
public:
	static std::pair<ULL, ULL> isPrimeSixths(ULL limit) {
		ModernCPPLCPN temp;
		for (ULL index = 2; index < limit; ++index) {
			if (temp.isPrime(index) && temp.isPrime(index + 6))
				return std::make_pair(index, index + 6);
		}
		
		return std::make_pair(-1, -1);
	}
};
