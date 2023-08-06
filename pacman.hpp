enum GAMESTATE {
    running = 0,
    win, lose
};

enum DIRECTION {
    Still = 0,
    Upward, Downward, Left, Right
};

DIRECTION state;

struct POSITION{
    short x;
    short y;
    short ex;
    short ey;
}player, enemy;

struct PACMAN{
    GAMESTATE status;
    int score, max_score;
}pacman;

int distance_x, distance_y;