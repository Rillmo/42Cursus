#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main () {
	ClapTrap c("clap1");
	ScavTrap s("scav1");
	FragTrap f("frag1");

	c.attack("frag1");
	s.attack("frag1");
	f.attack("scav1");
	
	s.takeDamage(30);
	f.takeDamage(20);

	s.beRepaired(30);
	f.beRepaired(20);

	f.highFivesGuys();
}
