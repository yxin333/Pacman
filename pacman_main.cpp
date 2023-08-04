#include <iostream>
#include <windows.h>
#include "pacman.hpp"

using namespace std;

char map[20][40] = {
    "+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|    $                                |",
    "|     $                               |",
    "|      $                              |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "|                                     |",
    "+$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$+"};

void CursorPosition(short x, short y) {
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD position = {(short)x, (short)y};  
  
    SetConsoleCursorPosition(hStdout, position); 
} 

void ShowMap()  
{  
    for (int row = 0; row < 20; row++)  
    {  
        for(int column = 0; column < 40; column++ ) {
            cout << map[row][column];
        }
        cout << endl;
    }  
}  

bool check_obstacles(short x, short y) {
    return map[y][x] == '$' || map[y][x] == '|';
}

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

void delete_old_position(short x, short y) {
        CursorPosition(x, y);
        cout << " ";
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

int main() {
    ShowMap();
    CursorPosition(20, 10);
    cout << "X";
    state = DIRECTION::Still;
    pacman.status = GAMESTATE::running;
    while(pacman.status == GAMESTATE::running) {
        check_direction();
        if(next_position()) {
            draw_player_position();          
            Sleep(100);
        }
    }      
}


