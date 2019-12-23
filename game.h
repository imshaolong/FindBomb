#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define EASY 10
#define ROW 9
#define COL 9
#define ROWS ROW + 2
#define COLS COL + 2

void init_board(char board[ROWS][COLS], int rows, int  cols, char ch);
void display_board(char board[ROWS][COLS],  int row, int col);
void set_bomb(char board[ROWS][COLS], int row, int col);
char get_bomb_num(char board[ROWS][COLS], int x, int y );
void find_bomb(char bomb[ROWS][COLS], char show[ROWS][COLS], int row, int y );
