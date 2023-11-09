#include "ScalarConverter.hpp"
#include "detection.hpp"
#include "conversion.hpp"

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter(ScalarConverter const &inst) {
	*this = inst;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other) {
	if (this != &other)
		*this = other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal) {
	if (isException(literal))
		displayException(literal);
	else if (isChar(literal))
		convertToChar(literal);
	else if (isInt(literal))
		convertToInt(literal);
	else if (isFloat(literal))
		convertToFloat(literal);
	else if (isDouble(literal))
		convertToDouble(literal);
}
