#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
    this->name = name;
    std::cout << "Zombie [" << name << "] created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie [" << name << "] destroyed" << std::endl;
}

Zombie* newZombie( std::string name ) {
    Zombie *res = new Zombie(name);
    return res;
}