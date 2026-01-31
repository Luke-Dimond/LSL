#include <lsl/utility.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

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


}
