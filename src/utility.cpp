#include "utility.hpp"
#include <vector>
#include <fstream>
#include <sstream>

namespace lsl {

	/*
	*  Empties a vector then reads a line from a file into it
	*
	*  @param file: File that will be read
	*  @param vec: vector values will be placed into 
	*  @return true if the function read a line; returns false if EOF
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
}
