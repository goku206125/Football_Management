#include "league.h"

League::League(int id, const char *name)
{
    this->id = id;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->head = nullptr;
}

League::~League()
{
    delete[] this->name;
    this->clear();
}

int League::get_id()
{
    return this->id;
}

bool League::add_player(int id, const char *name, POSITION position)
{
    if (this->head == nullptr)
    {
        this->head = new PlayerNode;
        this->head->player = new Player(id, name, position);
        this->head->next = nullptr;
        return true;
    }

    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            if (node->player->get_id() == id)
            {
                return false;
            }
            if (node->next == nullptr)
            {
                node->next = new PlayerNode;
                node->next->player = new Player(id, name, position);
                node->next->next = nullptr;
                return true;
            }
        }
        node = node->next;
    }

    return false;
}

bool League::add_player(Player *player)
{
    if (this->head == nullptr)
    {
        this->head = new PlayerNode;
        this->head->player = player;
        this->head->next = nullptr;
        return true;
    }

    this->remove_player(player->get_id());

    PlayerNode *node = this->head;

    while (node)
    {
        if (node->next == nullptr)
        {
            node->next = new PlayerNode;
            node->next->player = player;
            node->next->next = nullptr;
            return true;
        }
        node = node->next;
    }
    return false;
}

bool League::remove_player(int id)
{
    if (this->head == nullptr)
    {
        return false;
    }

    if (this->head->player != nullptr)
    {
        if (this->head->player->get_id() == id)
        {
            PlayerNode *next = this->head->next;
            delete this->head->player;
            delete this->head;
            this->head = next;
            return true;
        }
    }

    PlayerNode *current = this->head;
    PlayerNode *previous = this->head;

    while (current)
    {
        if (current->player != nullptr)
        {
            if (current->player->get_id() == id)
            {
                delete current->player;
                previous->next = current->next;
                delete current;
                return true;
            }
        }
        previous = current;
        current = current->next;
    }
    return false;
}

bool League::modify_player(int id, const char *new_name, POSITION new_position)
{

    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            if (node->player->get_id() == id)
            {
                node->player->modify(new_name, new_position);
                return true;
            }
        }
        node = node->next;
    }
    return false;
}

int League::player_count(POSITION position)
{
    int count = 0;
    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            if (node->player->get_position() == position)
            {
                count++;
            }
        }
        node = node->next;
    }
    return count;
}

int League::player_count()
{
    int count = 0;
    PlayerNode *node = this->head;

    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
}

bool League::player_exists(int id)
{
    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            if (node->player->get_id() == id)
            {
                return true;
            }
        }
        node = node->next;
    }
    return false;
}

Player *League::get_player(int id)
{
    if (this->head->player != nullptr)
    {
        if (this->head->player->get_id() == id)
        {
            PlayerNode *next = this->head->next;
            Player *player = this->head->player;
            delete this->head;
            this->head = next;
            return player;
        }
    }

    PlayerNode *current = this->head;
    PlayerNode *previous = this->head;

    while (current)
    {
        if (current->player != nullptr)
        {
            if (current->player->get_id() == id)
            {
                Player *player = current->player;
                previous->next = current->next;
                delete current;
                return player;
            }
        }
        previous = current;
        current = current->next;
    }
    return nullptr;
}

void League::clear()
{
    PlayerNode *next, *node = this->head;

    while (node)
    {
        next = node->next;
        delete node->player;
        delete node;
        node = next;
    }
}

void League::display(POSITION position)
{
    std::cout << "\n\nLeague ID : " << this->id << "\n";
    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            if (node->player->get_position() == position)
            {
                node->player->display();
            }
        }
        node = node->next;
    }
}

void League::display()
{
    std::cout << "\n\nLeague ID : " << this->id << "\n";
    PlayerNode *node = this->head;

    while (node)
    {
        if (node->player != nullptr)
        {
            node->player->display();
        }
        node = node->next;
    }
}
