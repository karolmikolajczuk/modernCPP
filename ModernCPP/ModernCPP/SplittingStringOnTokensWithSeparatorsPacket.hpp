#pragma once

#include <vector>
#include <string>

namespace splitting {

	// Types
	template <typename T>
	using myString = std::basic_string<T, std::char_traits<T>, std::allocator<T>>;

	template <typename T>
	using myStream = std::basic_stringstream<T, std::char_traits<T>, std::allocator<T>>;

	// split functions, are basing on string data and delimter or delimiters.
	// takes whole string as first argument, and checks it if any of delimiter is kept in string, if so
	// then cut this part (without delimiter) and keep it in memory - vector.
	// do it till end of string
	// after that, return a vector with string splitted into small parts without delimiters.

	// return vector of strings
	// param1 text (string)
	// param2 delimiter (1, char)
	template <typename T>
	std::vector<myString<T>> split(myString<T> text, const T delimiter) {

		// string that contains whole string
		auto string = myStream<T>{ text };

		// packet of substrings 
		auto tokens = std::vector<myString<T>>{ };

		// temporary string for keeping substring
		auto token = myString<T>{};

		// read string into token till u find delimiter
		// repeat that
		while (std::getline(string, token, delimiter)) {
			// if token isnt empty, remember data
			if (!token.empty()) tokens.push_back(token);
		}

		// return packet
		return tokens;
	}

	// return vector of strings
	template <typename T>
	std::vector<myString<T>> split(myString<T> text, const myString<T> delimiters) {
		//
		auto tokens = std::vector<myString<T>>{};

		size_t pos, prev_pos = 0;

		while ((pos = text.find_first_of(delimiters, prev_pos)) != std::string::npos) {

			if (pos > prev_pos)
				tokens.push_back(text.substr(prev_pos, std::string::npos));
			prev_pos = pos + 1;
		}

		if (prev_pos < text.length())
			tokens.push_back(text.substr(prev_pos, std::string::npos));


		return tokens;
	}

}
