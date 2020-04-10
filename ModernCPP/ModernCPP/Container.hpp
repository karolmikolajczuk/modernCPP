#pragma once

#include <vector>
#include <algorithm>
#include <list>

template<typename T>
class Container
{
	typedef T*			iterator;
	typedef T const*	const_iterator;

public:
	Container(size_t y, size_t x) {
		this->__container2D = new T[y][x];
	}

	Container(std::initializer_list<std::list<T>> l) {
		size_t size_of_sublists = l.size().size();
		size_t size_of_list = l.size();

		this->__container2D = new T[size_of_sublists][size_of_list];

		for (size_t y = 0; y < size_of_sublists; ++y) {
			for (size_t x = 0; x < size_of_list; ++x) {
				this->__container2D[y][x] = l.at(y).at(x);
			}
		}
	}

	Container(const Container& container) = default;
	Container& operator=(const Container& container) = default;

	Container(Container&& container) {
		this->__container2D = std::move(container.__container2D);
		container.~Container();
	}

	Container& operator=(const Container&& container) {
		this->__container2D = std::move(container.__container2D);
		container.~Container();
	}

	// return specific value
	constexpr T at(const size_t y, const size_t x) const {
		
		return this->__container2D[y][x];
	}

	constexpr T* atRow(const size_t y) const {
		return this->__container2D[y];
	}
	
	// size
	constexpr size_t cells() const {
		return this->__y * this->__x;

	}

	constexpr size_t bytes() const {
		return sizeof(T)* cells();
	}

	// settery
	constexpr void set(const T& data, const size_t y, const size_t x) {
		this->__container2D[y][x] = data;
	}

	constexpr void set(T&& data, size_t y, size_t x) {
		this->__container2D[y][x] = std::move(data);
	}

	// swap
	constexpr void swap(size_t y1, size_t x1, size_t y2, size_t x2) {
		std::swap(this->__container2D[y1][x1], 
			this->__container2D[y2][x2]);
	}

	constexpr void swap(const Container& container) {
		std::swap(this->__container2D, container.__container2D);
	}

	// fill
	constexpr void fill(const T& data) {
		std::fill(std::begin(this->__container2D), std::end(this->__container2D) data);
	}

	constexpr void fill(T&& data) {
		std::fill(std::begin(this->__container2D), std::end(this->__container2D), std::move(data));
	}

	// iterator
	iterator begin() { 
		return this->__container2D[0];
	}

	iterator end() {
		return this->__container2D[y][x] + 1;
	}

	const_iterator cbegin() const {
		return this->__container2D[0];
	}

	const_iterator cend() const {
		return this->__container2D[y][x] + 1;
	}

	~Container() {
		if (__container2D != nullptr) {
			this->__container2D = nullptr;
		}

		this->y = NULL;
		this->x = NULL;
	}

private:

	size_t y;
	size_t x;
	T** __container2D;
};

