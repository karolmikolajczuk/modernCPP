#pragma once

#include <sstream>
#include <string>

namespace CapitalLetter {

	std::string setCapitalLetters() { 
		return "";
	}

	template <typename TEXT, typename... Args>
	std::string setCapitalLetters(TEXT text, Args... args) {
		std::ostringstream oss_temp;
		oss_temp << (char)std::toupper(static_cast<std::string>(text).at(0)) <<
			static_cast<std::string>(text).substr(1) << " ";
	
		return oss_temp.str() + setCapitalLetters(args...);
	}
}

