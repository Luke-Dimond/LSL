#include "utility.hpp"
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdint>
#include <random>

namespace lsl {

	/*
	*  Reads a line from a file and splits words into a vector.
	*  Returns false on EOF.
	*/
	bool readLineToVector(std::ifstream& file, std::vector<std::string>& vec) {

		std::string token{};
		vec.clear();
		if (!std::getline(file, token)) return false;

		std::istringstream iss(token);

		while (iss >> token) {
			vec.push_back(token);
		}

		return true;
	}

	namespace Random {
		static std::mt19937_64 rd{ std::random_device{}() };

		/*
		*  Generates a random integer between two numbers.
		*/
		int randomNumber(int low, int high) {
			std::uniform_int_distribution<int> dist(low, high);
			return dist(rd);
		}

		/*
		*  Generates a random float between two numbers.
		*/
		float randomNumber(float low, float high) {
			std::uniform_real_distribution<float> dist(low, high);
			return dist(rd);
		}

		/*
		*  Generates a random double between two numbers.
		*/
		double randomNumber(double low, double high) {
			std::uniform_real_distribution<double> dist(low, high);
			return dist(rd);
		}

		/*
		*  Sets the seed for the random number generator.
		*/
		void setSeed(uint64_t seed) {
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
