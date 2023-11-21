#include "RPN.hpp"

bool isArgValid(char **argv) {
	int numberCount = 0;
	int operatorCount = 0;

	for (size_t i = 0; i < strlen(argv[1]); ++i) {
		if (argv[1][i] == ' ')
			continue;
		if (isdigit(argv[1][i])) {
			numberCount++;
			continue;
		}
		if (isOperator(argv[1][i])) {
			operatorCount++;
			continue;
		}
		if (isBadChar(argv[1][i]))
			return false;
	}
	if ((operatorCount + 1 ) == numberCount)
		return true;
	return false;
}

bool isOperator(char c) {
		if (c == 42 || c == 43 || c == 45 || c == 47)
			return true;
		return false;
}

bool isBadChar(char c) {
	if (!isdigit(c) && !isOperator(c))
		return true;
	return false;
}

int Add(int a, int b) { return a + b; }
int Subtract(int a, int b) { return a - b; }
int Multiply(int a, int b) { return a * b; }
int Divide(int a, int b) {
	if (b == 0)
		throw std::runtime_error("Divide by 0");
	return  a / b;
}

int resultProcess(int stackTop, char operation, int temp, Operation operations[]) {
	switch (operation) {
		case '+': return operations[0](stackTop, temp);
		case '-': return operations[1](stackTop, temp);
		case '*': return operations[2](stackTop, temp);
		case '/': return operations[3](stackTop, temp);
		default: std::cerr << "Operation inconnue" << std::endl; return -1;
	}
}
