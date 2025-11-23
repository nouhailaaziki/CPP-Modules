#ifndef ICE_HPP
# define ICE_HPP

# include "ICharacter.hpp"

class	Ice : public AMateria
{
	public :
		Ice();
		Ice(const Ice& other);
		Ice& operator=(const Ice& other);
		virtual ~Ice();

		AMateria*	clone() const;
		void		use(ICharacter& target);
};

#endif