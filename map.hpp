#pragma once
#include <iostream>
#include <windows.h>
#include "global.hpp"


using namespace std;

char map[20][40] = {
    "+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+",
    "|                                     |",
    "|                                     |",
    "|          $              $           |",
    "|          $              $           |",
    "|          $              $           |",
    "|        $$$              $$$         |",
    "|                                     |",
    "|                  X                  |",
    "|               |     |               |",
    "|               |$$$$$|               |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+"};



void ShowMap()  
{  
    for (int row = 0; row < 20; row++)  
    {  
        // print out the whole map
        for(int column = 0; column < 40; column++ ) {
            // find where the initial player position
            if(map[row][column] == 'X') {
                player.x = column;
                player.y = row;
            }
            cout << map[row][column];
        }
        cout << endl;
    }  
}  
