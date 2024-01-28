#include "HumanB.hpp"

HumanB::HumanB(std::string name) 
    :weapon(0), name(name) 
{}

HumanB::~HumanB() {}

void HumanB::attack() {
    std::cout << name + "attacks with their" + weapon->getType() << std::endl;
}