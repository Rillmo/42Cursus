#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter {
	private:
		std::string _name;
		AMateria *(_slots[4]);
		AMateria *(_trash);
	public:
		/* Orthodox Canonical Form */
		Character();
		Character(const Character& obj);
		Character& operator=(const Character& obj);
		~Character();
		/*.........................*/

		Character(std::string name);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
		AMateria* pickTrash();

};

#endif