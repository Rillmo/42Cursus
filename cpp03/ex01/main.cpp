#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <unistd.h>

int main () {
	ClapTrap t("clap1");
	ScavTrap s("scav1");

	t.attack("scav1");
	s.attack("clap1");

	t.beRepaired(10);
	s.beRepaired(10);
	
	s.guardGate();
}
