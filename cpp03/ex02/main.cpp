#include "FragTrap.hpp"

int main () {
	FragTrap frag("frag");

	frag.printStatus();
	frag.beRepaired(10);
	frag.takeDamage(20);
	frag.highFivesGuys();
}
