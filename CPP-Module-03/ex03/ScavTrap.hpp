#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : virtual public ClapTrap {
    protected:
        unsigned int    scavtrap_energy_points;

    public:
        ScavTrap();
        ScavTrap(const std::string& name_value);
        ScavTrap(const ScavTrap& other);
        ScavTrap& operator=(const ScavTrap& other);
        ~ScavTrap();

        void    attack(const std::string& target);
        void    guardGate();
};

#endif