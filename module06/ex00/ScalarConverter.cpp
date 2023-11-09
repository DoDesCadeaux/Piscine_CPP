#include "ScalarConverter.hpp"
#include "detection.hpp"
#include "conversion.hpp"

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
