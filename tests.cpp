#include "tests.h"

void Tests::test1()
{ //number of leagues in a empty Football_League object should be 0
    Football_League FL("Football League");

    if (FL.league_count() == 0)
    {
        std::cout << "Test 1 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 1 : Fail" << std::endl;
    }
}

void Tests::test2()
{ // add_league function adds league to Football_League object properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    if (FL.league_count() == 2 && FL.league_exists(1) && FL.league_exists(2))
    {
        std::cout << "Test 2 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 2 : Fail" << std::endl;
    }
}

void Tests::test3()
{ //there can be a maximum of 7 leagues in a Football_League object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");
    FL.add_league(4, "League 4");
    FL.add_league(5, "League 5");
    FL.add_league(6, "League 6");
    FL.add_league(7, "League 7");
    FL.add_league(8, "League 8");

    if (FL.league_count() == 7 && FL.league_exists(1) && FL.league_exists(2) && FL.league_exists(3) && FL.league_exists(4) && FL.league_exists(5) && FL.league_exists(6) && FL.league_exists(7) && !FL.league_exists(8))
    {
        std::cout << "Test 3 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 3 : Fail" << std::endl;
    }
}

void Tests::test4()
{ //a league is not added if a league with the id already exists in the league list
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(1, "League 2");

    if (FL.league_count() == 1 && FL.league_exists(1))
    {
        std::cout << "Test 4 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 4 : Fail" << std::endl;
    }
}

void Tests::test5()
{ //remove_league function does not affect an empty Football_League object
    Football_League FL("Football League");
    FL.remove_league(1);

    if (FL.league_count() == 0 && !FL.league_exists(1))
    {
        std::cout << "Test 5 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 5 : Fail" << std::endl;
    }
}

void Tests::test6()
{ //remove_league functions removes a league from the top of the league list properly

    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");

    FL.remove_league(1);

    if (FL.league_count() == 2 && !FL.league_exists(1) && FL.league_exists(2) && FL.league_exists(3))
    {
        std::cout << "Test 6 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 6 : Fail" << std::endl;
    }
}

void Tests::test7()
{ //remove_league functions removes a league from the middle of the league list properly

    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");

    FL.remove_league(2);

    if (FL.league_count() == 2 && FL.league_exists(1) && !FL.league_exists(2) && FL.league_exists(3))
    {
        std::cout << "Test 7 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 7 : Fail" << std::endl;
    }
}

void Tests::test8()
{ //remove_league functions removes a league from the end of the league list properly

    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");

    FL.remove_league(3);

    if (FL.league_count() == 2 && FL.league_exists(1) && FL.league_exists(2) && !FL.league_exists(3))
    {
        std::cout << "Test 8 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 8 : Fail" << std::endl;
    }
}

void Tests::test9()
{ //remove_league function does not affect a non-empty Football_League object if the id does not exist in the league list

    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");

    FL.remove_league(4);

    if (FL.league_count() == 3 && FL.league_exists(1) && FL.league_exists(2) && FL.league_exists(3))
    {
        std::cout << "Test 9 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 9 : Fail" << std::endl;
    }
}

void Tests::test10()
{ //league_exists function returns true if a league exists in the league list with the given id

    Football_League FL("Football League");
    FL.add_league(1, "League 1");

    if (FL.league_exists(1))
    {
        std::cout << "Test 10 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 10 : Fail" << std::endl;
    }
}

void Tests::test11()
{ //league_exists function returns false if a league does not exist in the league list with the given id

    Football_League FL("Football League");
    FL.add_league(1, "League 1");

    if (!FL.league_exists(2))
    {
        std::cout << "Test 11 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 11 : Fail" << std::endl;
    }
}

void Tests::test12()
{ //the number of players in an empty league would be 0
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    if (FL.player_count(1) == 0)
    {
        std::cout << "Test 12 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 12 : Fail" << std::endl;
    }
}

void Tests::test13()
{ //add_league function adds player to league object properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);

    if (FL.player_count(1) == 1 && FL.player_exists(1, 1))
    {
        std::cout << "Test 13 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 13 : Fail" << std::endl;
    }
}

void Tests::test14()
{ //a league can have at most 11 players in the following configuration 1 KEEPER, 5 ATTACk, 5 DEFENCE
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);

    if (FL.player_count(1) == 1 && FL.player_exists(1, 1))
    {
        std::cout << "Test 14 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 14 : Fail" << std::endl;
    }
}

void Tests::test15()
{ //remove_player function does not affect a league list if the given id does not exist in the list
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.remove_player(1, 4);

    if (FL.player_count(1) == 3 && FL.player_exists(1, 1) && FL.player_exists(1, 2) && FL.player_exists(1, 3))
    {
        std::cout << "Test 15 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 15 : Fail" << std::endl;
    }
}

void Tests::test16()
{ //remove_player functions removes a player object from the top of the player list properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.remove_player(1, 1);

    if (FL.player_count(1) == 2 && !FL.player_exists(1, 1) && FL.player_exists(1, 2) && FL.player_exists(1, 3))
    {
        std::cout << "Test 16 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 16 : Fail" << std::endl;
    }
}

void Tests::test17()
{ //remove_player functions removes a player object from the middle of the player list properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.remove_player(1, 2);

    if (FL.player_count(1) == 2 && FL.player_exists(1, 1) && !FL.player_exists(1, 2) && FL.player_exists(1, 3))
    {
        std::cout << "Test 17 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 17 : Fail" << std::endl;
    }
}

void Tests::test18()
{ //remove_player functions removes a player object from the end of the player list properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.remove_player(1, 3);

    if (FL.player_count(1) == 2 && FL.player_exists(1, 1) && FL.player_exists(1, 2) && !FL.player_exists(1, 3))
    {
        std::cout << "Test 18 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 18 : Fail" << std::endl;
    }
}

void Tests::test19()
{ //add_player function does not add player if id already exists in the list
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 2, "Player 3", DEFENCE);

    if (FL.player_count(1) == 2 && FL.player_exists(1, 1) && FL.player_exists(1, 2))
    {
        std::cout << "Test 19 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 19 : Fail" << std::endl;
    }
}

void Tests::test20()
{ //modify_player function modifies the data of a player properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    std::cout << "Test 20 : Before Modification" << std::endl;
    FL.display(1);
    FL.modify_player(1, 2, "Modified Player 2", DEFENCE);
    std::cout << "Test 20 : After Modification" << std::endl;
    FL.display(1);
}

void Tests::test21()
{ //modify_player function does not modify the data of a player if if does not exist in the list
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    std::cout << "Test 21 : Before Modification" << std::endl;
    FL.display(1);
    FL.modify_player(1, 3, "Modified Player 2", DEFENCE);
    std::cout << "Test 21 : After Modification" << std::endl;
    FL.display(1);
}

void Tests::test22()
{ //move_player function moves a player from one league to another properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_league(2, "League 2");
    std::cout << "Test 22 : Before Movement" << std::endl;
    FL.display();
    FL.move_player(1, 1, 2);
    std::cout << "Test 22 : After Movement" << std::endl;
    FL.display();
    if (FL.player_count(1) == 1 && FL.player_count(2) == 1 && FL.player_exists(1, 2) && FL.player_exists(2, 1) && !FL.player_exists(1, 1))
    {
        std::cout << "Test 22 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 22 : Fail" << std::endl;
    }
}

void Tests::test23()
{ //move_player function does not affect league lists if given id does not exist
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_league(2, "League 2");
    std::cout << "Test 23 : Before Movement" << std::endl;
    FL.display();
    FL.move_player(1, 3, 2);
    std::cout << "Test 23 : After Movement" << std::endl;
    FL.display();
    if (FL.player_count(1) == 2 && FL.player_count(2) == 0 && FL.player_exists(1, 1) && FL.player_exists(1, 2) && !FL.player_exists(2, 3))
    {
        std::cout << "Test 23 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 23 : Fail" << std::endl;
    }
}

void Tests::test24()
{ //league_exists function works properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    if (FL.league_exists(1) && !FL.league_exists(2))
    {
        std::cout << "Test 24 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 24 : Fail" << std::endl;
    }
}

void Tests::test25()
{ //player_exists function works properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    if (FL.player_exists(1, 1) && !FL.player_exists(1, 2))
    {
        std::cout << "Test 25 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 25 : Fail" << std::endl;
    }
}

void Tests::test26()
{ //league_count function returns 0 in an empty Football_League object
    Football_League FL("Football League");
    if (FL.league_count() == 0)
    {
        std::cout << "Test 26 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 26 : Fail" << std::endl;
    }
}

void Tests::test27()
{ //league_count function returns the number of leagues in a Football_League object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_league(2, "League 2");
    FL.add_league(3, "League 3");
    if (FL.league_count() == 3)
    {
        std::cout << "Test 27 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 27 : Fail" << std::endl;
    }
}

void Tests::test28()
{ //player_count function returns the number of players in a League object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    if (FL.player_count(1) == 3)
    {
        std::cout << "Test 28 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 28 : Fail" << std::endl;
    }
}

void Tests::test29()
{ //player_count function returns 0 in a empty League object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    if (FL.player_count(1) == 0)
    {
        std::cout << "Test 29 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 29 : Fail" << std::endl;
    }
}

void Tests::test30()
{ //player_count function returns 0 in a empty Football_league object
    Football_League FL("Football League");
    if (FL.player_count() == 0)
    {
        std::cout << "Test 30 : Success" << std::endl;
    }
    else
    {
        std::cout << "Test 30 : Fail" << std::endl;
    }
}

void Tests::test31()
{ //player_count function returns the number of players in a Football_league object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.add_league(2, "League 2");
    FL.add_player(2, 1, "Player 1", KEEPER);
    FL.add_player(2, 2, "Player 2", ATTACK);
    if (FL.player_count() == 5)
    {
        std::cout << "Test 31 : Success" << std::endl;
    }
    else
    {
        std::cout << FL.player_count() << "Test 31 : Fail" << std::endl;
    }
}

void Tests::test32()
{ //position_count function works properly
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", ATTACK);
    FL.add_player(1, 4, "Player 4", DEFENCE);
    FL.add_player(1, 5, "Player 5", DEFENCE);
    if (FL.position_count(1, KEEPER) == 1 && FL.position_count(1, ATTACK) == 2 && FL.position_count(1, DEFENCE) == 2)
    {
        std::cout << "Test 32 : Success" << std::endl;
    }
    else
    {
        std::cout << FL.player_count() << "Test 32 : Fail" << std::endl;
    }
}

void Tests::test33()
{ //clear function removes all the leagues and its players in the Football_League object
    Football_League FL("Football League");
    FL.add_league(1, "League 1");
    FL.add_player(1, 1, "Player 1", KEEPER);
    FL.add_player(1, 2, "Player 2", ATTACK);
    FL.add_player(1, 3, "Player 3", DEFENCE);
    FL.add_league(2, "League 2");
    FL.add_player(2, 1, "Player 1", KEEPER);
    FL.add_player(2, 2, "Player 2", ATTACK);
    FL.clear();
    if (FL.player_count() == 0 && FL.league_count() == 0)
    {
        std::cout << "Test 33 : Success" << std::endl;
    }
    else
    {
        std::cout << FL.player_count() << "Test 33 : Fail" << std::endl;
    }
}

void Tests::run()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test11();
    test12();
    test13();
    test14();
    test15();
    test16();
    test17();
    test18();
    test19();
    test20();
    test21();
    test22();
    test23();
    test24();
    test25();
    test26();
    test27();
    test28();
    test29();
    test30();
    test31();
    test32();
    test33();
}
