#ifndef CLI_H
#define CLI_H
#include <ncurses.h>

#include "../brick_game/tetris.h"

void initGui();

void printGame(GameInfo_t game, struct timespec sp_start,
               struct timespec sp_end);

void printField(GameInfo_t game);

void printNextFigure(GameInfo_t game);

void printInfo(GameInfo_t game);

UserAction_t getAction();

void handleDelay(struct timespec sp_start, struct timespec sp_end,
                 int game_speed);

#endif