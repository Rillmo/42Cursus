#include "DiamondTrap.hpp"

int main() {
	DiamondTrap d("dia1");

	d.attack("dia1");
	d.takeDamage(30);
	d.beRepaired(30);

	d.whoAmI();
}