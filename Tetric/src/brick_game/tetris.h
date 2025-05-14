#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef enum { INIT, DROP, MOVING, COLLISION, PAUSE, GAMEOVER } GameState;

typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
} GameInfo_t;

typedef struct Block {
  int b;
} Block;

typedef struct Figure {
  int x;
  int y;
  int size;
  Block **blocks;
} Figure;

typedef struct FiguresT {
  int count;
  int size;
  Block **blocks;
} FiguresT;

typedef struct Field {
  int width;
  int height;
  Block **blocks;
} Field;

typedef struct Player {
  int action;
} Player;

typedef struct Game {
  Field *field;
  Figure *figure;
  FiguresT *figurest;
  Player *player;
  Block **tet_templates;

  int score;
  int high_score;
  int ticks_left;
  int ticks;
  int speed;
  int level;
  int next;

  int pause;
  int state;

} Game;

void initGame();

Game *createGame(int field_width, int field_height, int figures_size,
                 int count);

Field *createField(int width, int height);

Block **createTemplates();

FiguresT *createFiguresT(int count, int figures_size, Block **figures_template);

Figure *createFigure(Game *tetg);

int **createPrintField(int width, int height);

int **createNextBlock(int size);

void userInput(UserAction_t action, bool hold);

void dropNewFigure(Game *tetg);

GameInfo_t updateCurrentState();

void calculate(Game *tetg);

void calcOne(Game *tetg);

void moveFigureDown(Game *tetg);

void moveFigureUp(Game *tetg);

void moveFigureRight(Game *tetg);

void moveFigureLeft(Game *tetg);

int collision(Game *tetg);

int eraseLines(Game *tetg);

int lineFilled(int i, Field *tfl);

void dropLine(int i, Field *tfl);

Figure *rotFigure(Game *tetg);

void handleRotation(Game *tetg);

void plantFigure(Game *tetg);

void countScore(Game *tetg);

void saveHighScore(int high_score);

int loadHighScore();

extern Game *tetg;

void freeGame(Game *tetg);

void freeField(Field *tetf);

void freeFigure(Figure *tf);

void freeFiguresT(FiguresT *tetft);

void freeTemplates(Block **templates);

void freePrintField(int **print_field, int height);

void freeNextBlock(int **next, int size);

void freeGui(GameInfo_t game, int size, int height);

#endif