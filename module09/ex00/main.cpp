#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	(void)argv;
	if (argc != 2) {
		std::cerr << "Bad args" << std::endl;
		return 1;
	}

	std::ifstream input;
	input.open(argv[1]);
	if (!input) {
		return 1;
	}

	std::ifstream ifs;
	ifs.open("data.csv");
	if (!ifs)
		return 1;

	std::map<std::string, float> datamap = fillMapCSV(ifs);

	try {
		inputParsing(input, datamap);
	} catch (std::runtime_error &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	ifs.close();
	input.close();

	return 0;
}
