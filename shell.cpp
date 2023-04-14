#include <iterator>
#include <sstream>
#include <vector>
#include <sstream>
#include "shell.h"

void Shell::handle_input(std::string input)
{
    std::vector<std::string> vstrings;
    split(input, ' ', vstrings);

    if (vstrings.size() == 0)
    {
        return;
    }

    else if (vstrings[0] == "clear")
    {
        if (vstrings.size() == 1)
        {
            system("clear");
            return;
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }

    else if (vstrings[0] == "display")
    {
        if (vstrings.size() == 1)
        {
            FL.display();
            return;
        }
        else if (vstrings.size() == 3)
        {
            if (vstrings[1] == "league")
            {
                if (is_number(vstrings[2]))
                {
                    FL.display(stoi(vstrings[2]));
                    return;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else if (vstrings[1] == "position")
            {
                POSITION position;
                if (vstrings[2] == "KEEPER")
                {
                    position = KEEPER;
                }
                else if (vstrings[2] == "ATTACK")
                {
                    position = ATTACK;
                }
                else if (vstrings[2] == "DEFENCE")
                {
                    position = DEFENCE;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
                FL.display(position);
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings.size() == 5)
        {
            if (vstrings[1] == "league")
            {
                if (is_number(vstrings[2]))
                {
                    if (vstrings[3] == "position")
                    {
                        POSITION position;
                        if (vstrings[4] == "KEEPER")
                        {
                            position = KEEPER;
                        }
                        else if (vstrings[4] == "ATTACK")
                        {
                            position = ATTACK;
                        }
                        else if (vstrings[4] == "DEFENCE")
                        {
                            position = DEFENCE;
                        }
                        else
                        {
                            std::cout << "Invalid Input" << std::endl;
                            return;
                        }
                        FL.display(stoi(vstrings[2]), position);
                        return;
                    }
                    else
                    {
                        std::cout << "Invalid Input" << std::endl;
                        return;
                    }
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }

    else if (vstrings[0] == "add")
    {
        if (vstrings.size() == 1)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "league")
        {
            if (vstrings.size() == 4)
            {
                if (is_number(vstrings[2]))
                {
                    FL.add_league(stoi(vstrings[2]), vstrings[3].c_str());
                    return;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings[1] == "player")
        {
            if (vstrings.size() == 6)
            {
                if (is_number(vstrings[2]) && is_number(vstrings[3]))
                {
                    POSITION position;
                    if (vstrings[5] == "KEEPER")
                    {
                        position = KEEPER;
                    }
                    else if (vstrings[5] == "ATTACK")
                    {
                        position = ATTACK;
                    }
                    else if (vstrings[5] == "DEFENCE")
                    {
                        position = DEFENCE;
                    }
                    else
                    {
                        std::cout << "Invalid Input" << std::endl;
                        return;
                    }
                    FL.add_player(stoi(vstrings[2]), stoi(vstrings[3]), vstrings[4].c_str(), position);
                    return;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }
    else if (vstrings[0] == "remove")
    {
        if (vstrings.size() == 1)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "league")
        {
            if (vstrings.size() == 3)
            {
                if (is_number(vstrings[2]))
                {
                    FL.remove_league(stoi(vstrings[2]));
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings[1] == "player")
        {
            if (vstrings.size() == 4)
            {
                if (is_number(vstrings[2]) && is_number(vstrings[3]))
                {
                    FL.remove_player(stoi(vstrings[2]), stoi(vstrings[3]));
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
    }
    else if (vstrings[0] == "exists")
    {
        if (vstrings.size() == 1)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "league")
        {
            if (vstrings.size() == 3)
            {
                if (is_number(vstrings[2]))
                {
                    if (FL.league_exists(stoi(vstrings[2])))
                    {
                        std::cout << "League exists" << std::endl;
                        return;
                    }
                    else
                    {
                        std::cout << "League does not exists" << std::endl;
                        return;
                    }
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings[1] == "player")
        {
            if (vstrings.size() == 4)
            {
                if (is_number(vstrings[2]) && is_number(vstrings[3]))
                {
                    if (FL.player_exists(stoi(vstrings[2]), stoi(vstrings[3])))
                    {
                        std::cout << "Player exists" << std::endl;
                    }
                    else
                    {
                        std::cout << "Player does not exists" << std::endl;
                    }
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
    }
    else if (vstrings[0] == "modify")
    {
        if (vstrings.size() != 6)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "player")
        {
            if (is_number(vstrings[2]) && is_number(vstrings[3]))
            {
                POSITION position;
                if (vstrings[5] == "KEEPER")
                {
                    position = KEEPER;
                }
                else if (vstrings[5] == "ATTACK")
                {
                    position = ATTACK;
                }
                else if (vstrings[5] == "DEFENCE")
                {
                    position = DEFENCE;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
                FL.modify_player(stoi(vstrings[2]), stoi(vstrings[3]), vstrings[4].c_str(), position);
                return;
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }
    else if (vstrings[0] == "move")
    {
        if (vstrings.size() != 5)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "player")
        {
            if (is_number(vstrings[2]) && is_number(vstrings[3]) && is_number(vstrings[4]))
            {
                FL.move_player(stoi(vstrings[2]), stoi(vstrings[3]), stoi(vstrings[4]));
            }
        }
    }
    else if (vstrings[0] == "count")
    {
        if (vstrings.size() == 1)
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
        else if (vstrings[1] == "league")
        {
            if (vstrings.size() == 2)
            {
                std::cout << "Number of leagues : " << FL.league_count() << std::endl;
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings[1] == "player")
        {
            if (vstrings.size() == 2)
            {
                std::cout << "Number of players : " << FL.player_count() << std::endl;
            }
            else if (vstrings.size() == 3)
            {
                if (is_number(vstrings[2]))
                {
                    std::cout << "Number of players in league " << stoi(vstrings[2]) << " : " << FL.player_count(stoi(vstrings[2])) << std::endl;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
        else if (vstrings[1] == "position")
        {
            if (vstrings.size() == 4)
            {
                POSITION position;
                if (vstrings[2] == "KEEPER")
                {
                    position = KEEPER;
                }
                else if (vstrings[2] == "ATTACK")
                {
                    position = ATTACK;
                }
                else if (vstrings[2] == "DEFENCE")
                {
                    position = DEFENCE;
                }
                else
                {
                    std::cout << "Invalid Input" << std::endl;
                    return;
                }
                {
                    if (is_number(vstrings[3]))
                    {
                        std::cout << "Number of players in the given position : " << FL.position_count(stoi(vstrings[3]), position) << std::endl;
                    }
                    else
                    {
                        std::cout << "Invalid Input" << std::endl;
                        return;
                    }
                }
            }
            else
            {
                std::cout << "Invalid Input" << std::endl;
                return;
            }
        }
    }
    else if (vstrings[0] == "delete")
    {
        if (vstrings.size() == 1)
        {
            FL.clear();
        }
        else
        {
            std::cout << "Invalid Input" << std::endl;
            return;
        }
    }
    else
    {
        std::cout << "Invalid Input" << std::endl;
        return;
    }
}

bool Shell::is_number(const std::string &s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

void Shell::split(std::string const &str, const char delim, std::vector<std::string> &out)
{
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

void Shell::run()
{
    while (true)
    {
        std::cout << "Input : ";
        std::string s;
        std::getline(std::cin, s);
        handle_input(s);
    }

    return;
}

int main()
{
    Shell s;
    s.run();
    return 0;
}