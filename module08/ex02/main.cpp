#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	s.push(10);
	s.push(20);
	std::cout << "Classic Stack top element : " << s.top() << std::endl;
	s.pop();
	std::cout << "Classic Stack Size : " << s.size() << std::endl;

	MutantStack<int> anotherStack(mstack);
	MutantStack<int>::iterator it2 = anotherStack.begin();
	MutantStack<int>::iterator ite2 = anotherStack.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << "AnotherStack : " <<  *it2 << std::endl;
		++it2;
	}

	return 0;
}
