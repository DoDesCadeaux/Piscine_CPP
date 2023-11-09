#include "ScalarConverter.hpp"
#include "detection.hpp"

bool isException(const std::string &literal) {

	std::string exceptions[] = {
			"nanf",
			"+inff",
			"-inff",
			"nan",
			"+inf",
			"-inf"
	};

	for (size_t i = 0; i < (sizeof(exceptions) / sizeof(exceptions[0])); i++)
	{
		if (literal == exceptions[i])
			return true;
	}

	return false;
}

bool isChar(const std::string &literal) {
	if (literal.length() == 1 && !isdigit(literal[0]))
		return true;
	return false;
}

bool isInt(const std::string &literal) {
	if (literal.empty())
		return false;

	unsigned int i = 0;
	unsigned int end = 0;

	while (literal[end])
		end++;

	if (literal[i] == '+' || literal[i] == '-')
	{
		if (i == end)
			return false;
		i++;
	}

	while ((i != end) && isdigit(literal[i]))
		i++;

	return (i == end);
}

bool isFloat(const std::string &literal) {

	if (literal.empty())
		return false;

	std::string acceptedLiteral[] = {
			"nanf",
			"-inff",
			"+inff"
	};

	for (unsigned long i = 0; i < (sizeof(acceptedLiteral) / sizeof(acceptedLiteral[0])); i++) {
		if (literal == acceptedLiteral[i])
			return true;
	}

	unsigned int i = 0;
	unsigned int end = 0;
	unsigned int dotCount = 0;
	unsigned int fCount = 0;

	while (literal[end])
		++end;

	if (literal[i] == '-' || literal[i] == '+')
	{
		if (i == end)
			return false;
		i++;
	}
	while (i != end && dotCount <= 1)
	{
		if (!(isdigit(literal[i])) && literal[i] != '.' && literal[i] != 'f')
			return false;
		if (isdigit(literal[i]))
			i++;
		else if (literal[i] == '.' || literal[i] == 'f')
		{
			if (literal[i] == '.' && dotCount <= 1)
			{
				i++;
				dotCount++;
			}
			else if (literal[i] == 'f')
			{
				i++;
				fCount += 1;
			}
			if (i == end && fCount <= 1 && dotCount == 1)
				return true;
		}
	}
	return ((i == end) && dotCount == 1 && fCount == 1);
}

bool isDouble(const std::string &literal)
{
	if (literal.empty())
		return false;

	std::string acceptedLiteral[] = {
			"nan",
			"-inf",
			"+inf",
	};

	for (unsigned long i = 0; i < (sizeof(acceptedLiteral) / sizeof(acceptedLiteral[0])); i++) {
		if (literal == acceptedLiteral[i])
			return true;
	}
	unsigned int i = 0;
	unsigned int end = 0;
	unsigned int dotCount = 0;

	while (literal[end])
		++end;

	if (literal[i] == '-' || literal[i] == '+')
	{
		if (i == end)
			return false;
		i++;
	}

	while (i != end && dotCount <= 1)
	{
		if (!(isdigit(literal[i])) && literal[i] != '.')
			return false;
		if (isdigit(literal[i]))
			i++;
		else if (literal[i] == '.')
		{
			if (literal[i] == '.' && dotCount <= 1)
			{
				i++;
				dotCount++;
			}
			if (i == end && dotCount == 1)
				return true;
		}
	}
	return ((i == end) && dotCount == 1);
}
