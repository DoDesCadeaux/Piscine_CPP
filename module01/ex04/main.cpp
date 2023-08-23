#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	std::string	s1 = argv[2];
	std::string	s2 = argv[3];

	if (argc != 4) {
		std::cout << "Bad args" << std::endl;
		return 1;
	}
	if (s1.empty() || s2.empty()) {
		std::cout << "Strings cannot be empty" << std::endl;
		return 2;
	}
	std::string inputFileName = std::string(argv[1]);
	std::ifstream inputFile(inputFileName);

	if (inputFile.fail()) {
		std::cerr << "Can't open " << inputFileName << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string	outputFileName = inputFileName + ".replace";
	std::ofstream outputFile(outputFileName);

	if (outputFile.fail())
	{
		std::cerr << "Can't open " << outputFileName << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	while(std::getline(inputFile, line))
	{
		size_t pos = line.find(s1);
		while(pos != std::string::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);

			pos += s2.length();
			pos = line.find(s1, pos);
		}
		outputFile << line << std::endl;
	}
	inputFile.close();
	outputFile.close();
	return 0;
}