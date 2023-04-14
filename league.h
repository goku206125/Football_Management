#include "player.h"

class League
{
private:
    int id;           // league id
    char *name;       //league name
    PlayerNode *head; //Player linked list head

public:
    League(int id, const char *name);                             //League class constructor
    ~League();                                                    //League class destructor
    int get_id();                                                 //get to league_id
    bool add_player(int id, const char *name, POSITION position); //function to add new player to player list only if the player_id does not exist
    bool add_player(Player *player);
    bool remove_player(int id);                                              //function to remove player in player list with the given player_id
    bool modify_player(int id, const char *new_name, POSITION new_position); //function to modify player in player list with the new data
    int player_count(POSITION position);                                     //returns the number of players with the given position in the league
    int player_count();                                                      //returns the number of players in the league
    bool player_exists(int id);                                              //returns true if a player exists with the given id, false if not
    Player *get_player(int id);                                              //returns the Player object with the given id for moving
    void clear();                                                            //removes all the players in the league
    void display(POSITION position);                                         //displays the data of player with the given position
    void display();                                                          //display all the player data in the league
};

typedef struct LeagueNode
{
    League *league;   //pointer to current league
    LeagueNode *next; //pointer to next element of the linked list; if nullptr then this is the last node in the list
} LeagueNode;
