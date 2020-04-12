#pragma once

#include <string>
#include <sstream>
#include <type_traits>
#include <algorithm>


namespace joining_str {

	namespace {
		std::string temp;
	}

	template<typename Iterator>
	std::string join(Iterator begin, Iterator end, char separator = ' ') {
		std::ostringstream oss;

		for (; begin != end; ++begin) { oss << *begin << separator; }

		return oss.str();
	}

}
