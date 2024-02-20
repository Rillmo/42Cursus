#include "FragTrap.hpp"

int main () {
	FragTrap frag("frag");

	frag.printStatus();
	frag.attack("frag22");
	frag.beRepaired(10);
	frag.takeDamage(20);
	frag.highFivesGuys();
}
