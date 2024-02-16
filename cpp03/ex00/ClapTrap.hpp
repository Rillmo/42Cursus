#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <iostream>
#include <iomanip>

class ClapTrap {
	private:
		std::string _name;
		int	_hitPoints;
		int _energyPoints;
		int _attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap& operator=(const ClapTrap& obj);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void printStatus();
};

#endif