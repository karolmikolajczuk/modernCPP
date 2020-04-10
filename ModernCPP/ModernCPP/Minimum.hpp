#pragma once

#include <vector>
#include <stdexcept>

namespace NumericOperations {

	// just compare
	template<typename T>
	T minimum(T min) { return min; }

	template<typename T, typename... Args>
	T minimum(T number1, T number2, Args... numbers) {
		if (!std::is_arithmetic<T>::value)
			throw std::invalid_argument("Wrong argument type");

		return minimum(((number1 < number2) ? number1 : number2), numbers...);
	}

	// compare with own function
	template<class CompareF, typename T, typename... Args>
	T minimum_comp(CompareF comp, T num1, Args... nums) {
		return minimum_comp(comp, a, minimum_comp(comp, nums...));
	}

	template<class CompareF, typename T>
	T minimum_comp(CompareF comp, T num1, T num2) {
		return comp(num1, num2) ? num1 : num2;
	}
}
