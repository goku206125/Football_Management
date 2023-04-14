#include "league.h"

class Football_League
{
private:
    char *name;                 //name of the Football League Federation
    LeagueNode *head;           //pointer to next element of the linked list; if nullptr then this is the last node in the list
    League *get_league(int id); //returns the League object with the given id for moving

public:
    Football_League();                                                                   //Football_league class constructor
    Football_League(const char *name);                                                   //Football_league class constructor with name
    ~Football_League();                                                                  //Football_league class destructor
    bool add_league(int id, const char *name);                                           //adds a new league to the list with the given league id and name
    bool remove_league(int id);                                                          //removes a league with the given id
    bool league_exists(int id);                                                          //returns true if a league exists with the given id
    bool add_player(int league, int id, const char *name, POSITION position);            //adds a new player to the given league id with the given player data
    bool remove_player(int league, int id);                                              //removes the player in the given league id with the given player id
    bool modify_player(int league, int id, const char *new_name, POSITION new_position); //modifies the player data in the given league id with the new player data
    bool move_player(int source_league_id, int source_player_id, int target_league_id);  //move a player object from source league to target league
    bool player_exists(int league, int id);                                              //returns true if a player exists in the given league id with the given player id
    int league_count();                                                                  //returns the number of leagues in the Football_League object
    int player_count();                                                                  //returns the number of player in the Football_League object
    int player_count(int league);                                                        //returns the number of player in the given league id
    int position_count(int league, POSITION position);                                   //returns the number ofplayers with the given position in the given league id
    void clear();                                                                        //erases all the leagues and their player data in the Football_League object
    void display(int league);                                                            //displays the data of the league with the given id
    void display(POSITION position);                                                     //displays the players with the given position
    void display(int league, POSITION position);                                         //displays the players with the given position in the given league
    void display();                                                                      //displays all the leagues and their player data
};