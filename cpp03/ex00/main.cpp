#include "ClapTrap.hpp"

int main() {
	ClapTrap test = ClapTrap("junkim2");

	test.attack("tajeong");
	test.takeDamage(10);
	test.attack("yeonducho");
	test.beRepaired(3);
}