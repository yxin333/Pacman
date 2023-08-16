#include <iostream>
#include <windows.h>
#include "pacman.hpp"
#include "global.hpp"
#include "player.hpp"
#include "map.hpp"

using namespace std;


int main() {
    ShowMap();
    enemy.x = 19;
    enemy.y = 9;
    state = DIRECTION::Still;
    pacman.status = GAMESTATE::running;
    while(pacman.status == GAMESTATE::running) {
        check_direction();
        if(next_position()) {
            draw_player_position();          
        }
        Sleep(100);
    }      
}