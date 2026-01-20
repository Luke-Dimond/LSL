/*
* Created by: Luke Manuel
* 2025
*/
#pragma once
#include <string>
#include <charconv>
#include <vector>
#include <fstream>

namespace lsl {

/*
*  Converts a string into a numeric value.
*
*  @param s: Input string to parse
*  @param num: Output variable that receives the parsed value
*  @return bool: true if the entire string is successfully parsed as a number; false otherwise (invalid argument, out of range, partial parse)
*/
template <typename T>
bool stringToNum(const std::string& s, T& num) {

    const char* begin = s.data();
    const char* end = s.data() + s.size();
    const auto res = std::from_chars(begin, end, num);

    if (res.ec == std::errc::invalid_argument || res.ptr != end || res.ec == std::errc::result_out_of_range) {
        return false;
    }

    return true;
}

bool readLineToVector(std::ifstream& file, std::vector<std::string>& vec);

}
