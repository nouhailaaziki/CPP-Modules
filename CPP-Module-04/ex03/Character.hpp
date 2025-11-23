#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character : public ICharacter {
	private:
	    std::string	name;
		int			size;
	    AMateria*	inventory[4];
		AMateria**	garbageCollector;
	
	public:
	    Character();
	    Character(const std::string& name);
	    Character(const Character& other);
	    Character& operator=(const Character& other);
	    virtual ~Character();
	
	    std::string const&	getName() const;
	    void				equip(AMateria* m);
	    void				unequip(int idx);
	    void				use(int idx, ICharacter& target);
};

#endif
