#include <string>
#include <iostream>
#include "templates.hpp"

int main(void) {
	int a = 20;
	int b = 40;

	char c = 'c';
	char d = 'd';

	int mini = min<int>(a, b);
	int maxi = max<int>(a, b);

	float minif = min<float>(44.042f, 42.012f);
	float maxif = max<float>(192.0223f, 31232.21233f);


	std::cout << "before swap -> a : " << a << ", b : " << b << std::endl;
	swap<int>(a, b);
	std::cout << "after swap -> a : " << a << ", b : " << b << std::endl;

	std::cout << "before swap -> c : " << c << ", d : " << d << std::endl;
	swap<char>(c, d);
	std::cout << "after swap -> c : " << c << ", d : " << d << std::endl;

	std::cout << "min int : " << mini << std::endl;
	std::cout << "max int : " << maxi << std::endl;
	std::cout << "min float : " << minif << std::endl;
	std::cout << "max float : " << maxif << std::endl;

	return 0;
}
