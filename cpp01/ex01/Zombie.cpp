#include "Zombie.hpp"

Zombie::Zombie() {
}

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Zombie [" << name << "] created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie [" << name << "] destroyed" << std::endl;
}

void Zombie::setName(std::string name) {
    this->name = name;
}

void Zombie::announce(void) {
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
