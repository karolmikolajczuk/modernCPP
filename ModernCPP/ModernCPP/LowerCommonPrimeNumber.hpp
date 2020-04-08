#pragma once

class ModernCPPLCPN {
	
public:

	bool isPrimeHigherThan9(unsigned long long number) {
		short last_digit = number % 10;

		switch (last_digit) {
		case 0:
		case 2:
		case 4:
		case 5:
		case 6:
		case 8:
			return false;
		}

		return this->isPrime(number);
	}

	bool isPrime(unsigned long long number) {
		for (size_t divisor = 2; divisor <= number / 2; ++divisor) {
			if (!(number % divisor))
				return false;
		}
		
		return true;
	}

	ModernCPPLCPN() { }

	unsigned long long lowerCommonPrimeNumber(unsigned long long number) {

		while (--number > 1) {
			if (number > 9) {
				if (this->isPrimeHigherThan9(number)) {
					return number;
				}
			}
			else {
				if (this->isPrime(number)) {
					return number;
				}
			}
		}

		return -1;
	}
};
