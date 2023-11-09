#ifndef DETECTION_HPP
# define DETECTION_HPP

#include "ScalarConverter.hpp"
#include <cctype>

bool isException(const std::string &literal);
bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);

#endif
