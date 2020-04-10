#pragma once

namespace modernCPP {

	template<class Container, typename... T>
	void push_data(Container& cont, T&&... args) {
		(cont.push_back(args), ...);
	}

}
