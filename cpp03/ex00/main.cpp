#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1 = ClapTrap("clapTrap1");
	ClapTrap clapTrap2 = ClapTrap("clapTrap2");

	// clapTrap1 attack clapTrap2
	clapTrap1.printStatus();
	clapTrap1.attack("clapTrap2");
	clapTrap2.takeDamage(0);

	// clapTrap2 repairs itself
	clapTrap2.beRepaired(10);
}