#pragma once

#include <iostream>
#include <set>

namespace modernCPP {
	typedef unsigned long long ull;
	std::set<std::pair<ull, ull>> remembered;

	/*
		Longest collatz series
	*/
	void collatzSeries(ull number_given) {
		std::cout << "Computing " << number_given << "...\n";
		ull count_till_one = 0;
		ull number = number_given;
		while (number != 1 && number > 0) {
			std::cout << "\t>currently at: " << number << '\n';
			++count_till_one;
			if (!(number % 2)) number = number / 2;
			else number = 3 * number + 1;

			auto iter = std::find_if(remembered.begin(), remembered.end(),
				[&](std::pair<ull, ull> data) { return data.first == number;});
			if (iter != remembered.end()) {
				remembered.insert(
					std::make_pair(
						number_given, 
						count_till_one + (*iter).second));
			}
		}
	}

	void printCollatzTillMillion() {
		for (ull index = 2; index <= 1000000; ++index) {
			collatzSeries(index);
		}
		for (const auto& pair : remembered) {
			std::cout << "For " << pair.first << " it took " <<
				pair.second << " moves.\n";
		}
	}
}
