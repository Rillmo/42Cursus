#ifndef MATERIA_SOURCE
#define MATERIA_SOURCE

#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria *(_sources[4]);
	public:
		/* Orthodox Canonical Form */
		MateriaSource();
		MateriaSource(const MateriaSource& obj);
		MateriaSource& operator=(const MateriaSource& obj);
		~MateriaSource();
		/*.........................*/

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif