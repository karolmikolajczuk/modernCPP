#pragma once

#include <sstream>
#include <string>

namespace CapitalLetter {

	// when many one worded strings
	std::string setCapitalLetters() { 
		return "";
	}

	// when many one worded strings
	template <typename TEXT, typename... Args>
	std::string setCapitalLetters(TEXT text, Args... args) {
		std::ostringstream oss_temp;
		oss_temp << (char)std::toupper(static_cast<std::string>(text).at(0)) <<
			static_cast<std::string>(text).substr(1) << " ";
	
		return oss_temp.str() + setCapitalLetters(args...);
	}

	// when one string with many words
	std::string setCapitalLettersInString(std::string text) {
		
		for (auto index = std::begin(text); index != std::end(text); ++index) {
			if (index != std::begin(text)) {
				if (std::isspace(*(index - 1))) *index = std::toupper(*index);
			}
			else {
				if (!std::isspace(*index)) *index = std::toupper(*index);
			}
		}

		return text;
	}
}

