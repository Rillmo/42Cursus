#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("")
{
	this->_name = "default_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Default Constructor of DiamondTrap " << _name << " called" <<std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name) {
	this->_name = name + "_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "Naming Constructor of DiamondTrap " << _name << " called" <<std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {
	std::cout << "Copy Constructor of DiamondTrap " << _name << " called" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	std::cout << "Copy assignment operator of DiamondTrap " << _name << " called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor of DiamondTrap " << _name << " called" <<std::endl;
}

void DiamondTrap::whoAmI() {
	std::cout << "[WHO AM I]" << std::endl;
	std::cout << "===========================================" << std::endl;
	std::cout << "|" << std::setw(20) << "NAME";
	std::cout << "|" << std::setw(20) << "CLAPTRAP_NAME" << "|" << std::endl;
	std::cout << "-------------------------------------------" << std::endl;

	std::cout << "|" << std::setw(20) << _name;
	std::cout << "|" << std::setw(20) << ClapTrap::_name << "|" << std::endl;
	std::cout << "===========================================" << std::endl;
}