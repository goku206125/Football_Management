#include <string>
#include <stdlib.h>
#include "football_league.h"

class Shell
{
private:
    Football_League FL;                                                                  //Football League Object
    void handle_input(std::string);                                                      //does the respective function based on string
    bool is_number(const std::string &s);                                                //checks if the given string is a number or not
    void split(std::string const &str, const char delim, std::vector<std::string> &out); //splits the string with the delimiter and returns a vector of split tokens

public:
    void run(); //starts the shell
};