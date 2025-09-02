#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {
    private:
        Weapon      *_weapon;
        std::string name;
    public:
        HumanB(std::string name);
        void    setWeapon(Weapon &weapon);
        void    attack(void);
};

#endif