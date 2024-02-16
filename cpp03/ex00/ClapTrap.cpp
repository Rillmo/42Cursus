#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
	: _name(0), _hitPoints(10), _energyPoints(10), _attackDamage(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Naming constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
	: _name(obj._name), _hitPoints(obj._hitPoints), 
	_energyPoints(obj._energyPoints), _attackDamage(obj._attackDamage)
{
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj) {
	std::cout << "Copy assignment operator called" << std::endl;
	_name = obj._name;
	_hitPoints = obj._hitPoints;
	_energyPoints = obj._energyPoints;
	_attackDamage = obj._attackDamage;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Distructor called" << std::endl;
}

void ClapTrap::printStatus() {
	std::cout << "=============================================" << std::endl;
	std::cout << "|" << std::setw(10) << "NAME";
	std::cout << "|" << std::setw(10) << "HIT";
	std::cout << "|" << std::setw(10) << "ENERGY";
	std::cout << "|" << std::setw(10) << "DAMAGE" << "|" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	std::cout << "|" << std::setw(10) << _name;
	std::cout << "|" << std::setw(10) << _hitPoints;
	std::cout << "|" << std::setw(10) << _energyPoints;
	std::cout << "|" << std::setw(10) << _attackDamage << "|" << std::endl;
	std::cout << "=============================================" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "💢 ClapTrap " << _name << " failed to attck " << target << std::endl;
		printStatus();
		return ;
	}
	_energyPoints--;
	std::cout << "💢 ClapTrap " << _name << " attacks " << target;
	std::cout << ", causing " << _attackDamage << " points of damage!" << std::endl;
	printStatus();
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoints - amount < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "🥊 ClapTrap " << _name << " has taken a Damage " << amount << std::endl;
	printStatus();
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints == 0 || _hitPoints == 0) {
		std::cout << "🛠 ClapTrap " << _name << " failed to reapair" << std::endl;
		printStatus();
		return ;
	}
	std::cout << "🛠 ClapTrap " << _name << " repaired itself " << amount << std::endl;
	_hitPoints+=amount;
	_energyPoints--;
	printStatus();
}
