#include "Harl.hpp"

Harl::Harl() {return;}

Harl::~Harl() {return;}

void Harl::debug() {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do !"
		<< std::endl;

	return;
}

void Harl::info() {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !"
		<< std::endl;

	return;
}

void Harl::warning() {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;

	return;
}

void Harl::error() {
	std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl;

	return;
}

void Harl::complain(std::string level)  {
	void (Harl::*complaints[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (unsigned long i = 0; i < sizeof(levels) / sizeof(levels[0]); ++i) {
		if (level == levels[i])
		{
			(this->*complaints[i])();
			return;
		}
	}
	std::cout << "He is probably drunk" << std::endl;
}
