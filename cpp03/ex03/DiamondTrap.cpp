#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() :ClapTrap("DEFAULT_clap_name") {
	std::cout << "DiamondTrap Default Constructor called" <<std::endl;
	this->_name = "DEFAULT";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {
	std::cout << "DiamondTrap Naming Constructor called" <<std::endl;
	this->_name = name;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) {
	std::cout << "DiamondTrap Copy Constructor called" << std::endl;
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj) {
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap Destructor called" <<std::endl;
}

std::string& DiamondTrap::printAll() {
	std::cout << "name: " << _name << std::endl;
	std::cout << "clapTrapName: " << ClapTrap::_name << std::endl;
	std::cout << "hitPoints: " << _hitPoints << std::endl;
	std::cout << "energyPoints: " << _energyPoints << std::endl;
	std::cout << "attackDamage: " << _attackDamage << std::endl;
}