#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor of ScavTrap " << _name << " called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name)
{
	std::cout << "Naming constructor of ScavTrap " << _name << " called" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	std::cout << "Copy constructor of ScavTrap " << _name << " called" << std::endl;
	this->_name = obj._name;
	this->_hitPoints = obj._hitPoints;
	this->_energyPoints = obj._energyPoints;
	this->_attackDamage = obj._attackDamage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj) {
	std::cout << "Copy assignment operator of ScavTrap " << _name << " called" << std::endl;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor of ScavTrap " << _name << " called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "💢 ScavTrap " << _name << " failed to attck " << target << std::endl;
		printStatus();
		return ;
	}
	_energyPoints--;
	std::cout << "💢 ScavTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
	printStatus();
}

void ScavTrap::guardGate() {
	std::cout << "🚧 ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
