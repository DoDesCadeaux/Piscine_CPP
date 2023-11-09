#include "conversion.hpp"
#include "detection.hpp"

void    displayException(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (!isFloat(literal))
		std::cout << literal << "f" << std::endl;
	else
		std::cout << literal << std::endl;
	std::cout << "double: ";
	if (isDouble(literal))
		std::cout << literal << std::endl;
	else
	{
		std::string formated = literal;
		std::cout << formated.erase(formated.size() - 1) << std::endl;
	}
	exit(0);
}

void displayChar(int convertedLiteral) {
	if (convertedLiteral >= 0 && convertedLiteral <= CHAR_MAX) {
		if(isprint(convertedLiteral))
			std::cout << "char: '" << static_cast<char>(convertedLiteral) << "'" << std::endl;
		else
			std::cout << "Not displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}

void displayInt(int convertedLiteral) {
	std::cout << "int: ";
	if (convertedLiteral >= INT_MIN && convertedLiteral <= INT_MAX)
		std::cout << convertedLiteral << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void displayFloat(float convertedLiteral) {
	std::cout << "float: ";
	if (convertedLiteral >= std::numeric_limits<float>::lowest() && convertedLiteral <= std::numeric_limits<float>::max())
		std::cout << std::setprecision(1) << std::fixed << convertedLiteral << "f" << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void displayDouble(double convertedLiteral) {
	std::cout << "double: ";
	if (convertedLiteral <= std::numeric_limits<double>::max() && convertedLiteral >= std::numeric_limits<double>::lowest())
		std::cout << std::setprecision(1) << std::fixed << convertedLiteral << std::endl;
	else
		std::cout << "Impossible" << std::endl;
}

void displayIntProtection(const std::string &literal)
{
	try {
		std::stoi(literal);
		if (isFloat(literal))
			displayInt(static_cast<int>(std::stof(literal)));
		else if (isDouble(literal))
			displayInt(static_cast<int>(std::stod(literal)));
	} catch (std::out_of_range &)
	{
		std::cout << "int: impossible" << std::endl;
	}
}

void convertToChar(const std::string &literal) {
	int convert = static_cast<int>(literal[0]);

	displayChar(convert);
	displayInt(convert);
	displayFloat(static_cast<float>(convert));
	displayDouble(static_cast<double>(convert));
}

void convertToInt(const std::string &literal) {
	try {
		int convert = std::stoi(literal);

		displayChar(convert);
		displayInt(convert);
		displayFloat(static_cast<float>(convert));
		displayDouble(static_cast<double>(convert));
	} catch (std::out_of_range &)
	{
		std::cout << "Overflow : conversion is impossible" << std::endl;
	}
}

void convertToFloat(const std::string &literal) {
	try {
		float convert = std::stof(literal);

		displayChar(static_cast<int>(convert));
		displayIntProtection(literal);
		displayFloat(convert);
		displayDouble(static_cast<double>(convert));
	} catch (std::out_of_range &e) {
		std::cout << "Overflow : conversion is impossible" << std::endl;
	}
}

void convertToDouble(const std::string &literal) {
	try {
		double convert = std::stod(literal);

		displayChar(static_cast<int>(convert));
		displayIntProtection(literal);
		displayFloat(static_cast<float>(convert));
		displayDouble(convert);
	} catch (std::out_of_range &) {
		std::cout << "Overflow : conversion is impossible" << std::endl;
	}
}
