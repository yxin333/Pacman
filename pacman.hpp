enum GAMESTATE {
    running = 0,
    win, lose
};

enum DIRECTION {
    Still = 0,
    Upward, Downward, Left, Right
};

extern DIRECTION state;

struct POSITION{
    short x = 1;
    short y = 1;
    short ex = 19;
    short ey = 9;
}player, enemy;

struct PACMAN{
    GAMESTATE status;
    int score, max_score;
}pacman;

int distance_x, distance_y;
