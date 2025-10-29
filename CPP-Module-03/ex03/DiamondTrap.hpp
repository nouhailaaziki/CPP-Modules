#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {
	private:
        std::string     name;

    public:
        DiamondTrap();
        DiamondTrap(const std::string& name_value);
        DiamondTrap(const DiamondTrap& other);
        DiamondTrap& operator=(const DiamondTrap& other);
        ~DiamondTrap();

		void	whoAmI() const;
};

#endif