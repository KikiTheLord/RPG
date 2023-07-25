#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <memory>

class Object
{
    public:
        Object(std::string name,unsigned int quantity);
        std::string _name;
    protected:
        unsigned int _quantity;
};

class Weapon: public Object
{
    public:
        Weapon();
        Weapon(std::string name,int range,int damage);
        int _damage;
    private:
        
        int _range;
};

class Character
{
    public:
        Character();
        Character(std::string name,int health,int mana,std::string weaponName,int weaponRange,int weaponDamage,
                    int strength,int dexterity,int constitution,int intelligence,int charisma,int wisdom);
        virtual void showStats() const;
        virtual void attack();
        virtual void useObject();
        void hit(Character &target);
        void getHit(int damage);
        void getHealed(int heal);
        std::string _name;

    protected:
    Weapon _weapon;
    std::vector<Object> _inventory;
    int _health;
    int _mana;
    int _strength;
    int _dexterity;
    int _constitution;
    int _intelligence;
    int _charisma;
    int _wisdom;  
};


class Wizard: public Character
{
    public:
        Wizard(std::string name);
        void fireball(Character &target);
        void heal(Character &target);

};

class Thief: public Character
{
    public:
        void backstab(Character &target);
        void steal(Character &target);
};

class Barbarian: public Character
{
    public:
        Barbarian(std::string name);
        void protect(Character &target);
        void dashhit(Character &target);
};

class Elve: public Character
{
    public:
        void track();
        void racism();
};

class Dwarf: public Character
{
    public:
        void drink();
};

class Goblin: public Character
{
    public:
        using Character::Character;
        Goblin(std::string name);
};

void battle(std::vector<Character> players,std::vector<Character> ennemies);
int rollDice(int n,int score,int numberScore,int dexterity);
void playerTurn(Character &player);