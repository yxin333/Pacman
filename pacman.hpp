enum GAMESTATE {
    running = 0,
    win, lose
};

enum DIRECTION {
    Still = 0,
    Upward, Downward, Left, Right
}state, enemy_state;

/*
    To access the member of struct
    Use "."
    Example: player.x
*/
struct POSITION{
    short x;
    short y;
    short old_x;
    short old_y;
}player, enemy;
struct PACMAN{
    GAMESTATE status;
    int score, max_score;
}pacman;

int distance_x, distance_y;