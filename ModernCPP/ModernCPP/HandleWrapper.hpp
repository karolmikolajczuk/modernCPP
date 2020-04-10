#pragma once

#include <Windows.h>

template <typename Traits>
class HandleWrapper {

public:

	explicit HandleWrapper(pointer value = Traits::invalid()) noexcept : __value{ value } {
	}

	HandleWrapper(const HandleWrapper&) = delete;
	HandleWrapper& operator=(const HandleWrapper&) = delete;

	HandleWrapper(HandleWrapper&& handler) noexcept : __value{ handler.release } { }

	HandleWrapper& operator=(HandleWrapper&& handler) noexcept {
		if (this != &handler) reset(handler.release());
		return *this;
	}

	~HandleWrapper() noexcept {
		Traits::close(__value);
	}

	explicit bool operator() const noexcept {
		return this->__value != Traits::invalid();
	}

	pointer get() const noexcept {
		return this->__value;
	}

	pointer release() noexcept {
		auto value = this->__value;
		this->__value = Traits::invalid();
		return value;
	}

	bool reset(pointer value = Traits::invalid()) noexcept {
		if (this->__value != value) {
			Traits::close(this->__value);
			this->__value = value;
		}
		return static_cast<bool>(*this);
	}

	void swap(HandleWrapper<Traits>& handler) noexcept {
		std::swap(this->__value, handler.__value);
	}

private:

	using pointer = typename Traits::pointer;
	pointer __value;

};

template <typename Traits>
void swap(HandleWrapper<Traits>& l, HandleWrapper<Traits>& r) noexcept {
	l.swap(r);
}

template <typename Traits>
bool operator==(const HandleWrapper<Traits>& l, const HandleWrapper<Traits>& r) noexcept {
	return l.get() == r.get();
}

template <typename Traits>
bool operator!=(const HandleWrapper<Traits>& l, const HandleWrapper<Traits>& r) noexcept {
	return l.get() != r.get();
}

struct NULL_Handle_TRAITS {
	using pointer = HANDLE;
	static pointer invalid() noexcept { return nullptr; }
	static void close(pointer value) noexcept { CloseHandle(value); }
};

struct INVALID_Handle_TRAITS {
	using pointer = HANDLE;
	static pointer invalid() noexcept { return INVALID_HANDLE_VALUE; }
	static void close(pointer value) noexcept { CloseHandle(value); }
};

using NULL_HANDLE = HandleWrapper<NULL_Handle_TRAITS>;
using INVALID_HANDLE = HandleWrapper<INVALID_Handle_TRAITS>;
