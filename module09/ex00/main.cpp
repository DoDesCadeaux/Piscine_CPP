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
		std::cerr << "open: not such file or no access rights: " << argv[1] << std::endl;
		return 1;
	}

	std::ifstream ifs;
	std::string filename = "data.csv";
	ifs.open(filename);
	if (!ifs) {
		std::cerr << "open: not such file or no access rights: " << filename << std::endl;
		return 1;
	}

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
