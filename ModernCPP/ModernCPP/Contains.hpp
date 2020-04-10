#pragma once

#include <algorithm>


class Contains {
public:
	template <class Container, typename... Args>
	constexpr static bool any(const Container& c, Args&&... numbers) {
		return false;
	}

	template <class Container, typename T, typename... Args>
	constexpr static bool any(const Container& c, T&& number, Args&&... numbers) {
		//return std::find(std::begin(c), std::end(c), numer) != std::end(c); 
		for (const auto& element : c) if (number == element) return true;

		return any(c, numbers...);
	}

	template <class Container, typename... Args>
	constexpr static bool all(const Container& c, Args&&... numbers) {
		return true;
	}

	template <class Container, typename T, typename... Args>
	constexpr static bool all(const Container& c, T&& number, Args&&... numbers) {
		for (const auto& element : c) if (number == element) return all(c, numbers...);

		return false;
	}

	template <class Container, typename... Args>
	constexpr static bool none(const Container& c, Args&&... numbers) {
		return true;
	}

	template <class Container, typename T, typename... Args>
	constexpr static bool none(const Container& c, T&& number, Args&&... numbers) {
		for (const auto& element : c) if (element == number) return false;

		return none(c, numbers...);
	}

};
