#include "AssumeNumbersDivideBy3Or5.h"

#include <algorithm>
#include <type_traits>
#include <iostream>


template <typename LIMITS, typename RESULT>
RESULT assumeNumbers(LIMITS min, LIMITS max) {
	RESULT result = 0;

	// check if min and max are numeric
	if (!std::is_arithmetic<LIMITS>::value)
		return -1;

	// compute sum of numbers that 
	// divides by 3 and 5
	for (;min <= max; ++min) {
		std::cout << min << " " << max << " " << result << '\n';
		if (min % 3 == 0 || min % 5 == 0) { result += min; }
		std::cout << result << std::endl;
	}

	return result;
}
namespace modern_cpp {

	ull assume_numbers_that_divides_by_3_or_5(ull max_limit) {
		return assumeNumbers<unsigned int, unsigned long long > (3, max_limit);
	}

}
