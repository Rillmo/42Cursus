#include "FragTrap.hpp"


FragTrap::FragTrap() 
{
	std::cout << "FragTrap Default constructor called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name)
{
	std::cout << "FragTrap' Naming constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

FragTrap::FragTrap(const FragTrap& obj)
{
	std::cout << "FragTrap Copy constructor called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
}

FragTrap& FragTrap::operator=(const FragTrap& obj) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void) {
	std::cout << "🧤 FragTrap " << _name << " Requested High Five!" << std::endl;
}