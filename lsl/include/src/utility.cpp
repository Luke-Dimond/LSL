#include "utility.hpp"

bool stringToNum(const std::string& s, int& num) {
    std::from_chars(s.data(),s.data() + s.size(), num);
}

bool stringToNum(const std::string& s, float& num) {
    std::from_chars(s.data(),s.data() + s.size(), num);
}