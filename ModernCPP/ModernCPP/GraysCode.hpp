#pragma once

#include <string>
#include <bitset>
#include <iostream>

#define DEBUG(number) std::cout << __FUNCTION__ << number << '\n';

namespace modernCPP {


	// gray encode code basing on unsigned int's
	unsigned int gray_encode(const unsigned int number) {
		DEBUG(number);
		// number xor (number bitshift right 1place)
		return number ^ (number >> 1);
	}

	// gray decode code basing on unsigned int's
	unsigned int gray_decode(unsigned int number) {
		DEBUG(number);
		for (unsigned int index = 1U; index > 1; index >>= 1) {
			if (number & index) number ^= (index >> 1);
		}
		return number;
	}

	std::string to_binary(unsigned int number, unsigned int digits) {
		return std::bitset<32>(number).to_string().substr(32-digits-1);
	}

	void print(unsigned int const limit) {
		std::cout << "Liczba\tBinarnie\tGrayCode\tDecoded\n";
		for (unsigned int index = 1; index <= limit; ++index) {
			std::cout << index << '\t' << to_binary(index, 5) <<
				'\t' << gray_encode(index) << '\t' << 
				gray_decode(gray_encode(index)) << '\n';
		}
	}
}
