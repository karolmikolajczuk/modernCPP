#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <sstream>
#include <iostream>
#include <ostream>
#include <iomanip>
#include <algorithm>


class Conversion {

public:
	
	template <typename Iterator>
	static std::string toHex(Iterator begin, Iterator end)	{

		std::ostringstream temp;
		
		for (; begin != end; ++begin)
			temp << std::hex << std::setw(2) << std::setfill('0') <<
				static_cast<int>(*begin);

		return temp.str();
	}

	static std::vector<unsigned char> toBytes(std::string_view data) {

		std::vector<unsigned char> temp;

		for (size_t index = 0; index < data.size(); index+=2) {
			temp.push_back(
			(uchar_conversion_into_hex(data.at(index)) << 4) | uchar_conversion_into_hex(data.at(index+1))
			);
		}

		return temp;
	}

private:

	static unsigned char uchar_conversion_into_hex(const unsigned char data) {
		std::cout << __FUNCTION__ << " " << data << '\n';

		// int conversion
		if (data >= '0' && data <= '9') return data - '0';		// convert for digit
		if (data >= 'A' && data <= 'F') return data - 'A' + 10; // convert for big letter
		if (data >= 'a' && data <= 'f') return data - 'a' + 10; // convert for small letter

		throw std::invalid_argument("Char is out of range. Didn't expect that: " + data);
	}

};
