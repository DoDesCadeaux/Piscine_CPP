#include "Base.hpp"

Base::~Base() {}

Base *Base::generate() {
	int randomNumber = rand() % 3;

	switch (randomNumber) {
		case 2: {
			A *a = new A();
			return a;
		}
		case 1: {
			B *b = new B();
			return b;
		}
		case 0: {
			C *c = new C();
			return c;
		}
	}
	return NULL;
}

void Base::identify(Base *p) {
	if (dynamic_cast<A *>(p) != NULL) {std::cout << "A" << std::endl;}
	else if (dynamic_cast<B *>(p) != NULL) {std::cout << "B" << std::endl;}
	else if (dynamic_cast<C *>(p) != NULL) {std::cout << "C" << std::endl;}
}

void Base::identify(Base &p) {
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	} catch (std::bad_cast &) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	} catch (std::bad_cast &) {}
}
