#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
	    AMateria*	storage[4];
	
	public:
	    MateriaSource();
	    MateriaSource(const MateriaSource& other);
	    MateriaSource& operator=(const MateriaSource& other);
	    virtual ~MateriaSource();
	
	    void		learnMateria(AMateria* m);
	    AMateria*	createMateria(const std::string& type);
};

#endif

