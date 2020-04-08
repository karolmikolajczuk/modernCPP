#pragma once
#include <random>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <array>


namespace modernCPP {


	typedef unsigned int ui;
	
	// computes PI
	template <typename Engine = std::mt19937,
		typename Distance = std::uniform_real_distribution<>>
	double computePI(Engine& engine, Distance& distance, const int mill = 1'000'000) {
		int hit = 0;
		
		// do it million times
		for (auto index = 0; index < mill; ++index) {
			
			// generate x and y 
			auto x = distance(engine);
			auto y = distance(engine);


			if (y <= std::sqrt(1 - std::pow(x, 2))) ++hit;
		}

		// compute pi 
		return 4.0 * hit / mill;
	}
		
	void compute_PI() {
		// number generator
		std::random_device rand;

		// array for generated numbers
		auto reach_data = std::array<int, std::mt19937::state_size> {};
		
		// generate data through whole array
		std::generate(std::begin(reach_data), std::end(reach_data), std::ref(rand));

		// making seed
		std::seed_seq sequence(std::begin(reach_data), std::end(reach_data));
		
		// engine with seed
		auto engine = std::mt19937{ sequence };
		
		// the lower bound, produce number between <0;1)
		auto distance = std::uniform_real_distribution<>{ 0, 1 };

		// compute PI with given engine and distance
		for (auto j = 0; j < 10; ++j) std::cout << computePI(engine, distance) << std::endl;
	}
}
