#include "Base.hpp"

int main(void) {
	srand(static_cast<unsigned int>(time(NULL)));

	for (int i = 0; i < 10; ++i) {
		Base *basePtr = Base::generate();

		std::cout << "Test " << i + 1 << " :" << std::endl;

		std::cout << "Identify by pointer: ";
		Base::identify(basePtr);

		std::cout << "Identify by reference: ";
		Base::identify(*basePtr);

		delete basePtr;
		std::cout << std::endl;
	}

	return 0;
}
