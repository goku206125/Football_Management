#include "player.h"

Player::Player(int id, const char *name, POSITION position)
{
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->position = position;
}

Player::~Player()
{
    delete[] this->name;
}

int Player::get_id()
{
    return this->id;
}

char *Player::get_name()
{
    return this->name;
}

POSITION Player::get_position()
{
    return this->position;
}

void Player::modify(const char *name, POSITION position)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->position = position;
}

void Player::display()
{
    std::cout << "\nPlayer ID : " << this->id << "\n"
              << "Player Name : " << this->name << "\n"
              << "Player Position : ";

    switch (this->position)
    {
    case ATTACK:
        std::cout << "Attack"
                  << "\n";
        break;

    case DEFENCE:
        std::cout << "Defence"
                  << "\n";
        break;

    case KEEPER:
        std::cout << "Keeper"
                  << "\n";
        break;
    }
}