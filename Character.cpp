#pragma once
#include "Character.hpp"

int FIREBALLCOST(10);
int FIREBALLDAMAGE(10);
int HEALCOST(10);
int HEAL(10);

Object::Object(std::string name,unsigned int quantity): _name(name),_quantity(quantity)
{

}

Weapon::Weapon(std::string name,int range,int damage):Object(name,1),_range(range),_damage(damage){}
Weapon::Weapon():Object("Stick",1),_range(1),_damage(2){}

Character::Character(std::string name,int health,int mana,std::string weaponName,int weaponRange,int weaponDamage,
                            int strength,int dexterity,int constitution,int intelligence,int charisma,int wisdom):

            _name(name),_health(health),_mana(mana), _strength(strength), _dexterity(dexterity), _constitution(constitution),
            _intelligence(intelligence), _charisma(charisma), _wisdom(wisdom)
            {
                
                _weapon = Weapon(weaponName,weaponRange,weaponDamage);
                
            }

Character::Character():
            _name("NPC"),_health(100),_mana(100),_strength(10), _dexterity(10), _constitution(10),
            _intelligence(10), _charisma(10), _wisdom(10)
            {
            }

void Character::showStats() const
{
    std::cout <<"name: "<< _name <<std::endl;
    std::cout <<"health: "<< _health <<std::endl;
    std::cout <<"mana: "<< _mana <<std::endl;
    std::cout <<"weapon: "<< _weapon._name <<std::endl<<std::endl;
}
void Character::getHit(int damage)
{
    _health -= damage; 
}
void Character::getHealed(int heal)
{
    _health += heal; 
}

void Character::hit(Character &target)
{
    target._health -= _weapon._damage;
    std::cout<<"does "<<_weapon._damage<<" damage to "<<target._name<<std::endl;
}

void Character::attack()
{
    std::cout<<"how do you attack? Well you only have a stick you stoopid"<<std::endl;
    std::cout<<"Who are you attacking? "<<std::endl;
    std::string targetId;
    std::getline(std::cin,targetId);
    std::cout<<"you attack"<<targetId<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //probleme pour récupérer la cible il me faut la fonction GUI
}

void Character::useObject()
{
    std::string object;
    std::cout<<"what object do you want to use?"<<std::endl;
    std::getline(std::cin,object);
    std::cout<<"you use "<<object<<std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
Wizard::Wizard(std::string name)
{
    _name = name;
}

Barbarian::Barbarian(std::string name)
{
    _name = name;
}

void Wizard::fireball(Character &target)
{
    if (_mana >FIREBALLCOST)
    {  
        _mana -= FIREBALLCOST;
        target.getHit(FIREBALLDAMAGE);
    }
}

void Wizard::heal(Character &target)
{
    if (_mana >HEALCOST)
    {  
        _mana -= HEALCOST;
        target.getHealed(HEAL);
    }
}

Goblin::Goblin(std::string name)
{
    _name = name;
}

void battle(std::vector<Character> players, std::vector<Character> ennemies)
{
}

int rollDice(int n, int score, int numberScore, int dexterity)
{
    return 0;
}

void playerTurn(Character& player)
{
}
