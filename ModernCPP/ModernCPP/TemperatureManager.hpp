#pragma once

#include <iostream>

namespace temperature {

	enum class TEMPERATURE_TYPES {
		CELSIUS,
		FAHRENHEIT,
		KELVIN
	};

	using TEMPERATURE = long double;
	using TEMPERATURE_CAST = std::pair<TEMPERATURE_TYPES, TEMPERATURE>;

	template <TEMPERATURE_TYPES>
	class TemperatureManager;

	template <TEMPERATURE_TYPES type1, TEMPERATURE_TYPES type2>
	struct conversion_f {
		static TemperatureManager<type2>& conversion(TEMPERATURE temp) = delete;
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::CELSIUS, TEMPERATURE_TYPES::FAHRENHEIT> {
		static TEMPERATURE conversion(const TEMPERATURE temp) {
			return (temp * 9) / 5 + 32;
		}
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::CELSIUS, TEMPERATURE_TYPES::KELVIN> {
		static TEMPERATURE conversion(const TEMPERATURE temp) {
			return temp + 273.15;
		}
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::FAHRENHEIT, TEMPERATURE_TYPES::CELSIUS> {
		static TEMPERATURE conversion(const TEMPERATURE temp) {
			return (temp - 32) * 5 / 9;
		}
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::FAHRENHEIT, TEMPERATURE_TYPES::KELVIN> {
		static TEMPERATURE conversion(TEMPERATURE temp) {
			return ((temp * 9) / 5) - 459.67;
		}
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::KELVIN, TEMPERATURE_TYPES::CELSIUS> {
		static TEMPERATURE conversion(TEMPERATURE temp) {
			return temp - 273.15;
		}
	};

	template<>
	struct conversion_f<TEMPERATURE_TYPES::KELVIN, TEMPERATURE_TYPES::FAHRENHEIT> {
		static TEMPERATURE conversion(TEMPERATURE temp) {
			return (temp + 459.67) * 5 / 9;
		}
	};
	
	namespace cast {
		// First is from what convert
		// Second is to what we convert
		template<TEMPERATURE_TYPES First, TEMPERATURE_TYPES Second>
		constexpr TemperatureManager<Second> temperature_cast(TemperatureManager<First>& temperature_s) {
			return TemperatureManager<Second>(conversion_f<First, Second>::conversion(temperature_s.getTemperature()));
		}
	}

	template<TEMPERATURE_TYPES Type>
	class TemperatureManager {

	public:

		TemperatureManager(TEMPERATURE temperature) noexcept : __temperature{ temperature },
			__current_temperature_type{ Type } { }
		
		TemperatureManager(const TemperatureManager& temp_mngr) noexcept {
			this->__current_temperature_type = temp_mngr.__current_temperature_type;
			this->__temperature = temp_mngr.__temperature;
		}
		
		TemperatureManager(TemperatureManager&& temp_mngr) noexcept {
			this->__current_temperature_type = temp_mngr.__current_temperature_type;
			this->__temperature = temp_mngr.__temperature;
			temp_mngr.~TemperatureManager();
		}

		TemperatureManager& operator=(const TemperatureManager& temp_mngr) noexcept {
			this->__current_temperature_type = temp_mngr.__current_temperature_type;
			this->__temperature = temp_mngr.__temperature;
		}

		TemperatureManager& operator=(TemperatureManager&& temp_mngr) noexcept {
			this->__current_temperature_type = temp_mngr.__current_temperature_type;
			this->__temperature = temp_mngr.__temperature;
			temp_mngr.~TemperatureManager();
		}

		~TemperatureManager() {
			this->__temperature = NULL;
		}

		// compare current temperature with another one

		bool isEqual(TemperatureManager& temp) {
			return this->__current_temperature_type == temp.__current_temperature_type &&
				this->__temperature == temp.__temperature;
		}

		bool isEqual(TEMPERATURE& temp) {
			return this->__temperature == temp;
		}

		bool isEqual(TEMPERATURE&& temp) {
			return this->__temperature == temp;
		}

		void changeTemperature(TEMPERATURE new_temperature) {
			this->__temperature = new_temperature;
		}

		constexpr TEMPERATURE getTemperature() const noexcept {
			return this->__temperature;
		}
		
		constexpr TEMPERATURE_TYPES getScale() const noexcept {
			return this->__current_temperature_type;
		}

		// packet of operator's prepared for easier use of class

		/*
			ARE EQUAL METHOD EDIT, FIX
		*/
		bool operator==(const TemperatureManager& r) noexcept {
			return this->areEqual(r);
			//return l.__current_temperature_type == r.__current_temperature_type && l.__temperature == r.__temperature;
		}

		friend bool operator!=(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__current_temperature_type != r.__current_temperature_type || l.__temperature != r.__temperature;
		}

		friend bool operator<(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__current_temperature_type == r.__current_temperature_type && l.__temperature < r.__temperature;
		}

		friend bool operator>(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__current_temperature_type == r.__current_temperature_type && l.__temperature > r.__temperature;
		}

		friend bool operator<=(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__current_temperature_type == r.__current_temperature_type && !(r.__temperature > l.__temperature);
		}

		friend bool operator>=(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__current_temperature_type == r.__current_temperature_type && !(l.__temperature < r.__temperature);
		}

		friend TEMPERATURE operator+(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__temperature + r.__temperature;
		}

		friend TEMPERATURE operator+(const TEMPERATURE& l, const TemperatureManager& r) noexcept {
			return l + r.__temperature;
		}

		friend TEMPERATURE operator+(const TemperatureManager& l, const TEMPERATURE& r) noexcept {
			return l.__temperature + r;
		}

		friend TEMPERATURE operator-(const TemperatureManager& l, const TemperatureManager& r) noexcept {
			return l.__temperature - r.__temperature;
		}

		friend TEMPERATURE operator-(const TEMPERATURE& l, const TemperatureManager& r) noexcept {
			return l - r.__temperature;
		}

		friend TEMPERATURE operator-(const TemperatureManager& l, const TEMPERATURE& r) noexcept {
			return l.__temperature - r;
		}

		friend TemperatureManager& operator+=(TemperatureManager& l, const TemperatureManager& r) noexcept {
			l.__temperature += r.__temperature;
			return l;
		}

		friend TemperatureManager& operator+=(TemperatureManager& l, const TEMPERATURE& r) noexcept {
			l.__temperature += r;
			return l;
		}

		friend TemperatureManager& operator-=(TemperatureManager& l, const TemperatureManager& r) noexcept {
			l.__temperature -= r.__temperature;
			return l;
		}

		friend TemperatureManager& operator-=(TemperatureManager& l, const TEMPERATURE& r) noexcept {
			l.__temperature -= r;
			return l;
		}

		// prefix
		TemperatureManager& operator++() {
			++(this->__temperature);
			return *this;
		}

		// postfix
		TemperatureManager& operator++(int) {
			TemperatureManager temp = *this;
			temp.__temperature = (this->__temperature)++;
			return temp;
		}
		
		// prefix
		TemperatureManager& operator--() {
			--(this->__temperature);
			return *this;
		}

		// postfix
		TemperatureManager& operator--(int) {
			TemperatureManager temp = *this;
			temp.__temperature = (this->__temperature)--;
			return *this;
		}

		bool areEqual(const TemperatureManager<TEMPERATURE_TYPES::CELSIUS>& temp2, 
						long double epsilon = 0.0001) noexcept {
			if (this->getScale() == temp2.getScale())
				return std::fabs(this->getTemperature() - temp2.getTemperature()) < epsilon;

			return false;
		}

		bool areEqual(const TemperatureManager<TEMPERATURE_TYPES::FAHRENHEIT>& temp2, 
						long double epsilon = 0.0001) noexcept {
			if (this->getScale() == temp2.getScale())
				return std::fabs(this->getTemperature() - temp2.getTemperature()) < epsilon;

			return false;
		}

		bool areEqual(const TemperatureManager<TEMPERATURE_TYPES::KELVIN>& temp2, 
						long double epsilon = 0.0001) noexcept {
			if (this->getScale() == temp2.getScale())
				return std::fabs(this->getTemperature() - temp2.getTemperature()) < epsilon;

			return false;
		}
		
	private:

		TEMPERATURE_TYPES __current_temperature_type;
		TEMPERATURE __temperature;

	};

	TemperatureManager<TEMPERATURE_TYPES::CELSIUS> operator "" _deg(TEMPERATURE temp) noexcept {
		return TemperatureManager<TEMPERATURE_TYPES::CELSIUS>(temp);
	}

	TemperatureManager<TEMPERATURE_TYPES::FAHRENHEIT> operator "" _f(TEMPERATURE temp) noexcept {
		return TemperatureManager<TEMPERATURE_TYPES::FAHRENHEIT>(temp);
	}

	TemperatureManager<TEMPERATURE_TYPES::KELVIN> operator "" _k(TEMPERATURE temp) noexcept {
		return TemperatureManager<TEMPERATURE_TYPES::KELVIN>(temp);
	}
}