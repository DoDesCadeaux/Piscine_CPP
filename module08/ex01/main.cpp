#include "Span.hpp"

int main(void) {
	Span numbersat = Span(5);
	Span test = Span(5);


	std::srand(std::time(NULL));

	try {
		test.fillVectorRandomlySafely();
		numbersat.addRange(test.getNumbers().begin(), test.getNumbers().end());

		std::cout << "TEST DISPLAY : " << std::endl;
		test.displayNumbers();

		std::cout << "NUMBERSAT DISPLAY : " << std::endl;
		numbersat.displayNumbers();

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		exit(1);
	}

	try {
		unsigned int shortest = numbersat.shortestSpan();
		unsigned int longest = numbersat.longestSpan();
		std::cout << "Shortest : " <<  shortest << std::endl;
		std::cout << "Longest : " << longest << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		exit(1);
	}

	return 0;
}
