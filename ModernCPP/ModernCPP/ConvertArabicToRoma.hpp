#pragma once

#include <list>
#include <string>
#include <stdexcept>
#include <string_view>

namespace modernCPP {

	// list of connected arabic numerics to romanian ones
	static std::list<std::pair<unsigned int, std::string>> counterparts = {
		{1, "I"}, {4, "IV"}, {5, "V"}, {9, "IX"}, { 10, "X" }, 
		{40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, 
		{400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}
	};

	/**
		Function converts given arabic string and 
	*/
	std::string convertArabicToRoma(unsigned int arabic) {

		if (!std::is_arithmetic<decltype(arabic)>::value)
			throw std::invalid_argument("Should be a numeric");
		if (arabic < 1)
			throw std::invalid_argument("Year shouldn't be lower than 1");
		if (typeid(arabic) != typeid(unsigned int))
			throw std::out_of_range("If it's arithmetic and bigger than 0, then it's out of range");


		std::reverse(counterparts.begin(), counterparts.end());
		std::string result{ };

		for (const auto& ar_ro_pair : counterparts) {
			while (arabic >= ar_ro_pair.first) {
				result.append(ar_ro_pair.second);
				arabic -= ar_ro_pair.first;
			}
		}
		
		return result;
	}
}
