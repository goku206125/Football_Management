#include "football_league.h"

Football_League::Football_League()
{
    this->name = new char[16];
    strcpy(this->name, "Football League");
    this->head = nullptr;
}

Football_League::Football_League(const char *name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->head = nullptr;
}

Football_League::~Football_League()
{
    delete[] this->name;
    this->clear();
}

bool Football_League::add_league(int id, const char *name)
{
    if (this->league_count() == 7)
    {
        return false;
    }

    if (this->head == nullptr)
    {
        this->head = new LeagueNode;
        this->head->league = new League(id, name);
        this->head->next = nullptr;
        return true;
    }

    LeagueNode *node = this->head;

    while (node)
    {
        if (node->league != nullptr)
        {
            if (node->league->get_id() == id)
            {
                return false;
            }
        }
        if (node->next == nullptr)
        {
            node->next = new LeagueNode;
            node->next->league = new League(id, name);
            node->next->next = nullptr;
            return true;
        }
        node = node->next;
    }

    return false;
}

bool Football_League::remove_league(int id)
{
    if (this->head == nullptr)
    {
        return false;
    }

    if (this->head->league != nullptr)
    {
        if (this->head->league->get_id() == id)
        {
            LeagueNode *next = this->head->next;
            delete this->head->league;
            delete this->head;
            this->head = next;
            return true;
        }
    }

    LeagueNode *current = this->head;
    LeagueNode *previous = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == id)
            {
                delete current->league;
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

bool Football_League::league_exists(int id)
{
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == id)
            {
                return true;
            }
        }
        current = current->next;
    }
    return false;
}

bool Football_League::add_player(int league, int id, const char *name, POSITION position)
{
    if (this->player_exists(league, id))
    {
        return false;
    }

    if (this->player_count(league) == 11)
    {
        return false;
    }

    if ((this->position_count(league, KEEPER) == 1) && (position == KEEPER))
    {
        return false;
    }

    if ((this->position_count(league, ATTACK) == 5) && (position == ATTACK))
    {
        return false;
    }

    if ((this->position_count(league, DEFENCE) == 5) && (position == DEFENCE))
    {
        return false;
    }

    LeagueNode *current = this->head;
    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == league)
            {
                return current->league->add_player(id, name, position);
            }
        }
        current = current->next;
    }
    return false;
}

bool Football_League::remove_player(int league, int id)
{
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == league)
            {
                return current->league->remove_player(id);
            }
        }
        current = current->next;
    }
    return false;
}

bool Football_League::modify_player(int league, int id, const char *new_name, POSITION new_position)
{

    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == league)
            {
                return current->league->modify_player(id, new_name, new_position);
            }
        }
        current = current->next;
    }
    return false;
}

bool Football_League::move_player(int source_league, int source_player, int target_league)
{
    if (source_league == target_league)
    {
        return false;
    }

    LeagueNode *current = this->head;
    Player *source = nullptr;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == source_league)
            {
                source = current->league->get_player(source_player);
                break;
            }
        }
        current = current->next;
    }

    if (source == nullptr)
    {
        return false;
    }

    LeagueNode *target = this->head;

    while (target)
    {
        if (target->league != nullptr)
        {
            if (target->league->get_id() == target_league)
            {
                target->league->add_player(source);
                return true;
            }
        }
        target = current->next;
    }
    return false;
}

bool Football_League::player_exists(int league, int player)
{
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league->get_id() == league)
        {
            return current->league->player_exists(player);
        }
        current = current->next;
    }
    return false;
}

int Football_League::league_count()
{
    int count = 0;
    LeagueNode *current = this->head;

    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

int Football_League::player_count()
{
    int count = 0;
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            count += current->league->player_count();
        }
        current = current->next;
    }
    return count;
}

int Football_League::player_count(int league)
{
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == league)
            {
                return current->league->player_count();
            }
        }
        current = current->next;
    }
    return 0;
}

int Football_League::position_count(int league, POSITION position)
{
    LeagueNode *current = this->head;

    while (current)
    {
        if (current->league != nullptr)
        {
            if (current->league->get_id() == league)
            {
                return current->league->player_count(position);
            }
        }
        current = current->next;
    }
    return 0;
}

void Football_League::clear()
{
    LeagueNode *next, *node = this->head;

    while (node)
    {
        next = node->next;
        delete node->league;
        delete node;
        node = next;
    }
    this->head = nullptr;
}

void Football_League::display(int league)
{
    LeagueNode *node = this->head;

    while (node)
    {
        if (node->league != nullptr)
        {
            if (node->league->get_id() == league)
            {
                node->league->display();
                return;
            }
        }

        node = node->next;
    }
}

void Football_League::display(POSITION position)
{

    LeagueNode *node = this->head;

    while (node)
    {
        if (node->league != nullptr)
        {
            node->league->display(position);
        }
        node = node->next;
    }
}

void Football_League::display(int league, POSITION position)
{
    LeagueNode *node = this->head;

    while (node)
    {
        if (node->league != nullptr)
        {
            if (node->league->get_id() == league)
            {
                node->league->display(position);
                return;
            }
        }

        node = node->next;
    }
}

void Football_League::display()
{
    std::cout << this->name << "\n";
    LeagueNode *node = this->head;

    while (node)
    {
        if (node->league != nullptr)
        {
            node->league->display();
        }
        node = node->next;
    }
}
