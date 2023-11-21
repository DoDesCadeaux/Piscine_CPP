#include "RPN.hpp"

int main(int argc, char **argv) {
		if (argc != 2)
			return 1;

		std::stack<int> stack;
		int topTemp;
		int secondTemp;
		char operation;
		Operation operations[4] = { Add, Subtract, Multiply, Divide };

		if (isArgValid(argv)) {
			for (size_t i = 0; i < strlen(argv[1]); ++i) {
				if (isdigit(argv[1][i]))
					stack.push(argv[1][i] - '0');
				if (isOperator(argv[1][i]))
				{
					try {
						if (stack.empty())
							throw std::runtime_error("Bad RPN");
						operation = argv[1][i];
						topTemp = stack.top();
						stack.pop();
						if (stack.empty())
							throw std::runtime_error("Bad RPN");
						secondTemp = stack.top();
						stack.pop();
						stack.push(resultProcess(secondTemp, operation, topTemp, operations));
					} catch (std::runtime_error &e) {
						std::cout << "Error : " << e.what() << std::endl;
						exit(1);
					}
				}
			}
			std::cout << stack.top() << std::endl;
		}
		else {
			std::cerr << "Invalid Argument" << std::endl;
			exit(1);
		}
	return 0;
}