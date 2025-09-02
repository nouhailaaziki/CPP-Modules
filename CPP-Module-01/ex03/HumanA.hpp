#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {
    private:
        Weapon      &_weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon &_weapon);
        void    attack(void);
};

#endif