#include "Harl.hpp"

int main(void)
{
	Harl harlito;

	harlito.complain("INFO");
	harlito.complain("DEBUG");
	harlito.complain("WARNING");
	harlito.complain("ERROR");
	harlito.complain("TEST");
	return 0;
}