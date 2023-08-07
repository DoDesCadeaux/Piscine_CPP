#include <iostream>

int main(int argc, char **argv) {
	if (argc > 1) {
		for (int j = 1; j < argc ; j++)
		{
			unsigned int argLength = strlen(argv[j]);
			for (unsigned int i = 0; i < argLength; i++)
			{
				if (argv[j][i] >= 97 && argv[j][i] <= 122)
					argv[j][i] -= 32;
				std::cout << argv[j][i];
			}
		}
	}
	else {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	std::cout << std::endl;
}
