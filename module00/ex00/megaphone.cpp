#include <iostream>
#include <cstring>
#include <cctype>

int main(int argc, char **argv) {
	if (argc > 1) {
		for (int j = 1; j < argc; j++) {
			unsigned int argLength = strlen(argv[j]);
			for (unsigned int i = 0; i < argLength; i++) {
				std::cout << (char)toupper(argv[j][i]);
			}
			if (j < argc - 1)
				std::cout << ' ';
		}
	} else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
}
