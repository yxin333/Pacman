#pragma once
#include <iostream>
#include <windows.h>
#include "pacman.hpp"
#include "global.hpp"

using namespace std;

/*
    Check which key is pressed
    Set the player direction state 
*/ 
void check_direction() {
    if(GetAsyncKeyState(VK_UP) & 0x1) {
        state = DIRECTION::Upward;
    }
    else if(GetAsyncKeyState(VK_DOWN) & 0x1) {
        state = DIRECTION::Downward;
    }
    else if(GetAsyncKeyState(VK_LEFT) & 0x1) {
        state = DIRECTION::Left;
    }
    else if(GetAsyncKeyState(VK_RIGHT) & 0x1) {
        state = DIRECTION::Right;
    }
}

void draw_player_position() {
    switch(state) {
        case Upward:
            delete_old_position(player.x, player.y + 1); 
            CursorPosition(player.x, player.y);
            cout << "^";
            break;
        case Downward:
            delete_old_position(player.x, player.y - 1);
            CursorPosition(player.x, player.y);
            cout << "v";
            break;
        case Left:
            delete_old_position(player.x + 1, player.y);
            CursorPosition(player.x, player.y);
            cout << "<";
            break;
        case Right:
            delete_old_position(player.x - 1, player.y);
            CursorPosition(player.x, player.y);
            cout << ">";
            break;
        case Still:
            CursorPosition(player.x, player.y);
            cout << "X";
            break;
    }
    
}

// From the given direction state, change the player position according to the direction state
bool next_position() {
    switch(state) {
        case Upward:
            if (!check_obstacles(player.x, player.y - 1)){
                player.y--;
                return true;
            }
            break;
        case Downward:
            if (!check_obstacles(player.x, player.y + 1)){
                player.y++;
                return true;
            }
            break;
        case Left:
            if (!check_obstacles(player.x - 1, player.y)){
                player.x--;
                return true;
            }
            break;
        case Right:
            if (!check_obstacles(player.x + 1, player.y)){
                player.x++;
                return true;
            }
            break;
    }
    return false;
}