#include <lsl/random.hpp>
#include <random>
#include <cstdint>

namespace lsl {
    namespace random {
		static thread_local std::mt19937_64 rd{ std::random_device{}() };

		/*
		*  Generates a random integer between two numbers. [low, high]
		*/
		int randomNumber(int low, int high) {
			std::uniform_int_distribution<int> dist(low, high);
			return dist(rd);
		}

		/*
		*  Generates a random float between two numbers. [low, high)
		*/
		float randomNumber(float low, float high) {
			std::uniform_real_distribution<float> dist(low, high);
			return dist(rd);
		}

		/*
		*  Generates a random double between two numbers. [low, high)
		*/
		double randomNumber(double low, double high) {
			std::uniform_real_distribution<double> dist(low, high);
			return dist(rd);
		}

		/*
		*  Sets the seed for the random number generator.
		*/
		void setSeed(std::uint64_t seed) {
			rd.seed(seed);
		}

		/*
		*  Sets the seed for the random number generator to a random number.
		*
		*/
		void randomizeSeed() {
			rd.seed(std::random_device{}());
		}
	}
}