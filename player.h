#include <iostream>
#include <cstring>

typedef enum
{
    ATTACK,
    DEFENCE,
    KEEPER,
} POSITION;//enumeration of different positions of the player

class Player
{
private:
    int id;//unique id of the player
    char *name;//name of the player
    POSITION position;//position of the player

public:
    Player(int id, const char *name, POSITION position); //Player class constructor
    ~Player();//Player class destructor
    int get_id();//getid to player_id
    char *get_name();//getname to player_name
    POSITION get_position();//getpostion to player_position
    void modify(const char *name, POSITION position);//modifies the internal player data
    void display();//displays the player data(id,name and position)
};

typedef struct PlayerNode
{
    Player *player;//pointer to current playe
    PlayerNode *next; //pointer to next Node element, if nullptr then this is the last node in the list
} PlayerNode;//Linked list of player data