#include "Zombie.hpp"

int main() {
    Zombie *zombie1 = newZombie("zombie1");
    zombie1->announce();
    randomChump("zombie2");

    delete zombie1;
}